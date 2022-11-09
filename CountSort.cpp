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

// in count sort we make a new array of max index >= the largest element in the provided array
// all elements in the new array is initialised by 0
// iterate through the providede array
// for each element we increment the value in new array of at index [element]
// if we come across 3 during traversing , we increment the value at newarray[3]
// this indicates the no. of times a particular element was encountered
// after traversal , we traverse through the new array from beginning
// if value is not 0 , add the 'index' in the provided array as mantimes as its value
// ie; if index 3 has value 2 it means 3 appeared twice in the original array
// so add 3 two times in the array , then move forward
// since we do this from index 0 to maxlen , we will be adding elements in sorted order 

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