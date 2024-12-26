#include <iostream>
#include <memory>
#include <vector>
#include <string>

// 备忘录类
class Memento {
private:
  std::string state_;
public:
  Memento(const std::string& state) : state_(state) {}
  std::string getState() const {
    return state_;
  }
};

// 发起人类
class Originator {
private:
  std::string state_;
public:
  void setState(const std::string& state) {
    state_ = state;
    std::cout  << "Originator: Set state to " << state_ << std::endl;
  }

  std::string getState() const {
    return state_;
  }

  // 创建备忘录
  std::shared_ptr<Memento> createMemento() {
    return std::make_shared<Memento>(state_);
  }

  // 恢复备忘录
  void restoreMemento(std::shared_ptr<Memento> memento) {
    state_ = memento->getState();
    std::cout << "Originator: Restore state to " << state_ << std::endl;
  }
};

// 备忘录管理者类
class Caretaker {
private:
  std::vector<std::shared_ptr<Memento>> mementos_;
public:
  void addMemento(std::shared_ptr<Memento> memento) {
    mementos_.push_back(memento);
  }

  std::shared_ptr<Memento> getMemento(int index) {
    if(index < 0 || index >= mementos_.size()) {
      throw std::out_of_range("Index out of range");
    }
    return mementos_[index];
  }
};

int main(){
  Originator originator;
  Caretaker caretaker;

  // 设置状态并保存备忘录
  originator.setState("State1");
  caretaker.addMemento(originator.createMemento());

  // 设置状态并保存备忘录
  originator.setState("State2");
  caretaker.addMemento(originator.createMemento());

  // 恢复备忘录
  originator.restoreMemento(caretaker.getMemento(0));

  return 0;
}