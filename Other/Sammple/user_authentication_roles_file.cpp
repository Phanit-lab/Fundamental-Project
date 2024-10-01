#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Constants
const int MAX_USERS = 100;
const int USERNAME_SIZE = 30;
const int PASSWORD_SIZE = 30;
const int ROLE_SIZE = 20;

// User structure
struct User {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    char role[ROLE_SIZE];
};

// Function to add a new user
void addUser(User users[], int& userCount, const string& filename) {
    if (userCount >= MAX_USERS) {
        cout << "User list is full!" << endl;
        return;
    }

    cout << "Enter username: ";
    cin.ignore();
    cin.getline(users[userCount].username, USERNAME_SIZE);

    cout << "Enter password: ";
    cin.getline(users[userCount].password, PASSWORD_SIZE);

    cout << "Enter role (Admin/User): ";
    cin.getline(users[userCount].role, ROLE_SIZE);

    userCount++;

    // Write to binary file
    ofstream file(filename, ios::binary | ios::app); // Append to the file
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(&users[userCount - 1]), sizeof(User));
        file.close();
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

// Function to authenticate user
bool authenticateUser(const User users[], int userCount, User& loggedInUser) {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];

    cout << "Enter username: ";
    cin.ignore();
    cin.getline(username, USERNAME_SIZE);

    cout << "Enter password: ";
    cin.getline(password, PASSWORD_SIZE);

    // Search for the user
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            loggedInUser = users[i];
            cout << "Login successful! Role: " << loggedInUser.role << endl;
            return true;
        }
    }
    cout << "Login failed! Incorrect username or password." << endl;
    return false;
}

// Function to display role-specific actions
void roleBasedAccess(const User& user) {
    if (strcmp(user.role, "Admin") == 0) {
        cout << "Welcome, Admin! You have full access." << endl;
        // Admin-specific actions
    } else if (strcmp(user.role, "User") == 0) {
        cout << "Welcome, User! You have limited access." << endl;
        // User-specific actions
    } else {
        cout << "Unknown role!" << endl;
    }
}

// Function to display all users (for Admin)
void displayUsers(const User users[], int userCount) {
    cout << "User Accounts: " << endl;
    for (int i = 0; i < userCount; i++) {
        cout << "Username: " << users[i].username
             << ", Role: " << users[i].role << endl;
    }
}

// Main menu
void menu(User users[], int& userCount, const string& filename) {
    int choice;
    User loggedInUser;

    do {
        cout << "\nUser Authentication System:\n";
        cout << "1. Add User (Admin Only)\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (authenticateUser(users, userCount, loggedInUser) && strcmp(loggedInUser.role, "Admin") == 0) {
                addUser(users, userCount, filename);
            } else {
                cout << "Only Admins can add users!" << endl;
            }
            break;
        case 2:
            if (authenticateUser(users, userCount, loggedInUser)) {
                roleBasedAccess(loggedInUser);
                // For example, an admin can view all users
                if (strcmp(loggedInUser.role, "Admin") == 0) {
                    displayUsers(users, userCount);
                }
            }
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    string filename = "users.dat";

    // Load users from the binary file
    loadUsers(users, userCount, filename);

    // Display menu
    menu(users, userCount, filename);

    return 0;
}
