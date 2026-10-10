
// Created by mike on 9/16/26.//

#include "../include/Reservation.h"
#include <iostream>

Reservation::Reservation() {
    reservationID = "";
    studentID = "";
    studentName = "";
    resourceID = "";
    date = "";
}

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

void Reservation::display() const {
    std::cout << getReservation() << std::endl;
    std::cout << getStudentID() << std::endl;
    std::cout << getStudentName() << std::endl;
    std::cout << getResourceID() << std::endl;
    std::cout << getDate() << std::endl;

}