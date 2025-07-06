#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class AuthSystem
{
private:
 const string filename="E:\\INTERSHIP PROJECT\\INTERSHIP-1MONTH\\TASK-2\\Users.txt";

 bool userExists(const string username)
 {
 ifstream file("E:\\INTERSHIP PROJECT\\INTERSHIP-1MONTH\\TASK-2\\Users.txt");
 string user, pass;
 while (file >> user >> pass)
 {
 if (user == username)
 {
 return true;
 }
 }
 return false;
 }

public:
 void registerUser()
 {
 string username, password;

 cout << "Enter username: ";
 cin >> username;

 if (userExists(username))
 {
 cout << "Error: Username already exists." << endl;
 return;
 }

 cout << "Enter password: ";
 cin >> password;

 if (username.empty() || password.empty())
 {
 cout << "Error: Username and password cannot be empty." << endl;
 return;
 }

 ofstream file("E:\\INTERSHIP PROJECT\\INTERSHIP-1MONTH\\TASK-2\\Users.txt", ios::app);
 file << username << " " << password << endl;

 cout << "Registration successful!" << endl;
 }

 void loginUser()
 {
 string username, password;

 cout << "Enter username: ";
 cin >> username;
 cout << "Enter password: ";
 cin >> password;

 ifstream file("E:\\INTERSHIP PROJECT\\INTERSHIP-1MONTH\\TASK-2\\Users.txt");
 string user, pass;
 bool found = false;

 while (file >> user >> pass)
 {
 if (user == username && pass == password)
 {
 found = true;
 break;
 }
 }

 if (found)
 {
 cout << "Login successful! Welcome, " << username << "!" << endl;
 }
 else
 {
 cout << "Error: Invalid username or password." << endl;
 }
 }
};

int main()
{
 AuthSystem auth;
 int choice;

 while (true)
 {
 cout << endl;
 cout << "1. Register" << endl;
 cout << "2. Login" << endl;
 cout << "3. Exit" << endl;
 cout << "Enter choice: ";
 cin >> choice;

 if (choice == 1)
 {
 auth.registerUser();
 }
 else if (choice == 2)
 {
 auth.loginUser();
 }
 else if (choice == 3)
 {
 cout << "Exiting..." << endl;
 break;
 }
 else
 {
 cout << "Invalid choice. Try again." << endl;
 }
 }

 return 0;
}
