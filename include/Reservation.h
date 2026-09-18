//
// Created by mike on 9/16/26.
//

#include <string>

class Reservation {

private: //variable cannot be accessed from outside the class//
    std::string reservationID;  
    std::string studentID;           
    std::string studentname; 
    std::string resourceID;    
    std::string date;

public: //getter function allows external program to read variable//
    std::string getReservation();
    std::string getStudentID();
    std::string getStudentname();
    std::string getResourceID();
    std::string getDate();

};


