#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Constants
const int MAX_USERS = 100;

// User structure
struct User {
    char username[50];
    char password[50];
};

// Function to register a new user
void registerUser(User users[], int& userCount, const string& filename) {
    if (userCount >= MAX_USERS) {
        cout << "User limit reached!" << endl;
        return;
    }

    User newUser;
    cout << "Enter username: ";
    cin.ignore(); // Clear any newline character from previous input
    cin.getline(newUser.username, 50);
    cout << "Enter password: ";
    cin.getline(newUser.password, 50);

    // Add the new user to the array
    users[userCount] = newUser;
    userCount++;

    // Append the new user to the binary file
    ofstream file(filename, ios::binary | ios::app); // Append mode
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(&newUser), sizeof(User));
        file.close();
        cout << "User registered successfully!" << endl;
    } else {
        cout << "Unable to open file for writing!" << endl;
    }
}

// Function to load users from the binary file
void loadUsers(User users[], int& userCount, const string& filename) {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        userCount = 0;
        while (file.read(reinterpret_cast<char*>(&users[userCount]), sizeof(User)) && userCount < MAX_USERS) {
            userCount++;
        }
        file.close();
    } else {
        cout << "Unable to open file for reading!" << endl;
    }
}

// Function to authenticate a user
bool authenticateUser(const User users[], int userCount) {
    char inputUsername[50];
    char inputPassword[50];

    cout << "Enter username: ";
    cin.ignore();
    cin.getline(inputUsername, 50);
    cout << "Enter password: ";
    cin.getline(inputPassword, 50);

    // Check credentials
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, inputUsername) == 0 && strcmp(users[i].password, inputPassword) == 0) {
            return true; // Authentication successful
        }
    }
    return false; // Authentication failed
}

// Function to display all users (for debugging purposes)
void displayUsers(const User users[], int userCount) {
    cout << "Registered Users:" << endl;
    for (int i = 0; i < userCount; i++) {
        cout << "Username: " << users[i].username << ", Password: " << users[i].password << endl;
    }
}

// Main menu for user management and authentication
void menu(User users[], int& userCount, const string& filename) {
    int choice;
    do {
        cout << "\n System Menu:\n";
        cout << "1. Register User\n";
        cout << "2. login User\n";
        cout << "3. Display All Users (for debugging)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser(users, userCount, filename);
            break;
        case 2:
            if (authenticateUser(users, userCount)) {
                cout << "Authentication successful!" << endl;
            } else {
                cout << "Invalid username or password!" << endl;
            }
            break;
        case 3:
            displayUsers(users, userCount); // Only for debugging, you can remove this in a real application
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    string filename = "users.dat";

    // Load users from the binary file at the start
    loadUsers(users, userCount, filename);

    // Display menu for user registration and authentication
    menu(users, userCount, filename);

    return 0;
}
