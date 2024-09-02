#include <iostream>

#include "displays.cpp"
using namespace std;
// Color  code

struct User {
  string name;
  int id;
  string username;
  string password;
  string role;
};
// Feature Function
// Login Function
bool login(User user[], string keyName, string keyPassword, int count) {
  for (int i = 0; i < count; i++) {
    if (user[i].username == keyName && user[i].password == keyPassword) {
      return true;
    } else {
      return false;
    }
  }
}

// Add Function (Register)
void addword(string word[], int &currentcout) {
  cout << BRIGHT_BLUE << "---------ADD_WORD--------" << RESET << endl;
  int count;
  cout << "How many words you want to add? : ";
  cin >> count;
  while (cin.fail()) {
    cin.clear();
    cin.ignore();
    cout << "Invalid input. Please enter number: ";
    cin >> count;
  }
  for (size_t i = 0; i < count; i++) {
    cout << "Word [" << currentcout + 1 << "] :";
    cin >> word[currentcout];
    currentcout++;
  }
  cout << GREEN << "ADD Successful!!" << RESET << endl;
}
void addUser(User user[], int &userCount, int maxUsers) {
  int count;
  cout << BRIGHT_BLUE << "---------REGISTER--------" << RESET << endl;
  cout << "How many users do you want to add?: ";
  cin >> count;
  while (cin.fail()) {
    cin.clear();
    cin.ignore();
    cout << "Invalid input. Please enter Number: ";
    cin >> count;
  }
  if (userCount + count > maxUsers) {
    cout << RED << "Error: Adding " << count << " users would exceed the maximum capacity of "
         << maxUsers << " users." << RESET << endl;
    return;
  }
  for (int i = 0; i < count; i++) {
    cout << " Name: ";
    cin >> user[userCount].name;
    cout << " Username: ";
    cin >> user[userCount].username;
    cout << " Password: ";
    cin >> user[userCount].password;
    cout << " ID: ";
    cin >> user[userCount].id;
    cout << " Role: " << endl;
    cout << " 1. Admin" << endl;
    cout << " 2. User" << endl;
    cout << " Choose role: ";
    cin >> user[userCount].role;
    cout << BRIGHT_BLUE << "------------------------" << RESET << endl;
    cout << GREEN << "Register Successful!!" << RESET << endl;
    userCount++;
  }
}

