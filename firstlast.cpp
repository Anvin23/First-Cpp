#include<iostream>
using namespace std;
int main()
{
    int n,ld,fd;
    cout<<"Enter the number\n";
    cin>>n;
    ld=n%10;
    while(n/10!=0)
    {
        n=n/10;
    }
    fd=n;
    cout<<ld+fd;
    return 0;
}