#ifndef Event_h
#define Event_h

#include <iostream>
#include <string>

using namespace std;

class Event
{
private:
    string name;   // The event`s name
    int floor;     // The level the event is at
    int nextFloor; // The floor the person wants to go

public:
    Event(string name, int floor, int nextFloor);
    string getName();
    int getFloor();
    int getNextFloor();
    ~Event();
};
#endif
