#include<iostream>
using namespace std;

int distArray[10][10];
bool coloredVertices[10];

void init()
{
    for(int i = 0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            distArray[i][j] = INT32_MAX;
        }
        coloredVertices[i] = false;
    }

}

int min(int a , int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

void findDistance(int *arr , int source ,int n)
{
    distArray[source][source] = 0;
}
int main()
{
    int graph[6][6] = {
        {0,18,15,0,0,0} , 
        {18,0,6,9,0,0} , 
        {15,6,0,14,7,0} ,
        {0,9,14,0,10,28} ,
        {0,0,7,10,0,36} ,
        {0,0,0,28,36,0}
    } ;



}