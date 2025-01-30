#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// Structure to hold ticket attributes
struct Ticket {
    string fullName;
    string gender;
    string from;
    string destination;
    string travelDate;
    string travelClass;
    string contactInfo;
    string seat;
};

// Function to check if a ticket exists for a given full name
void checkTicket(const string& fullName) {
    ifstream file("tickets.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(fullName) != string::npos) {
            found = true;
            cout << "Ticket Details:\n";
            cout << line << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Ticket not found for " << fullName << "\n";
    }
}

// Function to book a new ticket
void bookTicket() {
    Ticket ticket;

    cout << "Enter Full Name: ";
    getline(cin >> ws, ticket.fullName);
    cout << "Enter Gender: ";
    getline(cin >> ws, ticket.gender);
    cout << "Enter From: ";
    getline(cin >> ws, ticket.from);
    cout << "Enter Destination: ";
    getline(cin >> ws, ticket.destination);
    cout << "Enter Travel Date: ";
    getline(cin >> ws, ticket.travelDate);
    cout << "Choose Class (1. First Class, 2. Second Class, 3. Regular Class): ";
    int classChoice;
    cin >> classChoice;
    switch (classChoice) {
        case 1:
            ticket.travelClass = "First Class";
            break;
        case 2:
            ticket.travelClass = "Second Class";
            break;
        case 3:
            ticket.travelClass = "Regular Class";
            break;
        default:
            cout << "Invalid class choice. Defaulting to Regular Class.\n";
            ticket.travelClass = "Regular Class";
            break;
    }
    cout << "Enter Contact Information: ";
    getline(cin >> ws, ticket.contactInfo);
    ticket.seat = "A1";

    // Save the ticket information to a file
    ofstream file("tickets.txt", ios::app);
    file << "Name: " << ticket.fullName << ", Gender: " << ticket.gender << ", From: " << ticket.from
         << ", Destination: " << ticket.destination << ", Travel Date: " << ticket.travelDate
         << ", Class: " << ticket.travelClass << ", Contact Info: " << ticket.contactInfo
         << ", Seat: " << ticket.seat << "\n";
    file.close();

    // Display confirmation message
    cout << "\nTicket booked successfully!\n";
    cout << "Confirmation:\n";
    cout << "Name: " << ticket.fullName << "\n";
    cout << "Gender: " << ticket.gender << "\n";
    cout << "From: " << ticket.from << "\n";
    cout << "Destination: " << ticket.destination << "\n";
    cout << "Travel Date: " << ticket.travelDate << "\n";
    cout << "Class: " << ticket.travelClass << "\n";
    cout << "Contact Info: " << ticket.contactInfo << "\n";
    cout << "Seat: " << ticket.seat << "\n";
}

int main() {
    int choice;

    cout << "Welcome \n"; // Display welcome message

    do {
        cout << "Airline Ticket System\n";
        cout << "1. Check Ticket\n";
        cout << "2. Book New Ticket\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Ignore any remaining characters in the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                string fullName;
                cout << "Enter Full Name: ";
                getline(cin >> ws, fullName);
                checkTicket(fullName);
                break;
            }
            case 2:
                bookTicket();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}