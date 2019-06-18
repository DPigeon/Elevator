#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "Event.h"

using namespace std;

Event::Event(string eventName, int levelId, int destination)
{
    name = eventName;
    floor = levelId;
    nextFloor = destination;
}

string Event::getName()
{
    return name;
}

int Event::getFloor()
{
    return floor;
}

int Event::getNextFloor()
{
    return nextFloor;
}

Event::~Event() {}