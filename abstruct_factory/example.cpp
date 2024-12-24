#include <iostream>
#include <memory>

// 抽象产品: 按钮
class Button {
public:
  virtual void render() const = 0;
  virtual ~Button() = default;
};

// 抽象产品: 文本框 
class TextBox {
public:
  virtual void render() const = 0;
  virtual ~TextBox() = default;    
};


// 具体产品: Windows按钮
class WindowsButton : public Button {
public:
  void render() const override {
    std::cout << "Windows Button\n";
  }
};

// 具体产品: Windows文本框
class WindowsTextBox : public TextBox {
public:
  void render() const override {
    std::cout << "Windows TextBox\n";
  }
};

// 具体产品: Linux按钮
class LinuxButton : public Button {
public:
  void render() const override {
    std::cout << "Linux Button\n";
  }
};

// 具体产品: Linux文本框
class LinuxTextBox : public TextBox {
public:
  void render() const override {
    std::cout << "Linux TextBox\n";
  }
};

// 抽象工厂
class GUIFactory {
public:
  virtual std::unique_ptr<Button> createButton() const = 0;
  virtual std::unique_ptr<TextBox> createTextBox() const = 0;
  virtual ~GUIFactory() = default;
};

// 具体工厂: Windows工厂
class WindowsFactory : public GUIFactory {
public:
  std::unique_ptr<Button> createButton() const override {
    return std::make_unique<WindowsButton>();
  }

  std::unique_ptr<TextBox> createTextBox() const override {
    return std::make_unique<WindowsTextBox>();
  }
};

// 具体工厂: Linux工厂
class LinuxFactory : public GUIFactory {
public:
  std::unique_ptr<Button> createButton() const override {
    return std::make_unique<LinuxButton>();
  }

  std::unique_ptr<TextBox> createTextBox() const override {
    return std::make_unique<LinuxTextBox>();
  }
};

int main() {
  std::unique_ptr<GUIFactory> factory;
  std::unique_ptr<Button> button;
  std::unique_ptr<TextBox> textBox;

  factory = std::make_unique<WindowsFactory>();
  button = factory->createButton();
  textBox = factory->createTextBox();
  button->render();
  textBox->render();

  factory = std::make_unique<LinuxFactory>();
  button = factory->createButton();
  textBox = factory->createTextBox();
  button->render();
  textBox->render();

  return 0;
}