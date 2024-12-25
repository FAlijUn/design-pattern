#include <iostream>

// 抽象主题类
class Subject {
public:
  virtual void request() = 0;
  virtual ~Subject() = default;
};

// 真实主题类
class RealSubject : public Subject {
public:
  void request() override {
    std::cout << "RealSubject request" << std::endl;
  }
};

// 代理类
class Proxy : public Subject {
private:
  RealSubject* real_subject_;

  void checkAccess() {
    // request() 方法中添加了访问控制逻辑 checkAccess()，同时在需要时创建 RealSubject 对象
    // 从而实现了对 RealSubject 对象的访问控制
    std::cout << "Proxy checkAccess" << std::endl;
  }
public:
  Proxy(): real_subject_(nullptr) {}
  ~Proxy() {
    if (real_subject_) {
      delete real_subject_;
    }
  }

  void request() override {
    checkAccess();
    if(real_subject_ == nullptr) {
      real_subject_ = new RealSubject();
    }
    real_subject_->request();
  }
};

int main() {
  Proxy* proxy = new Proxy();
  proxy->request();
  delete proxy;
  return 0;
}