#include <iostream>
#include <memory>
#include <string>

/*
Shape 是一个原型接口，定义了一个 clone() 方法，所有具体的图形类都需要实现该方法来克隆对象。
Circle 和 Rectangle 是具体的原型类，实现了 clone() 方法，允许我们通过克隆现有对象来创建新对象。
客户端代码演示了如何使用原型模式来复制图形对象，减少了从头创建对象的过程
*/

/*
浅拷贝：仅复制对象的引用，拷贝后的对象和原对象共享内部引用的资源。适用于对象内部没有复杂引用关系时。
深拷贝：不仅复制对象本身，还会复制对象所引用的所有资源，创建一个完全独立的新对象。适用于对象内部含有指针或引用成员时
*/

// 原型接口: 定义了克隆自身的方法
class Shape {
public:
  virtual std::unique_ptr<Shape> clone() const = 0;
  virtual void draw() const = 0;
  virtual ~Shape() {}
};

// 具体原型类: 实现了克隆自身的方法
class Circle : public Shape {
public:
  Circle(const std::string& colcor): color_(colcor) {}
  
  // 实现克隆自身的方法
  std::unique_ptr<Shape> clone() const override {
    return std::make_unique<Circle>(*this);
  }

  void draw() const override {
    std::cout << "Draw a " << color_ << " circle." << std::endl;
  }

private:
  std::string color_;
};

// 具体原型类: 实现了克隆自身的方法
class Rectangle : public Shape {
public:
  Rectangle(int width, int height): width_(width), height_(height) {}

  // 实现克隆自身的方法
  std::unique_ptr<Shape> clone() const override {
    return std::make_unique<Rectangle>(*this);
  }

  void draw() const override {
    std::cout << "Draw a rectangle with width " << width_ << " and height " << height_ << "." << std::endl;
  }

private:
  int width_;
  int height_;
};

// 客户端代码
int main(){
  std::unique_ptr<Shape> circle = std::make_unique<Circle>("red");
  circle->draw();

  std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>(100, 200);
  rectangle->draw();

  // 使用原型模式克隆对象
  std::unique_ptr<Shape> circle2 = circle->clone();
  circle2->draw();

  std::unique_ptr<Shape> rectangle2 = rectangle->clone();
  rectangle2->draw();

  return 0;
}

// 如果对象内部含有指针或引用成员时，需要实现深拷贝，否则拷贝后的对象会共享内部资源，导致资源释放问题。
/*
class Circle : public Shape {
public:
  Circle(const std::string& colcor, const std::shared_ptr<OtherResource>& resource): 
  color_(colcor),resource_(resource) {}

  // 深拷贝的方法
  std::unique_ptr<Shape> clone() const override {
    return std::make_unique<Circle>(color, std::make_shared<OtherResource>(*resource_));
  }

  void draw() const override {
    std::cout << "Draw a " << color_ << " circle." << std::endl;
  }
private:
  std::string color_;
  std::shared_ptr<OtherResource> resource_;
};
*/

