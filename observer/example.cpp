/*
温度检测系统
假设我们有一个温度监测系统，系统中有一个温度传感器（ConcreteSubject）
它会定期测量温度并通知所有的观察者（如显示器、手机应用等，ConcreteObserver）显示最新的温度数据
*/

#include <iostream>
#include <vector>
#include <string>

// 观察者接口
class Observer {
public:
  virtual void update(float temperature) = 0;
};

// 主题接口
class Subject {
  public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

// 具体主题
class TemperatureSensor : public Subject {
private:
  std::vector<Observer*> observers; // 观察者列表
  float temperature_; // 当前温度
public:
  void setTemperature(float temperature) {
    temperature_ = temperature;
    notifyObservers(); // 通知所有观察者
  }

  float getTemperature() {
    return temperature_;
  }

  void registerObserver(Observer* observer) override {
    observers.push_back(observer);
  }

  void removeObserver(Observer* observer) override {
    for (int i = 0; i < observers.size(); i++) {
      if (observers[i] == observer) {
        observers.erase(observers.begin() + i);
        break;
      }
    }
  }

  // 通知所有观察者
  void notifyObservers() override {
    for (int i = 0; i < observers.size(); i++) {
      observers[i]->update(temperature_);
    }
  }
};

// 具体观察者
class Display : public Observer {
private:
  std::string name_;
public:
  Display(std::string name) : name_(name) {}

  void update(float temperature) override {
    std::cout << name_ << " : " << temperature << std::endl;
  }
};

class MobileApp : public Observer {
public:
  void update(float temperature) override {
    std::cout << "MobileApp : " << temperature << std::endl;
  }
};

// 客户段代码
int main(){
  // 创建主题
  TemperatureSensor sensor;

  // 创建观察者
  Display display1("Display1");
  Display display2("Display2"); 
  MobileApp mobileApp;

  // 注册观察者
  sensor.registerObserver(&display1);
  sensor.registerObserver(&display2);
  sensor.registerObserver(&mobileApp);

  // 设置温度
  sensor.setTemperature(30.0f);

  return 0;
}