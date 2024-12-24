#include <iostream>

// 实现类接口
class Implementor{
public:
    virtual void operationImpl() = 0;
    virtual ~Implementor() = default;
};

// 具体实现类A
class ConcreteImplementorA : public Implementor{
public:
    void operationImpl() override{
        std::cout << "ConcreteImplementorA operationImpl" << std::endl;
    }
};

// 具体实现类B
class ConcreteImplementorB : public Implementor{
public:
    void operationImpl() override{
        std::cout << "ConcreteImplementorB operationImpl" << std::endl;
    }
};


// 抽象类
class Abstraction{
protected:
    Implementor* implementor_; // 持有实现类接口
public:
    Abstraction(Implementor* implementor):implementor_(implementor){}
    virtual void operation() = 0;
    virtual ~Abstraction() = default;
};

// 扩展抽象类
class RefinedAbstraction : public Abstraction{
public:
    RefinedAbstraction(Implementor* implementor):Abstraction(implementor){}
    void operation() override{
        implementor_->operationImpl(); // 委托给实现类
    }
};

int main(){
  // 创建实现类对象
  ConcreteImplementorA implA;
  ConcreteImplementorB implB;

  // 使用不同的实现方式
  RefinedAbstraction refinedA(&implA);
  RefinedAbstraction refinedB(&implB);

  refinedA.operation();
  refinedB.operation();
}