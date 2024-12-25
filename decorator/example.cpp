#include <iostream>
#include <memory>

// 抽象组件
class Window {
public:
  virtual void draw() = 0;
  virtual ~Window() = default;
};

// 具体组件
class SimpleWindow : public Window {
public:
  void draw() override {
    std::cout << "SimpleWindow::draw()" << std::endl;
  }
};

// 抽象装饰器
class WindowDecorator : public Window {
protected:
  std::unique_ptr<Window> window_;
public:
  WindowDecorator(std::unique_ptr<Window> window) : window_(std::move(window)) {}
  void draw() override {
    window_->draw();
  }
};

// 具体装饰器
class BorderDecorator : public WindowDecorator {
public:
  BorderDecorator(std::unique_ptr<Window> window) : WindowDecorator(std::move(window)) {}
  void draw() override {
    WindowDecorator::draw();
    std::cout << "BorderDecorator::draw()" << std::endl;
  }
};

class ScrollDecorator : public WindowDecorator {
public:
  ScrollDecorator(std::unique_ptr<Window> window) : WindowDecorator(std::move(window)) {}
  void draw() override {
    WindowDecorator::draw();
    std::cout << "ScrollDecorator::draw()" << std::endl;
  }
};


// 客户端
int main(){
  std::unique_ptr<Window> window = std::make_unique<SimpleWindow>();
  window->draw();

  // 在simpleWindow上添加边框和滚动条
  std::unique_ptr<Window> borderWindow = std::make_unique<BorderDecorator>(std::move(window));
  borderWindow->draw();

  std::unique_ptr<Window> scrollWindow = std::make_unique<ScrollDecorator>(std::move(borderWindow));
  scrollWindow->draw();

  return 0;
}