// Display function
void displayWord(string word[], int &currentcout) {
  cout << BRIGHT_BLUE << "=======LIST_WORDS=======" << RESET << endl;
  for (int i = 0; i < currentcout; i++) {
    cout << "[" << i + 1 << "]. " << "Word : " << word[i] << endl;
  }
  cout << GREEN << "Display Successful!!" << RESET << endl;
}
void displayUser(User user[], int count) {
  cout << BRIGHT_BLUE << "=========== USER INFOMATTIONS ==========" << endl;
  cout << "ID\t" << "Name\t  " << "Username\t" << "Role" << endl;
  cout << "========================================" << RESET << endl;
  for (int i = 0; i < count; i++) {
    cout << user[i].id << "\t" << user[i].name << "\t  " << user[i].username << "\t\t"
         << user[i].role << endl;
  }
  cout << BRIGHT_BLUE << "========================================" << RESET << endl;
  cout << GREEN << "Display Successful!!" << RESET << endl;
}
void displayEachUser(User user[], int index) {
  cout << BRIGHT_BLUE << "===========USER INFOMATTIONS==========" << endl;
  cout << "ID\t" << "Name\t" << "Username\t" << "Role" << endl;
  cout << user[index].id << "\t" << user[index].name << "\t" << user[index].username << "\t\t"
       << user[index].role << endl;
  cout << "======================================" << RESET << endl;
  cout << GREEN << "SEARCH... Successful!!" << RESET << endl;
}
// Search Function (search for user by id and name)
int linearSearch(string array[], int count, string key) {
  for (int i = 0; i < count; i++) {
    if (array[i] == key) {
      return i;
    }
  }
  return -1;
}
int linearSearch(User user[], int count, string key) {
  for (int i = 0; i < count; i++) {
    if (user[i].name == key) {
      return i;
    }
  }
  return -1;
}
int linearSearch(User user[], int count, int key) {
  for (int i = 0; i < count; i++) {
    if (user[i].id == key) {
      return i;
    }
  }
  return -1;
}
// Updated Function (User by name and id)
void update(string array[], int count, string update, string text) {
  string newWord;
  int index = linearSearch(array, count, update);
  if (index != -1) {
    cout << "Enter new " << text << " : ";
    cin >> newWord;
    array[index] = newWord;
    cout << GREEN << newWord << " successfull updated" << endl;
  } else {
    cout << newWord << " not found" << endl;
  }
}
void update(User user[], int count, string update, string name) {
  string newName;
  int index = linearSearch(user, count, update);
  if (index != -1) {
    cout << "Enter new " << name << " : ";
    cin >> newName;
    user[index].name = newName;
    cout << GREEN << name << " Successfull Updated" << endl;
  } else {
    cout << name << " not found" << endl;
  }
}
void update(User user[], int count, int update, string name) {
  int newId;
  int index = linearSearch(user, count, update);
  if (index != -1) {
    cout << "Enter new " << name << " : ";
    cin >> newId;
    user[index].id = newId;
    cout << GREEN << name << " Successfull Updated" << endl;
  } else {
    cout << name << " not found" << endl;
  }
}
// Swapping and Short Function
void swappingWord(string &a, string &b) {
  string t;
  t = a;
  a = b;
  b = t;
}
void swappingUser(User &a, User &b) {
  User t = a;
  a = b;
  b = t;
}
void shortWord(string arr[], int count) {
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        swappingWord(arr[j], arr[j + 1]);
      }
    }
  }
  cout << GREEN << "Word already shorted Successful!!" << RESET << endl;
}
void shortFunction(User user[], int count, int key) {
  if (key == 1) {  // Sort by name
    for (int i = 0; i < count - 1; i++) {
      for (int j = 0; j < count - i - 1; j++) {
        if (user[j].name > user[j + 1].name) {
          swappingUser(user[j], user[j + 1]);
        }
      }
    }
    cout << GREEN << "Already shorted by name Successful!!" << RESET << endl;
  } else if (key == 2) {  // Sort by id
    for (int i = 0; i < count - 1; i++) {
      for (int j = 0; j < count - i - 1; j++) {
        if (user[j].id > user[j + 1].id) {
          swappingUser(user[j], user[j + 1]);
        }
      }
    }
    cout << GREEN << "Already shorted by id Successful!!" << RESET << endl;
  } else {
    cout << RED << "Invalid Choice" << RESET << endl;
  }
}

// Deleted Function (User by id)
void deleteFunction(string arr[], int &count, string deleteKey) {
  int index = linearSearch(arr, count, deleteKey);
  if (index != -1) {
    for (int i = index; i < count - 1; i++) {
      arr[i] = arr[i + 1];
    }
    count--;
    cout << GREEN << "Word already deleted!!" << RESET << endl;
  } else {
    cout << RED << "Word not found" << RESET << endl;
  }
}
void deleteUser(User users[], int &count) {
  int id;
  bool userDelete = false;
  cout << "Enter the ID of the User to delete: ";
  cin >> id;
  while (cin.fail()) {
    cin.clear();
    cin.ignore();
    cout << RED << "Invalid input." << RESET << endl;
    cout << " Please enter ID: " << endl;
    cin >> id;
  }
  for (int i = 0; i < count; i++) {
    if (users[i].id == id) {
      users[i] = users[--count];
      cout << GREEN << "User" << users[i].name << " deleted successfully!" << RESET << endl;
      userDelete = true;
    }
  }
  if (!userDelete) {
    cout << RED << "User not found!" << RESET << endl;
  }
}
