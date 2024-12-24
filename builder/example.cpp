// 假设正在构建复杂的电脑对象，这个对象由许多部分组成，例如 CPU、内存、硬盘、显示器等等。

#include <iostream>
#include <string>

// 产品类 Computer
class Computer {
public:
  void setCPU(const std::string& cpu) {
    this->cpu_ = cpu;
  }

  void setRAM(const std::string& ram) {
    this->ram_ = ram;
  }

  void setStorage(const std::string& storage) {
    this->storage_ = storage;
  }

  void setDisplay(const std::string& display) {
    this->display_ = display;
  }

  void show() {
    std::cout << "CPU: " << cpu_ << std::endl;
    std::cout << "RAM: " << ram_ << std::endl;
    std::cout << "Storage: " << storage_ << std::endl;
    std::cout << "Display: " << display_ << std::endl;
  }
private:
  std::string cpu_;
  std::string ram_;
  std::string storage_;
  std::string display_;
};

// 抽象建造者类 ComputerBuilder
class ComputerBuilder {
public:
  virtual void buildCPU() = 0;
  virtual void buildRAM() = 0;
  virtual void buildStorage() = 0;
  virtual void buildDisplay() = 0;
  virtual Computer* getResult() = 0;
  
  virtual ~ComputerBuilder() {}
};

// 具体建造者类
class HighConfigComputerBuilder : public ComputerBuilder {
public:
  HighConfigComputerBuilder() {
    computer_ = new Computer();
  }

  void buildCPU() override {
    computer_->setCPU("i7-8700");
  }

  void buildRAM() override {
    computer_->setRAM("16GB");
  }

  void buildStorage() override {
    computer_->setStorage("1TB SSD");
  }

  void buildDisplay() override {
    computer_->setDisplay("4K");
  }

  Computer* getResult() override {
    return computer_;
  }

private:
  Computer* computer_;
};

// 具体建造者类
// 具体的构建细节
class BasicComputerBuilder : public ComputerBuilder {
public:
  BasicComputerBuilder() {
    computer_ = new Computer();
  }

  void buildCPU() override {
    computer_->setCPU("i5-7200");
  }

  void buildRAM() override {
    computer_->setRAM("8GB");
  }

  void buildStorage() override {
    computer_->setStorage("512GB SSD");
  }

  void buildDisplay() override {
    computer_->setDisplay("1080P");
  }

  Computer* getResult() override {
    return computer_;
  }
private:
  Computer* computer_;
};



// 指挥者类 Director
// 负责构建复杂对象，它并不知道具体的构建细节
class ComputerDirector {
public:
  void setComputerBuilder(ComputerBuilder* builder) {
    builder_ = builder;
  }

  Computer* construct() {
    builder_->buildCPU();
    builder_->buildRAM();
    builder_->buildStorage();
    builder_->buildDisplay();
    return builder_->getResult();
  }
private:
  ComputerBuilder* builder_;
};

// 客户端使用生成器模式
int main() {
  ComputerDirector director;
  // 创建高配电脑对象
  ComputerBuilder* highConfigBuilder = new HighConfigComputerBuilder();
  director.setComputerBuilder(highConfigBuilder);
  Computer* highConfigComputer = director.construct();
  highConfigComputer->show();

  // 创建低配电脑对象
  ComputerBuilder* basicBuilder = new BasicComputerBuilder();
  director.setComputerBuilder(basicBuilder);
  Computer* basicComputer = director.construct();
  basicComputer->show();
}