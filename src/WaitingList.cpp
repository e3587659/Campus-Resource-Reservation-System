#include "WaitingList.h"

WaitingList::WaitingList() : front(nullptr), rear(nullptr) {}

WaitingList::~WaitingList() {
    while (front) {
        QueueNode* temp = front;
        front = front->next;
        delete temp;
    }
}

void WaitingList::enqueue(const std::string& studentID, const std::string& studentName) {
    QueueNode* newNode = new QueueNode(studentID, studentName);
    if (!rear) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

bool WaitingList::dequeue(std::string& studentID, std::string& studentName) {
    if (!front) return false;
    
    QueueNode* temp = front;
    studentID = temp->studentID;
    studentName = temp->studentName;
    
    front = front->next;
    if (!front) rear = nullptr;
    
    delete temp;
    return true;
}

bool WaitingList::isEmpty() const { return front == nullptr; }

void WaitingList::display() const {
    if (isEmpty()) {
        std::cout << "  [Empty]\n";
        return;
    }
    QueueNode* curr = front;
    int pos = 1;
    while (curr) {
        std::cout << "  " << pos++ << ". " << curr->studentName << " (ID: " << curr->studentID << ")\n";
        curr = curr->next;
    }
}
