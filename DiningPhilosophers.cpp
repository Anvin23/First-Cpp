#include<iostream>
#include<thread>

using namespace std;

bool forks[5];

void init() {
    for(int i=0;i<5;i++) {
        forks[i] = true;
    }
}

void philosopher(int n) {

    while(forks[n]==false || forks[(n+1)%5]==false);

    forks[n]=false;
    forks[(n+1)%5]=false;
    cout<<"Philosopher "<<n<<" is eating"<<endl;
    forks[n]=true;
    forks[(n+1)%5]=true;
    cout<<"Philosopher "<<n<<" finished eating"<<endl;

}

int main() {
    init();
    thread th1(philosopher , 0);
    thread th2(philosopher , 1);
    thread th3(philosopher , 2);
    thread th4(philosopher , 3);
    thread th5(philosopher , 4);

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();



    return 0;
}