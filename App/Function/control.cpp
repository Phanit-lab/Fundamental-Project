#include<iostream>
using namespace std;

void displayMenuLogin(){
    cout<< "----------MENU----------"<<endl;
    cout<< "1. Register"<<endl;
    cout<< "2. Login"<<endl;
    cout<< "3. Exit the program"<<endl;
    cout<< "------------------------"<<endl;
    cout<< "Enter your chooise: ";
}
void displayMenuAdmin(){
    cout<< "-------ADMIN_MENU-------"<<endl;
    cout<< "1. Word Control"<<endl;
    cout<< "2. User Account Control"<<endl;
    cout<< "3. Back to MENU";
    cout<< "------------------------"<<endl;
    cout<< "Enter your chooise: ";

}
void displayMenuControl(string control){
    cout<< "-------"<<control<<"CONTROL-------"<<endl;
    cout<< "1. Add "<<control<<endl;
    cout<< "2. Edit "<<control<<endl;
    cout<< "3. Delete "<<control<<endl;
    cout<< "4. Search "<<control<<endl;
    cout<< "5. Short "<<control<<endl;
    cout<< "6. Display "<<control<<endl;
    cout<< "7. Back to ADMIN_MENU"<<endl;
    cout<< "------------------------"<<endl;
    cout<< "Enter your chooise: ";

}