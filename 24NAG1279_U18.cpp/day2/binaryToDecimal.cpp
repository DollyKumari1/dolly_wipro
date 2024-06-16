#include <iostream>
#include <cmath>

using namespace std;

int binaryToDecimal(long long binaryNum) {
    int decimalNum = 0;
    int base = 1;

    while (binaryNum > 0) {
        int lastDigit = binaryNum % 10; 
        binaryNum = binaryNum / 10; 
        decimalNum += lastDigit * base; 
        base = base * 2; 
    }

    return decimalNum;
}

int main() {
    long long binaryNum;
    cout << "Enter a binary number: ";
    cin >> binaryNum;

    
    int decimalNum = binaryToDecimal(binaryNum);

    
    cout << "Decimal equivalent: " << decimalNum << endl;

    return 0;
}
