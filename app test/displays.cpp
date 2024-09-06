#include <iostream>
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string BRIGHT_BLUE = "\033[94m";

void displayfram(string text) {
  cout <<BRIGHT_BLUE<< "\n================ " << text << " ================\n" <<RESET<< endl;
}
void displayMenuLogin() {
  cout<<BRIGHT_BLUE<<"\n============================== THE GUESSING WORDS ==============================\n"<<RESET<<endl;
  cout << "1. Register" << endl;
  cout << "2. Login" << endl;
  cout << "0. Exit the program" << endl;
  cout << BRIGHT_BLUE << "------------------------\n" << RESET << endl;
}
void displayMenuAdmin() {
  displayfram("ADMIN_MENU");
  cout << "1. Word Control" << endl;
  cout << "2. User Account Control" << endl;
  cout << "3. Play Game" << endl;
  cout << "0. Back to MENU" << endl;
  cout << BRIGHT_BLUE << "------------------------\n" << RESET << endl;
}
void displayMenuControl(string control) {

  cout <<BRIGHT_BLUE<< "\n================= " << control << " _CONTROL=================\n" <<RESET<< endl;
  cout << "1. Add " << control << endl;
  cout << "2. Edit " << control << endl;
  cout << "3. Delete " << control << endl;
  cout << "4. Search " << control << endl;
  cout << "5. Short " << control << endl;
  cout << "6. Display " << control << endl;
  cout << "0. Back to ADMIN_MENU" << endl;
  cout << BRIGHT_BLUE << "------------------------\n" << RESET << endl;
}
void displaySearchMenu() {
  displayfram("SEARCH");
  cout << "What word you want to search? " << endl;
  cout << "1. By ID" << endl;
  cout << "2. By Name\n" << endl;
}
void displayEditMenu() {
  displayfram("EDIT");
  cout << "What do you want to eddit? " << endl;
  cout << " 1. Name" << endl;
  cout << " 2. ID\n" << endl;
}
void displayShortMenu() {
displayfram("SHORT");
  cout << "What do you want to short?" << endl;
  cout << "1. Name" << endl;
  cout << "2. ID\n" << endl;
}
void displayRole() {
  cout << " Role: " << endl;
  cout << " 1. Admin" << endl;
  cout << " 2. Player\n" << endl;
}