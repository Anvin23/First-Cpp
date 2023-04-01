#include<iostream>
#include<vector>
#include<algorithm>  // to get sort function

using namespace std;

void display(vector<int> &v)
{
    vector<int> :: iterator itr;

    for(itr = v.begin() ; itr != v.end() ; itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> v1; // creating an empty vector

    // vector<int> v2(5); creating a length 5 vector

    v1.push_back(42);
    v1.push_back(30);
    v1.push_back(1);
    v1.push_back(76);
    v1.push_back(208);
    // insertion at end
    // no function for insertion at front
    display(v1);

    v1.pop_back();
    // removes an element from the end
    display(v1);

    sort(v1.begin() , v1.end());
    // sorts from begin to end
    display(v1);

    cout<<"The size of the vector is "<<v1.size();


    return 0;
}