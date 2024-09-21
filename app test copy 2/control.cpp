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
      displayWord(word, wordCount);
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
void controlMenuAccount(int control, User user[], int& userCount, const int MAX_USERS) {
  switch (control) {
    case ADD: {
      addUser(user, userCount, MAX_USERS);
      break;
    }
    case EDIT: {
      int choice, newId;
      string newName;
      displayEditMenu();
      input(choice, "Enter your chooise: ");
      displayUser(user, userCount, MAX_USERS);
      update(user, userCount, choice, MAX_USERS);
      break;
    }
    case DELETE: {
      displayUser(user, userCount, MAX_USERS);
      deleteUser(user, userCount, MAX_USERS);
      break;
    }
    case SEARCH: {
      int choice;
      readUsersFromFile(user,userCount,"user.txt",MAX_USERS);
      searchUser(user,userCount,MAX_USERS);
      break;
    }
    case SHORT: {
      int keyShort;
      int choice;
      displayShort();
      input(choice, "Enter Choice: ");
      displayShortMenu(choice);
      input(keyShort, "Enter your chooise: ");
      shortFunction(user, userCount, keyShort, choice, MAX_USERS);
      break;

      case DISPLAY: {
        displayUser(user, userCount, MAX_USERS);
        cout << GREEN << "Display Successful!!" << endl;
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