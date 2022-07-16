#include<iostream>
using namespace std;
void getmatrix(int a[][100],int row,int col)
{
    cout<<"Enter elements rowwise \n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>a[i][j];
        }
    }
}
void displaymatrix(int a[][100],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void matrixsum(int a[][100],int b[][100],int row,int col)
{
    int i,j,c[100][100];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    cout<<"Sum of matrices is \n";
    displaymatrix(c,row,col);
}
void transpose(int a[][100],int row,int col)
{
    int i,j,c[100][100];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            c[j][i]=a[i][j];
        }
    }
    displaymatrix(c,col,row);
}
void matrixprod(int a[][100],int b[][100],int rowa,int rowcol,int colb)
{
    int i,j,k,c[100][100]={};
    for(i=0;i<rowa;i++)
    {
        for(j=0;j<colb;j++)
        {
            for(k=0;k<rowcol;k++)
            {
                // c[i][j] = i th row of a * j th col of b
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    cout<<"Product of matrices is \n";
    displaymatrix(c,rowa,colb);
}
int main()
{
    int row1,col1,row2,col2,opt,A[100][100],B[100][100];
    cout<<"Enter size(rows,columns) of matrix A : ";
    cin>>row1>>col1;
    getmatrix(A,row1,col1);
    cout<<"Enter size(rows,columns) of matrix B : ";
    cin>>row2>>col2;
    getmatrix(B,row2,col2);
    cout<<"Matrix A is \n";
    displaymatrix(A,row1,col1);
    cout<<"Matrix B is \n";
    displaymatrix(B,row2,col2);
    cout<<"\n \n";
    while(1)
    {
        cout<<"1.Add  2.Multiply  3.Transpose  4.Exit  \n";
        cout<<"Enter your option : ";
        cin>>opt;
        switch (opt)
        {
            case 1:
                    if(row1==row2 && col1==col2)
                    {
                        matrixsum(A,B,row1,col1);
                    }
                    else
                    {
                        cout<<"Not compatible for addition \n";
                    }
                    break;
            case 2:
                    if(col1==row2)
                    {
                        matrixprod(A,B,row1,col1,col2);
                    }
                    else
                    {
                        cout<<"Not compatible for multiplication \n";
                    }
                    break;
            case 3:
                    cout<<"Transpose of A is \n";
                    transpose(A,row1,col1);
                    cout<<"Transpose of B is \n";
                    transpose(B,row2,col2);
                    break;
            case 4:
                    exit(0);
            default:
                    cout<<"Invalid option \n";
        }
    }
    return 0;
}