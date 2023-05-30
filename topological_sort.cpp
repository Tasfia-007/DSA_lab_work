#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& stk) {
    visited[node] = true;


    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, stk);
        }
    }


    stk.push(node);
}


vector<int> topologicalSort(vector<vector<int>>& graph, int numNodes) {
    vector<int> result;
    vector<bool> visited(numNodes, false);
    stack<int> stk;

  
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, stk);
        }
    }

   
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> sortedOrder = topologicalSort(graph, numNodes);

    cout << "Topological sort order: ";
    for (int node : sortedOrder) {
        cout << node << " ";
    }
    cout << endl;

}