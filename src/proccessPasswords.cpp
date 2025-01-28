#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/rand.h>


std::string generate_salt(){
    unsigned char salt[16];
    RAND_bytes(salt, sizeof(salt));
    std::ostringstream oss;
    for(int i=0; i < sizeof(salt); i++){
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)salt[i];

    }
    return oss.str();
}

std::string hash_md5(const std::string& input){
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input.c_str(), input.size(), hash);
    std::ostringstream oss;
    for(int i=0; i < MD5_DIGEST_LENGTH; i++){
        oss << std::hex << std::setw(2) << std::setfill('0') << int(hash[i]);
    }
    return oss.str();
}

std::string hash_sha256(const std::string& input){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input.c_str(), input.size(), hash);
    std::ostringstream oss;
    for(int i=0; i < SHA256_DIGEST_LENGTH; i++){
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return oss.str();
}

void proccessPasswords(const std::string& input_file, const std::string& md5_output_file, const std::string& sha256_output_file){
    std::ifstream infline(input_file);
    std::ofstream md5_outfile(md5_output_file);
    std::ofstream sha256_outfile(sha256_output_file);

    md5_outfile << "Password:hash:salt" << std::endl << std::endl;
    sha256_outfile << "Password:hash:salt" << std::endl << std::endl;

    std::string password;
    while(std::getline(infline, password)){
        std::string salt = generate_salt();
        std::string md5_hash = hash_md5(password+salt);
        std::string sha256_hash = hash_sha256(password+salt);

        md5_outfile << password << ":" << md5_hash << ":" << salt << std::endl;
        sha256_outfile << password << ":" << sha256_hash << ":" << salt << std::endl;
    }
}