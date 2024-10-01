#include <iostream>
#include <string>
using namespace std;

struct MOD {
    int id;
    string brand_name;
    string suitable_car;
    double price;
};

void Admin(MOD bodykits[], int &count, const int MAXBDK);
void add_bodykit(MOD bodykits[], int &count, const int MAXBDK);
void display_bodykit_instock(const MOD bodykits[], int count);
void edit_bodykit_instock(MOD bodykits[], int count);
void delete_bodykit(MOD bodykits[], int &count);
void search_bodykit_instock(const MOD bodykits[], int count);

// User functions
void User(MOD bodykits[], int bodykits_count, MOD bucket[], int &bucket_count, const int MAXBDK);
void add_into_bucket(MOD bodykits[], int bodykits_count, MOD bucket[], int &bucket_count, const int MAXBDK);
void display_bodykit_inbucket_list(const MOD bucket[], int bucket_count);
void edit_bucket_list(MOD bucket[], int &bucket_count);
void delete_bodykit_from_bucket(MOD bucket[], int &bucket_count);
void search_bodykit_inbucket_list(const MOD bucket[], int bucket_count);
void add_bodykit(MOD bodykits[], int &count, const int MAXBDK);

// Admin Functions
void Admin(MOD bodykits[], int &count, const int MAXBDK){
    int choice;
        // this is admin menu
    do {
        cout<<"-------------------------------------"<<endl;
        cout<< "Admin Menu:\n";
        cout<<"-------------------------------------"<<endl;
        cout<<"1. Display all bodykits in stock\n";
        cout<<"2. Add bodykit\n";
        cout<<"3. Edit bodykit in stock\n";
        cout<<"4. Delete bodykit from stock\n";
        cout<<"5. Search bodykit in stock\n";
        cout<<"6. Exit Admin Menu\n";
        cout<<"-------------------------------------"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"-------------------------------------"<<endl;
        switch(choice){
            case 1:
                display_bodykit_instock(bodykits, count);
                break;
            case 2:
                add_bodykit(bodykits, count, MAXBDK);
                break;
            case 3:
                edit_bodykit_instock(bodykits, count);
                break;
            case 4:
                delete_bodykit(bodykits, count);
                break;
            case 5:
                search_bodykit_instock(bodykits, count);
                break;
            case 6:
                cout << "Exiting Admin Menu.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }while(choice != 6);
}
void add_bodykit(MOD bodykits[], int &count, const int MAXBDK){
    if (count >= MAXBDK) {
        cout << "Error: Cannot add more bodykits. The list is already full." << endl;
        return;
    }
    MOD new_bodykit;
    cout << "Enter ID: ";
    cin >> new_bodykit.id;
    cin.ignore(); // To clear the newline character from input buffer
    cout << "Enter bodykit brand: ";
    getline(cin, new_bodykit.brand_name);
    cout << "Enter suitable car for bodykit: ";
    getline(cin, new_bodykit.suitable_car);
    cout << "Enter price: ";
    cin >> new_bodykit.price;
    bodykits[count] = new_bodykit;
    count++;
}

void display_bodykit_instock(const MOD bodykits[], int count) {
    if (count == 0) {
        cout << "No bodykits available." << endl;
        return;
    }
    cout << "\nBodykits List:\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << bodykits[i].id << endl;
        cout << " Brand Name: " << bodykits[i].brand_name << endl;
        cout << " Suitable Car: " << bodykits[i].suitable_car << endl;
        cout << " Price: $" << bodykits[i].price << "\n";
    }
}

void edit_bodykit_instock(MOD bodykits[], int count) {
    int id;
    cout << "Enter ID of the bodykit to edit: ";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (bodykits[i].id == id) {
            cout << "Editing bodykit with ID " << id << "\n";
            cout << "Enter new Brand Name: ";
            cin.ignore(); // To clear the newline character from input buffer
            getline(cin, bodykits[i].brand_name);
            cout << "Enter new Suitable Car: ";
            getline(cin, bodykits[i].suitable_car);
            cout << "Enter new Price: ";
            cin >> bodykits[i].price;
            return;
        }
    }
    cout << "Bodykit with ID " << id << " not found.\n";
}

void delete_bodykit(MOD bodykits[], int &count) {
    int id;
    cout << "Enter ID of the bodykit to delete: ";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (bodykits[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                bodykits[j] = bodykits[j + 1];
            }
            count--;
            cout << "Bodykit with ID " << id << " has been deleted.\n";
            return;
        }
    }
    cout << "Bodykit with ID " << id << " not found.\n";
}

void search_bodykit_instock(const MOD bodykits[], int count) {
    int id;
    cout << "Enter ID of the bodykit to search: ";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (bodykits[i].id == id) {
            cout << "Bodykit found:\n";
            cout << "ID: " << bodykits[i].id << endl;
            cout << "Brand Name: " << bodykits[i].brand_name << endl;
            cout << "Suitable Car: " << bodykits[i].suitable_car << endl;
            cout << "Price: $" << bodykits[i].price << endl;
            return;
        }
    }
    cout << "Bodykit with ID " << id << " not found.\n";
}



