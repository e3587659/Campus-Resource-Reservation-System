#ifndef CANCELLATIONHISTORY_H
#define CANCELLATIONHISTORY_H

#include "Reservation.h"

struct StackNode {
    Reservation reservation;
    StackNode* next;
    StackNode(const Reservation& res) : reservation(res), next(nullptr) {}
};

class CancellationHistory {
private:
    StackNode* top;

public:
    CancellationHistory();
    ~CancellationHistory();

    void push(const Reservation& res);
    bool pop(Reservation& restoredRes);
    bool isEmpty() const;
    void display() const;
};

#endif
