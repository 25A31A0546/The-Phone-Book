# The-Phone-Book
The Phone Book (C++)

Overview

This project is a simple Phone Book Application implemented in C++ using a singly linked list.
It allows the user to store and manage contacts through a menu-driven program in the terminal.

The goal of this project was to practice data structures, pointers, and file handling in C++.

---

Features

The application supports the following operations:

- Add a new contact
- Display all saved contacts
- Search for a contact by name
- Delete a contact
- Update an existing contact
- Store contacts permanently using a file

All contacts are saved in a file called contacts.txt, so the data remains even after the program closes.

---

Data Structure Used

This project uses a Singly Linked List.

Each contact is stored as a node containing:

- Name
- Phone number
- Pointer to the next contact

Example representation:

Head → [Name | Phone] → [Name | Phone] → [Name | Phone] → NULL

---

How the Program Works

1. When the program starts, it reads the contacts from contacts.txt.
2. The contacts are loaded into a linked list in memory.
3. The user interacts with the program using a menu.
4. Whenever a contact is added, updated, or deleted, the file is updated.

---

How to Compile

Use the following command in the terminal:

g++ phonebook.cpp -o phonebook

---

How to Run

After compiling, run the program using:

./phonebook

---

Example Menu

----- PHONE BOOK -----

1. Add Contact
2. Display Contacts
3. Search Contact
4. Delete Contact
5. Update Contact
6. Exit

---

Concepts Practiced

This project helped practice:

- Linked Lists
- Pointers
- Dynamic Memory Allocation
- File Handling in C++
- Menu-Driven Programs

---

Future Modififications
1- input validation for phone numbers for only 10 numbers
etc

----
Author

Bhaskar Moreboina

First Year CSE Student
