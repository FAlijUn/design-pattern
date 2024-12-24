// 懒汉模式(线程安全)
// 1. 通过加锁的方式保证线程安全
// 2. 但是加锁的方式会影响性能
// 3. 且在多线程环境下，每次获取实例都需要加锁，会影响性能
// 4. 每次getInstance都需要加锁，即使实例已经创建
#include <mutex>
class Singleton {
public:
    static Singleton* getInstance() {
        if (instance_ == nullptr) {
            std::lock_guard<std::mutex> lock(mtx_);
            if (instance_ == nullptr) {
                instance_ = new Singleton();
            }
        }
        return instance_;
    }
private:
    Singleton() {}
    static Singleton* instance_;
    static std::mutex mtx_;
};

Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mtx_;