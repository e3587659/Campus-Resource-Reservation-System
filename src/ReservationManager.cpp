
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

void ReservationManager::displayAllReservations() const {

    Node* current = head;

    if (current == nullptr) {
        cout << "No active reservations." << endl;
        return;
    }

    while (current != nullptr) {

        current->data.display();

        cout << endl;

        current = current->next;
    }
}

bool ReservationManager::createReservation(const Reservation& reservation) {

    bool resourceExists = false;

    for (const Resource& resource : resources) {

        if (resource.getId() == reservation.getResourceID()) {

            resourceExists = true;
            
            break;
        }
    }

    if (!resourceExists) {

        return false;
    }

    Node* current = head;

        while (current != nullptr) {

        if (current->data.getReservation() == reservation.getReservation()) {

            return false;
        
        }

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

    //waiting for loadResources to be added 
    //manager.loadResources("/workspaces/Campus-Resource-Reservation-System/data/resources.txt"); 
 
    ifstream file("/workspaces/Campus-Resource-Reservation-System/data/reservations.txt"); 
 
    string line; 
 
    while (getline(file, line)) {
 
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
    }

    cout << "\nActive Reservations:" << endl;
    manager.displayAllReservations();

    return 0;
}