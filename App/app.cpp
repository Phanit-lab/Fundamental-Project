#include <iostream>
#include "Function/display.cpp"
using namespace std;

// Function declaration
bool login(string username, string password);
void controlMenu(int control);
void adminMenu(int choise);
void registerUser(string &name, string &username, string &password, int &id, int &role);
void addword(string word[], int &currentcout);
void displayWord(string word[], int &currentcout);
// Enum:

// Main Function
const int MAX_WORD = 10;
string word[MAX_WORD];
int currentcout = 0;
int main()
{

    int loginChoice;
    string name, username, password;
    int id, role;

    do
    {
        enum Login_Menu
        {
            EXIT,
            REGISTER,
            LOGIN
        };
        displayMenuLogin();
        cin >> loginChoice;
        switch (loginChoice)
        {

        case REGISTER:
            registerUser(name, username, password, id, role);
            break;
        case 6:
            cout << "Name: " << name << endl;
            cout << "username: " << username << endl;
            cout << "password: " << password << endl;
            cout << "in: " << id << endl;
            if (role == 1)
            {
                cout << "Role: Admin" << endl;
            }
            else if (role == 2)
            {
                cout << "Role: Player" << endl;
            }
            else
            {
                cout << RED << "Role not found!!" << RESET << endl;
            }
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
            addword(word, currentcout);
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
            displayWord(word, currentcout);
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
            cout << RED << "Invalid choise" << RESET << endl;
            break;
        }
        }
    }
}
void adminMenu(int choise)

{
    enum Menu
    {
        EXIT,
        WORD,
        ACCOUNT,
        PLAY
    };
    switch (choise)
    {
        {
            int control;
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
void addword(string word[], int &currentcout)
{
    cout << BRIGHT_BLUE << "---------ADD_WORD--------" << RESET << endl;
    int count;
    cout << "How many words you want to add? : ";
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        cout << "Word [" << currentcout + 1 << "] :";
        cin >> word[currentcout];
        currentcout++;
    }
}
void displayWord(string word[], int &currentcout)
{
    cout << BRIGHT_BLUE << "--------LIST_WORDS-------" << RESET << endl;
    for (int i = 0; i <= currentcout; i++)
    {
        cout << "Word [" << i + 1 << "] : " << word[i] << endl;
    }
}
void registerUser(string &name, string &username, string &password, int &id, int &role)
{
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