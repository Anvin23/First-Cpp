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

void selectionSort(int *a,int n)
{
    int mi;
    for(int i=0;i<n-1;i++)
    {
        mi=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[mi])
            {
                mi=j;
            }
        }
        int temp=a[i];
        a[i]=a[mi];
        a[mi]=temp;
    }
}


int main()
{
    int arr[100],n;
     cout<<"Enter no. of elements : ";
    cin>>n;
    cout<<"Enter "<<n<<" elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"The array is\n";
    display(arr,n);
    selectionSort(arr,n);
    cout<<"The sorted array is\n";
    display(arr,n);

    return 0;
}