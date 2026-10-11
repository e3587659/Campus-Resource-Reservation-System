#include <iostream>
#include <string>
#include "ReservationManager.h"

using namespace std;

void displayMenu() {
    cout << "\n===== Campus Resource Reservation System =====" << endl;
    cout << "1. Display All Resources" << endl;
    cout << "2. Display All Active Reservations" << endl;
    cout << "3. Create a Reservation" << endl;
    cout << "4. Remove a Reservation (Triggers Undo Stack)" << endl;
    cout << "5. Undo Last Cancellation" << endl;
    cout << "6. Search Reservation by ID" << endl;
    cout << "7. Generate System Report" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice (1-8): ";
}

int main() {
    ReservationManager manager;

    string filename = "data/resources.txt";
    cout << "Loading resources from " << filename << "..." << endl;
    manager.loadResources(filename);

    int choice = 0;
    do {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                manager.displayAllResources();
                break;
            }
            case 2: {
                manager.displayAllReservations();
                break;
            }
            case 3: {
                string resID, studID, studName, resourceID, date;
                cout << "Enter Reservation ID: ";
                cin >> resID;
                cout << "Enter Student ID: ";
                cin >> studID;
                cout << "Enter Student Name: ";
                cin >> studName;
                cout << "Enter Resource ID: ";
                cin >> resourceID;
                cout << "Enter Date (YYYY-MM-DD): ";
                cin >> date;

                Reservation newRes(resID, studID, studName, resourceID, date);
                if (manager.createReservation(newRes)) {
                    cout << "Reservation created successfully!" << endl;
                } else {
                    cout << "Error: Could not create reservation (Resource doesn't exist or schedule conflict)." << endl;
                }
                break;
            }
            case 4: {
                string resID;
                cout << "Enter Reservation ID to remove: ";
                cin >> resID;
                Reservation cancelledRes("", "", "", "", "");
                if (manager.removeReservation(resID, cancelledRes)) {
                    cout << "Reservation removed successfully and queued for undo." << endl;
                } else {
                    cout << "Reservation ID not found." << endl;
                }
                break;
            }
            case 5: {
                cout << "Undo feature called (Ensure stack pop is linked)." << endl;
                break;
            }
            case 6: {
                string searchID;
                cout << "Enter Reservation ID to search: ";
                cin >> searchID;
                manager.displayReservation(searchID);
                break;
            }
            case 7: {
                manager.generateSystemReport();
                break;
            }
            case 8: {
                cout << "Exiting system. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please choose between 1 and 8." << endl;
                break;
            }
        }
    } while (choice != 8);

    return 0;
}
