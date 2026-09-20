
// Created by mike on 9/16/26//

#include <iostream> 
#include <fstream>  
#include <string>   
#include <sstream>
#include "../include/ReservationManager.h"

using namespace std;

//starts the linked list as empty//
ReservationManager::ReservationManager() {
    head = nullptr;
}

//adds reservation to linked list//
void ReservationManager::addReservation(const Reservation& reservation) {

    //creates new node to store reservation//
    Node* newNode = new Node{reservation, nullptr};

    //if list is empty, it moved the new node to first//
    if (head == nullptr) {
        head = newNode;
        return;

    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;

    }

    current->next =newNode;

}

//searched link list for a reservation//
void ReservationManager::displayReservation(const std::string& reservationID) {
    Node* current = head;

    while(current != nullptr) {

        if (current->data.getReservation() == reservationID) {
            cout << current->data.getReservation() << endl;
            cout << current->data.getStudentID() << endl;
            cout << current->data.getStudentName() << endl;
            cout << current->data.getResourceID() << endl;
            cout << current->data.getDate() << endl;

            return;
        
        }

        current = current->next;

    }

    cout << "Reservation not found." << endl;

}

bool ReservationManager::createReservation(const Reservation& reservation) {

    Node* current = head;

        while (current != nullptr) {

        //checks for same resource on same date//
        if (current->data.getResourceID() == reservation.getResourceID() &&
            current->data.getDate() == reservation.getDate()) {

            return false;
        }

        current = current->next;
    }

    //if no conflict is found, adds reservation//
    addReservation(reservation);

    return true;

}

//removes reservation from link list//
bool ReservationManager::removeReservation(const std::string& reservationID) {
    
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {

        if (current->data.getReservation() == reservationID) {

            if (previous == nullptr) {
                head = current->next;

            }

            else {

                previous->next = current->next;
                
            }

            delete current;
            return true;

        }

        previous = current;
        current = current->next;

    }

        return false;

}

int main() {

    ReservationManager manager;

    ifstream file("/workspaces/Campus-Resource-Reservation-System/data/reservations.txt");

    string line;

    while (getline(file, line)) { //Reads each reservation from the file and splits into its individual//

        string reservationID;
        string studentID;
        string studentName;
        string resourceID;
        string date;

        stringstream ss(line);
     
        getline(ss, reservationID, '|');   
        getline(ss, studentID, '|');
        getline(ss, studentName, '|');
        getline(ss, resourceID, '|');
        getline(ss, date);

        //creates reservation from information read//
        Reservation reservation(reservationID,
                                studentID,
                                studentName,
                                resourceID,
                                date);
        
        //adds reservation to linked list//
        manager.addReservation(reservation);

        //test the reservation using getters// 
            // cout << reservation.getReservation() << endl;
            // cout << reservation.getStudentID() << endl;
            // cout << reservation.getStudentName() << endl;
            // cout << reservation.getResourceID() << endl;
            // cout << reservation.getDate() << endl;

    }

    //test creating a new reservation//
    Reservation newReservation("321", "1021", "Mike", "R999", "09/20/2026");

    if (manager.createReservation(newReservation)) {
        cout << "New reservation created successfully." << endl;
    }
    else {
        cout << "Reservation conflict." << endl;
        }

        manager.displayReservation("321");

    //test removal//
    cout << "\nRemoving reservation 303:" << endl;

    if (manager.removeReservation("303")) {
        cout << "Reservation removed successfully." << endl;
    }
    else {
        cout << "Reservation not found." << endl;
    }

    //test search after removal//
    cout << "\nSearching for reservation 303 after removal:" << endl;
    manager.displayReservation("303");
    //test conflicting reservation//
Reservation conflictReservation("322", "1022", "Test", "R999", "09/20/2026");

if (manager.createReservation(conflictReservation)) {
    cout << "New reservation created successfully." << endl;
}
else {
    cout << "Reservation conflict." << endl;
}
}