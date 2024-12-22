#include <iostream>
#include <memory>
// 创建一个产品基类
class Product {
public:
    virtual void use() = 0;
    virtual ~Product() {}
};


// 具体的产品类
class ConcreteProductA : public Product {
public:
    void use() {
        std::cout << "use ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() {
        std::cout << "use ConcreteProductB" << std::endl;
    }
};

// 创建一个工厂类
class Factory {
public:
    enum ProductType {
        PRODUCT_A,
        PRODUCT_B
    };  

    // static Product* createProduct(ProductType type) {
    //     Product* product = nullptr;
    //     switch (type) {
    //         case PRODUCT_A:
    //             product = new ConcreteProductA();
    //             break;
    //         case PRODUCT_B:
    //             product = new ConcreteProductB();
    //             break;
    //         default:
    //             break;
    //     }
    //     return product;
    // }

    static std::unique_ptr<Product> createProduct(ProductType type) {
        std::unique_ptr<Product> product = nullptr;
        switch (type) {
            case PRODUCT_A:
                product = std::make_unique<ConcreteProductA>();
                break;
            case PRODUCT_B:
                product = std::make_unique<ConcreteProductB>();
                break;
            default:
                break;
        }
        return product;
    }
};


// 使用工厂类创建产品
int main() {
    auto productA = Factory::createProduct(Factory::PRODUCT_A);
    productA->use();

    auto productB = Factory::createProduct(Factory::PRODUCT_B);
    productB->use();

    return 0;
}

