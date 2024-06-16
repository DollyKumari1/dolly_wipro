#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(string hexNum) {
    int decimalNum = 0;

    // Iterate over each character of the hexadecimal number
    for (int i = 0; i < hexNum.length(); i++) {
        char digit = hexNum[i];

        // Convert hexadecimal digit to decimal
        int digitValue;
        if (isdigit(digit)) {
            digitValue = digit - '0';
        } else {
            digit = toupper(digit);
            digitValue = digit - 'A' + 10;
        }

        // Update the decimal number by adding the decimal value of the digit multiplied by its position
        decimalNum += digitValue * pow(16, hexNum.length() - 1 - i);
    }

    return decimalNum;
}

int main() {
    string hexNum;
    cout << "Enter a hexadecimal number: ";
    cin >> hexNum;

    // Convert hexadecimal to decimal
    int decimalNum = hexadecimalToDecimal(hexNum);

    // Print the decimal equivalent
    cout << "Decimal equivalent: " << decimalNum << endl;

    return 0;
}
