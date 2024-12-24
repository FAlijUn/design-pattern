#include <iostream>

// 目标接口:客户端需要的接口
class Printer{
public:
    virtual void print(const std::string& message) = 0;
    virtual ~Printer() = default;
};

// 适配者:被适配的类
class OldPrinter{
public:
    void printMessage(const std::string& message){
        std::cout << "old printer"<<message << std::endl;
    }
};

// 适配器:将适配者转换为目标接口
class PrinterAdapter : public Printer{
private:
    OldPrinter& oldPrinter_;
public:
    PrinterAdapter(OldPrinter& oldPrinter):oldPrinter_(oldPrinter){}
    void print(const std::string& message) override{
        oldPrinter_.printMessage(message);
    }
};

// 客户端
int main(){
    OldPrinter oldPrinter;
    Printer* printer = new PrinterAdapter(oldPrinter);
    printer->print("hello world");
    delete printer;
    return 0;
}