#include <iostream>
#include <memory>

// 抽象处理类
class Approver {
protected:
  std::shared_ptr<Approver> successor;
public:
  Approver(std::shared_ptr<Approver> successor) : successor(successor) {}

  virtual void setSuccessor(std::shared_ptr<Approver> successor) {
    this->successor = successor;
  }

  virtual void processRequest(int requestAmount){
    if (successor != nullptr) {
      successor->processRequest(requestAmount);
    }
  }
};

// 具体处理类
class Manager : public Approver {
public:
  Manager(std::shared_ptr<Approver> successor) : Approver(successor) {}
  void processRequest(int requestAmount) override {
    if (requestAmount <= 1000) {
      std::cout << "Manager approved the request." << std::endl;
    } else {
      Approver::processRequest(requestAmount);
    }
  }
};

class Director : public Approver {
public:
  Director(std::shared_ptr<Approver> successor) : Approver(successor) {}
  void processRequest(int requestAmount) override {
    if (requestAmount <= 5000 && requestAmount > 1000) {
      std::cout << "Director approved the request." << std::endl;
    } else {
      Approver::processRequest(requestAmount);
    }
  }
};

class VicePresident : public Approver {
public:
  VicePresident(std::shared_ptr<Approver> successor) : Approver(successor) {}
  void processRequest(int requestAmount) override {
    if (requestAmount <= 10000 && requestAmount > 5000) {
      std::cout << "Vice President approved the request." << std::endl;
    } else {
      Approver::processRequest(requestAmount);
    }
  }
};

// 客户端
int main() {
  std::shared_ptr<Approver> manager = std::make_shared<Manager>(nullptr);
  std::shared_ptr<Approver> director = std::make_shared<Director>(manager);
  std::shared_ptr<Approver> vicePresident = std::make_shared<VicePresident>(director);

  vicePresident->processRequest(2000);
  vicePresident->processRequest(6000);
  vicePresident->processRequest(12000);

  return 0;
}