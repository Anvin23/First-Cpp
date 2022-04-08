#include<iostream>
using namespace std;
class mystack
{
    int arr[10];
    int l,a=-1;
    public:
    mystack(int n)
    {
        int arr[n];
        l=n;
    }
    void push(int n)
    {
        if(a==l-1)
        {
            cout<<"Stack Overflow !!\n"<<"Unable to push\n";
            return;
        }
        a++;
        arr[a]=n;
        return;
    }
    void pop()
    {
        if(a==-1)
        {
            cout<<"Stack Underflow !!\n"<<"Unable to pop\n";
            return;
        }
        cout<<arr[a]<<" ";
        a--;
        return;
    }
    void show()
    {
        if(a==-1)
        {
            cout<<"No elements in stack\n";
            return;
        }
        cout<<"\n"<<"\n";
        for(int i=a;i>-1;i--)
        {
            cout<<arr[i]<<"\n";
        }
        cout<<"\n";
        return;
    }
};
int main()
{
    mystack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.show();
    st.pop();
    st.pop();
    st.show();
}
