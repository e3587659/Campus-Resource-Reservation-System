//
// Created by mike on 9/16/26.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <vector>
#include "../include/Reservation.h"

using namespace std;

int main() {

    std::string reservationID;  
    std::string studentID;           
    std::string studentname; 
    std::string resourcesID;    
    std::string date;

    string line = "301|1001|Alice Smith|R101|09/15/2026";

    stringstream ss(line);

    getline(ss, reservationID, '|');
    getline(ss, studentID, '|');
    getline(ss, studentname, '|');
    getline(ss, resourcesID, '|');
    getline(ss, date);

    cout << reservationID << endl;
    cout << studentID << endl;
    cout << studentname << endl;
    cout << resourcesID << endl;
    cout << date << endl;
 
}