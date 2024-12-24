class Singleton {
public:
  static Singleton* getInstance() {
    return &instance_;
  }
private:
  Singleton() {}
  static Singleton instance_;
};

// 静态成员初始化
Singleton Singleton::instance_;