#include <iostream>
#include <iomanip>
#include "./src/Event.h"
#include "./src/Elevator.h"

using namespace std;

void initialMessage(Elevator elevator, Event event)
{
    cout << event.getName() << " is on level " << event.getFloor() << endl;
    cout << "Elevator is " << elevator.getStatus() << " and is on level " << elevator.getCurrentFloor() << endl;
}

int main()
{
    Elevator elevator("stopped", 1, 10, 2);
    Event event1("Jacob", 1, 6);
    Event event2("David", 6, 1);

    elevator.addEvent(event1);

    //initialMessage(elevator, event1);
    return 0;
}
