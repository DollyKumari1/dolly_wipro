#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double num1, num2, sum, average;
    cout<<"Enter first number "<<endl;
    cin>>num1;
    cout<<"Enter second number "<<endl;
    cin>>num2;

    sum= num1+num2;
    average=sum/2.0;

    cout<<fixed<<setprecision(2);
    cout<<"Sum :"<<setw(10)<<sum<<endl;
    cout<<"Average :"<<setw(10)<<average<<endl;
    return 0;
}