#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// structure for each contact
struct Contact
{
    string name;
    string phone;
    Contact* next;
};

// head pointer of linked list
Contact* head = NULL;

// --------------------------------
// Load contacts from file
// --------------------------------
void loadFromFile()
{
    ifstream file("contacts.txt");

    string name, phone;

    while(file >> name >> phone)
    {
        Contact* newNode = new Contact;

        newNode->name = name;
        newNode->phone = phone;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Contact* temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    file.close();
}

// --------------------------------
// Save contacts to file
// --------------------------------
void saveToFile()
{
    ofstream file("contacts.txt");

    Contact* temp = head;

    while(temp != NULL)
    {
        file << temp->name << " " << temp->phone << endl;
        temp = temp->next;
    }

    file.close();
}

// --------------------------------
// Add new contact
// --------------------------------
void addContact()
{
    string name, phone;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Phone Number: ";
    cin >> phone;

    Contact* newNode = new Contact;

    newNode->name = name;
    newNode->phone = phone;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Contact* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    saveToFile();

    cout << "Contact added successfully\n";
}

// --------------------------------
// Display all contacts
// --------------------------------
void displayContacts()
{
    if(head == NULL)
    {
        cout << "Phonebook is empty\n";
        return;
    }

    Contact* temp = head;

    cout << "\nContacts:\n";

    while(temp != NULL)
    {
        cout << "Name : " << temp->name << endl;
        cout << "Phone: " << temp->phone << endl;
        cout << "-----------------\n";

        temp = temp->next;
    }
}

// --------------------------------
// Search contact
// --------------------------------
void searchContact()
{
    string name;

    cout << "Enter name to search: ";
    cin >> name;

    Contact* temp = head;

    while(temp != NULL)
    {
        if(temp->name == name)
        {
            cout << "Contact found\n";
            cout << "Name : " << temp->name << endl;
            cout << "Phone: " << temp->phone << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Contact not found\n";
}

// --------------------------------
// Delete contact
// --------------------------------
void deleteContact()
{
    string name;

    cout << "Enter name to delete: ";
    cin >> name;

    Contact* temp = head;
    Contact* prev = NULL;

    while(temp != NULL)
    {
        if(temp->name == name)
        {
            if(prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;

            saveToFile();

            cout << "Contact deleted\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Contact not found\n";
}

// --------------------------------
// Update contact
// --------------------------------
void updateContact()
{
    string name;

    cout << "Enter name to update: ";
    cin >> name;

    Contact* temp = head;

    while(temp != NULL)
    {
        if(temp->name == name)
        {
            cout << "Enter new phone number: ";
            cin >> temp->phone;

            saveToFile();

            cout << "Contact updated successfully\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Contact not found\n";
}

// --------------------------------
// Main program
// --------------------------------
int main()
{
    loadFromFile();

    int choice;

    do
    {
        cout << "\n------ PHONE BOOK ------\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Update Contact\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                deleteContact();
                break;

            case 5:
                updateContact();
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 6);

    return 0;
}
