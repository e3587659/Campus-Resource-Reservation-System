#include <iostream>
#include <cassert>
#include "WaitingList.h"
#include "Cancellation.h"

void testWaitingListQueue() {
    std::cout << "[RUNNING TEST] Waiting List (Queue FIFO Operations)... ";
    WaitingList list;
    
    assert(list.isEmpty());

    // Enqueue items
    list.enqueue("1001", "Alice");
    list.enqueue("1002", "Bob");
    assert(!list.isEmpty());

    // Dequeue items in FIFO order
    std::string id, name;
    bool success = list.dequeue(id, name);
    assert(success && id == "1001" && name == "Alice");

    success = list.dequeue(id, name);
    assert(success && id == "1002" && name == "Bob");
    assert(list.isEmpty());

    // Test underflow state
    success = list.dequeue(id, name);
    assert(!success);

    std::cout << "PASSED!\n";
}

void testCancellationHistoryStack() {
    std::cout << "[RUNNING TEST] Cancellation History (Stack LIFO Operations)... ";
    CancellationHistory stack;

    assert(stack.isEmpty());

    // Push dummy reservations
    Reservation r1("RES01", "1001", "Alice", "R101", "2026-10-12");
    Reservation r2("RES02", "1002", "Bob", "R102", "2026-10-13");

    stack.push(r1);
    stack.push(r2);

    // Pop top item (LIFO order -> r2 first)
    Reservation restored;
    bool success = stack.pop(restored);
    assert(success && restored.getReservation() == "RES02");

    success = stack.pop(restored);
    assert(success && restored.getReservation() == "RES01");
    assert(stack.isEmpty());

    // Test empty pop underflow state
    success = stack.pop(restored);
    assert(!success);

    std::cout << "PASSED!\n";
}

int main() {
    std::cout << "========================================\n";
    std::cout << "   CAMPUS SYSTEM MODULE UNIT TESTS     \n";
    std::cout << "========================================\n";

    testWaitingListQueue();
    testCancellationHistoryStack();

    std::cout << "\nAll unit tests completed successfully!\n";
    return 0;
}
