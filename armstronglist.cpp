#include<iostream>
#include<cmath>
using namespace std;
int p;
bool isArmstrong(int n)
{
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
    cout<<"Enter no. of digits\n";
    cin>>p;
    int s=pow(10,p-1);
    int e = pow(10,p);
    for(int i=s;i<e;i++)
    {
        if(isArmstrong(i))
        {
            cout<<i<<" ";
        }
    }
    return 0;
}