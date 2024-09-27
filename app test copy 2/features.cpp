#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

#include "displays.cpp"
using namespace message;
using namespace displayMenu;

//====== Structure ========
struct User {
  int id;
  string name;
  string username;
  string password;
  int role;
};
//========ENUM=======
enum Sort { EXIT_SORT, SORT_INCREASE, SORT_DECREASE };
enum SortBy { EXIT_SORTS, SORT_NAME, SORT_ID, SORT_ROLE, SORT_USERNAME };
enum Update { EXIT_UPDATE, UPDATE_NAME, UPDATE_ID, UPDATE_ROLE };
enum SearchUser { EXIT_SEARCH, SEARCH_ID, SEARCH_NAME };

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
  cout << "--> " << text;
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
    messageFailWriteToFile();
  }
}
// Read data from the file
void readUsersFromFile(User user[], int &count, const string &fileName, const int MAX_USER) {
  ifstream file(fileName);
  if (!file.is_open()) {
    messageFailOpenFile();
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
void addUser(User user[], int &userCount, const string &fileName) {
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
  messageSuccessRegister();
  writeUserToFile(user[userCount], fileName);
  userCount++;
}

void displayUser(User user[], int count) {
  if (count == 0) {
    messageFailNoUser();
    return;
  }
  displayFram("DISPLAY_ALL_USER");
  cout << setw(7) << left << "ID" << setw(15) << left << "Name" << setw(20) << left << "Username"
       << setw(10) << left << "Role" << endl;
  cout << BRIGHT_BLUE << "==================================================" << RESET << endl;

  // Display user data
  for (int i = 0; i < count; i++) {
    cout << setw(7) << left << user[i].id << setw(15) << left << user[i].name << setw(20) << left
         << user[i].username << setw(10) << left;
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
  if (index < 0) {
    messageFailNoUser();
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
int searchUserByID(User user[], int userCount) {
  int keyId;
  int index;
  input(keyId, "Enter ID: ");
  if ((index = linearSearch(user, userCount, keyId)) != -1) {
    displayEachUser(user, index);
    return index;
  } else {
    messageFailFoundUser();
    return -1;
  }
}
int searchUserByName(User user[], int userCount) {
  string keyName;
  int index;
  inputName(keyName, " Enter Name: ");
  if ((index = linearSearch(user, userCount, keyName)) != -1) {
    displayEachUser(user, index);
    messageSuccessDisplay();
    return index;
  } else {
    messageFailFoundUser();
    return -1;
  }
}
void searchUser(User user[], int userCount) {
  int choice;  // Search by Name and ID;
  string keyName;
  input(choice, "Enter your chooise: ");

  switch (choice) {
    case SEARCH_ID:
      searchUserByID(user, userCount);
      break;
    case SEARCH_NAME:
      searchUserByName(user, userCount);
      break;
    case EXIT_SEARCH:
      break;

    default:
      messageFailInvalid();
      break;
  }
}
// Updated Function (User by name and id)
void updateFile(User user[], int count, const string &fileName) {
  ifstream originalFile(fileName);  // Open the original file
  ofstream tempFile("temp.txt");    // Open the temp file for writing

  if (!originalFile.is_open()) {
    messageFailOpenFileOrigin();
    return;
  }

  if (!tempFile.is_open()) {
    messageFailOpenFileTemporary();
    return;
  }

  string line;
  int index = 0;  // Keep track of the index to match user data

  // Loop through the original file and write updated data to temp file
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
    tempFile << user[index].id << ","        // Updated ID
             << user[index].name << ","      // Updated Name
             << user[index].username << ","  // Updated Username
             << currentPassword << ","       // Keep password unchanged
             << user[index].role << endl;    // Updated Role

    index++;
  }

  // Close both files
  originalFile.close();
  tempFile.close();

  // Replace the original file with the updated temporary file
  if (remove(fileName.c_str()) != 0) {
    messageErrorDeletingFile();
  } else if (rename("temp.txt", fileName.c_str()) != 0) {
    messageErrorRenameFile();
  } else {
    messageSuccessUpdateFile(count);
  }
}

// Update User
void update(User user[], int count, string fileName) {
  string newName;
  int newId, newRole;
  int index, choice;

  displaySearchToEdit();
  index = searchUserByID(user, count);

  displayEditMenu();
  input(choice, "Enter choice: ");
  switch (choice) {
    case UPDATE_NAME:
      if (index != -1) {
        inputName(newName, "Enter new name: ");
        user[index].name = newName;
        messageSuccessUpdate(newName);
      } else {
        messageFailFoundUser();
      }
      break;
    case UPDATE_ID:
      if (index != -1) {
        input(newId, "Enter new ID: ");
        user[index].id = newId;
        messageSuccessUpdate(user[index].name);
      } else {
        messageFailFoundUser();
      }
      break;
    case UPDATE_ROLE:
      if (index != -1) {
        input(newRole, "Enter new ID: ");
        user[index].role = newRole;
        messageSuccessUpdate(user[index].name);
      } else {
        messageFailFoundUser();
      }
      break;
    case EXIT_UPDATE:
      break;

    default:
      messageFailInvalid();
      break;
  };
  updateFile(user, count, fileName);
}

// Swapping and Short Function
void swappingUser(User &a, User &b) {
  User t = a;
  a = b;
  b = t;
}

void sortUser(User user[], int count, int key, int sortBy) {
  bool ascending = (sortBy == SORT_INCREASE);  // Flag for sorting order

  switch (key) {
    case SORT_NAME:  // Sort by name
      for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
          if ((ascending && user[j].name > user[j + 1].name) ||
              (!ascending && user[j].name < user[j + 1].name)) {
            swappingUser(user[j], user[j + 1]);
          }
        }
      }
      break;

    case SORT_ID:  // Sort by id
      for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
          if ((ascending && user[j].id > user[j + 1].id) ||
              (!ascending && user[j].id < user[j + 1].id)) {
            swappingUser(user[j], user[j + 1]);
          }
        }
      }
      break;

    case SORT_ROLE:  // Sort by role
      for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
          if ((ascending && user[j].role > user[j + 1].role) ||
              (!ascending && user[j].role < user[j + 1].role)) {
            swappingUser(user[j], user[j + 1]);
          }
        }
      }
      break;

    case SORT_USERNAME:  // Sort by username
      for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
          if ((ascending && user[j].username > user[j + 1].username) ||
              (!ascending && user[j].username < user[j + 1].username)) {
            swappingUser(user[j], user[j + 1]);
          }
        }
      }
      break;
    case EXIT_SORTS:
      break;
    default:
      messageFailInvalid();  // Invalid sort key
      return;
  }

  displayUser(user, count);  // Assuming displayUser only needs count
  messageSuccessSorted();
}

