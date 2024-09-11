#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int number,q;
    cin>>number;
    for(int p=2;p<=sqrt(number);p++)
    {
        q=number/p;
        if(p*q==number)
        {
            cout<<q;
            return 0;
        }
    }
    return 0;
}