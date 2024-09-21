#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

#include "displays.cpp"

// Structure
struct User {
  int id;
  string name;
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
             '\n');  // (For switching between different tpye of input int, string)
}
void inputName(string &value, string text) {
  cout << text;
  getline(cin, value);
}

// Use Namespace For Account:
namespace account {
// Write the User into file
void writeUserToFile(const User &user, const string &filename) {
  ofstream file;
  file.open(filename, ios::app);  // Open file in append mode
  if (file.is_open()) {
    file << user.id << "," << user.name << "," << user.username << "," << user.password << ","
         << user.role << endl;
    file.close();
  } else {
    cerr << "Unable to open file for writing." << endl;
  }
}
// Read data from the file
void readUsersFromFile(User user[], int &count, const string &fileName, const int MAX_USER) {
  ifstream file(fileName);

  if (!file.is_open()) {
    cerr << "Error: Could not open the file." << endl;
    return;
  }

  string line;
  count = 0;                                         // Reset the count before reading data
  while (getline(file, line) && count < MAX_USER) {  // Adjust 100 based on max array size
    stringstream read(line);

    if (read >> user[count].id) {
    }
    read.ignore(1);  // Ignore the comma

    getline(read, user[count].name, ',');
    getline(read, user[count].username, ',');
    getline(read, user[count].password, ',');
    read >> user[count].role;
    count++;  // Increment the count for each user read
  }

  file.close();
}

// Add user or Registeration
void addUser(User user[], int &userCount, int maxUsers) {
  displayFram("REGISTER");
  inputName(user[userCount].name, " Name: ");
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
  writeUserToFile(user[userCount], "user.txt");
  userCount++;
}

void displayUser(User user[], int count, const int MAX_USERS) {
  readUsersFromFile(user, count, "user.txt", MAX_USERS);
  if (count == 0) {
    cout << RED << "No users available to display." << RESET << endl;
    return;
  }
  displayFram("DISPLAY_ALL_USER");
  cout << setw(7) << left << "ID" << setw(15) << left << "Name" << setw(20) << left << "Username"
       << setw(10) << left << "Role" << endl;
  cout << BRIGHT_BLUE << "==================================================" << RESET << endl;

  // Display user data
  for (int i = 0; i < count; i++) {
    // Set left alignment and display user details with proper column width
    cout << setw(7) << left << user[i].id << setw(15) << left << user[i].name << setw(20) << left
         << user[i].username << setw(10) << left;

    // Display role with switch case
    switch (user[i].role) {
      case 1:
        cout << "Admin" << endl;
        break;
      case 2:
        cout << "Player" << endl;
        break;
      default:
        cout << "NA" << endl;
        break;
    }
  }
  cout << BRIGHT_BLUE << "==================================================" << RESET << endl;
}

void displayEachUser(User user[], int index) {
  if (index<=0)
  {
   cout<<RED<<"User Not Found!!"<<RESET<<endl;
  }
  
  if (index <= 0) {
    cout << "User Not Foun!!" << endl;
    return;
  }

  cout << BRIGHT_BLUE << "===========USER INFOMATTIONS==========" << RESET << endl;
  cout << "   ID: \t\t" << user[index].id << endl;
  cout << "   Name: \t" << user[index].name << endl;
  cout << "   Username: \t" << user[index].username << endl;
  switch (user[index].role) {
    case 1:
      cout << "   Role: \tAdmin " << endl;
      break;
    case 2:
      cout << "   Role: \tPlayer " << endl;
      break;
    default:
      cout << "   Role: \tNA" << endl;
      break;
  }
  cout << BRIGHT_BLUE << "======================================" << RESET << endl;
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
void searchUser(User user[], int userCount, const int MAX_USERS) {
  int choice;  // Search by Name and ID;
  int index;
  int keyId;
  string keyName;
  readUsersFromFile(user, userCount, "user.txt", MAX_USERS);
  displaySearchMenu();
  input(choice, "Enter your chooise: ");
  if (choice == 1) {
    input(keyId, "Enter ID: ");
    if ((index = linearSearch(user, userCount, keyId)) != -1) {
      displayEachUser(user, index);
      cout << GREEN << "Display Successful!!" << endl;
    } else {
      cout << RED << "User not found" << RESET << endl;
    }
  } else if (choice == 2) {
    input(keyName, " Enter Name: ");
    if ((index = linearSearch(user, userCount, keyName)) != -1) {
      displayEachUser(user, index);
      cout << GREEN << "Display Successful!!" << endl;
    } else {
      cout << RED << "User not found" << RESET << endl;
    }
  } else {
    cout << RED << "Invalid Choise" << RESET << endl;
  }
}
// Updated Function (User by name and id)
void updateFile(User user[], int count) {
  ifstream originalFile("user.txt");  // Open the original file
  ofstream tempFile("temp.txt");      // Open the temp file for writing

  if (!originalFile.is_open()) {
    cerr << RED << "Error: Could not open the original file." << RESET << endl;
    return;
  }

  if (!tempFile.is_open()) {
    cerr << RED << "Error: Could not open the temporary file for writing." << RESET << endl;
    return;
  }

  string line;
  int index = 0;  // Keep track of the index to match user data
  while (getline(originalFile, line) && index < count) {
    stringstream read(line);
    int currentId;
    string currentName, currentUsername, currentPassword;
    int currentRole;

    // Parse the existing line in the file
    read >> currentId;
    read.ignore(1);  // Ignore comma
    getline(read, currentName, ',');
    getline(read, currentUsername, ',');
    getline(read, currentPassword, ',');
    read >> currentRole;

    // Now write the updated or unchanged data to the temp file
    tempFile << user[index].id << ","    // Updated ID
             << user[index].name << ","  // Updated Name
             << currentUsername << ","   // Keep username unchanged
             << currentPassword << ","   // Keep password unchanged
             << currentRole << endl;     // Keep role unchanged

    index++;
  }

  // Close both files
  originalFile.close();
  tempFile.close();

  // Replace the original file with the updated temporary file
  if (remove("user.txt") != 0) {
    cerr << RED << "Error deleting the original file." << RESET << endl;
  } else if (rename("temp.txt", "user.txt") != 0) {
    cerr << RED << "Error renaming the temporary file." << RESET << endl;
  } else {
    cout << GREEN << "File updated successfully with " << count << " records." << RESET << endl;
  }
}
//

//
void update(User user[], int count, int choice, const int MAX_USERS) {
  readUsersFromFile(user, count, "user.txt", MAX_USERS);
  string name, newName;
  int id, newId;
  int index;

  switch (choice) {
    case 1:
      input(name, "Enter name: ");
      index = linearSearch(user, count, name);
      if (index != -1) {
        input(newName, "Enter new name: ");
        user[index].name = newName;
        cout << GREEN << newName << " successfull updated\n" << endl;
      } else {
        cout << RED << newName << " not found\n" << RESET << endl;
      }
      break;
    case 2:
      input(id, "Enter ID: ");
      index = linearSearch(user, count, id);
      if (index != -1) {
        input(newId, "Enter new ID: ");
        user[index].id = newId;
        cout << GREEN << newId << " Successfull Updated\n" << endl;
      } else {
        cout << RED << newId << " not found\n" << RESET << endl;
      }
      break;

    default:
      cout << RED << "Invalid choice" << RESET << endl;
      break;
  }
  updateFile(user, count);
}

// Swapping and Short Function
void swappingUser(User &a, User &b) {
  User t = a;
  a = b;
  b = t;
}

void shortFunction(User user[], int count, int key, int shortBy, const int MAX_USERS) {
  readUsersFromFile(user, count, "user.txt", MAX_USERS);
  switch (shortBy) {
    case 1:
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
      break;
    case 2:
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
      break;

    default:
      cout << "Invalid Choice" << endl;
      break;
  }
  updateFile(user, count);
}
// Deleted Function (User by id)
void deleteUser(User users[], int &count, const int MAX_USERS) {
  readUsersFromFile(users, count, "user.txt", MAX_USERS);
  bool userDelete = false;
  int id;
  char verify;
  displayFram("DELETE");
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
  updateFile(users, count);
}
};  // namespace account

// Use Namespace For Word Feature:
namespace word {
// Add Function (Add Word)
void addword(string word[], int &currentcout) {
  int count;
  displayFram("ADD_WORDS");
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
