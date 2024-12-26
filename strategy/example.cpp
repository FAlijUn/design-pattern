/*
支付系统中的策略模式
假设我们有一个支付系统，支持多种支付方式，比如“信用卡支付”、“支付宝支付”和“微信支付”
每种支付方式有不同的实现和处理逻辑
如果我们使用条件语句来实现每种支付方式的选择，代码会变得非常复杂且难以扩展
使用策略模式可以解决这个问题
*/

#include <iostream>
#include <memory>


// Strategy interface(支付方式接口)
class PaymentStrategy {
public:
  virtual void pay() = 0;
  virtual ~PaymentStrategy() = default;
};

// Concrete strategy 1(具体策略1)
class CreditCardPayment : public PaymentStrategy {
public:
  void pay() override {
    std::cout << "Credit card payment" << std::endl;
  }
};

// Concrete strategy 2(具体策略2)
class AlipayPayment : public PaymentStrategy {
public:
  void pay() override {
    std::cout << "Alipay payment" << std::endl;
  }
};

// Concrete strategy 3(具体策略3)
class WechatPayment : public PaymentStrategy {
public:
  void pay() override {
    std::cout << "Wechat payment" << std::endl;
  }
};

// Context(支付上下文)
class PaymentContext {
private:
  std::unique_ptr<PaymentStrategy> payment_strategy_;
public:
  void set_payment_strategy(std::unique_ptr<PaymentStrategy> payment_strategy) {
    payment_strategy_ = std::move(payment_strategy);
  }

  void pay() {
    payment_strategy_->pay();
  }
};

int main(){
  PaymentContext context;

  // 使用信用卡支付
  context.set_payment_strategy(std::make_unique<CreditCardPayment>());
  context.pay();

  // 使用支付宝支付
  context.set_payment_strategy(std::make_unique<AlipayPayment>());
  context.pay();

  // 使用微信支付
  context.set_payment_strategy(std::make_unique<WechatPayment>());
  context.pay();

  return 0;
}