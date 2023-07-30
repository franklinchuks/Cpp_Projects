#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "Security System" << endl;

    cout << "_____________________" << endl;
    cout << "| 1. Register |" << endl;
    cout << "| 2. Login |" << endl;
    cout << "| 3. Change Password |" << endl;
    cout << "| 4. Exit |" << endl;

    do
    {
        cout << endl << endl;
        cout << "Enter your choice: " << endl;
        cin >> a;

        switch(a)
        {
            case 1:
            {
                cout << "_____________________" << endl;
                cout << "_______Register______" << endl;
                cout << "_____________________" << endl;
                cout << "Enter your username: " << endl;
                cin >> name;
                cout << "Enter your password: " << endl;
                cin >> password0;
                cout << "Enter your age: " << endl;
                cin >> age;
                
                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open())
                {
                    of1 << name << "\n";
                    of1 << password0 << "\n";
                    cout << "Registration successful" << endl;
                }
                break;
            }
            case 2:
            {
                cout << "_____________________" << endl;
                cout << "_______Login______" << endl;
                cout << "_____________________" << endl;
                cout << "Enter your username: " << endl;
                cin >> name;
                cout << "Enter your password: " << endl;
                cin >> password0;
                
                i = 0;
                ifstream of2;
                of2.open("file.txt");
                if(of2.is_open())
                {
                    while(!of2.eof())
                    {
                        while(getline(of2, text))
                        {
                            istringstream iss(text);
                            iss >> word;
                            creds[i] = word;
                            i++;
                        }
                        if(user == creds[0] && pass == creds[1])
                        {
                            cout << "Login successful" << endl;
                            cout << endl << endl;

                            cout << "Details: " << endl;

                            cout << "Username: " + name << endl;
                            cout << "Password: " + pass << endl;
                            cout << "Age: " + age << endl;
                        }
                        else
                        {
                            cout << "Incorrect credentials" << endl;
                            cout << "| 1. Press 2 to Login |" << endl;
                            cout << "| 1. Press 3 to change password |" << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                cout << "__________Change Password_______" << endl;
                cout << "Enter the old password: ";
                cin >> old;

                ifstream of0;
                of0.open("file.txt");
                if(of0.is_open())
                {
                    while(of0.eof())
                    {
                        while(getline(of0, text))
                        {
                            istringstream iss(text)
                            iss >> word1;
                            cp[i] = word1;
                            i++;
                        }
                        if(old = cp[1])
                        {
                            of0.close();
                            ofstream of1;
                            if(of1.is_open())
                            {
                                cout << "Enter your new password: ";
                                cin >> password1;
                                cout << "Enter your new password again: ";
                                cin >> password2;

                                if(password1 == password2)
                                {
                                    of1 << cp[0] << "\n";
                                    of1 << password1;
                                    cout << "Password changed successfully" << endl;
                                }
                                else
                                {
                                    of1 << cp[0] << "\n";
                                    of1 << old;
                                    cout << "Password do not match!" << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Please enter a valid password" << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                cout << "_______Thank you!_______";
                break;
            }
            default:
            {
                cout << "Enter a valid choice!";
            }
        }
    }
    while(a!4);
}