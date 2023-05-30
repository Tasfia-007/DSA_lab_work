#include<bits/stdc++.h>
using namespace std;
bool vis[1000000];
void dfs(vector<vector<int>>& graph,  int node) {
    vis[node] = true;
    cout << node<< " ";

  
    for (auto i: graph[node]) {
        if (!vis[i]) {
            dfs(graph, i);
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);

    cout << "Enter the edges (node1 node2):\n";
    for (int i = 0; i < m; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int node;
    cin>>node;

   
    dfs(graph, node);
    cout << endl;

    return 0;
}