#include <iostream>
#include <string>
#include "hashmap_chaining.h"

using std::string;
using std::cout;

int main(){
    initHashTable();
    printTable();

    Node *fly = new Node("fly",151);
    Node *cupid = new Node("cupid",142);
    Node *eden = new Node("eden", 175);
    Node *Universe = new Node("Universe", 227);
    Node *RiskItAll = new Node("Risk It All", 204);

    hashTableInsert(fly);
    hashTableInsert(cupid);
    hashTableInsert(eden);
    hashTableInsert(Universe);
    hashTableInsert(RiskItAll);

    printTable();

    Lookup("eden");
    Lookup("Valentine");

    deleteSongHelper("Universe");
    printTable();

    return 0;
    
}