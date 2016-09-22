#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "interpretdata.h"

using namespace std;

int main(int argc, char* argv[])
{
    InterpretData* obj = new InterpretData();
    obj->extractFlightInfo(argv[1]);
    delete obj;
    return 0;
}

