#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int findParent(int node, vector<int>& parent) {
    if(parent[node] == node) {
        return node;
    }
    // Path Compression
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v]) {
        parent[u] = v;
    } else if(rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;
        rank[v]++;
    }

}

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

    // Sort the graph based on the weight of the edges
    sort(graph.begin(), graph.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        return a.second < b.second;
    });

    // Disjoint Set Implementation

    // Create a parent array of size n
    // Initially, each node is its own parent
    vector<int> parent(n);
    for(int i=0;i<n;i++) {
        parent[i] = i;
    }
    
    // Create a rank array of size n
    // Initially, each node has a rank of 0
    vector<int> rank(n, 0);


    vector<pair<pair<int, int>, int>> mst;
    int minCost = 0;

    for(int i=0;i<graph.size();i++) {
        int a = graph[i].first.first;
        int b = graph[i].first.second;
        int wt = graph[i].second;

        int p1 = findParent(a, parent);
        int p2 = findParent(b, parent);

        if(p1 != p2) {
            unionSet(p1, p2, parent, rank);
            minCost += wt;
            mst.push_back({{a, b}, wt});
        }
    }

    cout<<"Minimum Spanning Tree: "<<endl;
    for(auto edge: mst) {
        cout<<edge.first.first<<" - "<<edge.first.second<<"    Cost: "<<edge.second<<endl;
    }

    cout<<"Min Cost: "<<minCost<<endl;

    return 0;

}