#include "features.cpp"
using namespace account;
using namespace word;

int main() {
  const int MAX_USERS = 100;
  User user[MAX_USERS];
  int usersCount;
  int key;
  readUsersFromFile(user, usersCount, "user.txt", MAX_USERS);
  input(key, "Enter ID: ");
  displayEachUser(user, linearSearch(user, usersCount, key), MAX_USERS);
  // displayUser(user,usersCount,MAX_USERS);
  return 0;
}