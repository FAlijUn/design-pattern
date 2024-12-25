#include <iostream>
#include <vector>
#include <memory>


// 聚合接口
class Aggregate {
public:
  virtual ~Aggregate() = default;
  virtual std::shared_ptr<Iterator> createIterator() = 0;
  virtual void add(std::shared_ptr<Element> item) = 0;
};

// 迭代器接口
class Iterator {
public:
  virtual ~Iterator() = default;
  virtual bool hasNext() const = 0;
  virtual std::shared_ptr<const Element> next() = 0;
};

// 元素接口
class Element {
public:
  virtual ~Element() = default;
};

// 具体聚合类
class ConcreteAggregate : public Aggregate {
private:
  std::vector<std::shared_ptr<Element>> items;
public:
  void add(std::shared_ptr<Element> item) {
    items.push_back(item);
  }
  std::shared_ptr<Iterator> createIterator() override{
    return std::make_shared<ConcreteIterator>(items);
  }
};

// 具体迭代器类
class ConcreteIterator : public Iterator {
private:
  std::vector<std::shared_ptr<Element>> items;
  int position;
  ConcreteIterator(std::vector<std::shared_ptr<Element>> items) : items(items), position(0) {}
public:
  bool hasNext() const override {
    return position < items.size();
  }

  std::shared_ptr<const Element> next() override {
    if(hasNext()) {
      std::shared_ptr<Element> item = items[position];
      position++;
      return item;
    }
    return nullptr;
  }
};

// 客户端
int main(){
  std::shared_ptr<Aggregate> aggregate = std::make_shared<ConcreteAggregate>();
  aggregate->add(std::make_shared<Element>());
  aggregate->add(std::make_shared<Element>());
  aggregate->add(std::make_shared<Element>());

  std::shared_ptr<Iterator> iterator = aggregate->createIterator();

  while(iterator->hasNext()) {
    std::shared_ptr<const Element> item = iterator->next();
    std::cout << "item" << std::endl;
  }

  return 0;
}