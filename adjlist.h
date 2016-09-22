#ifndef ADJLIST_H
#define ADJLIST_H
//#include "adjlistnode.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class AdjListNode;

class AdjList
{
public:
    AdjList();
    AdjListNode* top;
};

#endif // ADJLIST_H
