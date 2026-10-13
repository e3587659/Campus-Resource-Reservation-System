#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <string>
#include <vector>
#include "Reservation.h"
#include "Resource.h"
#include "WaitingList.h"

class ReservationManager {

    private:
        struct Node {

            Reservation data;

            Node* next;
        };

        Node* head;

        std::vector<Resource> resources;
        WaitingList waitingQueue;
    
    public:
        ReservationManager();

        ~ReservationManager();

        void addReservation(const Reservation& reservation);

        bool createReservation(const Reservation& reservation);
    
        void displayReservation(const std::string& reservationID);

        void displayAllReservations() const;

        bool removeReservation(const std::string& reservationID,
            Reservation& cancelledReservation);

        void loadResources(const std::string& filename);

        void displayAllResources() const;

        const std::vector<Resource>& getResources() const;
};

#endif
