//
// Created by mike on 9/16/26.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include "../include/Reservation.h"

using namespace std;

int main() {

    string reservationID;  
    string studentID;           
    string studentname; 
    string resourceID;    
    string date;

    string line = "301|1001|Alice Smith|R101|09/15/2026";

    stringstream ss(line);

    getline(ss, reservationID, '|');
    getline(ss, studentID, '|');
    getline(ss, studentname, '|');
    getline(ss, resourceID, '|');
    getline(ss, date);

    cout << reservationID << endl;
    cout << studentID << endl;
    cout << studentname << endl;
    cout << resourceID << endl;
    cout << date << endl;
 
}