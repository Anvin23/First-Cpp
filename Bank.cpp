#include<iostream>
#include<fstream>
using namespace std;


class Account
{
    const char* name;
    int id;
    float balance;

    public:

        Account(const char* name , int id)
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
            }
        }

        void displayBalance()
        {
            cout<<"Account Name : "<<this->name<<endl;
            cout<<"Current balance : Rs."<<this->balance<<endl;
        }

        void addRecord()
        {
            
            FILE* fp = fopen("Accounts.txt","a");
            fprintf(fp,"Account Name : %s\n",this->name);
            fprintf(fp,"Balance Amount : Rs.%f\n\n",this->balance);

            fclose(fp);

        }

};

int main()
{
    Account* acc = new Account("Anlo",122);
    acc->deposit(70000);
    acc->displayBalance();
    acc->addRecord();
    
}