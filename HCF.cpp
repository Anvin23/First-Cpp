#include<iostream>
using namespace std;
int gcd(int a,int b)  // gcd = hcf(highest common factor)
{
    if(a==0)
    {
        return b; 
    }
    return gcd(b%a,a); //Euclidean algorithm
}
int main()
{
    int num1,num2;
    cout<<"Enter two numbers\n";
    cin>>num1>>num2;
    cout<<gcd(num1,num2);
    return 0;
}