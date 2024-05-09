#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(vector<vector<int>>& g, int start, vector<int>& vis) {
    vis[start] = 1;
    cout << start << " ";
    
    for(auto child : g[start]) {
        if(!vis[child]) {
            dfs(g, child, vis);
        }
    }
}

void bfs(vector<vector<int>>& g, int start, vector<int>& vis) {
    
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(auto child : g[cur]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
}

int main() {
    
    int V;
    cout << "Enter vertices: ";
    cin >> V;
    vector<vector<int>> g(V);  //Initialisation of V vector 

    int E;
    cout << "Enter Edges: ";
    cin >> E;

    for(int i = 0 ; i < E ; i++) {
        int a, b;
        cout << "a b: ";
        cin >> a >> b;
        g[a].push_back(b); // Adjacent vertices 
        g[b].push_back(a);
    }

    vector<int> vis(V, 0);
    
    cout << "DFS: ";
    dfs(g, 0, vis);
    cout << endl;

    vis.assign(V, 0); // Reset vis vector
    
    cout << "BFS: ";
    bfs(g, 0, vis);
    cout << endl;

    return 0;
}

    


/*
Enter vertices: 5
Enter Edges: 6
a b: 0 1
a b: 0 2
a b: 1 3
a b: 1 4
a b: 2 3
a b: 3 4      



   0
  / \
 1---2
 | / |
 3---4


output 


DFS: 0 1 3 4 2 
BFS: 0 1 2 3 4 

*/
