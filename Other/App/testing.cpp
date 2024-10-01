#include <iostream>
using namespace std;

void adminMenu(int adminControl);
void controlMenu(bool adminControl, int control);

int main() {
  int addminContrl, control;
  do {
    cout << "1. Word Control" << endl;
    cout << "2. Account Control" << endl;
    cin >> addminContrl;
    adminMenu(addminContrl);
    return 0;
  } while (addminContrl != 0);
}

// Function:
void adminMenu(int adminControl) {
  int control = adminControl;
  switch (adminControl) {
    case 1:
      cout << "ADD WORD Control " << endl;
      cout << "1. ADD Word" << endl;
      cout << "2. EDIT Word" << endl;
      controlMenu(adminControl, control);
      break;
    case 2:
      cout << "ADD Account control " << endl;
      cout << "1. ADD Account" << endl;
      cout << "2. EDIT Account" << endl;
      controlMenu(adminControl, control);
      break;
    case 0:
      cout << "Back to the Login Menu" << endl;
    default:
      break;
  }
}
void controlMenu(bool adminControl, int control) {
  switch (control) {
    case 1:
      if (adminControl) {
        cout << "Word Control";
      } else if (adminControl = false) {
        cout << "Acccount Control";
      }
      break;
    case 2:
      if (adminControl) {
        cout << "Word Control";
      } else if (adminControl = false) {
        cout << "Acccount Control";
      }
      break;
    case 3:
      if (adminControl) {
        cout << "Word Control";
      } else if (adminControl = false) {
        cout << "Acccount Control";
      }
      break;
    case 4:
      if (adminControl) {
        cout << "Word Control";
      } else if (adminControl = false) {
        cout << "Acccount Control";
      }
      break;
    case 5:
      if (adminControl) {
        cout << "Word Control";
      } else if (adminControl = false) {
        cout << "Acccount Control";
      }
      break;
    case 6:
      if (adminControl) {
        cout << "Word Control";
      } else if (adminControl = false) {
        cout << "Acccount Control";
      }
      break;

    case 0:
      cout << "Back to the Admin Menu..." << endl;
      break;

    default:
      cout << "Invalid Choise." << endl;
      break;
  }
}

void addFunction(string word[], int &currentcout) {
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
void displayFunction(string word[], int &currentcout) {
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
void updateFunction(string array[], int count, string update, string name) {
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
void swappingFunction(string &a, string &b) {
  string t;
  t = a;
  a = b;
  b = t;
}
void shortFunction(string arr[], int count) {
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        swappingFunction(arr[j], arr[j + 1]);
      }
    }
  }
}
void deleteFunction(string arr[], int &count, string deleteWord) {
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