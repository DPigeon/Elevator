#ifndef Elevator_h
#define Elevator_h

#include <iostream>
#include <string>
#include <queue>
#include "Event.h"

using namespace std;
class Elevator
{
private:
    queue<Event> elevatorQueue; // Events in the elevator
    queue<Event> waitQueue;     // Waiting events
    string status;              // The Elevator`s status (going up, going down, stopped)
    int currentFloor;           // The level the Elevator is at
    int floors;                 // Number of floors
    int speed;                  // Any value (the greater, the slower)
public:
    Elevator(string status, int currentFloor, int floors, int speed);
    void start(int);
    void stop(int nextLevel);
    void movement(int floor, int nextfloor);
    void addEvent(Event event);
    void print();
    string getStatus();
    int getCurrentFloor();
    ~Elevator();
};
#endif