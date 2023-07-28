#include <iostream>
#include <fstream>

using namespace std;

class Shopping
{
	private:
		int p_code;
		float price;
		float dis;
		string p_name;
		
	public:
		void menu();
		void admin();
		void buyer();
		void add ();
		void edit();
		void rem();
		void list();
		void receipt();		
};

void Shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout << "\t\t\t_________________________\n";
	cout << "\t\t\t                         \n";
	cout << "\t\t\t   Supermarket Main Menu \n";
	cout << "\t\t\t_________________________\n";
	cout << "\t\t\t                         \n";
	cout << "\t\t\t| 1) Administrator      |\n";
	cout << "\t\t\t| 2) Buyer              |\n";
	cout << "\t\t\t| 3) Exit               |\n";
	cout << "\t\t\t                         \n";
	cout << "\n\t\t     Please select!        ";
	cin >> choice;
	
	switch(choice)
	{
		case 1:
			cout << "\t\t\t   Please Login  \n";
			cout << "\t\t\t   Enter Email   \n";
			cin >> email;
			cout << "\t\t\t Password        \n";
			cin >> password;
			
			if (email == "admin" && password == "pass")
			{
				admin();
			}
			else
			{
				cout << "Invalid email/password";
			}
			break;
		
		case 2:
			{
				buyer();
			}
		
		case 3:
			{
				exit(0);
			}
			
		default:
			{
				cout << "Please select from the given options";
			}
	}
	
goto m;
};

void Shopping :: admin()
{
	m:
	int choice;
	cout << "\n\n\t\t\t   Administrator Menu    \n";
	cout << "\n\t\t\t| 1) Add the product      |\n";
	cout << "\n\t\t\t| 2) Modify the product   |\n";
	cout << "\n\t\t\t| 3) Delete the product   |\n";
	cout << "\n\t\t\t| 4) Back to main menu    |\n";
	
	cout << "\n\n\t   Please enter your choice: \n";
	cin >> choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout << "Invalid choice!";
	}
	goto m;
}

void Shopping::buyer()
{
	m:
	int choice;
	cout << "\n\n\t\t\t   Buyer Menu      \n";
	cout << "\n\t\t\t| 1) Buy product    |\n";
	cout << "\n\t\t\t| 2) Go back        |\n";
	
	cout << "\n\n\t Enter your choice:    \n";
	cin >> choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
		default:
			cout << "Invalid choice!";
	}
	goto m;
 }
 
void Shopping::add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout << "\n\n\t\t\t Add new product";
	cout << "\n\n\t Product code";
	cin >> p_code;
	cout << "\n\n\t Product name";
	cin >> p_name;
	cout << "\n\n\t Product price";
	cin >> price;
	cout << "\n\n\t Product discount";
	cin >> dis;
	
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data << " " << p_code << " " << p_name << " " << price << " " << dis << "\n";
		data.close();
	}
	else
	{
		data >> c >> n >> p >> d;
		
		while(!data.eof())
		{
			if(c == p_code)
			{
				token++;
			}
			data >> c >> n >> p >> d;
		}
		data.close();
		if(token == 1)
		goto m;
		else
		{
			data.open("database.txt", ios::app|ios::out);
			data << " " << p_code << " " << p_name << " " << price << " " << dis << "\n";
			data.close();
		}
	}
	cout << "\n\n\t\t Record inserted!";
}

void Shopping::edit()
{
	fstream data, data1;
	
	int p_key;
	int token = 0;
	int c;
	float p;
	float d;
	string n;
	
	cout << "\n\t\t\t Modify the record";
	cout << "\n\t\t\t Product code: ";
	cin >> p_key;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "\n\n File doesn't exist! ";
	}
	else
	{
		data.open("database1.txt", ios::app|ios::out);
		
		data >> p_code >> p_name >> price >> dis;
		while(!data.eof())
		{
			if(p_key == p_code)
			{
				cout << "\n\t\t Product new code: ";
				cin >> c;
				cout << "\n\t\t Name of the product: ";
				cin >> n;
				cout << "\n\t\t Price: ";
				cin >> p;
				cout << "\n\t\t Discount: ";
				cin >> d;
				data1 << " " << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n\t\t Record edited ";
				token++;
			}
			else
			{
				data1 << " " << p_code << " " << p_name << " " << price << " " << dis << "\n";
			}
			data >> p_code >> p_name >> price >> dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0)
		{
			cout << "\n\n Record not found, sorry!";
		}
	}
}

void Shopping::rem()
{
	fstream data, data1;
	int p_key;
	int token = 0;
	cout << "\n\n\t Modify the record";
	cout << "\n\n\t Product code: ";
	cin >> p_key;
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		cout << "File doesn't exist";
	}
	else
	{
		data1.open("database1.txt", ios::app|ios::out);
		data >> p_code >> p_name >> price >> dis;
		while(!data.eof())
		{
			if(p_code == p_key)
			{
				cout << "\n\n\t Product deleted successfully ";
				token++;
			}
			else
			{
				data1 << " " << p_code << " " << p_name << " " << price << " " << dis << "\n";
			}
			data >> p_code >> p_name >> price >> dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0)
		{
			cout << "\n\n Record not found";
		}
	}
}

void Shopping::list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n|__________________________________\n";
	cout << "ProNo \t\t Name \t\t Price \n";
	cout << "\n\n|__________________________________\n";
	data >> p_code >> p_name >> price >> dis;
	while(!data.eof())
	{
		cout << p_code << "\t\t" << p_name << "\t\t" << price << "\t\t" << "\n";
		data >> p_code >> p_name >> price >> dis;
	}
	data.close();
}

void Shopping::receipt()
{
	fstream data;
	
	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;
	
	cout << "\n\n\t\t\t Receipt ";
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "\n\n Empty database";
	}
	else
	{
		data.close();
		
		list();
		cout << "\n__________________________________\n";
		cout << "\n|                                 \n";
		cout << "\n      Please place the order      \n";
		cout << "\n|                                 \n";
		cout << "\n__________________________________\n";
		do
		{
			m:
			cout << "\n\n Enter Product code: ";
			cin >> arrc[c];
			cout << "\n\n Enter Product quantity: ";
			cin >> arrq[c];
			for(int i = 0; i < c; i++)
			{
				if(arrc[c] == arrc[i])
				{
					cout << "\n\n Duplicate product code. Please try again!";
					goto m;
				}
			}
			c++;
			cout << "\n\n Buy another product?";
			cin >> choice;
		}
		while(choice == 'y');
			
		cout << "\n\n\t\t\t____________Receipt_________\n";
		cout << "\n Product No \t Product Name \t Product Quantity \t Price \t Amount with discount \n";
			
		for(int i = 0; i < c; i++)
		{
			data.open("database.txt", ios::in);
			data >> p_code >> p_name >> price >> dis;
			while(!data.eof())
			{
				if(p_code == arrc[i])
				{
					amount = price * arrq[i];
					dis = amount - (amount * dis/100);
					total = total + dis;
					cout << "\n" << p_code << "\t\t" << p_name << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
				}
				data >> p_code >> p_name >> price >> dis;
			}
		}
		data.close();
	}
	cout << "\n\n_______________________________________________\n";
	cout << "\n Total Amount: " << total;
}

int main()
{
	Shopping s;
	s.menu();
}






