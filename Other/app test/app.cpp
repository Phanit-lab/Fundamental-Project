#include "control.cpp"



void runningApp() {
  int loginChoice;
  const int MAX_USERS = 100;
  const int MAX_WORDS = 100;
  User user[MAX_USERS];
  string word[MAX_WORDS];
  int userCount = 0;
  int wordCount = 0;

  do {
    displayMenuLogin();
    input(loginChoice,"Enter your chooise: ");
    switch (loginChoice) {
      case REGISTER:
        addUser(user, userCount, MAX_USERS);
        break;
      case LOGIN: {
        string username, password;
        int control;
        int choise;
        displayFram("LOGIN_MENU");
        input(username,"Enter username: ");
        input(password, "Enter password: ");
        if (login(user, username, password, userCount)) {
          cout << GREEN << "Login Successful!!" << RESET << endl;
          do {
            displayMenuAdmin();
            input(choise,"Enter your chooise: ");
            adminMenu(choise, word, wordCount, user, userCount, MAX_USERS);
          } while (choise != 0);
          break;
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
}
