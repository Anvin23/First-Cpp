#include<iostream>
#define SIZE 10
using namespace std;

int stack[SIZE],top1=-1,top2=SIZE;

void push1(int x)
{
    if(top1+1==top2)
    {
        cout<<"Stack Overflow !!\n";
        return;
    }
    top1++;
    stack[top1]=x;
}

void push2(int x)
{
    if(top2-1==top1)
    {
        cout<<"Stack Overflow !!\n";
        return;
    }
    top2--;
    stack[top2]=x;
}

void pop1()
{
    if(top1==-1)
    {
        cout<<"Stack Underflow !!\n";
        return;
    }
    int val = stack[top1];
    top1--;
    cout<<val<<" is popped\n";
}

void pop2()
{
    if(top2==SIZE)
    {
        cout<<"Stack Underflow !!\n";
        return;
    }
    int val = stack[top2];
    top2++;
    cout<<val<<" is popped\n";
}

void display1()
{
    if(top1==-1)
    {
        cout<<"Empty Stack !!\n";
        return;
    }
    for(int i=0;i<=top1;i++)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

void display2()
{
    if(top2==SIZE)
    {
        printf("Empty Stack !!\n");
        return;
    }
    for(int i=SIZE-1;i>=top2;i--)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    display1();
    display2();
    push1(5);
    push1(7);
    push1(200);
    push1(65);
    push1(57);
    push2(4);
    push2(78);
    push2(45);
    push2(41);
    display1();
    display2();
    pop1();
    pop1();
    pop1();
    pop2();
    pop2();
    pop2();
    display1();
    display2();

    return 0;
}