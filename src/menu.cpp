#include <string>
#include <iostream>
#include "../include/menu.h"
#include "../include/createuser.h"
#include "../include/testlogin.h"

void menu(){
    std::string choice;
    while(true){
        std::cout << std::endl << "1. Enter your hash" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Choice: ";
        std::getline(std::cin, choice);
        
        if(choice == "1"){
        }
        else if(choice == "2"){
            return;
        }
        else{
            std::cout << "Not a valid option, try again" << std::endl;
        }
    }
}

