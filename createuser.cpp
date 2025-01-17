#include <string>
#include <iostream>
#include <iomanip>
#include <openssl/md5.h>
#include <sstream>
#include <fstream>
#include <regex>
#include <string>
#include "createuser.h"

std::string md5(const std::string &str){
  unsigned char hash[MD5_DIGEST_LENGTH];

  MD5_CTX md5;
  MD5_Init(&md5);
  MD5_Update(&md5, str.c_str(), str.size());
  MD5_Final(hash, &md5);

  std::stringstream ss;

  for(int i = 0; i < MD5_DIGEST_LENGTH; i++){
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>( hash[i] );
  }
  return ss.str();
}



void md5(){
    std::string theHash = md5("hejsan123");
    std::ofstream MyFile("users.txt");
    theHash = md5("hejsan123");
    MyFile << theHash;
    MyFile.close();
}


void createUser(){
    std::string userName;
    std::string password;
    std::regex emailRegex(R"((\w+)(\.{1}\w+)*@(\w+)(\.\w+)+)");
    
    std::cout << "Enter your username (email)" << std::endl;
    std::cin >> userName;
    
    while(!std::regex_match(userName, emailRegex)){
        std::cout << "Invalid email format. Please enter a valid email:" << std::endl;
        std::cin >> userName;
    }
    
    std::cout << "Enter your password" << std::endl;
    std::cin >> password;
    password = md5(password);
    std::ofstream MyFile("users.txt", std::ios::app);
    if(MyFile.is_open()){
        MyFile << userName << ":" << password << std::endl;
    MyFile.close();
}
}