#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "../include/menu.h"

void hashMd5(){
    std::string hash, line;
    std::ifstream MyFile("hashes-md5.txt");
    std::string password;
    bool hashFound = false;

    std::cout << "Enter your hash: ";
    std::getline(std::cin, hash);

    hash.erase(std::remove_if(hash.begin(), hash.end(), ::isspace), hash.end());

    if(MyFile.is_open()){
        while(std::getline(MyFile, line)){
            std::istringstream iss(line);
            std::string storedHash, salt;
            if(std::getline(iss, password, ':') && std::getline(iss, storedHash, ':') && std::getline(iss, salt)){
                storedHash.erase(std::remove_if(storedHash.begin(), storedHash.end(), ::isspace), storedHash.end());
                if(storedHash == hash){
                    hashFound = true;
                    break;
                }
            }
        }
        MyFile.close();
    }

    if(hashFound){
        std::cout << "Your hash: " << hash << " was found" << std::endl << "Your password is: " << password << std::endl;
    }else{
        std::cout << "Your hash was not found" << std::endl;
    }
}