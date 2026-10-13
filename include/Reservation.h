#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {

private:
    std::string reservationID;  
    std::string studentID;            
    std::string studentName; 
    std::string resourceID;    
    std::string date;

public: 
    Reservation();

    Reservation(std::string reservationID,
                std::string studentID,
                std::string studentName,
                std::string resourceID,
                std::string date);

    std::string getReservation() const;
    std::string getStudentID() const;
    std::string getStudentName() const;
    std::string getResourceID() const;
    std::string getDate() const;
    
    void display() const;

};

#endif