// User Functions
void add_into_bucket(MOD bodykits[], int bodykits_count, MOD bucket[], int &bucket_count, const int MAXBDK) {
    if (bucket_count >= MAXBDK) {
        cout << "Error: Cannot add more bodykits to the bucket. The bucket is already full.\n";
        return;
    }
    int id;
    cout << "Enter ID of bodykit to add into bucket list: ";
    cin >> id;
    for (int i = 0; i < bodykits_count; i++) {
        if (bodykits[i].id == id) {
            bucket[bucket_count] = bodykits[i];
            bucket_count++;
            cout << "Bodykit with ID " << id << " added to the bucket list.\n";
            return;
        }
    }
    cout << "Bodykit with ID " << id << " not found in stock.\n";
}

void display_bodykit_inbucket_list(const MOD bucket[], int bucket_count) {
    if (bucket_count == 0) {
        cout << "No bodykits in the bucket list.\n";
        return;
    }
    cout << "Bodykits in Bucket List:\n";
    for (int i = 0; i < bucket_count; i++) {
        cout << "ID: " << bucket[i].id
             << "\nBrand Name: " << bucket[i].brand_name
             << "\nSuitable Car: " << bucket[i].suitable_car
             << "\nPrice: $" << bucket[i].price << "\n";
    }
}

void edit_bucket_list(MOD bucket[], int &bucket_count) {
    int id;
    cout << "Enter ID of the bodykit to edit in bucket list: ";
    cin >> id;
    for (int i = 0; i < bucket_count; i++) {
        if (bucket[i].id == id) {
            cout << "Editing bodykit with ID " << id << "\n";
            cout << "Enter new Brand Name: ";
            cin.ignore(); // To clear the newline character from input buffer
            getline(cin, bucket[i].brand_name);
            cout << "Enter new Suitable Car: ";
            getline(cin, bucket[i].suitable_car);
            cout << "Enter new Price: ";
            cin >> bucket[i].price;
            return;
        }
    }
    cout << "Bodykit with ID " << id << " not found in bucket list.\n";
}

void delete_bodykit_from_bucket(MOD bucket[], int &bucket_count) {
    int id;
    cout << "Enter ID of the bodykit to delete from bucket list: ";
    cin >> id;
    for (int i = 0; i < bucket_count; i++) {
        if (bucket[i].id == id) {
            for (int j = i; j < bucket_count - 1; j++) {
                bucket[j] = bucket[j + 1];
            }
            bucket_count--;
            cout << "Bodykit with ID " << id << " has been deleted from the bucket list.\n";
            return;
        }
    }
    cout << "Bodykit with ID " << id << " not found in bucket list.\n";
}

void search_bodykit_inbucket_list(const MOD bucket[], int bucket_count) {
    int id;
    cout << "Enter ID of the bodykit to search in bucket list: ";
    cin >> id;
    for (int i = 0; i < bucket_count; i++) {
        if (bucket[i].id == id) {
            cout << "Bodykit found in bucket list:\n";
            cout << "ID: " << bucket[i].id << endl;
            cout << "Brand Name: " << bucket[i].brand_name << endl;
            cout << "Suitable Car: " << bucket[i].suitable_car << endl;
            cout << "Price: $" << bucket[i].price << endl;
            return;
        }
    }
    cout << "Bodykit with ID " << id << " not found in bucket list.\n";
}
void User(MOD bodykits[], int bodykits_count, MOD bucket[], int &bucket_count, const int MAXBDK){
    int choice;
        // This is user menu
    do {
        
        cout<<"-------------------------------------"<<endl;
        cout<< "User Menu:\n";
        cout<<"-------------------------------------"<<endl;
        cout<<"1. Add bodykit to bucket list\n";
        cout<<"2. Display all bodykits in stock\n";
        cout<<"3. Display bodykits in bucket list\n";
        cout<<"4. Edit bodykit in bucket list\n";
        cout<<"5. Delete bodykit from bucket list\n";
        cout<<"6. Seach bodykit in bucket list\n";
        cout<<"7. Exit User Menu\n";
        cout<<"-------------------------------------"<<endl;
        cout<< "Enter your choice: ";
        cin>> choice;
        cout<<"-------------------------------------\n"<<endl;
        
        switch(choice){
            case 1:
                add_into_bucket(bodykits, bodykits_count, bucket, bucket_count, MAXBDK);
                break;
            case 2:
                display_bodykit_instock(bodykits, bodykits_count);
                break;
            case 3:
                display_bodykit_inbucket_list(bucket, bucket_count);
                break;
            case 4:
                edit_bucket_list(bucket, bucket_count);
                break;
            case 5:
                delete_bodykit_from_bucket(bucket, bucket_count);
                break;
            case 6:
                search_bodykit_inbucket_list(bucket, bucket_count);
                break;
            case 7:
                cout <<"Exiting User Menu.\n";
                break;
            default:
                cout <<"Invalid choice! Please try again.\n";
                break;
        }
    }while(choice != 7);
}