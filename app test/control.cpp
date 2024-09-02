#include <iostream>

#include "features.cpp"
using namespace std;

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

void controlMenuWord(int control, string word[], int& wordCount)

{
  switch (control) {
    case ADD: {
      addword(word, wordCount);


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
      if(linearSearch(word, wordCount, keyWord)!=-1){
      cout << GREEN << keyWord<<" alreay have" << RESET << endl;
      }else{
      cout << RED << keyWord<<" not found" << RESET << endl;
      }
      break;
    }
    case SHORT: {
      shortWord(word, wordCount);
      break;
    }
    case DISPLAY: {
      displayWord(word, wordCount);
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
void controlMenuAccount(int control, User user[], int& userCount, int maxUser) {
  switch (control) {
    case ADD: {
      addUser(user, userCount, maxUser);
      break;
    }
    case EDIT: {
      int edit, newId, newRole;
      string newName;
      cout << "What do you want to eddit? " << endl;
      cout << " 1. Name" << endl;
      cout << " 2. ID" << endl;
      cout<<"Enter choice:";
      cin >> edit;
      if (edit == 1) {
        cout << "Enter update Name: ";
        cin >> newName;
        update(user, userCount, newName, " name");
      } else if (edit == 2) {
        cout << "Enter update ID: ";
        cin >> newId;
        update(user, userCount, newId, " id");
      } else {
        cout << "Invalid Input" << endl;
      }
      break;
    }
    case DELETE: {
      deleteUser(user, userCount);
      break;
    }
    case SEARCH: {
      int keyId;
      string keyName;
      int choice;
      cout << "What word you want to search? " << endl;
      cout << "1. By ID" << endl;
      cout << "2. By Name" << endl;
      cout<<"Enter choice: ";
      cin >> choice;
      while (cin.fail()) {
          cin.clear();
          cin.ignore();
          cout << RED << "Invalid input." << RESET << endl;
          cout << " Enter your choice " << endl;
          cin >> choice;
        }
      if (choice == 1) {
        cout << " Enter ID: ";
        cin >> keyId;
        displayEachUser(user, linearSearch(user, userCount, keyId));
        break;
      } else if (choice == 2) {
        cout << " Enter Name: ";
        cin >> keyName;
        displayEachUser(user, linearSearch(user, userCount, keyName));
        break;
      } else {
        cout << RED << "Invalid Choise" << RESET << endl;
        break;
      }
    }
    case SHORT: {
      int keyShort;
      cout << "What do you want to short?" << endl;
      cout << "1. Name" << endl;
      cout << "2. ID" << endl;
      cout<<" Enter choice: ";
      cin >> keyShort;
        while (cin.fail()) {
          cin.clear();
          cin.ignore();
          cout << RED << "Invalid input." << RESET << endl;
          cout << " Enter your choice " << endl;
          cin >> keyShort;
        }
        shortFunction(user, userCount, keyShort);
        cout << GREEN << "Short User Successful!!" << RESET << endl;
        break;
      
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
}
void adminMenu(int choise, string word[], int& wordCount, User user[], int& userCount,
               int maxUser) {
  switch (choise) {
    case WORD: {
      int controlWord;
      do {
        displayMenuControl("WORD");
        cin >> controlWord;
        while (cin.fail()) {
          cin.clear();
          cin.ignore();
          cout << "Invalid input. Please enter Number: ";
          cin >> controlWord;
        }
        controlMenuWord(controlWord, word, wordCount);
      } while (controlWord != 0);
      break;
    }
    case ACCOUNT: {
      int controlAccount;
      do {
        displayMenuControl("ACCOUNT");
        cin >> controlAccount;
        while (cin.fail()) {
          cin.clear();
          cin.ignore();
          cout << RED << "Invalid input." << RESET << endl;
          cout << " Enter your choice " << endl;
          cin >> controlAccount;
        }
        controlMenuAccount(controlAccount, user, userCount, maxUser);
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