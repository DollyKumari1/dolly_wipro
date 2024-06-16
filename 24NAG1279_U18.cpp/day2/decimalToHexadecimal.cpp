#include <iostream>
#include <sstream>

using namespace std;

// Function to convert decimal to hexadecimal
string decimalToHexadecimal(int decimalNum) {
    stringstream ss;
    ss << hex << decimalNum; // Convert decimal to hexadecimal using stringstream
    return ss.str(); // Return the hexadecimal string
}

int main() {
    int decimalNum;
    cout << "Enter a decimal number: ";
    cin >> decimalNum;

    // Convert decimal to hexadecimal
    string hexadecimalNum = decimalToHexadecimal(decimalNum);

    // Print the hexadecimal equivalent
    cout << "Hexadecimal equivalent: " << hexadecimalNum << endl;

    return 0;
}
