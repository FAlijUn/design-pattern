// 工厂模式用于创建一个通用接口来隐藏具体的类的实现细节
#include <iostream>

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
    virtual Shape* createShape() const = 0;
    virtual ~ShapeFactory() = default;
};

//具体的形状工厂
class CircleFactory : ShapeFactory{
public:
    Shape* createShape() const override{
        return new Circle();
    }
};

class SquareFactory: ShapeFactory{
public:
    Shape* createShape() const override{
        return new Square();
    }
};

class TriangleFactory: ShapeFactory{
public:
    Shape* createShape() const override{
        return new Triangle();
    }
};