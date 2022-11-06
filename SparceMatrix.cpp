#include<iostream>
using namespace std;

typedef struct
{
    int value,row,col;
}mtrx;
mtrx a[10],b[10];

void printMatrix(mtrx m[])
{
    int p=1;
    for(int i=0;i<m[0].row;i++)
    {
        for(int j=0;j<m[0].col;j++)
        {
            if(m[p].row==i && m[p].col==j)
            {
                printf("%d ",m[p].value);
                p++;
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    printf("\n\n");
}

void transpose(mtrx m[])
{
    int cb=0;

    b[0].row=m[0].col;
    b[0].col=m[0].row;
    b[0].value=m[0].value;

    for(int i=0;i<m[0].col;i++)
    {
        for(int j=1;j<=m[0].value;j++)
        {
            if(m[j].col==i)
            {
                cb++;
                b[cb].row=m[j].col;
                b[cb].col=m[j].row;
                b[cb].value=m[j].value;
            }
        }
    }
}

int main()
{
    a[0].col=6;
    a[0].row=6;
    a[0].value=9;

    a[1].row=0;
    a[1].col=1;
    a[1].value=1;

    a[2].row=0;
    a[2].col=4;
    a[2].value=2;

    a[3].row=1;
    a[3].col=3;
    a[3].value=3;

    a[4].row=2;
    a[4].col=0;
    a[4].value=5;

    a[5].row=2;
    a[5].col=2;
    a[5].value=7;

    a[6].row=3;
    a[6].col=4;
    a[6].value=6;

    a[7].row=4;
    a[7].col=4;
    a[7].value=8;

    a[8].row=5;
    a[8].col=1;
    a[8].value=9;

    a[9].row=5;
    a[9].col=5;
    a[9].value=4;

    printMatrix(a);

    transpose(a);

    printMatrix(b);



    return 0;
}