// Deleted Function (User by id)
void deleteUser(User users[], int &count, string fileName) {
  bool userDelete = false;
  int id;
  char verify;
  displayFram("DELETE");
  input(id, "Enter the ID of the User to delete:");
  for (int i = 0; i < count; i++) {
    if (users[i].id == id) {
      input(verify, "Are you sure you want to delete? (y/n): ");
      if (verify == 'y' || verify == 'Y') {
        messageSuccessDelete(users[i].name);
        users[i] = users[--count];
        userDelete = true;
      } else if (verify == 'n' || verify == 'N') {
        exit(0);
      } else {
        messageFailInvalid();
      }
    }
  }
  if (!userDelete) {
    messageFailFoundUser();
  }
  updateFile(users, count, fileName);
}
};  // namespace account

// Use Namespace For Word Feature:
namespace word {
void addWordToFile(const string &filePath) {
  ofstream file(filePath, ios::app);  // Open the file in append mode
  if (!file) {
    cerr << "Unable to open file for writing." << endl;
    return;
  }

  string newWord;
  cout << "Enter a new word to add: ";
  cin >> newWord;

  // Optional: Validate the word (can be extended)
  for (char c : newWord) {
    if (!isalpha(c)) {
      cout << "Invalid word! Please enter letters only." << endl;
      return;
    }
  }
}
// Add Function (Add Word)
void addword(string word[], int &currentcout, string fileName) {
  int count;
  displayFram("ADD_WORDS");
  input(count, "How many words you want to add? : ");
  for (int i = 0; i < count; i++) {
    cout << "Word [" << currentcout + 1 << "] :";
    cin >> word[currentcout];
    currentcout++;
  }
  addWordToFile(fileName);
  messageSuccess("ADD");
}
// Display Function
void displayWord(string word[], int &currentcout) {
  cout << BRIGHT_BLUE << "=======LIST_WORDS=======" << RESET << endl;
  for (int i = 0; i < currentcout; i++) {
    cout << i + 1 << ". " << word[i] << endl;
  }
  messageSuccess("Display");
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
    messageSuccess("Update");
  } else {
    messageFail(newWord);
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
  messageSuccess("Sort");
}
void deleteFunction(string arr[], int &count, string deleteKey) {
  int index = linearSearch(arr, count, deleteKey);
  char verify;
  if (index != -1) {
    input(verify, "Are you sure you want to delete? (y/n): ");
    if (verify == 'Y' || verify == 'y') {
      messageSuccessDeleteWord(arr[index]);
      for (int i = index; i < count - 1; i++) {
        arr[i] = arr[i + 1];
      }
      count--;
    } else if (verify = 'N', verify = 'n') {
      messageFailDeleteWord(arr[index]);
    }
  } else {
    messageFailFoundWord();
  }
}
};  // namespace word

