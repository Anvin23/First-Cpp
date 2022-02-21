#include<iostream>
using namespace std;
void pat(int n)
{
    if(n==1)
    {
        cout<<"1\n";
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    pat(n-1);
    for(int j=1;j<=n;j++)
    {
        cout<<j<<" ";
    }
    cout<<endl;
}
int main()
{
    int num;
    cout<<"Enter a number\n";
    cin>>num;
    pat(num);
    return 0;
}