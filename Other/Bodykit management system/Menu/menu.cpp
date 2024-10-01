#include<iostream>
using namespace std;

void menu_of_program(){
// noted : 
    // BDK full word is Bodykits
    const int MAXBDK = 20;
    MOD bodykits[MAXBDK];   // we used array for bodykits here to store bodykit info in stockk
    MOD bucket[MAXBDK];     // we used array for bucket is to store body kit info user have buy in bucket list for( user featured)
    int bodykits_count = 0; // use to Count for the number of bodykits that available in the stock
    int bucket_count = 0;   // count for the number of bodykits in user bucket list
    int choice;
        // main menu of program (option)
    do {
        cout<<"-------------------------------------"<<endl;
        cout<<"Body Kit Management Application\n";
        cout<<"-------------------------------------"<<endl;
        cout << "1. User Feature\n";
        cout << "2. Admin Feature\n";
        cout << "3. Exit Program\n";
        cout<<"-------------------------------------"<<endl;
        cout << "Enter your choice:  ";
        cin >> choice;
        cout<<"-------------------------------------\n"<<endl;
        // menu choice option for user and admin
        switch (choice){
            case 1:
                User(bodykits, bodykits_count, bucket, bucket_count, MAXBDK);
                break;
            case 2:
                Admin(bodykits, bodykits_count, MAXBDK);
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 3);
}
   