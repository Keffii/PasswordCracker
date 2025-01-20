#include <string>
#include <iostream>
#include "../include/menu.h"
#include "../include/createuser.h"
#include "../include/testlogin.h"

void menu(){
    std::string choice;
    while(true){
        std::cout << std::endl << "1. Create user" << std::endl;
        std::cout << "2. Test login" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choice: ";
        std::getline(std::cin, choice);
        
        if(choice == "1"){
            createUser();
        }
        else if(choice == "2"){
            testLogin;
        }
        else if(choice == "3"){
            return;
        }
        else{
            std::cout << "Not a valid option, try again" << std::endl;
        }
    }
}

