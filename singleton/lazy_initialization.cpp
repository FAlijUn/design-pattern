// 懒汉模式(非线程安全)
class Singleton {
public:
static Singleton* getInstance() {
    if (instance_ == nullptr) {
        instance_ = new Singleton();
    }
    return instance_;
  }
private:
  Singleton() {}
  static Singleton* instance_;
};
// 静态成员变量需要在类外初始化
Singleton* Singleton::instance_ = nullptr;