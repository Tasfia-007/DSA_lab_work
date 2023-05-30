#include<bits/stdc++.h>
using namespace std;
bool vis[1000000];
void bfs(vector<vector<int>>& graph,  int node) {
    queue<int> q;
    q.push(node); 

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (!vis[curr]) {
            vis[curr] = true;
            cout << curr << " "; 
            for (auto i: graph[curr]) {
                if (!vis[i]) {
                    q.push(i);
                }
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);

   while(m--) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int x;
    cin>>x;

    
    bfs(graph, x);
    cout << endl;

    return 0;
}
