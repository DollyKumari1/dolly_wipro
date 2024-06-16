#include <iostream>

using namespace std;

// Function to convert decimal to binary
void decimalToBinary(int n) {
    int binaryNum[32]; // Array to store binary number

    // Counter for binary array
    int i = 0;
    while (n > 0) {
        // Store the remainder when n is divided by 2
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Print the binary representation in reverse order
    cout << "Binary representation: ";
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

int main() {
    int decimalNum;
    cout << "Enter a decimal number: ";
    cin >> decimalNum;

    // Convert decimal to binary
    decimalToBinary(decimalNum);

    return 0;
}
