#include "CancellationHistory.h"

CancellationHistory::CancellationHistory() : top(nullptr) {}

CancellationHistory::~CancellationHistory() {
    while (top) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

void CancellationHistory::push(const Reservation& res) {
    StackNode* newNode = new StackNode(res);
    newNode->next = top;
    top = newNode;
}

bool CancellationHistory::pop(Reservation& restoredRes) {
    if (!top) return false;
    
    StackNode* temp = top;
    restoredRes = temp->reservation;
    top = top->next;
    delete temp;
    return true;
}

bool CancellationHistory::isEmpty() const { return top == nullptr; }

void CancellationHistory::display() const {
    if (isEmpty()) {
        std::cout << "  No cancelled reservations in history.\n";
        return;
    }
    StackNode* curr = top;
    while (curr) {
        std::cout << "  ";
        curr->reservation.display();
        curr = curr->next;
    }
}
