//Implementation using open addressing (linear probing)
//better for fixed sized lists, good for CPU caching (faster efficiency) 
//and good for memory constraints (doesn't need extra space for next or prev pointers)

#include "hashmap_openaddress.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
Student *hash_table[TABLE_SIZE];


unsigned int hashFunction(string name){
    int length = name.length();
    unsigned int hashValue = 0;

    for(int i = 0; i < length; i++){
        hashValue += name[i];
        hashValue = (hashValue * name[i]) % TABLE_SIZE;
    }
    return hashValue;
}

void initHashTable(){
    for (int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = nullptr;
    }
}

void printTable(){
    cout << "\t ---START--- \t\n";
    for (int i = 0; i < TABLE_SIZE; i++){
        if (hash_table[i] == nullptr){
            cout << "\t" << i << "\t---\n";
        }
        else if(hash_table[i] == DELETED){
            cout << "\t" << i << "\t<deleted>\t\n";
        }
        else{
            cout <<"\t" << i << "\t" << hash_table[i]->name << std::endl;
        }
    }
    cout << "\t ---End--- \t\n";
}

bool hashTableInsert(Student *p){

    int attempt = hashFunction(p->name);

    for (int i = 0; i < TABLE_SIZE; i++){
        int currentIndex = (attempt + i) % TABLE_SIZE;
        if(hash_table[currentIndex] == nullptr || hash_table[currentIndex] == DELETED){
            hash_table[currentIndex] = p;
            return true;
        }
    }
    return false;
}

Student *hashTableLookup(string name){
    int attempt = hashFunction(name);

    for (int i = 0; i < TABLE_SIZE; i++){ 
        int currentIndex = (attempt + i) % TABLE_SIZE;
        
        if(hash_table[currentIndex] == nullptr){
            break;
        }

        if(hash_table[currentIndex] == DELETED ){
                continue;
            }

        if (hash_table[currentIndex]->name == 
            name){
            return hash_table[currentIndex]; 
        }
    }
    return nullptr;
}

Student *deleteStudent(string name){
    int attempt = hashFunction(name);

    for (int i = 0; i < TABLE_SIZE; i++){
        int currentIndex = (attempt + i) % TABLE_SIZE;

        if (hash_table[currentIndex] == nullptr){
                break;
            }

        if(hash_table[currentIndex] == DELETED){
            continue;
        }

        if (name == hash_table[currentIndex]->name){
            Student *temp = hash_table[currentIndex];
            hash_table[currentIndex] = DELETED;
            return temp;
        }
    }
    return nullptr;
}