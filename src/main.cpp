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
            std::cout << "Enter the count of products: ";
            std::cin >> count;
           if(std::cin.fail()) {
                std::cin.clear();
                std::string str;
                std::getline(std::cin, str);
                std::cout << "Not a number" << std::endl;
                continue;
            }
            try{
                
                shop.add(item, count);
            } catch(const std::invalid_argument& x){
                std::cerr << x.what() << std::endl;
            } catch(...){
                std::cerr << "Some kind of exception has happend..." << std::endl;
            }
        }  
    }while(item != "stop");


    std::string ans;
    
    while(true){
        std::cout << std::endl << "Сhoose an action with basket: add remove exit >>";
        std::cin >> ans;
        if(ans == "add"){
            std::cout << "Enter the product article: ";
            std::cin >> item;
            std::cout << "Enter the count of the product: ";
            std::cin >> count;

            if(std::cin.fail()){
                std::cin.clear();
                std::string str;
                std::getline(std::cin, str);
                std::cout << "Not a number" << std::endl;
                continue;
            }

            try{
                shop.transfer(basket, item, count);
                std::cout << "Basket:" << std::endl;
                basket.showAll();
                std::cout << std::endl;
                std::cout << "Shop:" << std::endl;
                shop.showAll();
            }catch(const std::invalid_argument& x){
                std::cerr << x.what() << std::endl;
            }catch(const std::runtime_error& x){
                std::cerr << x.what() << std::endl;
            }catch(...){
                std::cerr << "Some kind of exception has happend..." << std::endl;
            }

        } else if (ans == "remove"){
            std::cout << "Enter the product article: ";
            std::cin >> item;
            std::cout << "Enter the count of the product: "; 
            std::cin >> count;

            if(std::cin.fail()) {
                std::cin.clear();
                std::string str;
                std::getline(std::cin, str);
                std::cout << "Not a number" << std::endl;
                continue;
            }

            try{
                basket.transfer(shop, item, count);
                std::cout << "Your basket:" << std::endl;
                basket.showAll();
                std::cout << std::endl;
                std::cout << "Your shop:" << std::endl;
                shop.showAll();
            }catch(const std::invalid_argument& x){
                std::cerr << x.what() << std::endl;
            }catch(const std::runtime_error& x){
                std::cerr << x.what() << std::endl;
            }catch(...){
                std::cerr << "Some kind of exception has happend..." << std::endl;
            }

        } else if (ans == "exit"){
            break;
        } else {
            std::cout << "Uncknown command" << std::endl;
        }
    }
}
