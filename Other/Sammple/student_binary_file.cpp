#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constants
const int MAX_STUDENTS = 100;

// Student structure
struct Student {
    int id;
    char name[50];
    float grade;
};

// Function to add a student
void addStudent(Student students[], int& studentCount, const string& filename) {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student list is full!" << endl;
        return;
    }

    cout << "Enter student ID: ";
    cin >> students[studentCount].id;
    cin.ignore();  // Ignore newline after ID input
    cout << "Enter student name: ";
    cin.getline(students[studentCount].name, 50);
    cout << "Enter student grade: ";
    cin >> students[studentCount].grade;

    // Increment student count
    studentCount++;

    // Save to binary file
    ofstream file(filename, ios::binary | ios::app); // Append to the binary file
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(&students[studentCount - 1]), sizeof(Student));
        file.close();
    } else {
        cout << "Unable to open file for writing!" << endl;
    }
}

// Function to load students from the binary file
void loadStudents(Student students[], int& studentCount, const string& filename) {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        studentCount = 0;
        while (file.read(reinterpret_cast<char*>(&students[studentCount]), sizeof(Student)) && studentCount < MAX_STUDENTS) {
            studentCount++;
        }
        file.close();
    } else {
        cout << "Unable to open file for reading!" << endl;
    }
}

// Function to display all students
void displayStudents(const Student students[], int studentCount) {
    cout << "Student List: " << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Grade: " << students[i].grade << endl;
    }
}

// Function to delete a student
void deleteStudent(Student students[], int& studentCount, const string& filename) {
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Remove student by shifting the array
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;

        // Write updated student list to the binary file
        ofstream file(filename, ios::binary | ios::trunc); // Overwrite the file
        if (file.is_open()) {
            for (int i = 0; i < studentCount; i++) {
                file.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
            }
            file.close();
        } else {
            cout << "Unable to open file for writing!" << endl;
        }
        cout << "Student deleted." << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

// Function to update a student
void updateStudent(Student students[], int studentCount, const string& filename) {
    int id;
    cout << "Enter student ID to update: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Enter new name: ";
        cin.ignore();
        cin.getline(students[index].name, 50);
        cout << "Enter new grade: ";
        cin >> students[index].grade;

        // Write updated student list to the binary file
        ofstream file(filename, ios::binary | ios::trunc); // Overwrite the file
        if (file.is_open()) {
            for (int i = 0; i < studentCount; i++) {
                file.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
            }
            file.close();
        } else {
            cout << "Unable to open file for writing!" << endl;
        }
        cout << "Student updated." << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

// Main menu
void menu(Student students[], int& studentCount, const string& filename) {
    int choice;
    do {
        cout << "\nStudent Management Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students, studentCount, filename);
            break;
        case 2:
            displayStudents(students, studentCount);
            break;
        case 3:
            deleteStudent(students, studentCount, filename);
            break;
        case 4:
            updateStudent(students, studentCount, filename);
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
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    string filename = "students.dat";

    // Load students from the binary file at the start
    loadStudents(students, studentCount, filename);

    // Display menu
    menu(students, studentCount, filename);

    return 0;
}
