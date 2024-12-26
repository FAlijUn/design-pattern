#include <iostream>

class Cooking{
public:
  // 模板方法
  void cook(){
    prepareIngredients();
    cookIngredients();
    plateFood();
  }
protected:
  virtual void prepareIngredients() = 0;
  virtual void cookIngredients() = 0;
  virtual void plateFood() = 0;
};

class Noodles : public Cooking{
protected:
  void prepareIngredients() override{
    std::cout << "Preparing Noodles" << std::endl;
  }
  void cookIngredients() override{
    std::cout << "Cooking Noodles" << std::endl;
  }
  void plateFood() override{
    std::cout << "Plating Noodles" << std::endl;
  }
};

// 客户端代码
int main(){
  Noodles noodles;
  noodles.cook(); //通过调用模板方法，完成了一次烹饪面条的过程
  return 0;
}