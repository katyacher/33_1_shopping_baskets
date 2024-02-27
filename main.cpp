#include <iostream>
#include <string>
#include <map>
#include <exception>

class Basket{
    std::map<std::string, int> basket;
    Shop* shop;
public:
    Basket(Shop* sh): shop(sh){};

    //Добавление товара в корзину со склада с указанным его количеством
    //При вводе аргументов должна осуществляться их валидация. 
    //Артикул должен быть в базе данных магазина, количество не должно превышать 
    //количество доступного продукта на складе 
    void add(const std::string& item, int count){
        if(count <= 0){
            throw std::invalid_argument("Invalid count");
        }

        if(shop->getDb().find(item) == shop->getDb().end()){
            throw std::invalid_argument("Article " + item + " not found in the shop BD");
        }

        if(shop->getDb()[item] < count){
            throw std::invalid_argument("There are no such count of item in the shop");
        }

        basket[item] += count;
        shop->remove(item, count);
    };

    // удаление товара из корзины (возвращение на склад) с указанным количеством 
    //При вводе аргументов должна осуществляться их валидация. 
    //Артикул должен быть в корзине, количество не должно превышать 
    //количество доступного продукта в корзине.
    void remove(const std::string& item, int count){
        if(count <= 0){
            throw std::invalid_argument("Invalid count");
        }

        if(basket.find(item) == basket.end()){
            throw std::invalid_argument("No such item in the basket");
        }

        if(basket[item] < count) {
            throw std::invalid_argument("Too much count of items");
        }

    basket[item] -= count;
    shop->add(item, count);
    }
};

class Shop{
    std::map<std::string, int> db;
public:
    Shop(){};

    void create_bd(){
        std::cout << "Заполните базу данных." << std::endl;
        std::string item;
        int count;

        while(item != "n"){
            std::cout << "Введите артикул товара : ";
            std::cin >> item;

            std::cout << "Введите количество товара: ";
            std::cin >> count;

            db.emplace(item, count);

            std::cout << "Продолжить?  y/n: ";
            std::cin >> item;
        }
    }

    std::map<std::string, int> getDb(){
        return db;
    }

    void add(const std::string& item, int count){
        db[item] += count;
    }

    void remove(const std::string& item, int count){
        db[item] -=count;
    }

    void showDb(){
        for(auto it = db.begin(); it != db.end(); ++it){
            std::cout << std::left << it->first << " : " << it->second << std::endl;
        }
    }


};


int main(int, char**){
    std::cout << "Hello, from 33_1_shopping_baskets!\n";
    std::map<std::string, int> bd;

    
    Shop shop;
    shop.create_bd();

}
