#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <string>
#include <iostream>

struct QueueNode {
    std::string studentID;
    std::string studentName;
    QueueNode* next;
    QueueNode(std::string sID, std::string sName) 
        : studentID(sID), studentName(sName), next(nullptr) {}
};

class WaitingList {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    WaitingList();
    ~WaitingList();

    void enqueue(const std::string& studentID, const std::string& studentName);
    bool dequeue(std::string& studentID, std::string& studentName);
    bool isEmpty() const;
    void display() const;
};

#endif
