#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float numFloat = 1.11111111111111111111;
    double numDouble = 1.11111111111111111111;
    long double numLongDouble = 1.11111111111111111111;

    for (int i = 0; i < 3000000; i++)
    {
        numFloat = numFloat + 1.11111111111111111111;
    }
    for (int i = 0; i < 3000000; i++)
    {
        numDouble = numDouble + 1.11111111111111111111;
    }

    cout << setprecision(25) << numFloat << endl;
    cout << setprecision(25) << numDouble << endl;
    cout << setprecision(25) << numLongDouble << endl;
    return 0;
    
}