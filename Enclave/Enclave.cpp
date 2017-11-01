#include "Enclave_t.h"
#include <map>
#include <string>

std::map<int, std::string> strings;

std::map<int, int> numbers;

int generate_random_number() {
    ocall_print("Processing random number generation...");
    return 42;
}

void put_int(int key, int value){
    numbers[key] = value;
}

void put_string(int key, char *value){
    strings[key] = std::string(value);    
}

void get_string(int key, char *copyTo, size_t max_size){
    char *msg = strings[key].data();
    int i = 0;
    while(msg[i] && i < max_size){
        copyTo[i] = msg[i];
        i++;
    }
}

int get_int(int key){
    return numbers[key];
}
