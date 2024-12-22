// 工厂模式用于创建一个通用接口来隐藏具体的类的实现细节
#include <iostream>
#include <memory>

// 定义一个形状的接口   
class Shape{
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// 实现具体的形状类
class Circle : public Shape{
public:
    void draw() const override{
        std::cout << "Circle::draw\n";
    }
};

class Square : public Shape{
public:
    void draw() const override{
        std::cout << "Square::draw\n";
    }
};

class Triangle : public Shape{
public:
    void draw() const override{
        std::cout << "Triangle::draw\n";
    }
};


// 定义一个工厂接口类
class ShapeFactory{
public:
    virtual std::unique_ptr<Shape> createShape() const = 0;
    virtual ~ShapeFactory() = default;
};

//具体的形状工厂
class CircleFactory : public ShapeFactory{
public:
    std::unique_ptr<Shape> createShape() const override{
        return std::make_unique<Circle>();
    }
};

class SquareFactory: public ShapeFactory{
public:
    std::unique_ptr<Shape> createShape() const override{
        return std::make_unique<Square>();
    }
};

class TriangleFactory: public ShapeFactory{
public:
    std::unique_ptr<Shape> createShape() const override{
        return std::make_unique<Triangle>();
    }
};


int main(){
    // 客户端程序
    std::unique_ptr<ShapeFactory> factory;

    factory = std::make_unique<CircleFactory>();
    std::unique_ptr<Shape> shape = std::unique_ptr<Shape>(factory->createShape());
    shape->draw();

    factory = std::make_unique<SquareFactory>();
    shape = std::unique_ptr<Shape>(factory->createShape());
    shape->draw();

    factory = std::make_unique<TriangleFactory>();
    shape = std::unique_ptr<Shape>(factory->createShape());
    shape->draw();

    return 0;
}