#include "flightmap.h"
#include "interpretdata.h"

FlightMap::FlightMap()
{

}

void FlightMap::addFlyingFrom(InterpretData::AdjList*& list, string& flyingFrom, int numEntries)
{
    InterpretData* obj = new InterpretData();
    //check to see if the head node already exists
    bool exist = checkIfExist(list, flyingFrom, numEntries);
    if(exist == false)
    {
        int index = 0;
        //add the node to the closest index available
        while(list[index].head != NULL)
        {
            index++;
        }
        //create a new node to hold the destination and cost
        InterpretData::AdjListNode* newNode = obj->newAdjListNode(flyingFrom, 0);
        //add node at that index
        list[index].head = newNode;
    }
    else
    {

    }
}

void FlightMap::addFlyingTo(InterpretData::AdjList*& list, string& flyingFrom, string& flyingTo, int numEntries)
{
    int index = 0;
    //increase to find the index where the head exists
    while(list[index].head->destination != flyingFrom)
    {
        index++;
    }


}

//determine if the head string is already in, else we are to add it
bool FlightMap::checkIfExist(InterpretData::AdjList*& list, string& flyingFrom, int numEntries)
{
    bool exist = false;
    for(int i = 0; i < numEntries; i++)
    {
        //if there is a head with the flyingFrom then the node exists and there's no need to add to it
        if(list[i].head->destination == flyingFrom)
            exist = true;
    }
    return exist;
}

