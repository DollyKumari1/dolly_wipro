#include <iostream>
 
int sumOf(int num1, int num2 = 0, int num3 = 0);
// sumOf@int@int@int
 
double sumOf(double num1, double num2, double num3);
double sumOf(double num1, double num2);
 
int main()
{
    int sum = sumOf(10, 20, 30);
    std::cout << "Sum: " << sum << std::endl;
 
    sum = sumOf(10, 20);
    std::cout << "Sum: " << sum << std::endl;
 
    sum = sumOf(10);
    std::cout << "Sum: " << sum << std::endl;
 
 
 
 
    double dsum = sumOf(100.23, 200.23);
    std::cout << "Sum: " << dsum << std::endl;
 
}
 
int sumOf(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}
 
double sumOf(double num1, double num2, double num3)
{
    return num1 + num2 + num3;
}
 
double sumOf(double num1, double num2)
{
    return num1 + num2;
}
