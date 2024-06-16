#include <iostream>

int main() {
    int arr[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target;
    bool found = false;

    
    std::cout << "Enter the number to search: ";
    std::cin >> target;

    
    for (int i = 0; i < 10; ++i) {
        if (arr[i] == target) {
            std::cout << "Number found at index: " << i << std::endl;
            found = true;
            break;
        }
    }

    // If not found, display error message
    if (!found) {
        std::cout << "Number not found in the array." << std::endl;
    }

    return 0;
}
