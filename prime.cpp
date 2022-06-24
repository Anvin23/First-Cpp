#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    cout<<"Enter a number\n";
    int num,i;
    cin>>num;
    if(num==1)
    {
        cout<<"Not Prime";
        exit(0);
    }
    for(i=2;i<=sqrt(num);i++)
    if(num%i==0)
    {
        cout<<"Not Prime";
        exit(0);
    }
    cout<<"Prime Number";
    return 0;
}