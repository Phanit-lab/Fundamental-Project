#include <iostream>
using namespace std;

void registerFunction(string name[], string username[], string password[], string id[], int role[], int& index);
void displayFunction(string name[], string username[], string password[], string id[], int role[], int currentcount);

string name[10];
string username[10];
string password[10];
string id[10];
int role[10];

int main() {
    int currentcount = 0;
    int control;

    do {
        cout << "-----Login_Menu-----" << endl;
        cout << "1. Register" << endl;
        cout << "2. Display" << endl;
        cout << "0. Exit" << endl;
        cin >> control;

        switch (control) {
            case 1:
                registerFunction(name, username, password, id, role, currentcount);
                currentcount++; // Increment the count after each registration
                break;

            case 2:
                displayFunction(name, username, password, id, role, currentcount);
                break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please choose again." << endl;
                break;
        }
    } while (control != 0);

    return 0;
}

void registerFunction(string name[], string username[], string password[], string id[], int role[], int& index) {
    cout << "----Register_Menu-------" << endl;
    cout << "  Name: ";
    cin >> name[index];
    cout << "  Username: ";
    cin >> username[index];
    cout << "  Password: ";
    cin >> password[index];
    cout << "  ID: ";
    cin >> id[index];
    cout << "  Role:" << endl;
    cout << "  1. Admin" << endl;
    cout << "  2. Player " << endl;
    cin >> role[index];
}

void displayFunction(string name[], string username[], string password[], string id[], int role[], int currentcount) {
    for (int i = 0; i < currentcount; i++) {
        cout << "-----User_" << name[i] << "-----" << endl;
        cout << "  Name: " << name[i] << endl;
        cout << "  Username: " << username[i] << endl;
        cout << "  Password: " << password[i] << endl;
        cout << "  ID: " << id[i] << endl;
        if (role[i] == 1) {
            cout << "  Role: Admin" << endl;
        } else if (role[i] == 2) {
            cout << "  Role: Player" << endl;
        } else {
            cout << "  Role: Unknown" << endl;
        }
    }
}
