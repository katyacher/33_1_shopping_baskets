#include <iostream>
#include <string>
#include <exception>
#include "Storage.h"

int main(int, char**){
    std::cout << "Hello, from 33_1_shopping_baskets!\n";
   
    Storage basket;
    Storage shop;
    
    std::cout << "Fill out the store database. Type 'stop' to finish. " << std::endl;
    
    std::string item;
    int count;

    
    do{
        std::cout << "Enter the product article: ";
        std::cin >> item;
        if(item != "stop"){
            std::cout << "Enter the count of the product: ";
            std::cin >> count;

            try{
                shop.add(item, count);
            } catch(const std::invalid_argument& x){
                std::cerr << x.what() << std::endl;
            }
        }  
    }while(item != "stop");


    std::string ans;
    
    while(true){
        std::cout << "Сhoose an action with basket: add remove exit >>";
        std::cin >> ans;
        if(ans == "add"){
            std::cout << "Enter the product article: ";
            std::cin >> item;
            std::cout << "Enter the count of the product: ";
            std::cin >> count;
            
            try{
                shop.transfer(basket, item, count);
            }catch(const std::invalid_argument& x){
                std::cerr << x.what() << std::endl;
            }catch(const std::runtime_error& x){
                std::cerr << x.what() << std::endl;
            }catch(...){
                std::cerr << "Some kind of exception has happend..." << std::endl;
            }

            std::cout << "Your basket:" << std::endl;
            basket.showAll();
            std::cout << "Your shop:" << std::endl;
            shop.showAll();

        } else if (ans == "remove"){
            std::cout << "Enter the product article: ";
            std::cin >> item;
            std::cout << "Enter the count of the product: "; 
            std::cin >> count;
            
            try{
                basket.transfer(shop, item, count);
            }catch(const std::invalid_argument& x){
                std::cerr << x.what() << std::endl;
            }catch(const std::runtime_error& x){
                std::cerr << x.what();
            }catch(...){
                std::cerr << "Some kind of exception has happend..." << std::endl;
            }

            std::cout << "Your basket:" << std::endl;
            basket.showAll();
            std::cout << "Your shop:" << std::endl;
            shop.showAll();

        } else if (ans == "exit"){
            break;
        } else {
            std::cout << "Uncknown command" << std::endl;
        }
    }
}
