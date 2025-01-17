#include <limits>

#include "displays.cpp"

// Structure
struct User {
  string name;
  int id;
  string username;
  string password;
  int role;
};
// Feature Function
// Login Function
bool login(User user[], string keyName, string keyPassword, int count) {
  for (int i = 0; i < count; i++) {
    if (user[i].username == keyName && user[i].password == keyPassword) {
      return true;
    }
  }
  return false;
}
// Input Function
template <typename T>
void input(T &inPut, const string &text) {
  cout << "--> " << text;
  cin >> inPut;
  while (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << RED << "Invalid input. " << RESET << endl;
    cout << "--> " << text;
    cin >> inPut;
  }
  cin.ignore(numeric_limits<streamsize>::max(),
             '\n');  // (For switching between different tpye of input (int, string))
}
// Use Namespace For Account:
namespace account {
void addUser(User user[], int &userCount, int maxUsers) {
  int count = 1;
  displayfram("REGISTER");

  for (int i = 0; i < count; i++) {
    input(user[userCount].name, " Name: ");
    input(user[userCount].username, " Username: ");
    input(user[userCount].password, " Password: ");
    input(user[userCount].id, " ID: ");
    displayRole();
    do {
      input(user[userCount].role, "Choose role: ");
      if (user[userCount].role != 1 && user[userCount].role != 2) {
        cout << RED << "Invalid input" << RESET << endl;
      }

    } while (user[userCount].role != 1 && user[userCount].role != 2);

    cout << BRIGHT_BLUE << "------------------------" << RESET << endl;
    cout << GREEN << "Register Successful!!" << RESET << endl;
    userCount++;
  }
}

void displayUser(User user[], int count) {
  cout << BRIGHT_BLUE << "=========== USER INFOMATTIONS ==========" << RESET << endl;
  cout << "ID\t" << "Name\t  " << "Username\t" << "Role" << endl;
  cout << BRIGHT_BLUE << "========================================" << RESET << endl;
  for (int i = 0; i < count; i++) {
    cout << user[i].id << "\t" << user[i].name << "\t  " << user[i].username << "\t\t";
    if (user[i].role == 1) {
      cout << "Admin " << endl;
    } else if (user[i].role == 2) {
      cout << "Player " << endl;
    } else {
      cout << "NA" << endl;
    }
  }
  cout << BRIGHT_BLUE << "========================================" << RESET << endl;
  cout << GREEN << "Display Successful!!" << endl;
}
void displayEachUser(User user[], int index) {
  cout << BRIGHT_BLUE << "=========== USER INFOMATTIONS ==========" << RESET << endl;
  cout << "   Name: \t" << user[index].name << endl;
  cout << "   ID: \t\t" << user[index].id << endl;
  cout << "   Username: \t" << user[index].username << endl;
  if (user[index].role == 1) {
    cout << "   Role: \tAdmin " << endl;
  } else if (user[index].role == 2) {
    cout << "   Role: \tPlayer " << endl;
  } else {
    cout << "   Role: \tNA" << endl;
  }
  cout << BRIGHT_BLUE << "========================================" << RESET << endl;
  cout << GREEN << "Display Successful!!" << endl;
}
// Search Function (search for user by id and name)

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
// Updated User By Name
void update(User user[], int count, string update) {
  string newName;
  int index = linearSearch(user, count, update);
  if (index != -1) {
    input(newName, "Enter new name: ");
    user[index].name = newName;
    cout << GREEN << newName << " successfull updated\n" <<RESET<< endl;
  } else {
    cout << RED << newName << " not found\n" << RESET << endl;
  }
}
// Updated User By ID
void update(User user[], int count, int update) {
  int newId;
  int index = linearSearch(user, count, update);
  if (index != -1) {
    input(newId, "Enter new ID: ");
    user[index].id = newId;
    cout << GREEN << newId << " Successfull Updated\n" <<RESET<< endl;
  } else {
    cout << RED << newId << " not found\n" << RESET << endl;
  }
}
// Swapping and Short Function
void swappingUser(User &a, User &b) {
  User t = a;
  a = b;
  b = t;
}

void shortFunction(User user[], int count, int key, int shortBy) {
  if (shortBy == 1) {
    if (key == 1) {  // Sort by name
      for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
          if (user[j].name > user[j + 1].name) {
            swappingUser(user[j], user[j + 1]);
          }
        }
      }
      cout << GREEN << "Already shorted by name increase Successful!!\n" << RESET << endl;
    } else if (key == 2) {  // Sort by id
      for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
          if (user[j].id > user[j + 1].id) {
            swappingUser(user[j], user[j + 1]);
          }
        }
      }
      cout << GREEN << "Already shorted by id increase Successful!!\n" << RESET << endl;
    } else {
      cout << RED << "Invalid Choice\n" << RESET << endl;
    }
  } else if (shortBy == 2) {
    if (key == 1) {  // Sort by name
      for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
          if (user[j].name < user[j + 1].name) {
            swappingUser(user[j], user[j + 1]);
          }
        }
      }
      cout << GREEN << "Already shorted by name discrease Successful!!\n" << RESET << endl;
    } else if (key == 2) {  // Sort by id
      for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
          if (user[j].id < user[j + 1].id) {
            swappingUser(user[j], user[j + 1]);
          }
        }
      }
      cout << GREEN << "Already shorted by id discrease Successful!!\n" << RESET << endl;
    } else {
      cout << RED << "Invalid Choice\n" << RESET << endl;
    }
  }
}

};  // namespace account

