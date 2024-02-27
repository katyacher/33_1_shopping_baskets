#include <iostream>
#include <string>
#include <map>
#include <exception>

class Storage{
    std::map<std::string, int> storage;
public:
    Storage(){};

    void add(const std::string& item, int count);

    void remove(const std::string& item, int count);

    bool transfer(Storage& to, std::string& item, int count);

    void showAll();
};

