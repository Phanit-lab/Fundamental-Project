#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constants
const int MAX_USERS = 100;

// User account structure
struct UserAccount {
    string username;
    string password;
};

// Function to add a user
void addUser(UserAccount users[], int& userCount, const string& filename) {
    if (userCount >= MAX_USERS) {
        cout << "User list is full!" << endl;
        return;
    }

    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    users[userCount].username = username;
    users[userCount].password = password;
    userCount++;

    // Save to file
    ofstream file(filename, ios::app); // Append to the file
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
    } else {
        cout << "Unable to open file for writing!" << endl;
    }
}

// Function to load users from the file
void loadUsers(UserAccount users[], int& userCount, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string username, password;
        userCount = 0;
        while (file >> username >> password && userCount < MAX_USERS) {
            users[userCount].username = username;
            users[userCount].password = password;
            userCount++;
        }
        file.close();
    } else {
        cout << "Unable to open file for reading!" << endl;
    }
}

// Function to display all users
void displayUsers(const UserAccount users[], int userCount) {
    cout << "User Accounts: " << endl;
    for (int i = 0; i < userCount; i++) {
        cout << "Username: " << users[i].username << ", Password: " << users[i].password << endl;
    }
}

// Function to delete a user
void deleteUser(UserAccount users[], int& userCount, const string& filename) {
    string username;
    cout << "Enter username to delete: ";
    cin >> username;

    int index = -1;
    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Remove user by shifting the array
        for (int i = index; i < userCount - 1; i++) {
            users[i] = users[i + 1];
        }
        userCount--;

        // Write updated user list to file
        ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < userCount; i++) {
                file << users[i].username << " " << users[i].password << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file for writing!" << endl;
        }
        cout << "User deleted." << endl;
    } else {
        cout << "User not found!" << endl;
    }
}

// Function to update a user
void updateUser(UserAccount users[], int userCount, const string& filename) {
    string username, newPassword;
    cout << "Enter username to update: ";
    cin >> username;

    int index = -1;
    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Enter new password: ";
        cin >> newPassword;
        users[index].password = newPassword;

        // Write updated user list to file
        ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < userCount; i++) {
                file << users[i].username << " " << users[i].password << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file for writing!" << endl;
        }
        cout << "User updated." << endl;
    } else {
        cout << "User not found!" << endl;
    }
}

// Main menu
void menu(UserAccount users[], int& userCount, const string& filename) {
    int choice;
    do {
        cout << "\nUser Account Management Menu:\n";
        cout << "1. Add User\n";
        cout << "2. Display Users\n";
        cout << "3. Delete User\n";
        cout << "4. Update User\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addUser(users, userCount, filename);
            break;
        case 2:
            displayUsers(users, userCount);
            break;
        case 3:
            deleteUser(users, userCount, filename);
            break;
        case 4:
            updateUser(users, userCount, filename);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
}

int main() {
    UserAccount users[MAX_USERS];
    int userCount = 0;
    string filename = "users.txt";

    // Load users from the file at the start
    loadUsers(users, userCount, filename);

    // Display menu
    menu(users, userCount, filename);

    return 0;
}
