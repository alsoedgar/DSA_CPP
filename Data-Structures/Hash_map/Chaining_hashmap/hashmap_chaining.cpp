#include "hashmap_chaining.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
Node *hash_table[TABLE_SIZE];

Songs::Songs(string songName, int duration){
    this->songName = songName;

    if (duration > 0){
    this->duration = duration;
    }
    else {
        this->duration = -1;
    }
}

Node::Node(string songName, int duration){
    this->song = Songs(songName, duration);
    this->pNext = nullptr;
}

unsigned int hashFunction(string songName){
    int length = songName.length();
    unsigned int hashValue = 0;

    for(int i = 0; i < length; i++){
        hashValue += songName[i];
        hashValue = (hashValue * songName[i]) % TABLE_SIZE;
    }
    return hashValue;
}

//create empty hash table
void initHashTable(){
    for (int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = nullptr;
    }
}

//make table print out whole list
//if an index is empty, that means it doesn't have chain, just print empty
//if index has a chain, print through entire chain song --> next --> ... and update count
//if there's only one song in index print only that song
//show total songs (may != to TABLE_SIZE) 
void printTable(){
    int count = 0;
    cout << "\t ---START--- \t\n";
    for (int i = 0; i < TABLE_SIZE; i++){
        cout << "\t" << i << "\t";
        if (hash_table[i] == nullptr){
            cout << "---\n";
        }
        else {
            Node *temp = hash_table[i];
            while (temp != nullptr){
                count++;
                cout << temp->song.songName;
                if (temp->pNext != nullptr) {
                    cout << " -> ";
                }
                temp = temp->pNext;
            }
            cout << std::endl;
        }
    }
    cout << "\t Total # songs: " << count << "\t\n";
    cout << "\t ---End--- \t\n";
}

//insert song if index is empty
//if index isn't empty, add song to the end of the linked list
bool hashTableInsert(Node *p){

    int index = hashFunction(p->song.songName);

    if(hash_table[index] == nullptr){
        hash_table[index] = p;
        return true;
    }
    else{
        Node *temp = hash_table[index];
        while(temp->pNext!=nullptr){
            temp = temp->pNext;
        }
        temp->pNext = p;
        return true;
    }
    return false;
}

Node *hashTableLookup(string name){
    int index = hashFunction(name);
        
        //if it's nullptr, we know there's no list past it, so we can skip searching through nodes
        if(hash_table[index] == nullptr){
            return nullptr;
        }
        //if the song just matches right away, return it, if not search through list then delete
        else{
            Node* temp = hash_table[index];
            while(temp != nullptr){
                if(temp->song.songName == name){
                   return temp; 
                }
                temp = temp->pNext;
            }
        }
        return nullptr;
}

bool deleteSongs(string name){
    int index = hashFunction(name);

    //bucket is empty
    if(hash_table[index] == nullptr){
        return false;
    }

    Node *current = hash_table[index];
    Node *prev = nullptr;

    //song is the first bucket of the list
    if(current->song.songName == name){
        Node* temp = current;
        hash_table[index] = temp->pNext;
        delete temp;
        return true;
    }

    //you need to go deeper in the list 
    while (current != nullptr){
        if(current->song.songName == name){
            Node* temp = current;
            prev->pNext = current->pNext;
            delete temp;
            return true;
        }
        prev = current;
        current = current->pNext;
    }
    return false;
}

void Lookup(string songName){
    Node* temp = hashTableLookup(songName);
    if (temp != nullptr){
        cout << '\'' << songName << '\'' << " found!\n";
    } else cout << '\'' << songName << '\'' << " not in list\n";
}

void deleteSongHelper(string songName){
    if(deleteSongs(songName)){
        cout << "Deleted \'" << songName << "\'\n";
    }
    else cout << '\'' << songName << " not in playlist!\n";
}