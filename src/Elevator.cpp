#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Elevator.h"

using namespace std;

Elevator::Elevator(string theStatus, int floorId, int maxFloors, int maxSpeed)
{
    status = theStatus;
    currentFloor = floorId;
    floors = maxFloors;
    speed = maxSpeed;
}

void Elevator::start(int movement)
{
    clock_t start;
    int duration;

    // Every speed * seconds, we increment the floor by 1
    start = clock();
    duration = (clock() - start) / (int)CLOCKS_PER_SEC;
    if (movement < 0)
        movement = abs(movement);
    long t = time(0);

    while (/*some condition here*/)

    {

        if (time(0) > t)

        {

            printf("stuff\n");

            t = time(0);
        }
    }

    do
    {
        currentFloor++;
        Elevator::print();
    } while (duration == movement * speed);
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

void Elevator::movement(int currentLevel, int nextLevel)
{
    // Change the status
    int movement = currentLevel - nextLevel;
    if (movement < 0)
        status = "going up";
    else if (movement > 0)
        status = "going down";
    else
        status = "stopped";
    Elevator::print();
    // Fix a speed elevator & increment the current floor by 1 according to that speed
    Elevator::start(movement);

    // Stop elevator once reached the desired and closer floor
    Elevator::stop(nextLevel);
}

void Elevator::addEvent(Event event)
{
    // Look if on the same floor, otherwise wait
    if (event.getFloor() == currentFloor)
        elevatorQueue.push(event);
    else
        waitQueue.push(event);

    Elevator::print();

    // Start the mechanism
    Elevator::movement(event.getFloor(), event.getNextFloor());
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