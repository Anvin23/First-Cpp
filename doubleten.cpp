#include<iostream>
using namespace std;
int main()
{
    int n,s=0;
    cout<<"Enter a positive number\n";
    cin>>n;
    while(n%10!=0)
    {
        n=n*2;
        s++;
    }
    cout<<"No. of turns required is "<<s<<endl;
    return 0;
}
/* a number is multiplied by 2 in each turn.
display minimum no.of turns required so that the number is divisible by 10 */