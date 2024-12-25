/*
模拟了一个简单的文字处理系统，其中字符内容（内在状态）可以共享，而字体、大小、颜色（外在状态）则由客户端动态传递
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

// 抽象享元类
class Flyweight{
public:
  virtual void display(const std::string& font, int size, const std::string& color) const = 0;
  virtual ~Flyweight() = default;
};

// 具体享元类
class ConcreteFlyweight : public Flyweight{
private:
  char state_; // 内在状态, 也就是字符内容
public:
  explicit ConcreteFlyweight(char state) : state_(state){}
  void display(const std::string& font, int size, const std::string& color) const override{
    std::cout << "Character: " << state_ << ", Font: " << font << ", Size: " << size << ", Color: " << color << std::endl;
  }
};


// 享元工厂类
class FlyweightFactory{
private:
  // 存储享元对象的容器
  std::unordered_map<char, std::shared_ptr<Flyweight>> flyweights_;
public:
  // 获取享元对象
  std::shared_ptr<Flyweight> getFlyweight(char state){
    if(flyweights_.find(state) == flyweights_.end()){
      flyweights_[state] = std::make_shared<ConcreteFlyweight>(state);
      std::cout << "Create new flyweight object with state: " << state << std::endl;
    }
    return flyweights_[state];
  }

  // 获取享元对象的个数
  int getFlyweightCount() const{
    return flyweights_.size();
  }
};


// 客户端
int main(){
  FlyweightFactory factory;
  std::shared_ptr<Flyweight> flyweight1 = factory.getFlyweight('A');
  flyweight1->display("Arial", 12, "Red");

  std::shared_ptr<Flyweight> flyweight2 = factory.getFlyweight('B');
  flyweight2->display("Times New Roman", 14, "Blue");

  std::shared_ptr<Flyweight> flyweight3 = factory.getFlyweight('A');
  flyweight3->display("Arial", 12, "Red");

  std::cout << "Total number of flyweight objects: " << factory.getFlyweightCount() << std::endl;

  return 0;
}