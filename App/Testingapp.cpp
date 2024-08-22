#include<iostream>
#include "Function/control.cpp"
#include "Function/menu.cpp"

using namespace std;

int  main(){
    int login;


    displayMenuLogin();
    cin>>login;
    loginMenu(login);


    return 0;
}