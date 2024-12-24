/*
避免类的层次过于复杂
一个系统中包含多个不同的实现，而这些实现的组合会导致复杂的继承结构，桥接模式可以通过将抽象部分与具体实现部分分离来减少类的数量，从而避免类爆炸问题。
在一个图形绘制程序中，可能会有很多种图形（如圆形、矩形）和不同的颜色（红色、蓝色、绿色）
如果采用传统的继承方式，你可能需要为每个图形和颜色的组合创建一个类（例如 RedCircle, BlueCircle, GreenCircle），这样会产生大量的类
使用桥接模式，可以将图形和颜色分离，减少类的数量

抽象类: Shape
具体类: Color
*/

#include <iostream>

class Color {
public:
  virtual void fill() = 0;
  virtual ~Color() = default;
};

// 具体颜色实现类
class Red : public Color {
public:
  void fill() override {
    std::cout << "Red fill" << std::endl;
  }
};

class Green : public Color {
public:
  void fill() override {
    std::cout << "Green fill" << std::endl;
  }
};

// 形状抽象类
class Shape {
protected:
  Color* color_; // 持有颜色接口
public:
  Shape(Color* color) : color_(color) {}
  virtual void draw() = 0;
  virtual ~Shape() = default;
};


// 具体形状实现类
class Circle : public Shape {
public:
  Circle(Color* color) : Shape(color) {}
  void draw() override {
    color_->fill();
    std::cout << "Circle draw" << std::endl;
  }
};

class Rectangle : public Shape {
public:
  Rectangle(Color* color) : Shape(color) {}
  void draw() override {
    color_->fill();
    std::cout << "Rectangle draw" << std::endl;
  }
};

int main() {
  // 创建实现类对象
  Color* red = new Red();
  Shape* redCircle = new Circle(red);
  redCircle->draw();
  delete redCircle;
  delete red;

  Color* green = new Green();
  Shape* greenRectangle = new Rectangle(green);
  greenRectangle->draw();
  delete greenRectangle;
  delete green;
  return 0;
}