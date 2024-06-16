#include<iostream>
using namespace std;

int main(){
    int marks1, marks2, marks3;
    float avg;

    cout<<"Enter marks for subject1: ";
    cin>>marks1;
    cout<<"Enter marks for subject2: ";
    cin>>marks2;
    cout<<"Enter marks for subject 3: ";
    cin>>marks3;

    avg=(marks1+marks2+marks3)/3.0;
    if(marks1<40||marks2<40||marks3<40){
        cout<<"Grade F"<<endl;
    }
    else if(avg>75.0f){
        cout<<"Grade A"<<endl;
    }
    else if(avg>60.0f){
        cout<<"Grade B"<<endl;

    }else{
        cout<<"Grade C"<<endl;
    }
    return 0;
}