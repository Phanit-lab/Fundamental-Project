#include <iostream>
using namespace std;

// Color Code
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string BRIGHT_BLUE = "\033[94m";

// Function declarations
bool login(string username, string password);
void controlMenuWord(int control);
void adminMenu(int choice);
void registerUser(string &name, string &username, string &password, int &id, int &role);
void addword(string word[], int &currentcout);
void displayWord(string word[], int &currentcout);
int linearSearch(string array[], int count, string key);
void update(string array[], int count, string update, string name);
void swappingWord(string &a, string &b);
void shortWord(string arr[], int count);
void deleteWord(string arr[], int &count, string deleteWord);
void displayMenuControl(string control);
void displayMenuAdmin();
void displayMenuLogin();

// Enum definitions
enum Login_Menu { LOGIN_EXIT, REGISTER, LOGIN };
enum Control_Menu { CONTROL_EXIT, ADD, EDIT, DELETE, SEARCH, SHORT, DISPLAY };
enum Admin_Menu { ADMIN_EXIT, WORD, ACCOUNT, PLAY };

// Constants
const int MAX_WORD = 10;
string word[MAX_WORD];
int currentcout = 0;
const int MAX_ACCOUNT = 10;
string account[MAX_ACCOUNT];
int accountCount = 0;

int main() {
  int loginChoice;
  string name, username, password;
  int id, role;

  do {
    displayMenuLogin();
    cin >> loginChoice;
    switch (loginChoice) {
      case REGISTER:
        registerUser(name, username, password, id, role);
        break;
      case LOGIN: {
        cout << BRIGHT_BLUE << "=======LOGIN_MENU======" << RESET << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (login(username, password)) {
          int choice;
          cout << GREEN << "Login Successful!!" << RESET << endl;
          do {
            displayMenuAdmin();
            cin >> choice;
            adminMenu(choice);
          } while (choice != ADMIN_EXIT);
        } else {
          cout << RED << "Incorrect username or password" << RESET << endl;
        }
        break;
      }
      case LOGIN_EXIT:
        cout << RED << "The Program is Exited" << RESET << endl;
        exit(0);
        break;
      default:
        cout << "Invalid choice!" << endl;
        break;
    }
  } while (loginChoice != LOGIN_EXIT);

  return 0;
}

bool login(string username, string password) {
  string keyName = "phanit";
  string keyPassword = "123";
  return (username == keyName && password == keyPassword);
}

void controlMenuWord(int admidControl, int control) {
  control = admidControl;
  switch (control) {
    case ADD:
      if (admidControl) {
        addword(word, currentcout);
        cout << GREEN << "ADD... Successful!!" << RESET << endl;
      } else if (admidControl == 2) {
        addword(account, accountCount);
        cout << GREEN << "ACCOUNT IS ADDED SUCCESSFULL!!" << RESET << endl;
      }
      break;

    case EDIT: {
      string updateWord;
      cout << "Enter Word you want to update: ";
      cin >> updateWord;
      update(word, currentcout, updateWord, "Word");
      cout << GREEN << "EDIT... Successful!!" << RESET << endl;
      break;
    }
    case DELETE: {
      string delete_word;
      cout << "Enter the word you want to delete: ";
      cin >> delete_word;
      deleteWord(word, currentcout, delete_word);
      cout << GREEN << "DELETE... Successful!!" << RESET << endl;
      break;
    }
    case SEARCH: {
      string keyWord;
      cout << "What word do you want to search: ";
      cin >> keyWord;
      linearSearch(word, currentcout, keyWord);
      cout << GREEN << "SEARCH... Successful!!" << RESET << endl;
      break;
    }
    case SHORT:
      shortWord(word, currentcout);
      cout << GREEN << "SHORT... Successful!!" << RESET << endl;
      break;
    case DISPLAY:
      displayWord(word, currentcout);
      cout << GREEN << "DISPLAY... Successful!!" << RESET << endl;
      break;
    case CONTROL_EXIT:
      cout << YELLOW << "Back to the USER Menu..." << RESET << endl;
      break;
    default:
      cout << RED << "Invalid choice" << RESET << endl;
      break;
  }
}

void adminMenu(int adminControl) {
  switch (adminControl) {
    case WORD: {
      int controlWord;
      do {
        displayMenuControl("WORD");
        cin >> controlWord;
        controlMenuWord(controlWord);
      } while (controlWord != CONTROL_EXIT);
      break;
    }
    case ACCOUNT: {
      int controlAccount;
      do {
        displayMenuControl("ACCOUNT");
        cin >> controlAccount;
        controlMenuWord(controlAccount);
      } while (controlAccount != CONTROL_EXIT);
      break;
    }
    case PLAY:
      cout << RED << "GAME_WILL_RELEASE_SOON" << RESET << endl;
      break;
    case ADMIN_EXIT:
      cout << YELLOW << "Back to the Login Menu..." << RESET << endl;
      break;
    default:
      cout << RED << "Invalid choice!" << RESET << endl;
      break;
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
int linearSearch(string array[], int count, string key) {
  for (int i = 0; i < count; i++) {
    if (array[i] == key) {
      return i;
    }
  }
  return -1;
}
void update(string array[], int count, string update, string name) {
  string newWord;
  int index = linearSearch(array, count, update);
  if (index != -1) {
    cout << "Enter new " << name << " : ";
    cin >> newWord;
    array[index] = newWord;
    cout << GREEN << name << " Successfull Updated" << endl;
  } else {
    cout << name << " not found" << endl;
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
void deleteWord(string arr[], int &count, string deleteWord) {
  int index = linearSearch(arr, count, deleteWord);
  if (index != -1) {
    for (int i = index; i < count - 1; i++) {
      arr[i] = arr[i + 1];
    }
    count--;
  } else {
    cout << "Word not found" << endl;
  }
}
void registerUser(string &name, string &username, string &password, int &id, int &role) {
  cout << BRIGHT_BLUE << "---------REGISTER--------" << RESET << endl;
  cout << " Name: ";
  cin >> name;
  cout << " username: ";
  cin >> username;
  cout << " Password: ";
  cin >> password;
  cout << " ID: ";
  cin >> id;
  cout << " Role: " << endl;
  cout << " 1. Admin: " << endl;
  cout << " 2. User " << endl;
  cout << " Chouse role: ";
  cin >> role;
  cout << BRIGHT_BLUE << "------------------------" << RESET << endl;
  cout << GREEN << "Register Successful!!" << RESET << endl;
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
