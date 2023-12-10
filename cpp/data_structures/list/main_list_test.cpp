#include <iostream>
#include <vector>
#include <unordered_map>

#include "list.hpp"


int main() {
    List<std::string> list;
    list.PushBack("0");
    list.PushBack("1");
    list.PushBack("2");
    list.PushBack("3");
    list.PushBack("4");
    list.PushBack("5");

    std::cout << list.PopBack() << std::endl;
    std::cout << list.PopFront() << std::endl;

}

