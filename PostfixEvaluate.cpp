#include<iostream>
#include<cstring>
#define SIZE 15
using namespace std;
char expr[20];
float stack[SIZE];
int top=-1;
void push(float x)
{
        top++;
        stack[top]=x;
}
float pop()
{
    if(top==-1)
    {
        cout<<"\nStack Underflow !! \n\n";
    }
    else
    {
        float val=stack[top];
        top--;
        return val;
    }
    return 0.0;
}
bool isOperator(char x)
{
    switch(x)
    {
        case '+':
        case '-':
        case '*':
        case '/':
                return true;
    }
    return false;
}
float scanNum(char x)
{
    switch(x)
    {
        case '0':
                return 0.0;
                break;
        case '1': 
                return 1.0;
                break;
        case '2': 
                return 2.0;
                break;
        case '3': 
                return 3.0;
                break;
        case '4': 
                return 4.0;
                break;
        case '5': 
                return 5.0;
                break;
        case '6': 
                return 6.0;
                break;
        case '7': 
                return 7.0;
                break;
        case '8': 
                return 8.0;
                break;
        case '9': 
                return 9.0;
                break;
    }
}
float compute(float p,char op,float q)
{
    switch(op)
    {
        case '+':
                return(p+q);
                break;
        case '-':
                return(p-q);
                break;
        case '*':
                return(p*q);
                break;
        case '/':
                return(p/q);
                break;   
    }
    return 0;
}
int main()
{
    int length;
    cout<<"Enter the postfix expression\n";
    gets(expr);
    length = sizeof(expr);
    for(int i=0;i<length;i++)
    {
        if(isOperator(expr[i]))
        {
            float a = pop();
            float b = pop();
            push(compute(b,expr[i],a));
        }
        else
        {
            float num = scanNum(expr[i]);
            push(num);
        }
    }
    cout<<"The result of evaluation = "<<stack[top]<<"\n";  
    return 0;
}