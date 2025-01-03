模板方法模式（Template Method Pattern） 是一种行为型设计模式，它定义了一个操作的骨架，并将某些步骤的执行延迟到子类中
通过模板方法，父类可以将操作的流程控制住，而子类只需实现具体的步骤
模板方法模式的目的是将算法的结构固定下来，让子类可以在不改变算法结构的情况下，重定义算法的某些步骤

父类：定义算法的骨架，提供一个“模板方法”来执行
子类：实现一些细节步骤

1. abstractclass 抽象类定义一个模板方法
2. concreteclass 实现具体类的具体操作

应用场景
1. 算法框架固定，部分步骤可以变动
  如果某个算法的框架结构是固定的，但其中有一些步骤可以由子类根据具体情况进行定制，可以使用模板方法模式。
  游戏开发中的关卡设计：游戏中不同关卡可能有不同的规则（如敌人出现的方式、地图的生成方式等），但每个关卡的流程结构（如开始、进行、结束）是固定的。使用模板方法模式，可以将固定的流程封装在父类中，将变化的部分交给子类实现。
  文件操作：读取文件的过程可能有固定的步骤，如打开文件、读取内容、关闭文件，但不同类型的文件（如文本文件、二进制文件等）的读取方式不同，可以通过模板方法模式将具体的读取操作交给子类实现。
2. 行为的复用
  当不同的类在实现时，重复了大量的代码，且这些代码的执行顺序和结构是相同的，只是某些步骤的实现不同，可以使用模板方法模式来减少代码重复
  报告生成系统：报告生成的过程包括：数据采集、数据处理、报告格式化和输出。不同类型的报告（如销售报告、财务报告、员工报告）可能在数据采集和处理的方式上有所不同，但其它步骤是相同的
  编译过程：编译过程包括解析源文件、生成中间代码、优化和链接等步骤，虽然每种编译器可能有不同的优化策略，但其编译流程是固定的，优化步骤可以通过模板方法模式来定义
3. 控制流程并扩展具体步骤
  模板方法模式非常适合用于控制算法的流程，并允许在子类中扩展具体的步骤实现
  日志框架：日志的流程可能包括：获取日志信息、格式化日志、输出日志。不同的日志实现（如控制台输出、文件输出、远程输出）可能会在格式化和输出步骤上有所不同，模板方法模式允许在固定流程中扩展具体实现
  自动化测试：自动化测试框架可以定义固定的测试流程（如设置环境、执行测试、报告结果），但是每个测试的执行方式不同，可以通过模板方法模式来实现