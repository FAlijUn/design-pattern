/*
当抽象和实现需要独立扩展
如果系统中的抽象部分和实现部分都有独立的变化需求，可以使用桥接模式。这样可以在不影响另一方的情况下，独立扩展抽象和实现类
假设你正在开发一个通用遥控器系统，它需要支持不同的设备（如电视、空调）
遥控器的操作（如开关机、调整音量）是抽象的，而具体的操作（如何控制电视、空调）是设备实现部分
通过桥接模式，遥控器和设备之间的变化是解耦的，因此可以独立扩展

抽象类：遥控器 RemoteControl
实现类：设备 Device
客户端: 遥控器和设备的组合
*/

#include <iostream>

// 设备接口
class Device {
public:
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
  virtual void setChannel(int channel) = 0;
  virtual ~Device() = default;
};

// 电视机实现类
class TV : public Device {
public:
  void turnOn() override {
    std::cout << "TV turnOn" << std::endl;
  }
  void turnOff() override {
    std::cout << "TV turnOff" << std::endl;
  }
  void setChannel(int channel) override {
    std::cout << "TV setChannel " << channel << std::endl;
  }
};

// 抽象遥控器
class RemoteControl {
protected:
  Device* device_; // 持有设备接口
public:
  RemoteControl(Device* device) : device_(device) {}
  virtual void PowerButton() = 0;
  virtual void ChannelButton() = 0;
  virtual ~RemoteControl() = default;
};

// 遥控器实现类：基础遥控器
class BasicRemoteControl : public RemoteControl {
public:
  BasicRemoteControl(Device* device) : RemoteControl(device) {}
  void PowerButton() override {
    device_->turnOn();
  }
  void ChannelButton() override {
    device_->setChannel(1);
  }
};

int main(){
  // 创建实现类对象
  Device* tv = new TV();
  RemoteControl* remoteControl = new BasicRemoteControl(tv);
  remoteControl->PowerButton();
  remoteControl->ChannelButton();
  delete remoteControl;
  delete tv;
  return 0;
}