#include <iostream>
#include <list>
#include <string>
#include <memory>

// 同事类抽象基类
class Colleague {
protected:
  std::shared_ptr<Mediator> mediator;
public:
  Colleague(const std::string& name, std::shared_ptr<Mediator> mediator) : name(name), mediator(mediator) {}
  virtual void send(const std::string& message) = 0;
  virtual void receive(const std::string& message) = 0;
  std::string name;
};

// 具体同事类
class User : public Colleague {
public:
  User(const std::string& name, std::shared_ptr<Mediator> mediator) : Colleague(name, mediator) {}
  void send(const std::string& message) override {
    std::cout << name << " send message: " << message << std::endl;
    mediator->send(name, message);
  }
  void receive(const std::string& message) override {
    std::cout << name << " receive message: " << message << std::endl;
  }
};

// 中介者抽象基类
class Mediator {
public:
  virtual void addUser(std::shared_ptr<Colleague> colleague) = 0;
  virtual void send(const std::string& from, const std::string& message) = 0;  
};

// 具体中介者类
class ChatRoom : public Mediator {
private:
  std::list<std::shared_ptr<Colleague>> colleagues;
public:
  void addUser(std::shared_ptr<Colleague> colleague) {
    colleagues.push_back(colleague);
  }

  void send(const std::string& from, const std::string& message) override {
    for (auto& colleague : colleagues) {
      if (colleague->name != from) {
        colleague->receive(message);
      }
    }
  }
};


int main(){
  std::shared_ptr<Mediator> chatroom = std::make_shared<ChatRoom>();
  std::shared_ptr<Colleague> alice = std::make_shared<User>("Alice", chatroom);
  std::shared_ptr<Colleague> bob = std::make_shared<User>("Bob", chatroom);
  chatroom->addUser(alice);
  chatroom->addUser(bob);
  alice->send("Hello, Bob!");
  bob->send("Hello, Alice!");
  return 0;
}