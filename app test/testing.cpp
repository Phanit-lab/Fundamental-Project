#include <iostream>
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string BRIGHT_BLUE = "\033[94m";
enum Login_Menu { LOGIN_EXIT, REGISTER, LOGIN };
enum Control_Menu {
  CONTROL_EXIT,
  ADD,
  EDIT,
  DELETE,
  SEARCH,
  SHORT,
  DISPLAY,
};

enum Admin_Menu { ADMIN_EXIT, WORD, ACCOUNT, PLAY };
// Control Function
void controlMenuWord(int control, string word[], int &wordCount);
void controlMenuAccount(int control, User user[], int &userCount);
void adminMenu(int choise, int controlWord, string word[], int &wordCount, User user[],
               int &userCount, int controlAccount);
void deleteUser(User users[], int &count);
void deleteFunction(string arr[], int &count, string deleteKey);
void shortFunction(User user[], int count, int key);
void shortWord(string arr[], int count);
void swappingWord(User &a, User &b);
void swappingWord(string &a, string &b);
void update(User user[], int count, int update, string name);
void update(User user[], int count, string update, string name);
void update(string array[], int count, string update, string text);
int linearSearch(User user[], int count, int key);
int linearSearch(User user[], int count, string key);
int linearSearch(string array[], int count, string key);
void displayEachUser(User user[], int index);
void displayUser(User user[], int &count);
void displayWord(string word[], int &currentcout);
void addUser(User user[], int &count);
void addword(string word[], int &currentcout);
bool login(User user[], string keyName, string keyPassword, int count);

struct User {
  string name;
  int id;
  string username;
  string password;
  string role;
};

int main() {
  int loginChoice;
  const int MAX_USERS = 100;
  const int MAX_WORDS = 100;
  User user[MAX_USERS];
  string word[MAX_WORDS];
  int userCount = 0;
  int wordCount = 0;

  do {
    displayMenuLogin();
    cin >> loginChoice;
    switch (loginChoice) {
      case REGISTER:
        userCount++;
        addUser(user, userCount);
        break;
      case 6:
        displayUser(user, userCount);
        break;
      case LOGIN: {
        string username, password;
        int control;
        int choise;
        cout << BRIGHT_BLUE << "-------LOGIN_MENU-------" << RESET << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (login(user, username, password, userCount)) {
          cout << GREEN << "Login Successful!!" << RESET << endl;
          do {
            displayMenuAdmin();
            cin >> choise;
            adminMenu(choise, control, word, wordCount, user, userCount, control);
          } while (choise != 0);
        } else {
          cout << RED << "Incorect username or password" << RESET << endl;
          break;
        }
      }
      case LOGIN_EXIT:
        cout << RED << "The Program is Exited" << RESET << endl;
        exit(0);
        break;
      default:
        cout << RED << "Invalid choice!" << RESET << endl;
        break;
    }
  } while (loginChoice != 0);

  return 0;
}

void controlMenuWord(int control, string word[], int &wordCount)

