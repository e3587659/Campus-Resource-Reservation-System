//
// Created by mike on 9/16/26.
//

#include "../include/Reservation.h"

Reservation::Reservation(std::string reservationID,
                         std::string studentID,        
                         std::string studentName, 
                         std::string resourceID,   
                         std::string date) {

    this->reservationID = reservationID;
    this->studentID = studentID;
    this->studentName = studentName;
    this->resourceID = resourceID;
    this->date = date;
} 

std::string Reservation::getReservation() {
    return reservationID;
}
                
std::string Reservation::getStudentID() {
    return studentID;
}

std::string Reservation::getStudentName() {
    return studentName;
}

std::string Reservation::getResourceID() {
    return resourceID;
}

std::string Reservation::getDate() {
    return date;
}

