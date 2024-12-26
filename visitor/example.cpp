#include <iostream>
#include <vector>
#include <memory>

// 元素接口
class Shape {
public:
  virtual ~Shape() = default;
  virtual void accept(class ShapeVisitor &visitor) = 0;
};

// 具体元素
class Circle : public Shape {
public:
  void accept(ShapeVisitor &visitor) override;
};

class Rectangle : public Shape {
public:
  void accept(ShapeVisitor &visitor) override;
};

class Triangle : public Shape {
public:
  void accept(ShapeVisitor &visitor) override;
};

// 访问者接口
class ShapeVisitor {
public:
  virtual ~ShapeVisitor() = default;
  virtual void visit(Circle &circle) = 0;
  virtual void visit(Rectangle &rectangle) = 0;
  virtual void visit(Triangle &triangle) = 0;
};

// 具体访问者
class AreaVisitor : public ShapeVisitor {
public:
  void visit(Circle &circle) override {
    std::cout << "Area of circle" << std::endl;
  }

  void visit(Rectangle &rectangle) override {
    std::cout << "Area of rectangle" << std::endl;
  }

  void visit(Triangle &triangle) override {
    std::cout << "Area of triangle" << std::endl;
  }
};

class DrawVisitor : public ShapeVisitor {
public:
  void visit(Circle &circle) override {
    std::cout << "Draw circle" << std::endl;
  }

  void visit(Rectangle &rectangle) override {
    std::cout << "Draw rectangle" << std::endl;
  }

  void visit(Triangle &triangle) override {
    std::cout << "Draw triangle" << std::endl;
  }
};

// 具体元素实现
void Circle::accept(ShapeVisitor &visitor) {
  visitor.visit(*this);
}

void Rectangle::accept(ShapeVisitor &visitor) {
  visitor.visit(*this);
}

void Triangle::accept(ShapeVisitor &visitor) {
  visitor.visit(*this);
}

int main(){
  // 创建元素
  std::vector<std::shared_ptr<Shape>> shapes;
  shapes.push_back(std::make_shared<Circle>());
  shapes.push_back(std::make_shared<Rectangle>());
  shapes.push_back(std::make_shared<Triangle>());

  // 创建访问者
  AreaVisitor area_visitor;
  DrawVisitor draw_visitor;

  for(auto &shape : shapes) {
    shape->accept(area_visitor);
    shape->accept(draw_visitor);
  }

  return 0;
}