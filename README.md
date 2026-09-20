# Campus-Resource-Reservation-System
CSCE 2110 Project 1 - Campus Resource Reservation System

Individual Contributions:

| Team Member - Mia Mendez
| Component(s) - Resource Management
| Specific Tasks Completed - Coding the resource class and file loading 
| Testing/Debugging -  Tested code and checked the structure 
| GitHub Contributions - Made resource management branch, added to resource code files and merged branch into main

Mia Mendez: Designed the resource management end of the Milestone 1 project. This included developing the resource class to help sort individual inventory items and the reservation manager class to help organize them. With these classes created, they allowed me to store and load data from campus inventory from text files. For resource management, I created a feature branch specifically for it, wrote the code for each part, and then merged the feature branch into the main branch to allow that work to be shown in the main repository.

| Team Member - Mike Romero
| Component(s) - Reservation
| Specific Tasks Completed - Created the Reservation class, linked list, reservation validation, and reservation file loading
| Testing/Debugging -  Tested adding, searching, removing, validating, and displaying active reservations 
| GitHub Contributions - Created reservation feature branch, made commits, tested changes, and merged branch into main

Mike Romero: Worked on the reservation management portion of the Milestone 1 project. I created the Reservation class and set up the linked list used to keep track of reservations. I added the ability to read the reservation information from the text file provided, add new reservations, search for them, and remove them. I also added checks to prevent duplicate reservation IDs and conflictinh reservations, as well as a check to make sure selected resources are available. I also tested and merged my changes into the main repository. 

| Team Member - Marvelous 
| Component(s) - Waitinglist and Cancellation 
| Specific Tasks Completed - Organized the process of resource requests during contention, enable "Undo" to restore for the most recent cancellation, Linked Queue FIFO, and Linked Stack LIFO
| Testing/Debugging -  Tested queue FIFO ordering and auto-assignments upon cancellations, verified stack LIFO undo/restore limits, and debugged edge cases like empty state operations, invalid IDs, and dynamic memory leaks using Valgrind.
| GitHub Contributions - Created the line system (queue) for waiting lists and the undo stack for cancellations, connected them to auto-assign resources, fixed bugs, and cleaned up memory leaks.

Marvelous Ojeh: I built the waiting line (queue) and undo stack, connected them to auto-assign resources when freed, prevented crash bugs, and cleaned up memory leaks.
