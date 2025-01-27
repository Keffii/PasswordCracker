#include <string>
#include <iostream>
#include "../include/hashMd5.h"

void menu(){
    std::string choice;
    while(true){
        std::cout << std::endl << "1. md5 hash" << std::endl;
        std::cout << "2. sha256 hash" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choice: ";
        std::getline(std::cin, choice);
        
        if(choice == "1"){
            hashMd5();
        }
        else if(choice == "2"){

        }
        else if(choice == "3"){
            return;
        }
        else{
            std::cout << "Not a valid option, try again" << std::endl;
        }
    }
}