// Deleted Function (User by id)
void deleteUser(User users[], int &count) {
  bool userDelete = false;
  int id;
  char verify;
  displayfram("DELETE");
  input(id, "Enter the ID of the User to delete:");
  for (int i = 0; i < count; i++) {
    if (users[i].id == id) {
      input(verify, "Are you sure you want to delete? (y/n): ");
      if (verify == 'y' || verify == 'Y') {
        cout << GREEN << "User " << users[i].name << " is deleted successfully!\n" << RESET << endl;
        users[i] = users[--count];
        userDelete = true;
      } else if (verify == 'n' || verify == 'N') {
        exit(0);
      } else {
        cout << "Invalid Input" << endl;
      }
    }
  }
  if (!userDelete) {
    cout << RED << "User not found!\n" << RESET << endl;
  }
};  // namespace account

// Use Namespace For Word Feature:
namespace word {
// Add Function (Add Word)
void addword(string word[], int &currentcout) {
  int count;
  displayfram("ADD_WORDS");
  input(count, "How many words you want to add? : ");
  for (int i = 0; i < count; i++) {
    cout << "Word [" << currentcout + 1 << "] :";
    cin >> word[currentcout];
    currentcout++;
  }
  cout << GREEN << "ADD Successful!!" << RESET << endl;
}
// Display Function
void displayWord(string word[], int &currentcout) {
  cout << BRIGHT_BLUE << "=======LIST_WORDS=======" << RESET << endl;
  for (int i = 0; i < currentcout; i++) {
    cout << i + 1 << ". " << word[i] << endl;
  }
  cout << GREEN << "Display Successful!!" << RESET << endl;
}
// Search Function
int linearSearch(string array[], int count, string key) {
  for (int i = 0; i < count; i++) {
    if (array[i] == key) {
      return i;
    }
  }
  return -1;
}
void update(string array[], int count, string update) {
  string newWord;
  int index = linearSearch(array, count, update);
  if (index != -1) {
    input(newWord, "Enter new Word: ");
    array[index] = newWord;
    cout << GREEN << newWord << " successfull updated\n" << endl;
  } else {
    cout << RED << newWord << " not found\n" << RESET << endl;
  }
}
void swappingWord(string &a, string &b) {
  string t;
  t = a;
  a = b;
  b = t;
}
void shortWord(string arr[], int count) {
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swappingWord(arr[j], arr[j + 1]);
      }
    }
  }
  cout << GREEN << "Word already shorted Successful!!\n" << RESET << endl;
}
void deleteFunction(string arr[], int &count, string deleteKey) {
  int index = linearSearch(arr, count, deleteKey);
  char verify;
  if (index != -1) {
    input(verify, "Are you sure you want to delete? (y/n): ");
    if (verify == 'Y' || verify == 'y') {
      cout << GREEN << arr[index] << " already deleted!!\n" << RESET << endl;
      for (int i = index; i < count - 1; i++) {
        arr[i] = arr[i + 1];
      }
      count--;
    } else if (verify == 'N', verify == 'n') {
      cout << RED << arr[index] << " is not deleted " << RESET << endl;
    }

  } else {
    cout << RED << arr[index] << "  not found\n" << RESET << endl;
  }
}
};  // namespace word
