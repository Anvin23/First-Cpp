#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k,h,q,mi;
    cout<<"Enter no. of rounds\n";
    cin>>n;
    int p1[n],p2[n];
    for(i=0;i<n;i++)
    {
        cin>>p1[i]>>p2[i];
    }
    for(j=1;j<n;j++)
    {
        p1[j]=p1[j-1]+p1[j];
        p2[j]=p2[j-1]+p2[j];
    }
    int l[n],m[n],max;
    for(k=0;k<n;k++)
    {
        l[k]=p1[k]-p2[k];
    }
    for(h=0;h<n;h++)
    {
        m[h]=l[h]*l[h];
    }
    max=0;
    for(q=0;q<n;q++)
    {
        if(m[q]>max)
        {
            max=m[q];
            mi=q;
        }
    }
    if(l[mi]>0)
    {
        cout<<"Player 1 wins\n"<<"Max lead = "<<l[mi]<<endl;
    }
    else
    {
        cout<<"Player 2 wins\n"<<"Max lead = "<<-1*l[mi]<<endl;
    }
    return 0;
}

