#include<iostream>
using namespace std;
int cq[5];
int size=5;
int front=-1,rear=-1;
bool isFull()
{
    if(rear+1==front || (front==0 && rear==(size-1)))
    {
        return true;
    }
    return false;
}
bool isEmpty()
{
    if(front==-1)
    {
        return true;
    }
    return false;
}
void insert(int x)
{
    if(isFull())
    {
        cout<<"\nQueue Overflow !!\nCouldn't insert "<<x<<"\n\n";
        return;
    }
    if(front==-1)
    {
        front++;
        rear++;
        cq[rear]=x;
        cout<<x<<" successfully inserted\n";
        return;
    }
    if(rear<size-1)
    {
        rear++;
        cq[rear]=x;
        cout<<x<<" successfully inserted\n";
    }
    else
    {
        rear=0;
        cq[rear]=x;
        cout<<x<<" successfully inserted\n";
    }
}
void remove()
{
    int val;
    if(isEmpty())
    {
        cout<<"\nQueue Underflow !!\n\n";
        return;
    }
    if(front==size-1)
    {
        val=cq[front];
        front=0;
    }
    else if (front==rear)
    {
        val=cq[front];
        front=-1;
        rear=-1;
    }
    else
    {
        val=cq[front];
        front++;
    }
}
void display()
{
    if(isEmpty())
    {
        cout<<"\nEmpty Queue\n\n";
        return;
    }
    else
    {
        cout<<"\nQueue Status\n";
        int i=front;
        while(true)
        {
            cout<<cq[i]<<" ";
            if(i==rear)
            {
                break;
            }
            if(i==size-1)
            {
                i=0;
            }
            else
            {
                i++;
            }
        }
        cout<<"\n\n";
    }
}
int main()
{
    remove();
    display();
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    remove();
    remove();
    insert(7);
    insert(8);
    display();
}