{
  switch (control) {
    case ADD: {
      addword(word, wordCount);
      cout << GREEN << "ADD... Successful!!" << RESET << endl;

      break;
    }
    case EDIT: {
      string updateWord;
      cout << "Enter Word you want to updated: ";
      cin >> updateWord;
      update(word, wordCount, updateWord, " word");
      cout << GREEN << "EDIT... Successful!!" << RESET << endl;
      break;
    }
    case DELETE: {
      string delete_word;
      cout << "Enter the word you want to delete: ";
      cin >> delete_word;
      deleteFunction(word, wordCount, delete_word);
      cout << GREEN << "DELETE... Successful!!" << RESET << endl;
      break;
    }
    case SEARCH: {
      string keyWord;
      cout << "What word you want to search: ";
      cin >> keyWord;
      linearSearch(word, wordCount, keyWord);
      cout << GREEN << "SEARCH... Successful!!" << RESET << endl;
      break;
    }
    case SHORT: {
      shortWord(word, wordCount);
      cout << GREEN << "SHORT... Successful!!" << RESET << endl;
      break;
    }
    case DISPLAY: {
      displayWord(word, wordCount);
      cout << GREEN << "DISPLAY... Successful!!" << RESET << endl;
      break;
    }
    case CONTROL_EXIT: {
      cout << YELLOW << "Back to the USER Menu..." << RESET << endl;
      break;
    }

    default: {
      cout << RED << "Invalid choise" << RESET << endl;
      break;
    }
  }
}
void controlMenuAccount(int control, User user[], int &userCount) {
  switch (control) {
    case ADD: {
      int count;
      cout << "How many user you want to add?";
      cin >> count;
      addUser(user, count);
      cout << GREEN << "ADD... Successful!!" << RESET << endl;

      break;
    }
    case EDIT: {
      int edit, newId, newRole;
      string newName;
      cout << "What do you want to eddit? " << endl;
      cout << " 1. Name" << endl;
      cout << " 2. ID" << endl;
      cin >> edit;
      if (edit == 1) {
        cout << "Enter update Name: ";
        cin >> newName;
        update(user, userCount, newName, " name");
      } else if (edit == 2) {
        cout << "Enter update Name: ";
        cin >> newId;
        update(user, userCount, newId, " id");
      } else if (edit == 3) {
        cout << "Enter update Role: " << endl;
        cout << " 1. Admin" << endl;
        cout << " 2. User" << endl;
        cin >> newRole;
        update(user, userCount, newRole, " role");
      }
      cout << GREEN << "EDIT... Successful!!" << RESET << endl;
      break;
    }
    case DELETE: {
      int deleteKey;
      cout << "Enter the name you want to delete: ";
      cin >> deleteKey;
      deleteUser(user, userCount);
      cout << GREEN << "DELETE... Successful!!" << RESET << endl;
      break;
    }
    case SEARCH: {
      int keyId;
      string keyName;
      int choice;
      cout << "What word you want to search? ";
      cout << " 1. By ID" << endl;
      cout << "2. By Name" << endl;
      cin >> choice;
      if (choice == 1) {
        cout << " Enter ID: ";
        cin >> keyId;
        displayEachUser(user, linearSearch(user, userCount, keyId));
        cout << GREEN << "SEARCH... Successful!!" << RESET << endl;
        break;
      } else if (choice == 2) {
        cout << " Enter Name: ";
        cin >> keyName;
        displayEachUser(user, linearSearch(user, userCount, keyName));
        cout << GREEN << "SEARCH... Successful!!" << RESET << endl;
        break;
      } else {
        cout << GREEN << "SEARCH... Successful!!" << RESET << endl;
        break;
      }
    }
    case SHORT: {
      int keyShort;
      cout << "What do you want to short?" << endl;
      cout << "1. ID" << endl;
      cout << "2. Name" << endl;
      cin >> keyShort;
      shortFunction(user, userCount, keyShort);
      cout << GREEN << "Short User Successful!!" << RESET << endl;
      break;
    }
    case DISPLAY: {
      displayUser(user, userCount);
      cout << GREEN << "DISPLAY... Successful!!" << RESET << endl;
      break;
    }
    case CONTROL_EXIT: {
      cout << YELLOW << "Back to the USER Menu..." << RESET << endl;
      break;
    }

    default: {
      cout << RED << "Invalid choise" << RESET << endl;
      break;
    }
  }
}
void adminMenu(int choise, int controlWord, string word[], int &wordCount, User user[],
               int &userCount, int controlAccount) {
  switch (choise) {
    case WORD: {
      do {
        displayMenuControl("WORD");
        cin >> controlWord;
        controlMenuWord(controlWord, word, wordCount);
      } while (controlWord != 0);
      break;
    }
    case ACCOUNT: {
      do {
        displayMenuControl("ACCOUNT");
        cin >> controlAccount;
        controlMenuAccount(controlAccount, user, userCount);
      } while (controlAccount != 0);
      break;
    }
    case PLAY: {
      cout << RED << "GAME_WILL_RELEASE_SOON" << RESET << endl;
      break;
    }
    case ADMIN_EXIT: {
      cout << YELLOW << "Back to the Login Menu..." << RESET << endl;
      break;
    }

    default: {
      break;
    }
  }
}

