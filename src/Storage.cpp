#include "Storage.h"

void Storage::add(const std::string& item, int count){
    if(count <= 0){
        throw std::invalid_argument("Invalid argumet");
    }

    storage[item] += count;
}

void Storage::remove(const std::string& item, int count){
    if(count <= 0){
        throw std::invalid_argument("Invalid count");
    }

    if(storage.find(item) == storage.end()){
        throw std::runtime_error("No such item");
    }

    if(storage[item] < count) {
        throw std::invalid_argument("You want to remove too much");
    }

    storage[item] -= count;
}

void Storage::transfer(Storage& to, std::string& item, int count){
    remove(item,count);// если удаление не удалось, то функция кинет исключение и товар не добавится.
    to.add(item, count);
}

void Storage::showAll(){
    for(auto it = storage.begin(); it != storage.end(); ++it){
        std::cout << std::left << it->first << " : " << it->second << std::endl;
    } 
}