Milestone 1 - Complexity Analysis

This document outlines the Big-O time and space complexities for each data structure and module

1. Resource Management & File Loading
Time Complexity: O(N) - N (number of records/lines in the resource text file), because the program must read through each entry one by one to load them into memory.
Space Complexity: O(N) to help store the resources in vectors or memory structures.

2. Active Reservations (Linked List)
Insertion (addReservation): O(N) would be used in a worst case scenario to traverse the list and append a new reservation node.
Removal (removeReservation): O(N) time, because you would need to traverse the linked list to locate and delete the node needed.
Space Complexity: O(N)- N (total number of active reservations currently stored in the linked list).

3. Waiting List (Queue)
Enqueue (enqueue):O(1) time (nodes are added directly to the rear pointer).
Dequeue (dequeue):O(1) time (since nodes are removed directly from the front pointer).
Space Complexity:O(M) M can be the number of students who are currently waiting in the queue.

4. Cancellation History (Stack)
Push (push):O(1) time (cancelled reservations are pushed directly onto the top of the stack).
Pop / Undo (pop):O(1) time (Most recently cancelled reservation is retrieved and removed from the top
Space Complexity:O(K)- K (number of stored cancellations in the stack history).
