观察者模式: 事件订阅者、监听者、Event-Subscriber、Listener、Observer
观察者模式是一种行为设计模式， 允许你定义一种订阅机制， 可在对象事件发生时通知多个 “观察” 该对象的其他对象
观察者模式是一种行为型设计模式，定义了一种一对多的依赖关系，
让多个观察者对象同时监听一个主题对象（发布者）
当对象主题的状态发生变化，会自动同时所有的观察者对象

观察者模式的结构
1. subject(主题)：被观察的对象，维护一系列的观察者，并提供方法来注册、注销观察者，同时也负责通知观察者状态的变化
2. observer(观察者)：每一个观察者都定义了一个更新方法，接受并处理主题对象状态变化
3. concreteSubject(具体主题)：实现了主题接口的具体类，通常会包含一些具体的状态，当状态变化的时候通知观察者
4. concreteObserver(具体观察者)：实现了观察者接口的具体类，接受主题的通知会更新自身的状态

