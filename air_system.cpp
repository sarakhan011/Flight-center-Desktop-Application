#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct UserInfo {
    string username, password;
};

const int totalSeats = 50;
int availableSeats[] = {15, 13, 7};

const string departureTimes[] = {"1pm", "4pm", "5pm"};

// Function prototypes
void displayFlights();
int getFlightSelection();
void displaySeatAvailability(int flightIndex);
void getSeatSelections(int numSeats, int* selectedSeats);
void updateSeatAvailabilityFile();
void bookSeats(int flightIndex, int numSeats, int* selectedSeats);
void registerUser(const UserInfo& user);
bool authenticateUser(const string& enteredUsername, const string& enteredPassword);
void processPayment(double amount, const string& creditCardNumber);
void makeReservation(int selectedFlight);

int main() {
    cout << "------WELCOME TO PAKISTAN INTERNATIONAL AIRLINE (PIA)\n";

    UserInfo newUser;
    cout << "Registration :)\nEnter username: ";
    cin >> newUser.username;
    cout << "Enter password: ";
    cin >> newUser.password;

    registerUser(newUser);

    cout << "Thanks for your cooperation. Registration completed.\n";

    string enteredUsername, enteredPassword;

    cout << "\nAuthentication\nEnter username: ";
    cin >> enteredUsername;

    cout << "Enter password: ";
    cin >> enteredPassword;

    if (authenticateUser(enteredUsername, enteredPassword)) {

        cout << "Authentication successful! Access granted.\n";

        displayFlights();

        int selectedFlight = getFlightSelection();

        if (selectedFlight >= 1 && selectedFlight <= 3) {

            cout << "You selected:\n";

            switch (selectedFlight) {

            case 1:
                cout << "Lahore\nDeparture Time: " << departureTimes[0] << endl;
                break;

            case 2:
                cout << "Karachi\nDeparture Time: " << departureTimes[1] << endl;
                break;

            case 3:
                cout << "Islamabad\nDeparture Time: " << departureTimes[2] << endl;
                break;
            }
            displaySeatAvailability(selectedFlight);

            makeReservation(selectedFlight);

        } else {
            cout << "Invalid choice.\n";
        }

    } else {

        cout << "Authentication failed!\n";

    }

    return 0;
}

void displayFlights() {
    cout << "\nAvailable Flights\n";
    cout << "1. Lahore\n";
    cout << "2. Karachi\n";
    cout << "3. Islamabad\n";
}

int getFlightSelection() {

    int choice;

    cout << "Enter destination (1-3): ";
    cin >> choice;

    return choice;
}

void displaySeatAvailability(int flightIndex) {

    cout << "\nTotal Seats: " << totalSeats << endl;
    cout << "Available Seats: " << availableSeats[flightIndex - 1] << endl;

}

void getSeatSelections(int numSeats, int* selectedSeats) {

    cout << "Enter seat numbers:\n";

    for (int i = 0; i < numSeats; i++) {

        cout << "Seat " << i + 1 << ": ";
        cin >> selectedSeats[i];

    }

}

void updateSeatAvailabilityFile() {

    ofstream outFile("seat_availability.txt");

    for (int i = 0; i < 3; i++) {

        outFile << availableSeats[i] << endl;

    }

    outFile.close();

}

void bookSeats(int flightIndex, int numSeats, int* selectedSeats) {

    for (int i = 0; i < numSeats; i++) {

        if (selectedSeats[i] >= 1 &&
            selectedSeats[i] <= totalSeats &&
            availableSeats[flightIndex - 1] > 0) {

            availableSeats[flightIndex - 1]--;

            cout << "Seat " << selectedSeats[i]
                 << " booked successfully.\n";

        } else {

            cout << "Invalid seat or no seats available.\n";
            return;

        }

    }

}

void registerUser(const UserInfo& user) {

    ofstream outFile("user_info.txt", ios::app);

    if (outFile.is_open()) {

        outFile << user.username << " "
                << user.password << endl;

        cout << "User registered successfully.\n";

        outFile.close();

    } else {

        cout << "Unable to open file.\n";

    }

}

bool authenticateUser(const string& enteredUsername,
                      const string& enteredPassword) {

    ifstream inFile("user_info.txt");

    UserInfo user;

    while (inFile >> user.username >> user.password) {

        if (enteredUsername == user.username &&
            enteredPassword == user.password) {

            inFile.close();
            return true;

        }

    }

    inFile.close();

    return false;

}

void processPayment(double amount,
                    const string& creditCardNumber) {

    if (creditCardNumber.length() == 16) {

        cout << "\nProcessing payment of $"
             << amount << endl;

        cout << "Payment Successful!\n";

    } else {

        cout << "Invalid Credit Card Number.\n";

    }

}

void makeReservation(int selectedFlight) {

    int option;

    cout << "\n1. Book Seats\n";
    cout << "2. Exit\n";
    cout << "Enter option: ";

    cin >> option;

    if (option == 1) {

        int numSeats;

        cout << "Enter number of seats: ";
        cin >> numSeats;

        vector<int> selectedSeats(numSeats);

        getSeatSelections(numSeats, selectedSeats.data());

        bookSeats(selectedFlight, numSeats, selectedSeats.data());

        updateSeatAvailabilityFile();

        double totalAmount = 500.0;

        string creditCardNumber;

        cout << "\nTotal Amount: $"
             << totalAmount * numSeats << endl;

        cout << "Enter 16-digit credit card number: ";

        cin >> creditCardNumber;

        processPayment(totalAmount * numSeats,
                       creditCardNumber);

    }
    else if (option == 2) {

        cout << "Exiting...\n";

    }
    else {

        cout << "Invalid option.\n";

    }

}