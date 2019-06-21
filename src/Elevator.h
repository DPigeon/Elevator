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
public:
    Elevator(string status, int currentFloor, int floors);
    void addEvent(Event event);
    void start();
    void movement(int movement, int nextLevel);
    void stop(int nextLevel);
    void print();
    string getStatus();
    int getCurrentFloor();
    ~Elevator();
};
#endif