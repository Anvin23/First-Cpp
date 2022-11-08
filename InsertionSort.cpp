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

void insertionSort(int *a,int n)
{
    int num,j;
    for(int i=1;i<n;i++)
    {
        num=a[i];
        j=i-1;
        while(j>=0 && num<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=num;
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
    insertionSort(arr,n);
    cout<<"The sorted array is\n";
    display(arr,n);

    return 0;
}