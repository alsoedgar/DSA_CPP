#include <iostream>
#include <string>
#include "hashmap_openaddress.h"

using std::cout;
using std::string;
using std::endl;

main(){

    initHashTable();
    printTable();

    Student *Edgar = new Student {"Edgar", 4.0};
    Student *Rino = new Student {"Rino", 4.0};
    Student *Rainee = new Student {"Rainee", 4.0};
    Student *JZ = new Student{"JZ", 3.9};
    Student *Bacoj = new Student {"Bacoj", 4.0};
    Student *Steve = new Student{"Steve", 3.99};

    hashTableInsert(Edgar);
    hashTableInsert(Rino);
    hashTableInsert(Rainee);
    hashTableInsert(JZ);
    hashTableInsert(Bacoj);
    hashTableInsert(Steve);
    printTable();

    Student *temp = hashTableLookup("JZ");
    if(temp == nullptr){
        cout << "Not found!\n";
    }
    else{
        cout <<"Found " << temp->name << "\n";
    }

    Student *removed = deleteStudent("JZ");
    if(removed != nullptr){
        //created students on heap so free memory
        //store/save any data if necessary before freeing memory 
        delete removed;
    }

    printTable();

    temp = hashTableLookup("JZ");
    if(temp == nullptr){
        cout << "Not found!\n";
    }
    else{
        cout <<"Found " << temp->name << "\n";
    }

    return 0;
}