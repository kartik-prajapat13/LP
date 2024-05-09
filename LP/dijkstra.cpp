#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(vector<pair<int, int>> adj[], int V, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src)); 
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex Distance from Source " << src << ":" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << " \t\t " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<pair<int, int>> adj[V];

    // Example graph
    adj[0].push_back(make_pair(1, 9));
    adj[0].push_back(make_pair(2, 6));
    adj[0].push_back(make_pair(3, 5));
    adj[0].push_back(make_pair(4, 3));
    adj[2].push_back(make_pair(1, 2));
    adj[2].push_back(make_pair(3, 4));

    dijkstra(adj, V, 0);

    return 0;
}


// 0 -> (1, 9), (2, 6), (3, 5), (4, 3)
// 1 -> (empty)
// 2 -> (1, 2), (3, 4)
// 3 -> (empty)
// 4 -> (empty)
