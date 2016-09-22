#ifndef ADJLISTNODE_H
#define ADJLISTNODE_H
#include "interpretdata.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class AdjListNode
{
public:

    AdjListNode();
    string destination;
    int cost;
    bool visited;
    AdjListNode* next;

    AdjListNode* newAdjListNode(string dest, int cost)
    {
        AdjListNode* newNode = new AdjListNode;
        newNode->destination = dest;
        newNode->cost = cost;
        newNode->next = NULL;
        return newNode;
    }
};

#endif // ADJLISTNODE_H
