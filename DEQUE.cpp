#include<iostream>
using namespace std;
const int MAXSIZE=10;
int Deque[MAXSIZE];
int front=-1,rear=-1;
void insert_in_front(int val)
{
    if(front==0 && rear==MAXSIZE-1)
    {
        cout<<"\nQueue Overflow !!\n\n";
        return;
    }
    else if(front==-1)
    {
        front++;
        rear++;
        Deque[front]=val;
    }
    else if (front>0)
    {
        front--;
        Deque[front]=val;
    }
    else
    {
        for (int i = rear; i >= 0; i--)
        {
            Deque[i+1]=Deque[i];
        }
        Deque[front]=val;
        rear++;
    }
}
void insert_in_rear(int val)
{
    if(front==0 && rear==MAXSIZE-1)
    {
        cout<<"\nQueue Overflow !!\n\n";
        return;
    }
    else if(rear==-1)
    {
        front++;
        rear++;
        Deque[rear]=val;
    }
    else if(rear<MAXSIZE-1)
    {
        rear++;
        Deque[rear]=val;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            Deque[i-1]=Deque[i];
        }
        Deque[rear]=val;
        front--;
    }
}
void delete_from_front()
{
    if(front==-1 || front>rear)
    {
        cout<<"\nQueue Underflow !!\n\n";
        return;
    }
    else
    {
        int data=Deque[front];
        front++;
        cout<<"\n"<<data<<" is removed\n\n";
    }
}
void delete_from_rear()
{
     if(rear==-1 || front>rear)
    {
        cout<<"\nQueue Underflow !!\n\n";
        return;
    }
    else
    {
        int data=Deque[rear];
        rear--;
        cout<<"\n"<<data<<" is removed\n\n";
    }
}
void display()
{
    if(front==-1 || front>rear)
    {
        cout<<"\nEmpty Queue\n\n";
        return;
    }
    cout<<"\nQueue Status\n";
    for(int i=front;i<=rear;i++)
    {
        cout<<Deque[i]<<" ";
    }
    cout<<"\n\n";
}
int main()
{
    int op,data;
    do
    {
        cout<<"1.Insert from front\n2.Insert from rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n";
        cin>>op;
        switch(op)
        {
            case 1:
                    cout<<"Enter the element to be inserted : ";
                    cin>>data;
                    insert_in_front(data);
                    break;
            case 2:
                    cout<<"Enter the element to be inserted : ";
                    cin>>data;
                    insert_in_rear(data);
                    break;
            case 3:
                    delete_from_front();
                    break;
            case 4:
                    delete_from_rear();
                    break;
            case 5:
                    display();
                    break;
            case 6:
                    break;
            default:
                    cout<<"\nInvalid option\n\n";
        }
    } while (op!=6);
    return 0;
}