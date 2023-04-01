#include<iostream>
#include<fstream>
using namespace std;


class Account
{
    string name;
    int id;
    float balance;

    public:

        Account(){}

        Account(string name , int id)
        {
           this->name = name;
           this->id = id;
        }

        void deposit(float amt)
        {
            this->balance += amt;
            cout<<"Rs."<<amt<<" has been credited to your account"<<endl;
        }

        void withdraw(float amt)
        {
            if(this->balance < amt)
            {
                cout<<"Insufficient balance  Cannot withdraw"<<endl;
                return;
            }
            else
            {
                this->balance -= amt;
            }
        }

        void displayBalance()
        {
            cout<<"Account Name : "<< this->name<<endl;
            cout<<"Current balance : Rs."<< this->balance<<endl;
        }

        void addRecord()
        {

            ofstream out("Accounts.txt" , ios::app);
            out<<"Account Name : "<< this->name<<endl;
            out<<"Balance Amount : Rs."<< this->balance<<endl<<endl;

            out.close();

        }

};

int main()
{
    string name;
    int id , choice;
    float amt;

    cout<<"Enter your name : ";
    cin>>name;
    cout<<"Enter your id : ";
    cin>>id;

    Account *acc = new Account(name , id);

    do
    {
        cout<<"Enter the choice\n";
        cout<<"1.Deposit\n2.Withdraw\n3.Exit\n";
        cin>>choice;
        switch (choice)
        {
            case 1:
                    cout<<"Enter the amount to deposit : ";
                    cin>>amt;
                    acc->deposit(amt);
                    break;
            case 2:
                    cout<<"Enter the amount to withdraw : ";
                    cin>>amt;
                    acc->withdraw(amt);
                    break;
            case 3: break;
            
            default:
                    cout<<"Invalid selection\n";
        }
    } while (choice != 3);
    
    acc->addRecord();

    return 0;
    
}