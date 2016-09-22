#ifndef FLIGHTMAP_H
#define FLIGHTMAP_H
#include "interpretdata.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class FlightMap
{

public:
    FlightMap();
    //pass in an adjacency list structure by reference so it is changed when things are added to it
    void addFlyingFrom(InterpretData::AdjList*& list, string& flyingFrom, int numEntries);
    void addFlyingTo(InterpretData::AdjList*& list, string& flyingFrom, string& flyingTo, int numEntries);
    //determine if the head string is already in, else we are to add it
    bool checkIfExist(InterpretData::AdjList*& list, string& flyingFrom, int numEntries);

};

#endif // FLIGHTMAP_H
