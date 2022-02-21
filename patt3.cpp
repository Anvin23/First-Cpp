#include<iostream>
using namespace std;
int main()
{
    int a,i,j,k,l;
    cout<<"Enter a number\n";
    cin>>a;
    for(i=a;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(k=2;k<=a;k++)
    {
        for(l=1;l<=k;l++)
        {
            cout<<l<<" ";
        }
        cout<<endl;
    }
    return 0;
}