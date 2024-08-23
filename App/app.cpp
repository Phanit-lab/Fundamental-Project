#include <iostream>
#include "Function/display.cpp"
using namespace std;

// Function declaration
bool login(string username, string password);
void controlMenu(int control);
void adminMenu(int choise);
void registerUser();

// Main Function

int main()
{
    int loginChoice;

    do
    {
        displayMenuLogin();
        cin >> loginChoice;
        switch (loginChoice)
        {
            enum
            {
                EXIT,
                REGISTER,
                LOGIN
            };
        case REGISTER:
            registerUser();
            break;
        case LOGIN:
        {
            string username, password;
            cout << BRIGHT_BLUE << "-------LOGIN_MENU-------" << RESET << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (login(username, password))
            {
                int choise;
                cout << GREEN << "Login Successful!!" << RESET << endl;
                do
                {
                    displayMenuAdmin();
                    cin >> choise;
                    adminMenu(choise);
                } while (choise != 0);
            }
            else
            {
                cout << RED << "Incorect username or password" << RESET << endl;
            }

            break;
        }
        case EXIT:
            cout << RED << "The Program is Exited" << RESET << endl;
            exit(0);
            break;
        default:
            cout << RED << "Invalid choice!" << RESET << endl;
            break;
        }
    } while (loginChoice != 0);

    return 0;
}

/*
All Function
*/
bool login(string username, string password)
{
    string keyName = "phanit";
    string keyPassword = "123";
    if (username == keyName && password == keyPassword)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
        cout << GREEN << "ADD... Successful!!" << RESET << endl;
        break;
    }
    case EDIT:
    {
        cout << GREEN << "EDIT... Successful!!" << RESET << endl;
        break;
    }
    case DELETE:
    {
        cout << GREEN << "DELETE... Successful!!" << RESET << endl;
        break;
    }
    case SEARCH:
    {
        cout << GREEN << "SEARCH... Successful!!" << RESET << endl;
        break;
    }
    case SHORT:
    {
        cout << GREEN << "SHORT... Successful!!" << RESET << endl;
        break;
    }
    case DISPLAY:
    {
        cout << GREEN << "DISPLAY... Successful!!" << RESET << endl;
        break;
    }
    case EXIT:
    {
        cout << YELLOW << "Back to the USER Menu..." << RESET << endl;
        break;
    }

    default:
    {
        cout<<RED<<"Invalid choise"<<RESET<<endl;
        break;
    }
    }
}
void adminMenu(int choise)
{
    switch (choise)
    {
        {
            int control;

            enum Menu
            {
                EXIT,
                WORD,
                ACCOUNT,
                PLAY
            };
        case WORD:
        {
            int controlWord;
            do
            {
                displayMenuControl("WORD");
                cin >> controlWord;
                controlMenu(controlWord);
            } while (controlWord != 0);
            break;
        }
        case ACCOUNT:
        {
            int controlAccount;
            do
            {
                displayMenuControl("ACCOUNT");
                cin >> controlAccount;
                controlMenu(controlAccount);
            } while (controlAccount != 0);
            break;
        }
        case PLAY:
        {
            cout << RED << "GAME_WILL_RELEASE_SOON" << RESET << endl;
            break;
        }
        case EXIT:
        {
            cout << YELLOW << "Back to the Login Menu..." << RESET << endl;
            break;
        }

        default:
        {
            break;
        }
        }
    }
}
void registerUser()
{
    string name, username, password, id, role;
    cout << BRIGHT_BLUE << "---------REGISTER--------" << RESET << endl;
    cout << " Name: ";
    cin >> name;
    cout << " username: ";
    cin >> username;
    cout << " Password: ";
    cin >> password;
    cout << " ID: ";
    cin >> id;
    cout << " Role: " << endl;
    cout << " 1. Admin: " << endl;
    cout << " 2. User " << endl;
    cout << " Chouse role: ";
    cin >> role;
    cout << BRIGHT_BLUE << "------------------------" << RESET << endl;
    cout << GREEN << "Register Successful!!" << RESET << endl;
}