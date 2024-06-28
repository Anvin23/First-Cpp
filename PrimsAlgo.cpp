#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

int main() {
    vector<pair<pair<int, int>, int>> graph;
    graph.push_back({{0, 1}, 2});
    graph.push_back({{0, 2}, 3});
    graph.push_back({{1, 2}, 1});
    graph.push_back({{1, 3}, 1});
    graph.push_back({{2, 3}, 1});
    graph.push_back({{2, 4}, 4});
    graph.push_back({{3, 4}, 2});

    int n = 5;
    // no. of vertices in the graph = 5 (0, 1, 2, 3, 4)


    // Create an adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for(auto edge: graph) {
        adj[edge.first.first].push_back({edge.first.second, edge.second});
        adj[edge.first.second].push_back({edge.first.first, edge.second});
    }

    vector<int> parent(5, -1);
    vector<int> key(5, INT_MAX);
    vector<bool> mstSet(5, false);

    // Start from the first node ie 0
    // Set the key of the first node to 0 and parent to -1
    key[0] = 0;
    parent[0] = -1;

    for(int i=0;i<n;i++) {
        int min = INT_MAX, min_node;
        for(int j=0;j<n;j++) {
            if(mstSet[j] == false && key[j] < min) {
                min = key[j];
                min_node = j;
            }
        }

        mstSet[min_node] = true;

        for(auto neighbour: adj[min_node]) {
            if(mstSet[neighbour.first] == false && neighbour.second < key[neighbour.first]) {
                key[neighbour.first] = neighbour.second;
                parent[neighbour.first] = min_node;
            }
        }
    }

    vector<pair<pair<int, int>, int>> mst;
    int minCost = 0;
    for(int i=1;i<n;i++) {
        mst.push_back({{parent[i], i}, key[i]});
        minCost += key[i];
    }

    cout<<"Minimum Spanning Tree: "<<endl;
    for(auto edge: mst) {
        cout<<edge.first.first<<" - "<<edge.first.second<<"    Cost: "<<edge.second<<endl;
    }
    cout<<"Minimum Cost: "<<minCost<<endl;

    return 0;
}