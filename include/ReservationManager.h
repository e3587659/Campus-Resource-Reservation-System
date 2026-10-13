#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <vector>
#include <unordered_map>
#include "Resource.h"
#include "Reservation.h"
#include "WaitingList.h"
#include "CancellationHistory.h"

struct ListNode {
    Reservation reservation;
    ListNode* next;
    ListNode(const Reservation& res) : reservation(res), next(nullptr) {}
};

class ReservationManager {
private:
    std::vector<Resource> resources;
    ListNode* reservationHead;
    std::unordered_map<std::string, WaitingList> waitingLists; // Map Resource ID to its Queue
    CancellationHistory historyStack;

public:
    ReservationManager();
    ~ReservationManager();

    bool loadResourcesFromFile(const std::string& filename);
    void displayAllResources() const;
    
    Resource* findResource(const std::string& resourceID);
    bool reservationExists(const std::string& resID) const;

    void createReservation(const std::string& resID, const std::string& stID, 
                           const std::string& stName, const std::string& rID, 
                           const std::string& date);
    
    void cancelReservation(const std::string& resID);
    void undoCancellation();
    
    void displayActiveReservations() const;
    void displayWaitingLists() const;
    void displayCancellationHistory() const;
};

#endif
