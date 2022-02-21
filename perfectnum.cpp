#include<iostream>
using namespace std;
int main()
{
    int n,i,s=0;
    cout<<"Enter a number\n";
    cin>>n;
    for(i=1;i<n;i++)
    {
        if((n%i)==0)
        {
            s=s+i;
        }
    }
    if(s==n)
    {
        cout<<"It is a perfect number\n";
    }
    else
    {
        cout<<"It is not a perfect number\n";
    }
    return 0;
}