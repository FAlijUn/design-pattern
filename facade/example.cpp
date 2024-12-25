/*
外观模式（Facade Pattern）提供了一个统一的接口来访问一个子系统中的一组接口
创建一个简单的文件处理系统，其中包含多个复杂的操作，如创建文件、写入文件和读取文件
通过一个外观类来简化这些操作
*/

#include <iostream>
#include <fstream>

// 子系统: 文件创建
class FileCreator {
public:
  void createFile(const std::string& filename) {
    std::ofstream file(filename);
    file.close();
    std::cout << "File created: " << filename << std::endl;
  }
};

// 子系统: 文件写入
class FileWriter {
public:
  void writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename, std::ios::out | std::ios::app);
    file << content;
    file.close();
    std::cout << "Content written to file: " << filename << std::endl;
  }
};

// 子系统: 文件读取
class FileReader {
public:
  std::string readFromFile(const std::string& filename){
    std::ifstream file(filename);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    std::cout << "Content read from file: " << filename << std::endl;
  } 
};

// 外观类
class FileHandle {
private:
  FileCreator fileCreator;
  FileWriter fileWriter;
  FileReader fileReader;
public:
  void handleFile(const std::string& filename, const std::string& content) {
    fileCreator.createFile(filename);
    fileWriter.writeToFile(filename, content);
    fileReader.readFromFile(filename);
  }
};

int main() {
  FileHandle fileHandle;
  fileHandle.handleFile("example.txt", "Hello, Facade Pattern!");
  return 0;
}