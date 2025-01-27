#include <string>
#include <iostream>
#include "../include/menu.h"

void hashMd5(){
    std::string choice;
    while(true){
        std::cout << std::endl << "Enter md5 hash: " << std::endl;
        std::getline(std::cin, choice);
    }
}

