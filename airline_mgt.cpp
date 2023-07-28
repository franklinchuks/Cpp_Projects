#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void main_menu();

class Management
{
	public:
		Management()
		{
			main_menu();
		}
};


class Details
{
	public:
		static string name, gender;
		int phone_no;
		int age;
		string add;
		static int c_id;
		char arr[100];

		void information()
		{
			cout << "\n Enter the customer ID: ";
			cin >> c_id;
			cout << "\n Enter the name: ";
			cin >> name;
			cout << "\n Age: ";
			cin >> age;
			cout << "\n Address: ";
			cin >> add;
			cout << "\n Gender: ";
			cin >> gender;
			cout << "Your details are safe with us \n" << endl;
		}
};


int Details::c_id;
string Details::name;
string Details::gender;

class Registration
{
	public:
		static int choice;
		int choice1;
		int back;
		static float charges;

		void flights()
		{
			string flight_n[] = {"Dubai", "Canada", "UK", "USA", "Australia", "Europe"};

			for(int a = 0; a < 6; a++)
			{
				cout << (a+1) << ".flight to" << flight_n[a] << endl;
			}
			cout << "\n Welcome to the airlines!" << endl;
			cout << "Press the number of the country which you want to book flight: " << endl;
			cin >> choice;

			switch(choice)
			{
				case 1:
				{
					cout << "________Welcome to Dubai Emirates_______\n" << endl;
					cout << "The following are the flights: " << endl;
					cout << "1. DUB - 498" << endl;
					cout << "\t 08-01-2022 8:00AM 10hrs EUR 500" << endl;
					cout << "1. DUB - 658" << endl;
					cout << "\t 08-01-2022 12:00PM 10hrs EUR 550" << endl;
					cout << "1. DUB - 788" << endl;
					cout << "\t 08-01-2022 5:00PM 10hrs EUR 450" << endl;

					cout << "\n Select the flight you want to book: ";
					cin >> choice1;

					if(choice1 == 1)
					{
						charges = 500;
						cout << "\n You have successfully booked the flight DUB - 498" << endl;
						cout << "You can go back to menu and take the ticket" << endl;
					}
					else if(choice1 == 2)
					{
						charges = 500;
						cout << "\n You have successfully booked the flight DUB - 658" << endl;
						cout << "You can go back to menu and take the ticket" << endl;
					}
					else if(choice1 == 3)
					{
						charges = 500;
						cout << "\n You have successfully booked the flight DUB - 788" << endl;
						cout << "You can go back to menu and take the ticket" << endl;
					}
					else
					{
						cout <<"Invalid input";
						flights();
					}
					cout << "Press any key to go back to the main menu";
					cin >> back;

					if(back == 1)
					{
						main_menu();
					}
					else
					{
						main_menu();
					}
				}

				case 2:
				{
					cout << "________Welcome to Canadian Airlines_______\n" << endl;
					cout << "The following are the flights: " << endl;
					cout << "1. CAD - 498" << endl;
					cout << "\t 08-01-2022 8:00AM 10hrs EUR 500" << endl;
					cout << "1. CAD - 658" << endl;
					cout << "\t 08-01-2022 12:00PM 10hrs EUR 550" << endl;
					cout << "1. CAD - 788" << endl;
					cout << "\t 08-01-2022 5:00PM 10hrs EUR 450" << endl;

					cout << "\n Select the flight you want to book: ";
					cin >> choice1;

					if(choice1 == 1)
					{
						charges = 500;
						cout << "\n You have successfully booked the flight CAD - 498" << endl;
						cout << "You can go back to menu and take the ticket" << endl;
					}
					else if(choice1 == 2)
					{
						charges = 500;
						cout << "\n You have successfully booked the flight CAD - 658" << endl;
						cout << "You can go back to menu and take the ticket" << endl;
					}
					else if(choice1 == 3)
					{
						charges = 500;
						cout << "\n You have successfully booked the flight CAD - 788" << endl;
						cout << "You can go back to menu and take the ticket" << endl;
					}
					else
					{
						cout <<"Invalid input";
						flights();
					}
					cout << "Press any key to go back to the main menu";
					cin >> back;

					if(back == 1)
					{
						main_menu();
					}
					else
					{
						main_menu();
					}
				}
				default:
				{
					cout << "Invalid input" <<endl;
					main_menu();
					break;
				}
			}
			
		}
};

float Registration::charges;
int Registration::choice;

class Ticket: public Registration, Details
{
	public:
		void Bill()
		{
			string destination = " ";
			ofstream outf("records.txt");
			{
				outf << "_____________XYZ Airlines__________" << endl;
				outf << "_______________Ticket___________" << endl;
				outf << "_______________________________" << endl;

				outf << "Customer ID: " << Details::c_id << endl;
				outf << "Customer Name: " << Details::name << endl;
				outf << "Customer Gender: " << Details::gender << endl;
				outf << "\t Description" << endl;

				if(Registration::choice == 1)
				{
					destination = "Dubai";
				}
				else if(Registration::choice == 2)
				{
					destination = "Canada";
				}
				else if(Registration::choice == 3)
				{
					destination = "UK";
				}

				outf << "Destination \t\t" << destination << endl;
				outf << "Flight cost: \t\t" << Registration::charges << endl;
			}
			outf.close();
		}
		void disp_bill()
		{
			ifstream ifs("records.txt");
			{
				if(!ifs)
				{
					cout << "File error!" << endl;
				}
				while(!ifs.eof())
				{
					ifs.getline(arr, 100);
					cout << arr << endl;
				}
			}
			ifs.close();
		}
};

void main_menu()
{
	int l_choice;
	int s_choice;
	int back;
	
	cout << "\t        XYZ Airlines    \n" << endl;
	cout << "\t________Main Menu_______\n" << endl;
	
	cout << "\t__________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	
	
	cout << "\t|\t Press 1 to add the customer details \t|" << endl;
	cout << "\t|\t Press 2 for Flight Registration     \t|" << endl;
	cout << "\t|\t Press 3 for Ticket and Charges      \t|" << endl;
	cout << "\t|\t Press 4 to Exit                     \t|" << endl;
	
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t__________________________" << endl;

	cout << "Enter the choice: " << endl;
	cin >> l_choice;

	Details d;
	Registration r;
	Ticket t;

	
	switch (l_choice)
	{
		case 1:
		{
			cout << "______________Customers______________\n" << endl;
			d.information();
			cout << "Press 1 to go back to the Main menu" << endl;
			cin >> back;

			if(back == 1)
			{
				main_menu();
			}
			else
			{
				main_menu();
			}
			break;
		}

		case 2:
		{
			cout << "_______Book a flight using this system_______\n" << endl;
			r.flights();
			break;
		}
		case 3:
		{
			cout << "_______Get your ticket_______\n" << endl;
			t.disp_bill();

			cout << "Your ticket is printed, you can collect it \n" << endl;
			cout << "Press 1 to display your ticket" << endl;

			cin >> back;

			if(back == 1)
			{
				t.disp_bill();
				cout << "Press any key to go back to main menu: ";
				cin >> back;

				if(back == 1)
				{
					main_menu();
				}
				else
				{
					main_menu();
				}
			}
			else
			{
				main_menu();
			}
			break;
		}
			
		case 4:
		{
			cout << "\n\n\t__________Thank you________" << endl;
			break;
		}
		
		default:
		{
			cout << "Invalid input, please try again!\n" << endl;
			main_menu();
			break;
		}
	}
}


int main()
{
	Management Mobj;
	return 0;
}
