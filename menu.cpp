#include <string>
#include <iostream>
#include "menu.h"
#include "createuser.h"
#include "testlogin.h"

void menu(){
    std::string choice;

    while(true){
        std::cout << "\n1. Create user" << std::endl;
        std::cout << "2. Test login" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choice: ";
        
        std::getline(std::cin, choice);
        
        if(choice == "1"){ 
            createUser();
        }
        else if(choice == "2"){
            testLogin();
        }
        else if(choice == "3"){
            break;
        }
    }
}