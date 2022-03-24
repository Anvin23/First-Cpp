#include<iostream>
#include<cmath>
using namespace std;
int digits(int a)
{
    int d=0;
    while (a>0)
    {
       a=a/10;
       d++; 
    }
    return d;
}
bool isArmstrong(int n)
{
    int p = digits(n);
    int ognum = n;
    int rem,l = 0;
    while(n>0)
    {
        rem=n%10;
        l=l+pow(rem,p);
        n=n/10;
    }
    if(l==ognum)
    {
        return true;
    }
    return false;
}
int main()
{
    /* armstrong number of 'n' digits is the number whose sum of individual digits raised to
     the power 'n' gives the same number */

    int num;
    cout<<"Enter the number\n";
    cin>>num;
    if(isArmstrong(num))
    {
        cout<<"It is an Armstrong number\n";
    }
    else
    {
        cout<<"It is not an Armstrong number\n";
    }
    return 0;
}