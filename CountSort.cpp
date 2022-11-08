#include<iostream>
using namespace std;

void display(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int max(int* a,int n)
{
   int m=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>m)
        {
            m=a[i];
        }
    }
    return m;
}

void countSort(int *a,int n)
{
    int m = max(a,n);

    int* count = new int[m+1];

    //  initializing the new array elements to 0
    for(int i=0;i<m+1;i++)
    {
        count[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }

    int c1=0,c2=0;
    while(c1<=m)  // last index of new array
    {
        if(count[c1]>0)
        {
            a[c2]=c1;
            c2++;
            count[c1]--;
        }
        else
        {
            c1++;
        }
    }
}

int main()
{
    int arr[] = {5,70,46,31,102};
    int n=5;

    cout<<"The array is\n";
    display(arr,n);
    countSort(arr,n);
    cout<<"The sorted array is\n";
    display(arr,n);

    return 0;
}