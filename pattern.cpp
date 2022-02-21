#include<iostream>
using namespace std;
void pattern(int n)
{
    if(n==0)
    {
        return;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    pattern(n-1);
}
int main()
{
    int a;
    cout<<"Enter a number\n";
    cin>>a;
    pattern(a);
    return 0;
}