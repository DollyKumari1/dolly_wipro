#include <iostream>

void convertToCelsius(float *fahr, float *cel, int num);

int main() {
    float fahrenheit[10] = {18.9, 82.5, 68.3, 93.7, 87.1, 101.2, 105.6, 19.8, 114.5, 169.0};
    float celsius[10];

    convertToCelsius(fahrenheit, celsius, 10);

    std::cout << "Fahrenheit\tCelsius" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << *(fahrenheit + i) << "\t\t" << *(celsius + i) << std::endl;
    }

    return 0;
}

void convertToCelsius(float *fahr, float *cel, int num) {
    for (int i = 0; i < num; ++i) {
        *(cel + i) = (*(fahr + i) - 32) * 5 / 9; 
    }
}
