#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/md5.h"
#include "../include/testlogin.h"

void testLogin(){
    std::string userName, password, line;
    std::ifstream MyFile("users.txt");
    bool loginSuccess = false;

    std::cout << "Enter your username(email): ";
    std::getline(std::cin, userName);
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    password = md5(password);

    if (MyFile.is_open()){
        while (std::getline(MyFile, line)){
            std::istringstream iss(line);
            std::string storedUserName, storedPassword;
            if(std::getline(iss, storedUserName, ':') && std::getline(iss, storedPassword)){
                if(storedUserName == userName && storedPassword == password){
                    loginSuccess = true;
                    break;
                }
            }
        }
        MyFile.close();
    }

    if(loginSuccess){
        std::cout << "Login successful!" << std::endl;
    }else{
        std::cout << "Invalid username or password." << std::endl;
    }
}