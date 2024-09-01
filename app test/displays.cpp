#include <iostream>
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string BRIGHT_BLUE = "\033[94m";

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