#ifndef STACKTRAVERSING_H
#define STACKTRAVERSING_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include "interpretdata.h"
#include "adjlist.h"

using namespace std;

class StackTraversing
{
private:
    string flyingFrom;
    string flyingTo;
    int sum;
    stack<string> flightPath;

public:
    StackTraversing();
    //a function to take in the list and the start and ending desinations
    void resetList(AdjList*& list, int numEntries);
    bool determineFlightRoute(AdjList*& list, string start, string end, int numEntries, int totalDestinations);
    void printOutStack();
};

#endif // STACKTRAVERSING_H
