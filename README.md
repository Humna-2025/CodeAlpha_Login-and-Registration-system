# CodeAlpha_Login-and-Registration-system
✅ Program Overview
=
This is a simple authentication system written in C++ that allows:

Registering a new user

Logging in as an existing user

Storing user data (username and password) in a text file (Users.txt)

The system runs in a loop, offering a menu to choose between Register, Login, and Exit.

🔷 Classes and Methods
=
1️⃣ Class: AuthSystem
=
Handles all authentication logic.

2️⃣ Public Methods:
=
void registerUser()

Prompts for a username & password.

Checks if the username already exists.

Checks if inputs are not empty.

Appends the new user credentials to the file if valid.

Displays appropriate success/error messages.

void loginUser()

Prompts for username & password.

Reads through the file line by line.

Checks if the entered credentials match any record.

Displays success message if matched, otherwise error.

🔷 Main Function
=
int main()
Creates an instance of AuthSystem.

Displays a menu in a loop:
Reads the user’s choice and calls the corresponding function:

auth.registerUser() → Register

auth.loginUser() → Login

Exit the loop on 3

Print an error message for invalid choices.

🧪 Features
=
✅ Register new users

✅ Prevent duplicate usernames

✅ Prevent empty usernames/passwords

✅ Login with verification

✅ User-friendly menu-driven interface

🔷 Limitations / Notes
=
⚠ Passwords are stored in plain text — not secure.

⚠ No validation for special characters or password strength.

⚠ No support for deleting/updating users.

⚠ Not thread-safe (since it just appends and reads from the file).




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
 OUTPUT
 =
             1. Register
             2. Login
             3. Exit
             Enter choice: 1
             Enter username: hafsa123
             Enter password: 123
             Registration successful!

            1. Register
            2. Login
            3. Exit
            Enter choice: 2
            Enter username: hafsa123
            Enter password: 123
            Login successful! Welcome, hafsa123!
    
