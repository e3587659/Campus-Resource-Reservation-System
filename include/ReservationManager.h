//
// Created by mike on 9/16/26.
//

#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <string>
#include "Reservation.h"

class ReservationManager {

    private:
        struct Node {

            Reservation data;

            Node* next;
        };
        Node* head;
    
    public:
        ReservationManager();

        void addReservation(const Reservation& reservation);

        void displayReservation(const std::string& reservationID);

        bool removeReservation(const std::string& reservationID);

};

#endif