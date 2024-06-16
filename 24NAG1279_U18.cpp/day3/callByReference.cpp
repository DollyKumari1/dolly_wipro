#include <iostream>
using namespace std;

void sumAndAvgByRef(int num1, int num2, int num3, int& sum, float& avg) {
    sum = num1 + num2 + num3;
    avg = static_cast<float>(sum) / 3.0;
}

int main() {
    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    int sum;
    float avg;

    sumAndAvgByRef(num1, num2, num3, sum, avg);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << avg << std::end

    return 0;
}

