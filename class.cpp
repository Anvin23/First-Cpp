#include<iostream>
using namespace std;
class Human
{
    public : 
    int lifespan = 80;
    virtual void run()
    {
        cout<<"Human running\n";
    }
};
class Man : public Human
{
    char* name;
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
    cout<<h->lifespan<<endl;

    Human h1;
    h1.run();

    Man m;
    m.run();


    return 0;
}