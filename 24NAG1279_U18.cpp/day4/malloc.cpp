#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
    
    int size;
    int *pArray;

    cout<<"Input size "<<endl;
    cin>>size;

    pArray= (int *)malloc(size *sizeof(int));

    if(pArray ==nullptr)
    return 0;

   
    for(int i=0; i<size; i++){
        pArray[i]=100+i*10;

    }
    for(int i=0; i<size; i++){
        cout<< pArray[i]<<endl;
    }

    free(pArray);
    return 0;

}