#ifndef INTERPRETDATA_H
#define INTERPRETDATA_H
#include "stacktraversing.h"
#include "adjlist.h"
#include "adjlistnode.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//class is designed to interpret the input file and then use the info to create a hash table
class InterpretData
{
private:
    //first text file
    //ifstream flightInformation;
    //second text file
    ifstream flightPattern;
    int totalDestinations;


public:

    InterpretData();
    //assign the flight info to designated hash table
    void extractFlightInfo(char* textFile);
    //extract the flight pattern wanting to be accomplished
    void extractFlightPattern(char* textFile);

    void addFlyingFrom(AdjList*& list, string destination, int numEntries);
    void addFlyingTo(AdjList*& list, string flyingFrom, string flyingTo, int cost, int numEntries);
    bool destinationExists(AdjList*& list, string flyingFrom, int numEntries);

    //determine if the flight pattern is possible
    bool flightPossible();
    void printHeadOfList(AdjList*& list, int numEntries);
};
#endif // INTERPRETDATA_H
