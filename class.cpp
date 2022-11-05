#include<iostream>
using namespace std;
class Human
{
    char* name;
    public : 
    int lifespan = 80;
    virtual void run()
    {
        cout<<"Human running\n";
    }
};
class Man : public Human
{
    public : 
    void  run()
    {
        cout<<"Man running\n";
    }
};

int main()
{
    Human *h = new Man();
    h->run();
    cout<<h->lifespan;


    return 0;
}