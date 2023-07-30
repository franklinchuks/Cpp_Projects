#include <iostream>
using namespace std;

void show_menu()
{
    cout << "\n**********MENU**********" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "************************\n" << endl;
}

int main()
{
    //check bal, deposit, withdraw, menu
    int option;
    double balance = 500;
    double deposit_amount;

    do{
        show_menu();
        cout << "Option: ";
        cin >> option;

        switch(option)
        {
            case 1:
                cout << "Balance is: " << balance << "$\n\n\n" << endl;
                break;
            case 2:
                cout << "Deposit amount: ";
                double deposit_amount;
                cin >> deposit_amount;
                balance += deposit_amount;
                break;
            case 3:
                cout << "Withdraw amount: ";
                double withdraw_amount;
                cin >> withdraw_amount;
                if(withdraw_amount <= balance)
                {
                    balance -= withdraw_amount;
                }
                else
                {
                    cout << "Not enough money in account" << endl;
                }
                break;
            default:
                cout << "Invalid entry, please try again" << endl;
                break;
        }
    }
    while(option != 4);

    system("pause>0");
}