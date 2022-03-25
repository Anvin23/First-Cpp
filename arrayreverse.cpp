#include<iostream>
using namespace std;
void swap(int &n1,int &n2)
{
    int temp=n1;
    n1=n2;
    n2=temp;
}
int main()
{
    int size,i,j,k;
    cout<<"Enter the size of the array\n";
    cin>>size;
    int arr[size];
    cout<<"Enter the numbers\n";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for(j=0;j<size/2;j++)
    {
        swap(arr[j],arr[size-j-1]);
    }
    cout<<"The reversed array is \n";
    for(k=0;k<size;k++)
    {
        cout<<arr[k]<<" ";
    }
    return 0;
}