# design-pattern

## 单一职责原则
  定义: 一个类应该只有一个原因改变，一个类只有一个职责
  目的: 减少类的复杂性和依赖，使类功能聚焦。一个类如果承担了多个职责，当需求变化时，可能需要多次修改该类，从而增加维护的难度
  应用: 将复杂任务拆分成不同的职责，观察者模式，和责任链模式将任务分割多个处理器

## 开放/封闭原则
  定义: 软件实体（类、模块、函数等）应该对扩展开放，对修改封闭
  目的: 避免对已存在的代码进行修改，允许通过添加新代码的方式来实现新的功能。这样可以保证软件在未来可以灵活扩展，但不会影响到已有的功能
  应用: 策略模式、装饰器模式 和 工厂模式，通过接口和抽象类的使用来实现系统的扩展而不是修改现有的代码

## 里氏替换原则
  定义: 子类对象能够替代父类对象出现在任何地方，且程序的行为不会发生改变
  目的: 保证继承的正确性，使得子类能够替代父类并维持系统的正确性。遵守这一原则，确保系统中的多态性正确性
  应用: 工厂方法模式和策略模式都依赖于接口或基类的多态性，要求子类能够替代父类进行工作

## 依赖倒置原则
  定义: 高层模块不应该依赖低层模块，二者都应该依赖于抽象；抽象不应该依赖于细节，细节应该依赖于抽象
  目的: 减少模块之间的耦合度
  应用: 观察者模式中，观察者和被观察者通过接口进行交互，不依赖与具体的实现

## 接口隔离原则
  定义: 客户端不应该依赖于它不需要的接口
  目的: 通过细化接口，减少接口的功能范围，使得类只依赖它真正需要的功能
  应用: 在策略模式和装饰器模式中，通常定义多个小而专用的接口，而不是一个庞大的通用接口

## 迪米特法则
  定义: 一个对象应当对其他对象有尽可能少的了解
  目的: 减少模块之间的耦合度，提高代码的内聚性。使得对象的职责单一、简单，降低了对象之间的依赖关系。
  应用: 适配器模式和代理模式

## 合成复用原则
  定义: 优先使用对象组合（合成）而不是继承来达到复用的目的
  目的: 通过组合来扩展功能，而不是通过继承来实现复用，避免继承带来的紧密耦合
  应用: 装饰器模式和组合模式

## 最少知识原则
  定义: 一个对象应该对其他对象有尽可能少的了解。每个对象应只了解它直接依赖的对象，而不应该了解其他对象的实现
  目的: 减少类之间的耦合，增加系统的独立性和模块化
  应用: 外观模式 和 代理模式 都遵循这一原则，通过引入中介层来减少客户端与复杂系统的直接交互，使得每个类的责任更加单一和清晰


编译单元
每个源代码文件（通常以 .cpp 扩展名结尾）及其包含的头文件一起构成了一个编译单元
每个源代码文件经过预处理、编译后生成一个 目标文件（Object File）（通常以 .o 或 .obj 扩展名结尾），该目标文件包含编译后的机器码，但尚未链接到其他代码

编译单元的生成过程
  预处理:
    预处理阶段会处理宏，条件编译指令，头文件包含等
    #include 将头文件的内容插入到源代码文件中， #define 宏定义会被替换
  编译:
    将源代码转换成汇编代码或者机器代码.o
  汇编
    将汇编语言文件转换成机器码
  链接
    敬爱嗯多个目标文件进行链接形成最终的可执行文件

  每个编译单元都是独立编译
  编译单元的独立性
    每个 .cpp 文件是一个编译单元，编译器会单独编译每个编译单元
  头文件的重复包含问题
