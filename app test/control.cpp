#include "features.cpp"
using namespace account;
using namespace word;

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
      input(updateWord, "Enter Word you want to updated: ");
      update(word, wordCount, updateWord);
      break;
    }
    case DELETE: {
      string deleteWord;
      displayWord(word,wordCount);
      input(deleteWord, "Enter the word you want to delete: ");
      deleteFunction(word, wordCount, deleteWord);
      break;
    }
    case SEARCH: {
      string keyWord;
      input(keyWord, "What word you want to search: ");
      if (linearSearch(word, wordCount, keyWord) != -1) {
        cout << GREEN << keyWord << " have in list" << RESET << endl;
      } else {
        cout << RED << keyWord << " not found" << RESET << endl;
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
      int edit, newId;
      string newName;
      displayEditMenu();
      displayUser(user,userCount);
      input(edit, "Enter your chooise: ");
      if (edit == 1) {
        input(newName, "Enter update Name: ");
        update(user, userCount, newName);
      } else if (edit == 2) {
        input(newId, "Enter update ID: ");
        update(user, userCount, newId);
      } else {
        cout <<RED<< "Invalid Input" <<RESET<< endl;
      }
      break;
    }
    case DELETE: {
      displayUser(user, userCount);
      deleteUser(user, userCount);
      break;
    }
    case SEARCH: {
      int keyId;
      string keyName;
      int choice;
      displaySearchMenu();
      input(choice, "Enter your chooise: ");
      if (choice == 1) {
        input(keyId, "Enter ID: ");
        if (linearSearch(user, userCount, keyId) != -1) {
          displayEachUser(user, linearSearch(user, userCount, keyId));
        } else {
          cout << RED << "User not found" << RESET << endl;
        }

        break;
      } else if (choice == 2) {
        input(keyName, " Enter Name: ");
        if (linearSearch(user, userCount, keyName) != -1) {
          displayEachUser(user, linearSearch(user, userCount, keyName));
        } else {
          cout << RED << "User not found" << RESET << endl;
        }
        break;
      } else {
        cout << RED << "Invalid Choise" << RESET << endl;
        break;
      }
    }
    case SHORT: {
      int keyShort;
      int choice;
      displayShort();
      input(choice,"Enter Choice: ");
      displayShortMenu(choice);
      input(keyShort, "Enter your chooise: ");
      shortFunction(user, userCount, keyShort, choice);
      break;

      case DISPLAY: {
        displayUser(user, userCount);
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
        input(controlWord, "Enter your chooise: ");
        controlMenuWord(controlWord, word, wordCount);
      } while (controlWord != 0);
      break;
    }
    case ACCOUNT: {
      int controlAccount;
      do {
        displayMenuControl("ACCOUNT");
        input(controlAccount, "Enter your chooise: ");
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