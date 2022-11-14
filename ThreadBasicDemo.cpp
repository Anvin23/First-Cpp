#include<iostream>
#include<thread>
using namespace std;

static bool con = true;

void run()
{
    while(con)
    {
        cout<<"Running....\n";
        this_thread::sleep_for(2s);  // causes a 2s deley in printing Running....
    }
}

int main()
{
    thread runner(run);  // run is a function pointer

    cin.get();  // waits for user to enter something.This and runner thread runs parallely
    con=false;

    runner.join();  // waits for sub thread(runner) to finish it's execution before resuming main thread operations

    cout<<"Finished\n";  // this is executed only after sub thread(runner) finishes it's execution

    return 0;

}