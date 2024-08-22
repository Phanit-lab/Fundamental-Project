#include <iostream>
#include "control.cpp"
using namespace std;

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
        int control;
        string usercontol;
        cin >> control;
        if (control == 1)
        {
            usercontol = "Word";
        }
        else if (control == 2)
        {
            usercontol = "User Accounts";
        };
        displayMenuControl(usercontol);
        

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
        int userchoise;
        displayMenuAdmin();
        cin >> userchoise;
        userMenu(userchoise);
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