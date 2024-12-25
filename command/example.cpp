#include <iostream>

// 抽象命令类
class Command {
public:
  virtual void execute() = 0;
  virtual ~Command() {}
};

// 接受命令类
class Light {
public:
  void on() {
    std::cout << "Light is on" << std::endl;
  }
  void off() {
    std::cout << "Light is off" << std::endl;
  }
};

// 具体命令类
class LightOnCommand : public Command {
private:
  Light& light_;
public:
  LightOnCommand(Light& light) : light_(light) {}
  void execute() override {
    light_.on();
  }
};

class LightOffCommand : public Command {
private:
  Light& light_;
public:
  LightOffCommand(Light& light) : light_(light) {}
  void execute() override {
    light_.off();
  }
};

// 调用者
class RemoteControl {
private:
  Command* command_;
public:
  RemoteControl(Command* command) : command_(command) {}
  void pressButton() {
    command_->execute();
  }
};

// 客户端
int main(){
  Light light;
  Command* commandOn = new LightOnCommand(light);
  Command* commandOff = new LightOffCommand(light);

  RemoteControl remoteControlOn(commandOn);
  RemoteControl remoteControlOff(commandOff);

  remoteControlOn.pressButton();
  remoteControlOff.pressButton();

  delete commandOn;
  delete commandOff;

  return 0;
}
