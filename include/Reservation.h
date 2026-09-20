#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {

private: //variable cannot be accessed from outside the class//
    std::string reservationID;  
    std::string studentID;           
    std::string studentName; 
    std::string resourceID;    
    std::string date;

public: 
    //constructor created a reservation using the information provided//
    Reservation(std::string reservationID,
                std::string studentID,
                std::string studentName,
                std::string resourceID,
                std::string date);

    //getter function allows external program to read variable//
    std::string getReservation() const;
    std::string getStudentID() const;
    std::string getStudentName() const;
    std::string getResourceID() const;
    std::string getDate() const;
    
    void display() const;

};

#endif

