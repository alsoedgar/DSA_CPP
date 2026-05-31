/*
 * Hash maps are an unordered key-value pair way to store data
 * Efficient because user creates a hash function to create a key to point to the location of data
 * O(1) time complexity for searching, inserting, and deleting *unless collision occurs*
 * Worst-case O(n) for LL || O(logn) for BRT
 * Common issue is hash collisions, solved usually by linear probing, chaining, or double hashing
 * linear probing is done by checking following indexes to see availability, and placing data in next free slot 
 * chaining can also be accomplished by linked lists or red black trees for size flexibility, however more memory req.
 * This is an implementation done by linear probing!
 */

#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
using std::string;

#define TABLE_SIZE 10

struct Student{
    string name;
    float gpa; 
};

inline Student DELETED_INSTANCE; //keep track of which nodes are deleted, important for edge-cases!
inline Student *DELETED = &DELETED_INSTANCE;

void initHashTable();
unsigned int hashFunction(string name);
void printTable();
bool hashTableInsert(Student *p);
Student *hashTableLookup(string name);
Student *deleteStudent(string name);

#endif 