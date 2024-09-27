#include "control.cpp"

void runningApp() {
  int loginChoice;
  const int MAX_USERS = 100;
  const int MAX_WORDS = 100;
  User user[MAX_USERS];
  string word[MAX_WORDS];
  int userCount;
  int wordCount = 0;
  string fileName = "user.bat";

  do {
    displayMenuLogin();
    input(loginChoice, "Enter your chooise: ");
    switch (loginChoice) {
      case REGISTER:
        addUser(user, userCount, MAX_USERS,fileName);
        break;
      case LOGIN: {
        string username, password;
        int control;
        int choise;
        displayFram("LOGIN_MENU");
        readUsersFromFile(user,userCount,fileName,MAX_USERS);
        input(username,"Enter username: ");
        input(password, "Enter password: ");
        if (login(user, username, password, userCount)) {
          messageSuccessLogin();
        do {
          displayMenuAdmin();
          input(choise, "Enter your chooise: ");
          adminMenu(choise, word, wordCount, user, userCount, MAX_USERS,fileName);
        } while (choise != 0);
        break;
        } else {
          messageFailLogin();
        break;
        }
      }
      case LOGIN_EXIT: {
        messageExitProgram();
        exit(0);
        break;
      }
      default: {
        messageFailInvalid();
        break;
      }
    }
  } while (loginChoice != 0);
}
