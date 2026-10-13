
// Created by mike on 9/16/26//

#include "ReservationManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

ReservationManager::ReservationManager() : reservationHead(nullptr) {}

ReservationManager::~ReservationManager() {
    while (reservationHead) {
        ListNode* temp = reservationHead;
        reservationHead = reservationHead->next;
        delete temp;
    }
}

bool ReservationManager::loadResourcesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string id, name, type;
        
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, type, ',');

        if (!id.empty()) {
            resources.push_back(Resource(id, name, type, true));
        }
    }
    file.close();
    return true;
}

void ReservationManager::displayAllResources() const {
    std::cout << "\n--- Campus Resources ---\n";
    for (const auto& r : resources) {
        r.display();
    }
}

Resource* ReservationManager::findResource(const std::string& resourceID) {
    for (auto& r : resources) {
        if (r.getID() == resourceID) return &r;
    }
    return nullptr;
}

bool ReservationManager::reservationExists(const std::string& resID) const {
    ListNode* curr = reservationHead;
    while (curr) {
        if (curr->reservation.getReservationID() == resID) return true;
        curr = curr->next;
    }
    return false;
}

void ReservationManager::createReservation(const std::string& resID, const std::string& stID, 
                                            const std::string& stName, const std::string& rID, 
                                            const std::string& date) {
    Resource* res = findResource(rID);
    if (!res) {
        std::cout << "Error: Invalid Resource ID.\n";
        return;
    }

    if (reservationExists(resID)) {
        std::cout << "Error: Reservation ID already exists.\n";
        return;
    }

    if (!res->getAvailability()) {
        std::cout << "Resource unavailable. Adding " << stName << " to waiting list...\n";
        waitingLists[rID].enqueue(stID, stName);
        std::cout << "Added to waiting list successfully.\n";
        return;
    }

    res->setAvailability(false);
    Reservation newRes(resID, stID, stName, rID, date);
    
    ListNode* newNode = new ListNode(newRes);
    newNode->next = reservationHead;
    reservationHead = newNode;

    std::cout << "Reservation Created Successfully.\n";
}

void ReservationManager::cancelReservation(const std::string& resID) {
    ListNode* curr = reservationHead;
    ListNode* prev = nullptr;

    while (curr && curr->reservation.getReservationID() != resID) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        std::cout << "Error: Reservation ID not found.\n";
        return;
    }

    if (prev) prev->next = curr->next;
    else reservationHead = curr->next;

    Reservation cancelledRes = curr->reservation;
    std::string rID = cancelledRes.getResourceID();
    delete curr;

    historyStack.push(cancelledRes);
    std::cout << "Reservation Cancelled. Added to cancellation history.\n";

    // FIFO assignment from waiting list
    std::string nextStID, nextStName;
    if (waitingLists[rID].dequeue(nextStID, nextStName)) {
        std::cout << "Auto-assigning " << rID << " to next waiting student: " << nextStName << "\n";
        createReservation("AUTO_" + std::to_string(rand() % 900 + 100), nextStID, nextStName, rID, "Auto-Assigned");
    } else {
        Resource* res = findResource(rID);
        if (res) res->setAvailability(true);
    }
}

void ReservationManager::undoCancellation() {
    Reservation restored;
    if (!historyStack.pop(restored)) {
        std::cout << "Error: No cancellations to undo.\n";
        return;
    }

    Resource* res = findResource(restored.getResourceID());
    if (res && res->getAvailability()) {
        res->setAvailability(false);
        ListNode* newNode = new ListNode(restored);
        newNode->next = reservationHead;
        reservationHead = newNode;
        std::cout << "Reservation Restored Successfully.\n";
    } else {
        std::cout << "Cannot restore: Resource is currently occupied.\n";
    }
}

void ReservationManager::displayActiveReservations() const {
    std::cout << "\n--- Active Reservations ---\n";
    if (!reservationHead) {
        std::cout << "No active reservations.\n";
        return;
    }
    ListNode* curr = reservationHead;
    while (curr) {
        curr->reservation.display();
        curr = curr->next;
    }
}

void ReservationManager::displayWaitingLists() const {
    std::cout << "\n--- Waiting Lists ---\n";
    for (const auto& pair : waitingLists) {
        std::cout << "Resource ID " << pair.first << ":\n";
        pair.second.display();
    }
}

void ReservationManager::displayCancellationHistory() const {
    std::cout << "\n--- Cancellation History (Stack Top First) ---\n";
    historyStack.display();
}
