//
// Created by mike on 9/16/26
//
#include <iostream> 
#include <fstream>  
#include <string>   
#include <sstream>

using namespace std;

int main() {

    ifstream file("/workspaces/Campus-Resource-Reservation-System/data/reservations.txt");

    string line;

    while (getline(file, line)) { //Reads each reservation from the file and splits into its individual fields

        string reservationID;
        string studentID;
        string studentName;
        string resourceID;
        string date;

        stringstream ss(line);
     
        getline(ss, reservationID, '|');   
        getline(ss, studentID, '|');
        getline(ss, studentName, '|');
        getline(ss, resourceID, '|');
        getline(ss, date, '|');

        cout << reservationID << endl;
        cout << studentID << endl;
        cout << studentName << endl;
        cout << resourceID << endl;
        cout << date << endl;

    }

}