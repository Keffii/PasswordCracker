#include <string>
#include <iostream>
#include <iomanip>
#include <openssl/md5.h>
#include <sstream>
#include <fstream>
#include <regex>
#include <string>
#include "../include/createuser.h"


void createUser(){
    std::string userName;
    std::string password;
    std::regex emailRegex(R"((\w+)(\.{1}\w+)*@(\w+)(\.\w+)+)");
    
    std::cout << "Enter your username(email)" << std::endl;
    std::getline(std::cin, userName);
    
    while(!std::regex_match(userName, emailRegex)){
        std::cout << "Invalid email format. Please enter a valid email:" << std::endl;
        std::getline(std::cin, userName);
    }
    
    bool has_upper = false, has_lower = false, has_digit = false, has_punct = false;

while(true){
        has_upper = has_lower = has_digit = has_punct = false;
        std::cout << "Enter your password (8 characters minimum, including upper, lower, digit, and punctuation):" << std::endl;
        std::getline(std::cin, password);

        for(char c : password){
            if(std::isupper(c)) has_upper = true;
            if(std::islower(c)) has_lower = true;
            if(std::isdigit(c)) has_digit = true;
            if(std::ispunct(c)) has_punct = true;
        }

        if(password.length() >= 8 && has_upper && has_lower && has_digit && has_punct) {
            std::cout << "Valid password" << std::endl;
            break;
        }else{
            std::cout << "Invalid password. Try again." << std::endl;
        }
    }

    password = md5(password);
    std::ofstream MyFile("users.txt", std::ios::app);
    if(MyFile.is_open()){
        MyFile << userName << ":" << password << std::endl;
        MyFile.close();
    }
}
