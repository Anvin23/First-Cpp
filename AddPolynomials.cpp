#include<iostream>
using namespace std;

struct polynode
{
    int coef,exp;
    struct polynode* next;
};

void display(struct polynode* ptr)
{
    if(ptr==nullptr)
    {
        cout<<"Empty polynomial\n";
        return;
    }
    while(ptr->next != nullptr)
    {
        cout<<ptr->coef<<"x^"<<ptr->exp<<" + ";
        ptr=ptr->next;
    }
    cout<<ptr->coef<<"x^"<<ptr->exp<<endl;
}
void insertElement(struct polynode** start,int co,int xp)
{
    struct polynode* temp = (struct polynode*)malloc(sizeof(struct polynode));
    if(temp==nullptr)
    {
        printf("Node not created\n");
        return;
    }
    temp->coef=co;
    temp->exp=xp;
    temp->next=nullptr;
    if((*start)==nullptr)
    {
        (*start)=temp;
        return;
    }
    else
    {
        struct polynode *p ,*prev;
        p=(*start);
        if(xp>p->exp)
        {
            temp->next=p;
            (*start)=temp;
            return;
        }
        while(p->next != nullptr  &&  p->exp > xp)
        {
            prev=p;
            p=p->next;
        }
        if(p->exp==xp)
        {
            p->coef+=co;
            free(temp);
            return;
        }
        if(p->exp < xp)
        {
            temp->next=p;
            prev->next=temp;
        }
        else if(p->next==nullptr)
        {
            p->next=temp;
        }
    }
}
void addPolynomials(struct polynode** poly1,struct polynode** poly2,struct polynode ** polysum)
{
    struct polynode *tp1=(*poly1),*tp2=(*poly2);
    int new_coef,new_exp;
    while(1)
    {
        if(tp1==nullptr)
        {
            while(tp2 != nullptr)
            {
                insertElement(polysum,tp2->coef,tp2->exp);
                tp2=tp2->next;
            }
            return;
        }
        if(tp2==nullptr)
        {
            while(tp1 != nullptr)
            {
                insertElement(polysum,tp1->coef,tp1->exp);
                tp1=tp1->next;
            }
            return;
        }
        if(tp1->exp==tp2->exp)
        {
            new_coef=tp1->coef+tp2->coef;
            new_exp=tp1->exp;
            insertElement(polysum,new_coef,new_exp);
            tp1=tp1->next;
            tp2=tp2->next;
        }
        else if(tp1->exp > tp2->exp)
        {
            insertElement(polysum,tp1->coef,tp1->exp);
            tp1=tp1->next;
        }
        else
        {
            insertElement(polysum,tp2->coef,tp2->exp);
            tp2=tp2->next;
        }
    }
}
int main()
{
    struct polynode* p1=nullptr,*p2=nullptr,*sum=nullptr;
    int t1,t2,cf,ep;
    cout<<"Enter no. of terms in the first polynomial : ";
    cin>>t1;
    for(int i=0;i<t1;i++)
    {
        cout<<"Enter the coefficient : ";
        cin>>cf;
        cout<<"Enter the exponent : ";
        cin>>ep;
        insertElement(&p1,cf,ep);
    }
    cout<<"Enter no. of terms in the second polynomial : ";
    scanf("%d",&t2);
    for(int i=0;i<t2;i++)
    {
        cout<<"Enter the coefficient : ";
        cin>>cf;
        cout<<"Enter the exponent : ";
        cin>>ep;
        insertElement(&p2,cf,ep);
    }
    cout<<"The first polynomial is \n";
    display(p1);
    cout<<"The second polynomial is \n";
    display(p2);
    addPolynomials(&p1,&p2,&sum);
    cout<<"The sum of the polynomials is \n";
    display(sum);
    
    return 0;
}