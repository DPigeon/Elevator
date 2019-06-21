#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Elevator.h"

using namespace std;

Elevator::Elevator(string theStatus, int floorId, int maxFloors)
{
    status = theStatus;
    currentFloor = floorId;
    floors = maxFloors;
}

void Elevator::addEvent(Event event)
{
    // Look if on the same floor, otherwise wait
    if (event.getFloor() == currentFloor)
        elevatorQueue.push(event);
    else
        waitQueue.push(event);

    Elevator::print();
}

void Elevator::start()
{
    int currentLevel, nextLevel;
    if (!elevatorQueue.empty())
    {
        currentLevel = elevatorQueue.front().getFloor();
        nextLevel = elevatorQueue.front().getNextFloor();
    }
    else if (!waitQueue.empty())
    {
        currentLevel = waitQueue.front().getFloor();
        nextLevel = waitQueue.front().getNextFloor();
    }
    // Change the status
    int movement = currentLevel - nextLevel;
    if (movement < 0)
    {
        status = "going up";
        movement--;
    }
    else if (movement > 0)
    {
        status = "going down";
        movement++;
    }
    else
        status = "stopped";
    // Fix a speed elevator & increment the current floor by 1 according to that speed
    Elevator::movement(movement, nextLevel);
}

void Elevator::movement(int movement, int nextLevel)
{
    long duration = time(0);

    while (currentFloor != abs(movement))
    {
        if (time(0) > duration)
        {
            duration = time(0);
            if (movement > 0)
                currentFloor--;
            else if (movement < 0)
                currentFloor++;
            Elevator::print();
        }
    }
    // Stop elevator once reached the desired and closer floor
    Elevator::stop(nextLevel);
}

void Elevator::stop(int nextLevel)
{
    status == "stopped";
    // Find the event
    Event nextEvent = elevatorQueue.front();
    Event waitingEvent = waitQueue.front();
    // Open the doors (meaning delete all the current events)
    for (int i = 0; i < elevatorQueue.size(); i++)
    {
        if (nextLevel == nextEvent.getFloor())
            elevatorQueue.pop();
    }
    // Go to next task (waitQueue)
    if (waitQueue.empty())
        Elevator::movement(nextEvent.getFloor(), 1); // Initialize elevator to first floor
    else
        Elevator::movement(nextEvent.getFloor(), waitingEvent.getFloor()); // Go to next task
}

void Elevator::print()
{
    // Prints the elevator status at any time if
    cout << endl;
    cout << "<---------- Elevator Information ----------->" << endl;
    cout << endl;
    cout << "Waiting Queue: " << waitQueue.size() << endl;
    cout << "Elevator Queue: " << elevatorQueue.size() << endl;
    cout << endl;
    cout << "Elevator Status: " << status << endl;
    cout << endl;
    cout << "Current Floor: " << currentFloor << endl;
}

string Elevator::getStatus()
{
    return status;
}

int Elevator::getCurrentFloor()
{
    return currentFloor;
}

Elevator::~Elevator() {}