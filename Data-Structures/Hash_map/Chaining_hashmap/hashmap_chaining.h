/*
 *implementation closed addressing, using chaining (linked lists)
 *When a hash collision occurs, instead of moving to find the next free slot to place it
 *This solution instead creates a list at that index, chaining the object/data that was collided
 *with, with the new object so the index accessed has the object but later down the list
 *Less memory efficient, and doesn't have CPU cache efficiency because memory locations
 *aren't contigous, however more flexible for size, and situation dependent
 *This causes O(N) time for lookup, deletion, or insertion only if collided and poor hash function
 *Good implementations still have around a O(1) time average
 */

#ifndef HASHMAP_CHAINING_H
#define HASHMAP_CHAINING_H
#include <string>

#define TABLE_SIZE 4

using std::string;

struct Songs{
    string songName;
    int duration;
    Songs() : songName(""), duration(-1){}
    Songs(string songName, int duration);
};

struct Node{
    Songs song;
    Node *pNext;
    Node(string songName, int duration);
};

//core functions
void initHashTable();
unsigned int hashFunction(string name);
void printTable();
bool hashTableInsert(Node *p);
Node *hashTableLookup(string name);
bool deleteSongs(string name);

//utility functions
void Lookup(string songName);
void deleteSongHelper(string songName);

#endif