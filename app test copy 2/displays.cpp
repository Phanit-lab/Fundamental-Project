#include <iostream>
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string BRIGHT_BLUE = "\033[94m";

/*================ Menu Display =================*/
namespace displayMenu {
void displayFram(string text) {
  cout << BRIGHT_BLUE << "\n================ " << text << " ================" << RESET << endl;
}
void displayMenuLogin() {
  cout << BRIGHT_BLUE
       << "\n============================== THE GUESSING WORDS ==============================\n"
       << RESET << endl;
  cout << "1. Register" << endl;
  cout << "2. Login" << endl;
  cout << "0. Exit the program" << endl;
  cout << BRIGHT_BLUE << "------------------------\n" << RESET << endl;
}
void displayMenuAdmin() {
  displayFram("ADMIN_MENU");
  cout << "1. Word Control" << endl;
  cout << "2. User Account Control" << endl;
  cout << "3. Play Game" << endl;
  cout << "0. Back to MENU" << endl;
  cout << BRIGHT_BLUE << "------------------------\n" << RESET << endl;
}
void displayMenuControl(string control) {
  cout << BRIGHT_BLUE << "\n================= " << control << " _CONTROL=================\n"
       << RESET << endl;
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
  displayFram("SEARCH");
  cout << "What word you want to search? " << endl;
  cout << "1. By ID" << endl;
  cout << "2. By Name\n" << endl;
}
void displaySearchToEdit() { cout << "What ID you whant to Edit?" << endl; }
void displayEditMenu() {
  displayFram("EDIT");
  cout << "What do you want to eddit? " << endl;
  cout << " 1. Name" << endl;
  cout << " 2. ID" << endl;
  cout << " 3. Role\n" << endl;
}
void displayShort() {
  displayFram("SHORT");
  cout << "Do you want to short?" << endl;
  cout << "1. Increase" << endl;
  cout << "2. Discerease" << endl;
}
void displayShortMenu(int choice) {
  if (choice == 1) {
    cout <<BRIGHT_BLUE<< "=== SHORT_INCREASE ===" <<RESET<< endl;
    cout << "What do you want to short?" << endl;
    cout << "1. Name" << endl;
    cout << "2. ID" << endl;
    cout << "3. Role" << endl;
    cout << "4. Username\n" << endl;
  } else if (choice == 2) {
    cout <<BRIGHT_BLUE<< "=== SHORT_DISCREASE ===" <<RESET<< endl;
    cout << "What do you want to short?" << endl;
    cout << "1. Name" << endl;
    cout << "2. ID" << endl;
    cout << "3. Role" << endl;
    cout << "4. Username\n" << endl;
  } else {
    cout << RED << "Invalid Choice" << RESET << endl;
    ;
  }
}

void displayRole() {
  cout << " Role: " << endl;
  cout << " 1. Admin" << endl;
  cout << " 2. Player\n" << endl;
}

};  // namespace displayMenu

/*================ Message Display =================*/
namespace message {
/*------------Fail_Message-------------*/
void messageFail(const string& newWord) { 
  cout << RED << newWord << " not found\n" << RESET << endl; 
}

void messageFailInvalid() { 
  cout << RED << "Invalid Choice" << RESET << endl; 
}

void messageFailWriteToFile() {
  cout << RED << "Unable to open file for writing." << RESET << endl;
}

void messageFailOpenFile() { 
  cout << RED << "Error: Could not open the file." << RESET << endl; 
}

void messageFailFoundUser() { 
  cout << RED << "User Not Found!!" << RESET << endl; 
}

void messageFailDeleteWord(const string& word) {
  cout << RED << word << " is not deleted " << RESET << endl;
}

void messageFailFoundWord() { 
  cout << RED << "Word not found\n" << RESET << endl; 
}

void messageFailNoUser() { 
  cout << RED << "No users available to display." << RESET << endl; 
}

void messageFailOpenFileOrigin() {
  cout << RED << "Error: Could not open the original file." << RESET << endl;
}

void messageFailOpenFileTemporary() {
  cout << RED << "Error: Could not open the temporary file for writing." << RESET << endl;
}

void messageFailLogin() { 
  cout << RED << "Incorrect username or password" << RESET << endl; 
}

//--Message_Error---//
void messageErrorDeletingFile() {
  cout << RED << "Error deleting the original file." << RESET << endl;
}

void messageErrorRenameFile() {
  cout << RED << "Error renaming the temporary file." << RESET << endl;
}

/*------------Success_Message-------------*/
template <typename T>
void messageSuccess(const T& value) {
  cout << GREEN << value << " Successfully!!" << RESET << endl;
}

void messageSuccessDeleteWord(const string& word) {
  cout << GREEN << word << " already deleted!!\n" << RESET << endl;
}

void messageSuccessRegister() { 
  cout << GREEN << "Register Successful!!" << RESET << endl; 
}

void messageSuccessDisplay() { 
  cout << GREEN << "Display Successful!!" << endl; 
}

void messageSuccessUpdateFile(int count) {
  cout << GREEN << "File updated successfully with " << count << " records." << RESET << endl;
}

void messageSuccessUpdate(int value) { 
  cout << GREEN << value << " successfully updated\n" << RESET << endl; 
}

void messageSuccessUpdate(const string& text) {
  cout << GREEN << text << " successfully updated\n" << RESET << endl;
}

void messageSuccessSorted() { 
  cout << GREEN << "Already sorted Successfully!!\n" << RESET << endl; 
}

void messageSuccessDelete(const string& name) {
  cout << GREEN << "User " << name << " is deleted successfully!\n" << RESET << endl;
}

void messageSuccessSearchWord(const string& word) {
  cout << GREEN << word << " found in the list" << RESET << endl;
}

void messageSuccessLogin() { 
  cout << GREEN << "Login Successful!!" << RESET << endl; 
}

/*------------Back_And_Exit_Message-------------*/
void messageBack(const string& text) {
  cout << YELLOW << "Back to the " << text << " ..." << RESET << endl;
}

void messageExitProgram() { 
  cout << RED << "The Program has exited." << RESET << endl; 
}

};  // namespace message
