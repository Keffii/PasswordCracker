#include <iostream>
#include <iomanip>
#include <openssl/md5.h>
#include <sstream>
#include <fstream>
#include <regex>
#include <string>
#include "../include/menu.h"
#include "../include/proccessPasswords.h"
#include "../include/hashMd5.h"

int main(){
    proccessPasswords("rockyou.txt", "hashes-md5.txt", "hashes-sha256.txt");
    menu();
    return 0;
}