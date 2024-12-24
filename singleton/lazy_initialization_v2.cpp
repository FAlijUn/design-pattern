// 使用std::call_once来保证线程安全，且只在第一次调用时加锁
#include <mutex>
class Singleton {
public:
  static Singleton* getInstance() {
      std::call_once(once_flag_, []() {
          instance_ = new Singleton();
      });
      return instance_;
  }
private:
  Singleton() {}
  static Singleton* instance_;
  static std::once_flag once_flag_;
};

Singleton* Singleton::instance_ = nullptr;
std::once_flag Singleton::once_flag_;   