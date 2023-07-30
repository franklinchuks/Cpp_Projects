#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
	int c;
	cout << "\t\t\t___________________________________\n\n\n";
	cout << "\t\t\t      Welcome to the Login Page    \n\n\n";
	cout << "\t\t\t______________  MENU  _____________\n\n\n";
	cout << "\t\t\t| Press 1 to Login                |" << endl;
	cout << "\t\t\t| Press 2 to Register             |" << endl;
	cout << "\t\t\t| Press 3 if forgot password      |" << endl;
	cout << "\t\t\t| Press 4 to Exit                 |" << endl;
	cout << "\n\t\t\t Please enter your choice: ";
	cin >> c;
	cout << endl;
	
	switch(c)
	{
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
			
		case 3:
			forgot();
			break;
			
		case 4:
			cout << "\t\t\t Thank you! \n\n";
			
		default:
			system("cls");
			cout << "\t\t\t Please select from the options given above \n" << endl;
			main();
	}
	
}

void login()
{
	int count;
	string user_id, password, id, pass;
	system("cls");
	cout << "\t\t\t Please enter the username and password: " << endl;
	cout << "\t\t\t Username: ";
	cin >> user_id;
	cout << "\t\t\t Password: ";
	cin >> password;
	
	ifstream input("records.txt");
	
	while(input >> id >> pass)
	{
		if (id == user_id && pass == password)
		{
			count = 1;
			system("cls");			
		}
		else
		{
			count = 0;
			system("cls");
		}
	}
	input.close();
	
	if(count == 1)
	{
		cout << user_id << "\n Your login is successful \n Thanks for logging in! \n";
	}
	else
	{
		cout << "\n Login error \n Please check your username and password \n";
	}
}


void registration()
{
	string r_user_id, r_password, r_id, r_pass;
	system("cls");
	cout << "\t\t\t Please enter the Username: " << endl;
	cin >> r_user_id;
	cout << "\t\t\t Please enter the Password: ";
	cin >> r_password;
	
	ofstream f1("records.txt", ios::app);
	
	f1 << r_user_id << ' ' << r_password << endl;
	system("cls");
	
	cout << "\n\t\t\t Registration was successful! \n";
}


void forgot()
{
	int option;
	system("cls");
	cout << "\t\t\t You forgot your password? \n" << endl;
	cout << "Press 1 to search your id by username" << endl;
	cout << "Press 2 to go back to the main menu" << endl;
	cout << "\t\t\t Enter your choice: ";
	cin >> option;
	
	switch(option)
	{
		case 1:
			{
				int count = 0;
				string s_user_id, s_id, s_pass;
				cout << "\n\t\t Enter the username which you remembered: ";
				cin >> s_user_id;
				
				ifstream f2("records.txt");
				
				while(f2 >> s_id >> s_pass)
				{
					if(s_id == s_user_id)
					{
						count = 1;
					}
				}
				f2.close();
				if(count == 1)
				{
					cout << "\n\n Your account is found! \n";
					cout << "\n\n Your password is: " << s_pass;
					main();
				}
				else
				{
					cout << "\n\t Sorry! Your account was not found! \n";
					main();
				}
				break;
			}
		case 2:
			{
				main();
			}
		default:
			cout << "\t\t\t Wrong choice, please try again" << endl;
			forgot();
	}
}
	
	


