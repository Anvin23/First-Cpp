#include<iostream>
#define V 6
using namespace std;

int distArray[V];
bool coloredVertices[V];

void initialise()
{
    for(int i = 0;i<V;i++)
    {
        distArray[i] = INT32_MAX;
        coloredVertices[i] = false;
    }
}

bool isFull()
{
    for(int i=0;i<V;i++)
    {
        if(coloredVertices[i] == false)
        {
            return false;
        }
    }
    return true;
}

int selectVertex()
{
    int min = INT32_MAX , min_index;
    for(int i=0;i<V;i++)
    {
        if(coloredVertices[i] == false)
        {
            if(distArray[i] < min)
            {
                min_index = i;
                min = distArray[i];
            }
        }
    }
    coloredVertices[min_index] = true;
    return min_index;
}

int min(int a , int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

void printSolution(int source)
{
    cout<<"\nThe shortest distance from\n";

    for(int i=0;i<V;i++)
    {
        cout<<source<<" to "<<i<<" = "<<distArray[i]<<endl;
    }
}

void dijkstra(int arr[V][V] , int source)
{
    distArray[source] = 0;
    // coloredVertices[source] = true;

    while(!isFull())
    {
        int u = selectVertex();
        for(int v=0;v<V;v++)
        {
            if(coloredVertices[v] == false && arr[u][v] != 0)
            {
                distArray[v] = min(distArray[v] , distArray[u]+arr[u][v]);
            }
        }
    }

    printSolution(source);
}

int main()
{
    int source;
    int graph[V][V] = {
        {0,18,15,0,0,0} , 
        {18,0,6,9,0,0} , 
        {15,6,0,14,7,0} ,
        {0,9,14,0,10,28} ,
        {0,0,7,10,0,36} ,
        {0,0,0,28,36,0}
    } ;
    initialise();

    dijkstra(graph , 0);

    return 0;
}