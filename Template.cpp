#include<iostream>

using namespace std;



// the template gets evaluated at compile time
// the template gets created when we call it and based on how we call it

// whenever we call this function , it gets created and substitute T(template parameter) with the type we used to call the function wherever we used it in the template
template<typename T>
void print(T value)
{
    cout<<value<<endl;
}

// the template doesn't exist until we call it

template<typename T , int N>
class Array
{
    private:
        T m_array[N];
        int count = 0;

    public:
        void getDetails()
        {
            cout<<"The size of the array is "<<N<<endl;
        }
};
// in stack allocated array , we need to know the size of the array beforehand since it is created at compile time . But here , since the template will only be created when it is used , we only need to know the size during the creation.

int main()
{

    print(10);       // here T changes to int
    print("Hello");  // here T changes to char*
    print(5.6f);     // here T changes to float
    print(true);
    print<int>(25);  // we can also pass the type with which T should be replaced


    Array<float , 5> arr1;
    Array<int , 12> arr2;
    arr1.getDetails();
    arr2.getDetails();

    // each time we call the template , it gets created
    // when we called Array "2" times , "2 classes were created" according to the template
    // one where the N was substituted with 5 and type float and another one where N was substituted with 12 and type int


    return 0;
}