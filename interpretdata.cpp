#include "interpretdata.h"
#include "stacktraversing.h"
#include "adjlist.h"
#include "adjlistnode.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


using namespace std;



InterpretData::InterpretData()
{
}

//extract the info from the flight to determine the patterns
void InterpretData::extractFlightInfo(char* textFile)
{
    StackTraversing* obj = new StackTraversing();

    //pull in the text file
    ifstream flightInformation(textFile);
    //have to parse the word to find the commas
    string line = "";

    //get the first line which is the number of entries
    getline(flightInformation, line);
    int numEntries = atoi(line.c_str());
    int numEntriesCounter = 0;
    int costLength = 0;

    //create the adjaceny list
    AdjList* map = new AdjList[numEntries];
    for(int i = 0; i < numEntries; i++)
    {
        map[i].top = NULL;
    }

    //create a map that has an array the size of the entries

    //get the next lines so long as the counter is less than the number of Entries
    while(getline(flightInformation, line) && numEntriesCounter <= numEntries)
    {
        //now that you have a line, parse through the line and find the commas, EACH LINE HAS TWO ENTRIES
        //temporarily treat as char*
        const char* lineParser = line.c_str();
        //there are two commas in the line, find them in order to determine the string
        //int holder to hold the locations
        int commaHolder[2];
        int commaIndex = 0;
        for(int i = 0; i < line.length(); i++)
        {
            if(lineParser[i] == ',')
            {
                //put location into comma Index
                commaHolder[commaIndex] = i;
                commaIndex++;
            }
            //need a way to determine string length of int
            if(lineParser[i] >= 48 && lineParser[i] <= 57)
            {
                costLength++;
            }
        }
        string flyingFrom = line.substr(0, commaHolder[0]);
        //string length of the flying to string
        int stringLength = commaHolder[1]-(commaHolder[0]);
        string flyingTo = line.substr(commaHolder[0] + 2, stringLength-2);
        //next string is the integer
        string costOfFlight = line.substr(commaHolder[1]+2, costLength);
        //takes in the cost to pass this in
        int costToFly = atoi(costOfFlight.c_str());
        //from here, we assign one of the nodes in the map to be the Flying from so we can track it later


        //add the flying to destination, and flying from and the number of entries
        //obviously a segmentation fault happening here
        addFlyingFrom(map, flyingFrom, numEntries);
        addFlyingTo(map, flyingFrom,flyingTo, costToFly, numEntries);

    }
    string test = "Dallas";
    string end = "Houston";
    printHeadOfList(map, numEntries);
    obj->determineFlightRoute(map, test, end, numEntries, totalDestinations);
}

//be easier to just add nodes here and pass in list to another class
void InterpretData::addFlyingFrom(AdjList*& list, string destination, int numEntries)
{
    AdjListNode* obj = new AdjListNode;
    bool exist = destinationExists(list, destination, numEntries);
    int index = 0;
    if(exist == false)
    {
        totalDestinations++;
        if(list[0].top == NULL)
        {
            AdjListNode* newNode = obj->newAdjListNode(destination, 0);
            list[0].top = newNode;
        }
        else
        {
            //find the first location of the null list
            while(list[index].top != NULL)
            {
                index++;
            }

            AdjListNode* newNode = obj->newAdjListNode(destination, 0);
            list[index].top = newNode;
        }
    }
}

void InterpretData::addFlyingTo(AdjList*& list, string flyingFrom, string flyingTo, int cost, int numEntries)
{
    AdjListNode* obj = new AdjListNode;
    int index = 0;
    string stringCheck = list[index].top->destination;
    while(stringCheck.compare(flyingFrom) != 0)
    {
        index++;
        stringCheck = list[index].top->destination;
    }

    totalDestinations++;

    cout << "destination to be added " << flyingTo << endl;
    //create a new node
    AdjListNode* newNode = obj->newAdjListNode(flyingTo, cost);
    //have not changed to make new node
    AdjListNode* cur = list[index].top;
    cout << "current node : " << cur->destination << " " << cur->cost << endl;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    //list[index].head->next = newNode;

}

bool InterpretData::destinationExists(AdjList*& list, string flyingFrom, int numEntries)
{
    bool exists = false;
    int forLoop = 0;
    if(list[0].top == NULL)
        exists = false;
    else
    {
        for(int i = 0; i < numEntries; i++)
        {
            if(list[i].top == NULL)
            {

            }

            else
            {
                //check to see if the destination exists
                string checkString = list[i].top->destination;
                if(checkString.compare(flyingFrom) == 0)
                    exists = true;

            }
            forLoop++;
        }
    }

    return exists;
}

//extract the flight pattern wanting to be accomplished
void InterpretData::extractFlightPattern(char* textFile)
{

}

//determine if the flight pattern is possible
bool InterpretData::flightPossible()
{
    return false;
}

void InterpretData::printHeadOfList(AdjList*& list, int numEntries)
{
    for(int i = 0; i < numEntries; i++)
    {
        if(list[i].top != NULL)
        {
            cout<< "Flying From: " << list[i].top->destination << endl;
            AdjListNode* cur = list[i].top->next;
            while(cur != NULL)
            {
                cout << "flying to " << cur->destination << endl;
                cout <<"cost to fly to " << cur->cost << endl;
                cur = cur->next;

            }
        }
    }
}
