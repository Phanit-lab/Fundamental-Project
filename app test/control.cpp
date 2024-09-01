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
void controlMenuAccount(int control, User user[], int& userCount) {
    switch (control) {
      case ADD: {

        addUser(user, userCount);
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
void adminMenu(int choise, int controlWord, string word[], int& wordCount, User user[],
               int& userCount, int controlAccount) {
  switch (choise) {
    case WORD: {
      do {
        displayMenuControl("WORD");
        cin >> controlWord;
        controlMenuWord(controlWord,word,wordCount);
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