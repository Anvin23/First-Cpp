#include<iostream>
using namespace std;
void bubsortasc(int* a,int size)
{
    bool swap = false;
    for(int i=0;i<size;i++)
    {
        for(int j=1;j<size-i;j++)
        {
            if(a[j]<a[j-1])
            {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                swap = true;
            }
        }
        if(!swap)
        {
            return;
        }
    }
}
void bubsortdesc(int* a,int size)
{
    bool swap = false;
    for(int i=0;i<size;i++)
    {
        for(int j=1;j<size-i;j++)
        {
            if(a[j]>a[j-1])
            {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                swap = true;
            }
        }
        if(!swap)
        {
            return;
        }
    }
}
int main()
{
    int s,o;
    cout<<"Enter size of array\n";
    cin>>s;
    int arr[s];
    cout<<"Enter the numbers\n";
    for(int k=0;k<s;k++)
    {
        cin>>arr[k];
    }
    cout<<"How would you want to sort ?\n";
    cout<<"1 => Ascending order\n";
    cout<<"2 => Descending order\n";
    cin>>o;
    if(o==1)
    {
    bubsortasc(arr,s);
    cout<<"The sorted array is \n";
    for(int r=0;r<s;r++)
    {
        cout<<arr[r]<<" ";
    }
    }
    else if(o==2)
    {
     bubsortdesc(arr,s);
    cout<<"The sorted array is \n";
    for(int r=0;r<s;r++)
    {
        cout<<arr[r]<<" ";
    }
    }
    else
    {
        cout<<"Invalid number\n";
    }
    return 0;
}