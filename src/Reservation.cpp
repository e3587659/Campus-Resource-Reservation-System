
// Created by mike on 9/16/26.//

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

std::string Reservation::getReservation() const {
    return reservationID;
}

std::string Reservation::getStudentID() const {
    return studentID;
}

std::string Reservation::getStudentName() const {
    return studentName;
}

std::string Reservation::getResourceID() const {
    return resourceID;
}

std::string Reservation::getDate() const {
    return date;
}

