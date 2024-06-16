#include<iostream>
#include<string.h>

using namespace std;

int main(){
    char name[31] = "Harry Potter";
    char newName[31];
    char newStr[]= "Hello";

    int len= strlen(name);

    cout<<"Length is "<<len<<endl;
    strcpy(newName, name);

    cout<<"Copied string is "<<newName<<endl;

    strncpy(newName, newStr, 6);
    cout<<"Copied string is "<<newName<<endl;

    strcat(newName, name);
    cout<<"Concatenated string "<<newName<<endl;
    return 0;

}

