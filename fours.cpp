#include<iostream>
using namespace std;
int main()
{
    int n,r,s=0;
    cout<<"Enter the number\n";
    cin>>n;
    while(n/10!=0)
    {
        r=n%10;
        n=n/10;
        if(r==4)
        {
            s++;
        }
    }
    if(n==4)
    {
        s++;
    }
    cout<<s;
    return 0;
}