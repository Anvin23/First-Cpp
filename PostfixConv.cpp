#include<iostream>
#include<cstring>
using namespace std;
int size=20,top=-1;
char expr[20],stack[10];
char pop();
void push(char x);
bool isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}
bool isFull()
{
    if(top==size-1)
    {
        return true;
    }
    return false;
}
int priority(char ch)
{
    if(ch=='(')
    {
        return 0;
    }
    if(ch=='-' || ch=='+')
    {
        return 1;
    }
    if(ch=='*' || ch=='/')
    {
        return 3;
    }
    return 4;
}
void addToStack(char x)
{
    if(isEmpty() || x=='(')
    {
        push(x);
        return;
    }
    if(x==')')
    {
        while(stack[top]!='(')
        {
            cout<<pop();
        }
        if(stack[top]=='(')
        {
            pop();
            return;
        }
    }
    if(priority(x)>priority(stack[top]))
    {
        push(x);
    }
    else
    {
        while(priority(x)<=priority(stack[top]))
        {
            cout<<pop();

            if(isEmpty())
            {
                break;
            }
        }
        push(x);
    }
}
void push(char x)
{
    if(isFull())
    {
        cout<<"\n Stack Overflow !! \n\n";
        return;
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
char pop()
{
    if(isEmpty())
    {
        cout<<"\nStack Underflow !! \n\n";
    }
    else
    {
        char val=stack[top];
        top--;
        return val;
    }
    return ' ';
}
int main()
{
    cout<<"Enter the expression\n";
    gets(expr); 
    int length=sizeof(expr);
    for(int i=0;i<length;i++)
    {
        switch(expr[i])
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
                        addToStack(expr[i]);
                        break;
            default:
                        cout<<expr[i];
        }
    }
    while(!isEmpty())
    {
        cout<<pop();
    }
    return 0;
}
