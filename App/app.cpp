#include <iostream>

#include "Function/display.cpp"
using namespace std;

// Function declaration
bool login(string username, string password);
void controlMenuWord(int control);
void adminMenu(int choise);
void registerUser(string name[], string username[], string password[], int id[], int role[],
                  int &index);
void displayFunction(string name[], string username[], string password[], int id[], int role[],
                     int accountCount);
void addword(string word[], int &currentcout);
void displayWord(string word[], int &currentcout);
int linearSearch(string array[], int count, string key);
int linearSearch(int array[], int count, int key);
void update(string array[], int count, string update, string name);
void update(int array[], int count, int update, string name);
void swappingWord(string &a, string &b);
void shortWord(string arr[], int count);
void deleteFunction(string arr[], int &count, string deleteKey);
void controlMenuAccount(int control);

// Enum:
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

// Declaration
const int MAX_WORD = 10;
string word[MAX_WORD];
int wordCount = 0;
string name[100];
string username[100];
string password[100];
int id[100];
int role[100];
int accountCount = 0;

int main() {
  int loginChoice;

  do {
    displayMenuLogin();
    cin >> loginChoice;
    switch (loginChoice) {
      case REGISTER:
        registerUser(name, username, password, id, role, accountCount);
        accountCount++;
        break;
      case 6:
        displayFunction(name, username, password, id, role, accountCount);
        break;
      case LOGIN: {
        string username, password;
        cout << BRIGHT_BLUE << "-------LOGIN_MENU-------" << RESET << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (login(username, password)) {
          int choise;
          cout << GREEN << "Login Successful!!" << RESET << endl;
          do {
            displayMenuAdmin();
            cin >> choise;
            adminMenu(choise);
          } while (choise != 0);
        } else {
          cout << RED << "Incorect username or password" << RESET << endl;
        }

        break;
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

/*
All Function
*/
bool login(string username, string password) {
  string keyName = "phanit";
  string keyPassword = "123";
  if (username == keyName && password == keyPassword) {
    return true;
  } else {
    return false;
  }
}
void controlMenuWord(int control)

{
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
        update(word, wordCount, updateWord, "word");
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
}
void adminMenu(int choise) {
  switch (choise) {
    {
      int control;
      case WORD: {
        int controlWord;
        do {
          displayMenuControl("WORD");
          cin >> controlWord;
          controlMenuWord(controlWord);
        } while (controlWord != 0);
        break;
      }
      case ACCOUNT: {
        int controlAccount;
        do {
          displayMenuControl("ACCOUNT");
          cin >> controlAccount;
          controlMenuAccount(controlAccount);
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
}
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
void displayWord(string word[], int &currentcout) {
  cout << BRIGHT_BLUE << "--------LIST_WORDS-------" << RESET << endl;
  for (int i = 0; i < currentcout; i++) {
    cout << "[" << i + 1 << "]. " << "Word : " << word[i] << endl;
  }
}
void displayFunction(string name[], string username[], string password[], int id[], int role[],
                     int accountCount) {
  cout << BRIGHT_BLUE << "=======USER INFOMATTIONS=======" << RESET << endl;
  for (int i = 0; i < accountCount; i++) {
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
  cout << BRIGHT_BLUE << "=================================" << RESET << endl;
}
int linearSearch(string array[], int count, string key) {
  for (int i = 0; i < count; i++) {
    if (array[i] == key) {
      return i;
    }
    return -1;
  }
}
int linearSearch(int array[], int count, int key) {
  for (int i = 0; i < count; i++) {
    if (array[i] == key) {
      return i;
    }
    return -1;
  }
}
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
void update(int array[], int count, int update, string text) {
  int newWord;
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

void swappingWord(string &a, string &b) {
  string t;
  t = a;
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
void registerUser(string name[], string username[], string password[], int id[], int role[],
                  int &index) {
  cout << BRIGHT_BLUE << "---------REGISTER--------" << RESET << endl;
  cout << " Name: ";
  cin >> name[index];
  cout << " username: ";
  cin >> username[index];
  cout << " Password: ";
  cin >> password[index];
  cout << " ID: ";
  cin >> id[index];
  cout << " Role: " << endl;
  cout << " 1. Admin: " << endl;
  cout << " 2. User " << endl;
  cout << " Chouse role: ";
  cin >> role[index];
  cout << BRIGHT_BLUE << "------------------------" << RESET << endl;
  cout << GREEN << "Register Successful!!" << RESET << endl;
}

void controlMenuAccount(int control) {
  {
    switch (control) {
      case ADD: {
        registerUser(name, username, password, id, role, accountCount);
        accountCount++;
        cout << GREEN << "ADD... Successful!!" << RESET << endl;

        break;
      }
      case EDIT: {
        int edit, newId, newRole;
        string newName;
        cout << "What do you want to eddit? " << endl;
        cout << " 1. Name" << endl;
        cout << " 2. ID" << endl;
        cout << " 3. Role" << endl;
        cin >> edit;
        if (edit == 1) {
          cout << "Enter update Name: ";
          cin >> newName;
          update(name, accountCount, newName, " name");
        } else if (edit == 2) {
          cout << "Enter update Name: ";
          cin >> newId;
          update(id, accountCount, newId, " id");
        } else if (edit == 3) {
          cout << "Enter update Role: " << endl;
          cout << " 1. Admin" << endl;
          cout << " 2. User" << endl;
          cin >> newRole;
          update(role, accountCount, newRole, " role");
        }
        cout << GREEN << "EDIT... Successful!!" << RESET << endl;
        break;
      }
      case DELETE: {
        string deleteKey;
        cout << "Enter the name you want to delete: ";
        cin >> deleteKey;
        deleteFunction(name, accountCount, deleteKey);
        cout << GREEN << "DELETE... Successful!!" << RESET << endl;
        break;
      }
      case SEARCH: {
        string keyAccount;
        cout << "What word you want to search: ";
        cin >> keyAccount;
        linearSearch(name, accountCount, keyAccount);
        cout << GREEN << "SEARCH... Successful!!" << RESET << endl;
        break;
      }
      case SHORT: {
        shortWord(name, accountCount);
        cout << GREEN << "SHORT... Successful!!" << RESET << endl;
        break;
      }
      case DISPLAY: {
        displayFunction(name, username, password, id, role, accountCount);
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
}