#include<iostream>
using namespace std;

void convertToCelcius(float *fahr, float *cel, int num);
const double FAHR_RATIO= 5.0/9.0; //0.555

int main(){
    float fahr[5] = {100.5f, 50.7f, 40.8f, 94.3f, 83.2f};
    float cel[5];
    
    convertToCelcius(fahr, cel, 5);
    
    for(int indx= 0; indx< 5; indx++)
    {
        cout<<fahr[indx]<<","<<cel[indx]<<endl;
    }
}

void convertToCelcius(float *fahr, float *cel, int num)
{
    for(int idx=0; idx<num; idx++)
    {
        cel[idx]=FAHR_RATIO*(fahr[idx]-32.0);
    }
}