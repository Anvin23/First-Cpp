#include<iostream>
#include<map>

using namespace std;

void display(map<char , int> &m)
{
    map<char , int> :: iterator itr;

    for(itr = m.begin() ; itr != m.end() ; itr++)
    {
        cout<<(*itr).first<<" "<<(*itr).second<<endl;
                 // key             // value
    }
    cout<<endl;
}

int main()
{
    map<char , int> ascii_vals;
    ascii_vals['A'] = 65;
    ascii_vals['Z'] = 90;
    ascii_vals['a'] = 97;
    ascii_vals['z'] = 122;
    ascii_vals['$'] = 36;
    ascii_vals['0'] = 48;
    ascii_vals['9'] = 57;
    ascii_vals['='] = 61;

    ascii_vals.insert({'*' , 42});
    ascii_vals.insert({{';' , 59} , {'#' , 35}});

    display(ascii_vals);



    return 0;
}