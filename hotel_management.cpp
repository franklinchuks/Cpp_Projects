#include<iostream>
using namespace std;

int main()
{
	int quantity;
	int choice;
	
//	Quantity
	int Qrooms = 0, Qpasta = 0, Qburger = 0, Qnoodles = 0, Qshakes = 0, Qchicken = 0;
	
//	food items sold
	int Srooms = 0, Spasta = 0, Sburger = 0, Snoodles = 0, Sshakes = 0, Schicken = 0;
	
//	total price of items
	int Total_room = 0, Total_pasta = 0, Total_burger = 0, Total_noodles = 0, Total_shakes = 0, Total_chicken = 0;
	
	cout << "\n Quantity of items we have";
	cout << "\n Rooms available: ";
	cin >> Qrooms;
	cout << "\n Quantity of Pasta: ";
	cin >> Qpasta;
	cout << "\n Quantity of Burger: ";
	cin >> Qburger;
	cout << "\n Quantity of Noodles: ";
	cin >> Qnoodles;
	cout << "\n Quantity of Shake: ";
	cin >> Qshakes;
	cout << "\n Quantity of Chicken-roll: ";
	cin >> Qchicken;
	
	m:
	cout << "\n\n Please select from the menu options ";
	cout << "\n\n1) Rooms";
	cout << "\n2) Pasta";
	cout << "\n3) Burger";
	cout << "\n4) Noodles";
	cout << "\n5) Shake";
	cout << "\n6) Chicken-roll";
	cout << "\n7) Information regarding sales and collection";
	cout << "\n8) Exit";
	
	cout << "\n\n Please enter your choice! ";
	cin >> choice;
	
	switch(choice)
	{
//		rooms
		case 1:
			cout << "\n\n Enter the number of rooms you want: ";
			
			cin >> quantity;
			if(Qrooms - Srooms >= quantity)
			{
				Srooms = Srooms + quantity;
				Total_room = Total_room + (quantity * 1200);
				cout << "\n\n\t\t" <<  quantity << "room/rooms have been alloted to you!";
			}
			else
				cout << "\n\tOnly " << Qrooms - Srooms << " rooms remaining in the hotel";
				break;
		
//		pasta		
		case 2:
			cout << "\n\n Enter Pasta Quantity: ";
			
			cin >> quantity;
			if(Qpasta - Spasta >= quantity)
			{
				Spasta = Spasta + quantity;
				Total_pasta = Total_pasta + (quantity * 250);
				cout << "\n\n\t\t" <<  quantity << "pasta is the order!";
			}
			else
				cout << "\n\tOnly " << Qpasta - Spasta << " pasta remaining in the hotel";
				break;
		
//		burger			
		case 3:
			cout << "\n\n Enter burger Quantity: ";
			
			cin >> quantity;
			if(Qburger - Sburger >= quantity)
			{
				Sburger = Sburger + quantity;
				Total_burger = Total_burger + (quantity * 120);
				cout << "\n\n\t\t" <<  quantity << "burger is the order!";
			}
			else
				cout << "\n\tOnly " << Qburger - Sburger << " burger remaining in the hotel";
				break;
		
//		noodles				
		case 4:
			cout << "\n\n Enter noodles Quantity: ";
			
			cin >> quantity;
			if(Qnoodles - Snoodles >= quantity)
			{
				Snoodles = Snoodles + quantity;
				Total_noodles = Total_noodles + (quantity * 120);
				cout << "\n\n\t\t" <<  quantity << "noodles is the order!";
			}
			else
				cout << "\n\tOnly " << Qnoodles - Snoodles << " noodles remaining in the hotel";
				break;
		
//		shakes						
		case 5:
			cout << "\n\n Enter shakes Quantity: ";
			
			cin >> quantity;
			if(Qshakes - Sshakes >= quantity)
			{
				Sshakes = Sshakes + quantity;
				Total_shakes = Total_shakes + (quantity * 120);
				cout << "\n\n\t\t" <<  quantity << "shakes is the order!";
			}
			else
				cout << "\n\tOnly " << Qshakes - Sshakes << " shakes remaining in the hotel";
				break;
		
//		chicken-roll						
		case 6:
			cout << "\n\n Enter chicken-roll Quantity: ";
			
			cin >> quantity;
			if(Qchicken - Schicken >= quantity)
			{
				Schicken = Schicken + quantity;
				Total_chicken = Total_chicken + (quantity * 120);
				cout << "\n\n\t\t" <<  quantity << "chicken is the order!";
			}
			else
				cout << "\n\tOnly " << Qchicken - Schicken << " chicken-roll remaining in the hotel";
				break;
		
//		details
		case 7:
			cout << "\n\t\tDetails of sales and collection";
			
			cout << "\n\n Number of rooms we had: " << Qrooms;
			cout << "\n\n Number of rooms we gave for rent" << Srooms;
			cout << "\n\n Remaining rooms: " << Qrooms - Srooms;
			cout << "\n\n Total rooms collection for the day: " << Total_room;
			
			cout << "\n\n Number of pasta we had: " << Qpasta;
			cout << "\n\n Number of pasta we gave for rent" << Spasta;
			cout << "\n\n Remaining pasta: " << Qpasta - Spasta;
			cout << "\n\n Total pasta orders for the day: " << Total_pasta;
			
			cout << "\n\n Number of burger we had: " << Qburger;
			cout << "\n\n Number of burger we gave for rent" << Sburger;
			cout << "\n\n Remaining burger: " << Qburger - Sburger;
			cout << "\n\n Total burger orders for the day: " << Total_burger;
			
			cout << "\n\n Number of noodles we had: " << Qnoodles;
			cout << "\n\n Number of noodles we gave for rent" << Snoodles;
			cout << "\n\n Remaining noodles: " << Qnoodles - Snoodles;
			cout << "\n\n Total noodles orders for the day: " << Total_noodles;
			
			cout << "\n\n Number of shakes we had: " << Qshakes;
			cout << "\n\n Number of shakes we gave for rent" << Sshakes;
			cout << "\n\n Remaining shakes: " << Qshakes - Sshakes;
			cout << "\n\n Total shakes orders for the day: " << Total_shakes;
			
			cout << "\n\n Number of chicken-roll we had: " << Qchicken;
			cout << "\n\n Number of chicken-roll we gave for rent" << Schicken;
			cout << "\n\n Remaining chicken-roll: " << Qchicken - Schicken;
			cout << "\n\n Total chicken-roll orders for the day: " << Total_chicken;
			
			cout << "\n\n\n Total orders for the day: " << Total_room + Total_pasta + Total_burger + Total_noodles + Total_shakes + Total_chicken;
		
//		exit	
		case 8:
			exit(0);
			
			default:
				cout << "\n Please select the numbers mentioned above!";
			
	}
	goto m;
	
	
	
	
	
}
