#include<iostream>
using namespace std;
int main(){
    float temp_F, temp_C;
    cout<<"Input temperature in F "<<endl;
    cin>>temp_F;
    temp_C= 5.0/9.0*(temp_F-32);
    cout<<"Temperature in Celcius "<<temp_C<<endl;
}