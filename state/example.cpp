/*
电梯控制系统
假设我们有一个电梯系统，电梯有不同的状态，例如“停止”、“运行中”、“开门”、“关门”等
每个状态下，电梯的行为是不同的
如果不使用状态模式，我们可能会使用很多条件判断来处理不同状态下的行为
*/

#include <iostream>
#include <memory>

// State(状态接口)
class ElevatorState {
public:
  virtual ~ElevatorState() = default;
  virtual void pressButton() = 0;
  virtual void openDoor() = 0;
  virtual void closeDoor() = 0;
};

// 上下文(Context)
class Elevator {
private:
  std::shared_ptr<ElevatorState> current_state_; // 当前状态
public:
  Elevator(std::shared_ptr<ElevatorState> state) : current_state_(state) {}

  void setState(std::shared_ptr<ElevatorState> state) {
    current_state_ = state;
  }

  void pressButton() {
    current_state_->pressButton();
  }

  void openDoor() {
    current_state_->openDoor();
  }

  void closeDoor() {
    current_state_->closeDoor();
  }
};

// 具体状态(Concrete State)
class StopState : public ElevatorState {
public:
  void pressButton() override {
    std::cout << "电梯开始运行" << std::endl;
  }

  void openDoor() override {
    std::cout << "电梯开门" << std::endl;
  }

  void closeDoor() override {
    std::cout << "电梯关门" << std::endl;
  }
};

class RunningState : public ElevatorState {
public:
  void pressButton() override {
    std::cout << "电梯正在运行不能按按钮" << std::endl;
  }

  void openDoor() override {
    std::cout << "电梯不能开门" << std::endl;
  }

  void closeDoor() override {
    std::cout << "电梯关门" << std::endl;
  }
};

class OpenState : public ElevatorState {
public:
  void pressButton() override {
    std::cout << "Elevator is opening doors. Button pressed" << std::endl;
  }

  void openDoor() override {
    std::cout << "电梯已经开门" << std::endl;
  }

  void closeDoor() override {
    std::cout << "电梯关门" << std::endl;
  }
};

int main(){
  std::shared_ptr<ElevatorState> stop_state = std::make_shared<StopState>();
  std::shared_ptr<ElevatorState> running_state = std::make_shared<RunningState>();
  std::shared_ptr<ElevatorState> open_state = std::make_shared<OpenState>();

  Elevator elevator(stop_state); // 电梯初始状态为停止

  elevator.pressButton(); // 电梯开始运行
  elevator.setState(running_state);
  elevator.openDoor(); // 此时电梯不能开门
  elevator.setState(open_state);
  elevator.openDoor(); // 电梯已经开门
  elevator.closeDoor(); // 电梯关门
}