/*======== Game Feature ========*/
// Load words from a file
int loadWords(const string &filePath, string words[], const int MAX_WORDS) {
  ifstream file(filePath);
  if (!file.is_open()) {
    cerr << "Error: Unable to open file \"" << filePath << "\"." << endl;
    return 0;
  }

  int wordCount = 0;
  while (file >> words[wordCount] && wordCount < MAX_WORDS) {
    wordCount++;
  }
  file.close();
  return wordCount;
}

// Select a random word
string selectRandomWord(string words[], int wordCount) {
  srand(time(0));
  return words[rand() % wordCount];
}
// Display the current progress
void displayProgress(const string &secretWord, const string &guessedLetters) {
  for (char letter : secretWord) {
    bool found = false;

    // Check if the letter is in guessedLetters
    for (int i = 0; i < guessedLetters.length(); ++i) {
      if (letter == guessedLetters[i]) {
        found = true;  // Letter has been guessed
        break;         // No need to check further
      }
    }

    // Print the letter if guessed; otherwise print an underscore
    if (found) {
      cout << letter << ' ';
    } else {
      cout << "_ ";
    }
  }
  cout << endl;  // Move to the next line after displaying the progress
}
void playGuessingGame(const int MAX_WORDS, const string fileWord) {
  string words[MAX_WORDS];
  string guessedLetters;
  int wordCount = loadWords(fileWord, words, MAX_WORDS);

  if (wordCount == 0) {
    cerr << "Error: No words found in the file." << endl;
    return;
  }

  string secretWord = selectRandomWord(words, wordCount);
  int attempts = 6;

  cout << "Welcome to the Guessing Word Game!" << endl;

  while (attempts > 0) {
    displayProgress(secretWord, guessedLetters);
    cout << "Attempts left: " << attempts << endl;

    string guess;
    cout << "Guess a word: ";
    cin >> guess;

    // Validate the guess for alphabetic characters
    bool isValid = true;
    for (char c : guess) {
      if (!isalpha(c)) {
        isValid = false;
        break;
      }
    }

    if (!isValid) {
      cerr << "Error: Invalid word! Please enter letters only." << endl;
      continue;
    }

    // Add unguessed letters from the guess to guessedLetters
    for (char letter : guess) {
      bool alreadyGuessed = false;
      for (int i = 0; i < guessedLetters.length(); ++i) {
        if (guessedLetters[i] == letter) {
          alreadyGuessed = true;
          break;
        }
      }
      if (!alreadyGuessed) {
        guessedLetters += letter;  // Add only if it hasn't been guessed
      }
    }

    // Check if the guess matches the secret word
    if (guess == secretWord) {
      cout << "\nCongratulations! You've guessed the word: " << secretWord << endl;
      return;
    } else {
      cout << "Sorry, that word is not correct." << endl;
      attempts--;
    }
  }

  cout << "\nSorry, you've run out of attempts. The word was: " << secretWord << endl;
}
