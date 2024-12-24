/*
创建一个简单的文件系统，包含文件和目录，可以添加、删除、查找文件和目录
文件夹可以包含文件和文件夹
*/

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// 文件和文件夹的抽象类
class FileSystemComponent{
public:
  virtual void add(std::shared_ptr<FileSystemComponent> component) = 0;
  virtual void remove(std::shared_ptr<FileSystemComponent> component) = 0;
  virtual void list() const = 0;
  virtual ~FileSystemComponent() = default;
};

// 文件类
class File : public FileSystemComponent{
private:
  std::string name_;
public:
  File(const std::string& name):name_(name){}
  void add(std::shared_ptr<FileSystemComponent> component) override{
    // 文件不能添加文件或文件夹
    std::cout << "Cannot add to a file" << std::endl;
  }
  void remove(std::shared_ptr<FileSystemComponent> component) override{
    // 文件不能删除文件或文件夹
    std::cout << "Cannot remove from a file" << std::endl;
  }
  void list() const override{
    std::cout << "File: " << name_ << std::endl;
  }
};

// 文件夹类
class Folder : public FileSystemComponent{
private:
  std::string name_;
  std::vector<std::shared_ptr<FileSystemComponent>> children_;
public:
  Folder(const std::string& name):name_(name){}
  void add(std::shared_ptr<FileSystemComponent> component) override{
    children_.push_back(component);
  }
  void remove(std::shared_ptr<FileSystemComponent> component) override{
    children_.erase(std::remove_if(children_.begin(), children_.end(), [&](const std::shared_ptr<FileSystemComponent>& child){
      return child == component;
    }), children_.end());
  }
  void list() const override{
    std::cout << "Folder: " << name_ << std::endl;
    for(auto& child : children_){
      child->list();
    }
  }
};

int main(){
  // 创建根文件夹
  auto root = std::make_shared<Folder>("root");

  // 创建文件夹和文件
  auto folder1 = std::make_shared<Folder>("folder1");
  auto folder2 = std::make_shared<Folder>("folder2");
  auto file1 = std::make_shared<File>("file1");
  auto file2 = std::make_shared<File>("file2");

  // 添加文件夹和文件
  root->add(folder1);
  root->add(folder2);
  folder1->add(file1);
  folder2->add(file2);

  // 列出根文件夹
  root->list();

  return 0;
}

