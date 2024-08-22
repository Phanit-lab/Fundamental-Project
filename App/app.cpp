#include<iostream>
using  namespace std;


// Display Fuunction
void displayMenuLogin(){
    cout<< "----------MENU----------"<<endl;
    cout<< "1. Register"<<endl;
    cout<< "2. Login"<<endl;
    cout<< "0. Exit the program"<<endl;
    cout<< "------------------------"<<endl;
    cout<< "Enter your chooise: ";
}
void displayMenuAdmin(){
    cout<< "-------ADMIN_MENU-------"<<endl;
    cout<< "1. Word Control"<<endl;
    cout<< "2. User Account Control"<<endl;
    cout<< "0. Back to MENU"<<endl;
    cout<< "------------------------"<<endl;
    cout<< "Enter your chooise: ";

}
void displayMenuControl(string control){
    cout<< "-------"<<control<<"_CONTROL-------"<<endl;
    cout<< "1. Add "<<control<<endl;
    cout<< "2. Edit "<<control<<endl;
    cout<< "3. Delete "<<control<<endl;
    cout<< "4. Search "<<control<<endl;
    cout<< "5. Short "<<control<<endl;
    cout<< "6. Display "<<control<<endl;
    cout<< "0. Back to ADMIN_MENU"<<endl;
    cout<< "------------------------"<<endl;
    cout<< "Enter your chooise: ";

}
// Control Menu Funtion
void controlMenu(int control)
{

    switch (control)
    {
        enum Menu
        {
            EXIT,
            ADD,
            EDIT,
            DELETE,
            SEARCH,
            SHORT,
            DISPLAY,
        };
    case ADD:
    {
        cout << "ADD..." << endl;
        break;
    }
    case EDIT:
    {
        cout << "EDIT.." << endl;
        break;
    }
    case DELETE:
    {
        cout << "DELETE..." << endl;
        break;
    }
    case SEARCH:
    {
        cout << "SEARCH..." << endl;
        break;
    }
    case SHORT:
    {
        cout << "SHORT..." << endl;
        break;
    }
    case DISPLAY:
    {
        cout << "DISPLAY..." << endl;
        break;
    }
    case EXIT:
    {
        cout << "Back to the USER Menu..." << endl;
        displayMenuLogin();
        
        break;
    }

    default:
    {
        break;
    }
    }
}
void userMenu(int user)
{

    switch (user)
    {
        enum Menu
        {
            EXIT,
            ADMIN,
            PLAYER
        };
    case ADMIN:
    {

        break;
    }
    case PLAYER:
    {
        cout << "PLAYER." << endl;
        break;
    }
    case EXIT:
    {
        cout << "Back to the Login Menu..." << endl;
        break;
    }

    default:
    {
        break;
    }
    }
}
void loginMenu(int choise)
{

    switch (choise)
    {
        enum Menu
        {
            EXIT,
            REGISTER,
            lOGIN
        };
    case REGISTER:
    {
        cout << "Register." << endl;
        break;
    }
    case lOGIN:
    {
        int control, userControl;
        string adminControl;
        displayMenuAdmin();
        cin >> control;
        if (control == 1){
            adminControl = "Word";
        }if(control == 2){
            adminControl = " User_Account";
        }
        displayMenuControl(adminControl);
        cin>> userControl;
        controlMenu(userControl);
        break;
    }
    case EXIT:
    {
        cout << "The program is exited." << endl;
        break;
    }

    default:
    {
        break;
    }
    }
}

int main(){
    int menuchoise;
    displayMenuLogin();
    cin>>menuchoise;
    loginMenu(menuchoise);
}