// Feature Function
// Login Function
bool login(User user[], string keyName, string keyPassword, int count) {
  for (int i = 0; i < count; i++) {
    keyName = user[i].username;
    keyPassword = user[i].password;
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
  for (size_t i = 0; i < count; i++) {
    cout << "Word [" << currentcout + 1 << "] :";
    cin >> word[currentcout];
    currentcout++;
  }
}
void addUser(User user[], int &count) {
  cout << BRIGHT_BLUE << "---------REGISTER--------" << RESET << endl;
  for (int i = 0; i < count; i++) {
    cout << " Name: ";
    cin >> user[i].name;
    cout << " username: ";
    cin >> user[i].username;
    cout << " Password: ";
    cin >> user[i].password;
    cout << " ID: ";
    cin >> user[i].id;
    cout << " Role: " << endl;
    cout << " 1. Admin: " << endl;
    cout << " 2. User " << endl;
    cout << " Chouse role: ";
    cin >> user[i].role;
    cout << BRIGHT_BLUE << "------------------------" << RESET << endl;
    cout << GREEN << "Register Successful!!" << RESET << endl;
  }
}

// Display function
void displayWord(string word[], int &currentcout) {
  cout << BRIGHT_BLUE << "=======LIST_WORDS=======" << RESET << endl;
  for (int i = 0; i < currentcout; i++) {
    cout << "[" << i + 1 << "]. " << "Word : " << word[i] << endl;
  }
}
void displayUser(User user[], int &count) {
  cout << BRIGHT_BLUE << "===========USER INFOMATTIONS==========" << endl;
  cout << "ID\t" << "Name\t" << "Username\t" << "Role" << endl;
  for (int i = 0; i < count; i++) {
    cout << user[i].id << "\t" << user[i].name << "\t" << user[i].username << "\t\t" << user[i].role
         << endl;
  }
  cout << "======================================" << RESET << endl;
}
void displayEachUser(User user[], int index) {
  cout << BRIGHT_BLUE << "===========USER INFOMATTIONS==========" << endl;
  cout << "ID\t" << "Name\t" << "Username\t" << "Role" << endl;
  cout << user[index].id << "\t" << user[index].name << "\t" << user[index].username << "\t\t"
       << user[index].role << endl;
  cout << "======================================" << RESET << endl;
}
// Search Function (search for user by id and name)
int linearSearch(string array[], int count, string key) {
  for (int i = 0; i < count; i++) {
    if (array[i] == key) {
      return i;
    }
    return -1;
  }
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
    cout << GREEN << newWord << " Successfull Updated" << endl;
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
  int newWord;
  int index = linearSearch(user, count, update);
  if (index != -1) {
    cout << "Enter new " << name << " : ";
    cin >> newWord;
    user[index].id = newWord;
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
void swappingWord(User &a, User &b) {
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
}
void shortFunction(User user[], int count, int key) {
  if (key == 1) {  // Sort by name
    for (int i = 0; i < count; i++) {
      for (int j = 0; j < count - i - 1; j++) {
        if (user[j].name > user[j + 1].name) {
          swappingWord(user[j], user[j + 1]);
        }
      }
    }
  } else if (key == 2) {  // Sort by id
    for (int i = 0; i < count; i++) {
      for (int j = 0; j < count - i - 1; j++) {
        if (user[j].id > user[j + 1].id) {
        }
      }
    }
  } else {
    cout << "Invalid Choice" << endl;
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
  } else {
    cout << "Word not found" << endl;
  }
}
void deleteUser(User users[], int &count) {
  int id;
  cout << "Enter the ID of the User to delete: ";
  cin >> id;
  for (int i = 0; i < count; i++) {
    if (users[i].id == id) {
      users[i] = users[--count];
      cout << "User" << users[i].name << " deleted successfully!" << endl;
      return;
    }
  }
  cout << "User not found!" << endl;
}

void displayMenuLogin() {
  cout << BRIGHT_BLUE << "----------MENU----------" << RESET << endl;
  cout << "1. Register" << endl;
  cout << "2. Login" << endl;
  cout << "0. Exit the program" << endl;
  cout << BRIGHT_BLUE << "------------------------" << RESET << endl;
  cout << "Enter your chooise: ";
}
void displayMenuAdmin() {
  cout << BRIGHT_BLUE << "-------ADMIN_MENU-------" << RESET << endl;
  cout << "1. Word Control" << endl;
  cout << "2. User Account Control" << endl;
  cout << "3. Play Game" << endl;
  cout << "0. Back to MENU" << endl;
  cout << BRIGHT_BLUE << "------------------------" << RESET << endl;
  cout << "Enter your chooise: ";
}
void displayMenuControl(string control) {
  cout << BRIGHT_BLUE << "-------" << control << "_CONTROL-------" << RESET << endl;
  cout << "1. Add " << control << endl;
  cout << "2. Edit " << control << endl;
  cout << "3. Delete " << control << endl;
  cout << "4. Search " << control << endl;
  cout << "5. Short " << control << endl;
  cout << "6. Display " << control << endl;
  cout << "0. Back to ADMIN_MENU" << endl;
  cout << BRIGHT_BLUE << "------------------------" << RESET << endl;
  cout << "Enter your chooise: ";
}