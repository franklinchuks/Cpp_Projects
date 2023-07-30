#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    time_t t;
    tm* tPtr = localtime(&t);
    cout << localtime(&t) << endl;

    cout << "Hello world!" << endl;


}