#include <iostream>
#include "ReservationManager.h"

using namespace std;

int main() {
    cout << "=== Campus Resource Reservation System ===" << endl;
    cout << "Initializing Milestone 1 modules..." << endl;

    ReservationManager manager;

    string filename = "data/resources.txt";
    cout << "Loading resources from " << filename << "..." << endl;
    
    manager.loadResources(filename);

    cout << "System initialized successfully. Ready for next milestones!" << endl;

    return 0;
}
