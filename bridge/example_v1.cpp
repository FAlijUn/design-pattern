/*
类的多纬度变化
如果一个类有多个维度的变化（比如多个操作系统和多个设备类型），而每个维度的变化都可能影响类的行为，那么使用桥接模式可以将这些变化解耦
假设你正在开发一个图形应用，它需要在不同的操作系统（Windows、Linux、macOS）上运行，并且支持不同类型的图形设备（如屏幕、打印机、图形卡等）

抽象类: Graphics, 表示图形界面
实现类: WindowsGraphics, LinuxGraphics, MacOSGraphics, 表示不同操作系统的图形界面
*/

// 抽象类
#include <iostream>

class Graphics {
protected:
  Device* device_; // 持有实现类接口
public:
  Graphics(Device* device) : device_(device) {}
  virtual void draw() = 0;
  virtual ~Graphics() = default;
};

// 具体实现类A
class WindowsGraphics : public Graphics {
public:
  WindowsGraphics(Device* device) : Graphics(device) {}
  void draw() override {
    device_->drawImpl();
    std::cout << "WindowsGraphics draw" << std::endl;
  }
};

// 设备接口
class Device {
public:
  virtual void drawImpl() = 0;
  virtual ~Device() = default;
};

// 具体设备类A
class Screen : public Device {
public:
  void drawImpl() override {
    std::cout << "Screen drawImpl" << std::endl;
  }
};

// 客户端
int main() {
  // 创建实现类对象
  Device* screen = new Screen();
  Graphics* windowsGraphics = new WindowsGraphics(screen);
  windowsGraphics->draw();
  delete windowsGraphics;
  delete screen;
  return 0;
}
