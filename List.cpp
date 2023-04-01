#include<iostream>
#include<list>
using namespace std;

void display(list<int> &ls)
{
    list<int> :: iterator itr;
    // creating an iterator

    for(itr = ls.begin() ; itr != ls.end() ; itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
}

int main()
{
    list<int> ls;  // creating an empty vector

    // list<int> ls(6); creating a length 6 vector

    ls.push_back(24);
    ls.push_back(8);
    ls.push_back(137);
    // adds a value at the end of the list
    ls.push_front(91);
    ls.push_front(40);
    // adds a value at the beginning of the list

    display(ls);

    ls.pop_back();
    // removes an element from the back
    ls.pop_front();
    // removes an element from the front

    display(ls);

    ls.remove(24);
    // removes the given value from the list

    display(ls);

    return 0;
}