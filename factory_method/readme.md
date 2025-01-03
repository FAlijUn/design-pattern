## 在父类中提供一个创建对象的方法，允许子类决定实例化对象的类型

### 简单工厂模式
  通过一个工厂类来创建对象，根据不同的参数返回不同类型的实例  
  工厂类通常负责创建所有产品的实例

### 工厂方法模式
  工厂方法模式将对象的创建委托给子类来实现，允许子类决定实例化哪一个类
  基本上每个子类都有自己的工厂方法来创建相应的对象

### 抽象工厂
  提供一个创建一组相关或依赖对象的接口，而无需指定具体类
  每个工厂类都负责创建一系列相关的产品（例如，产品族）

封装性强：工厂模式封装了对象的创建过程，客户端不需要关心对象如何创建。
降低耦合性：客户端不需要知道具体的类，只需要知道工厂接口，这减少了类之间的依赖。
扩展性强：当需要新增产品时，只需增加新的工厂类或者新的产品类，不需要修改现有代码，符合开闭原则。
