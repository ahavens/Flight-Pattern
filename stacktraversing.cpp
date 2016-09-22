#include "stacktraversing.h"
#include "interpretdata.h"
#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

StackTraversing::StackTraversing()
{
}

//in this function, we want to determine whether or not the flight pattern really is possible
bool StackTraversing::determineFlightRoute(AdjList*& list, string start, string end, int numEntries, int totalDestinations)
{
    //have an array the size of the number of possible destination
    string* stackHolderArray = new string[totalDestinations];

    //bool that determines when the function should end
    bool exitCase = false;
    //bool that determines if there is a head with start at the front of it
    bool headExists = false;

    int stackHolderIndex = 0;
    int listIndex = 0;

    if(start.compare(end) == 0)
        return false;
    else
        return true;


}

//if the bool function returns a true, then this function is called
void StackTraversing::printOutStack()
{

}

void StackTraversing::resetList(AdjList*& list, int numEntries)
{
    for(int i = 0; i < numEntries; i++)
    {
        //assign head node bool to false
        list[i].top->visited = false;
        //create a new pointer named cur that traverses the nodes
        AdjListNode* cur = list[i].top->next;
        //traverse all the nodes and reset them
        while(cur != NULL)
        {
            //set bool to false
            cur->visited = false;
            //reset cur
            cur = cur->next;
        }
    }
    //at the end of this function, they should all be set to false, so then we now traverse it
}
