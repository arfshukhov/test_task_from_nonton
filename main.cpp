#include <string>
#include <vector>
#include <iostream>


class Product{
public:
    std::string id;
    std::string name;
    Product(std::string id, std::string name){
        this->id = id;
        this->name = name;
    }
};


class ProductsImpl {
public:
    static std::vector<Product> products;

    bool addProduct(Product product){
        for(Product & existsProduct:products){
            if(existsProduct.id == product.id) {
                return false;
            }
        }
        products.push_back(product);
        return true;
    }

    bool deleteProduct(Product product){
        for(unsigned long idx = 0; idx < products.size(); idx++){
            if (products[idx].id == product.id){
                products.erase(products.begin()+idx);
                return true;
            }
        }
        return false;
    }

    std::string getName(std::string id){
        for (Product & product: products){
            if (product.id == id){
                return product.name;
            }
        }
        return "";
    }

    std::vector<std::string> findByName(std::string name){
        std::vector<std::string> vec;
        for (Product & product:products){
            if (product.name == name){
                vec.push_back(product.id);
            }
        }
        return vec;
    }
};


std::vector<Product> ProductsImpl::products {};


void test(){
    /*
    эта функция была создана для самотестирования
    */
    ProductsImpl primp;
    primp.addProduct(Product("123", "milk"));
    primp.addProduct(Product("321", "bread"));
    primp.addProduct(Product("555", "bread"));
    primp.addProduct(Product("444", "strawberry"));
    primp.addProduct(Product("333", "fish"));
    primp.addProduct(Product("222", "oil"));
    for (Product& i: primp.products) {
        std::cout << i.id << "---" << i.name << "\n";
    }
    auto id_vec = primp.findByName("bread");
    for(auto k: id_vec){
        std::cout<<k<<"\n";
    }
    std::cout<<primp.getName("321")<<"\n";
    for (Product& i: primp.products) {
        std::cout << i.id << "---" << i.name << "\n";
    }
    bool res = primp.deleteProduct(Product("333", "melon"));
    std::cout<<res<<std::endl;
    res = primp.deleteProduct(Product("330", "melon"));
    std::cout<<res<<std::endl;
}

