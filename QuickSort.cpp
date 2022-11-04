#include<iostream>
using namespace std;

int part(int arr[],int low,int high)
{
    int mid = (low+high)/2;
    int s = low , e = high , pi = mid;
    int pivot = arr[mid];

    while(s<e)
    {
        while(arr[s]<pivot)
        {
            s++;
        }
        while(arr[e]>pivot)
        {
            e--;
        }

        if(s<e)
        {
            if(pi==s)
            {
                pi = e;
            }
            else if(pi==e)
            {
                pi = s;
            }
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            if(pi==e)
            {
                s++;
            }
            else if(pi==s)
            {
                e--;
            }
            else
            {
                s++;
                e--;
            }
        }
    }
    return pi;
}

void sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi = part(arr,low,high);
        sort(arr,low,pi-1);
        sort(arr,pi+1,high);
    }
}

int main()
{
    int n,arr[100];
    cout<<"Enter the no. of elements : ";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,0,n-1);

    cout<<"The sorted array is\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}