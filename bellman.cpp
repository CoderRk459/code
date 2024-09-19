# include<stdio.h>
# include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[1000];
vector<vector<int>> edges;

int n, m;
vector<int> dist(1000, 1e8);
bool visited[1000];

void dfs(int s) {
    visited[s] = true;

    for (auto it : graph[s]) {
        if (!visited[it.first]) dfs(it.first);
    }
}

bool bellman_ford(int s, int n, int d) {
    dist[s] = 0;

    for (int i = 1; i < n; i++) {
        for (auto vec : edges) {
            if (dist[vec[1]] > dist[vec[0]] + vec[2]) {
                dist[vec[1]] = dist[vec[0]] + vec[2];
            }
            // cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
        }
            // cout << "hello" << endl;
    }

    // for (auto it : dist) cout << it << " ";
    // cout << endl;

    // int temp_d = dist[d];

    // for (int i = 1; i < n; i++) {
    //     for (auto vec : edges) {
    //         if (dist[vec[1]] > dist[vec[0]] + vec[2]) {
    //             dist[vec[1]] = dist[vec[0]] + vec[2];
    //         }
    //         if (temp_d != dist[d]) break;
    //         // cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
    //     }
    //         // cout << "hello" << endl;
    // }

    for (auto vec : edges) {
        if (dist[vec[1]] > dist[vec[0]] + vec[2]) {
            // return false;
            // dist[vec[1]] = dist[vec[0]] + vec[2];
            dfs(vec[1]);
        }
    }

    // return temp_d == dist[d];
    return !visited[d];

    // return true;
}


int main() {
    int n, m;
    cin >> n >> m;
    int u, v, w;

    // cout << n << m;

    for (int  i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        edges.push_back({u, v, w});
    }

    // for (auto it : edges) {
    //     cout << it[0] << " " << it[1] << " " << it[2] << endl;
    // }

    int s, d;
    cin >> s >> d;
    // cout << s << d;

    if (bellman_ford(s, n, d)) {
        cout << dist[d] << endl;
    } else {
        cout << "UNSAFE" << endl;
    }

    return 0;
}


1. Graph Representation
vector<pair<int, int>> graph[1000]; stores an adjacency list where each node has a list of its connected neighbors and the corresponding edge weights.
vector<vector<int>> edges; stores all edges in the form of triplets {u, v, w}, where u is the starting node, v is the ending node, and w is the weight of the edge.
2. DFS Function
The dfs function performs depth-first search (DFS) on the graph to mark visited nodes starting from node s. This is used later when detecting if a negative-weight cycle is reachable from the destination.

3. Bellman-Ford Algorithm
The bellman_ford function runs the Bellman-Ford algorithm to compute the shortest path from the source node s to all other nodes in the graph:

It initializes the distance to all nodes as infinity (1e8), except for the source node, which is set to 0.
It then relaxes all edges n-1 times (the core idea of Bellman-Ford). For each edge (u, v, w), it checks if the distance to node v can be reduced by going through node u, and if so, it updates the distance.
After relaxing all edges, the algorithm performs one more iteration to detect negative-weight cycles. If any distance can still be reduced, it means a negative-weight cycle exists. In this case, instead of updating the distance, the code runs DFS from the node involved in the cycle to mark nodes affected by the cycle as visited.

4. Cycle Detection and Output
If the destination node d is not visited after the DFS, it means no negative-weight cycle affects d, and the shortest path to d is printed.
If node d is part of a negative-weight cycle, the code prints "UNSAFE" to indicate that the result is unreliable due to the cycle.
5. Input and Output
The user inputs n (number of vertices) and m (number of edges), followed by m edges defined by triplets u, v, and w.
After the edges, the user provides the source s and destination d.
The program outputs either the shortest distance to d or "UNSAFE" if a negative-weight cycle is detected.
Code Summary:
Input parsing: Takes in the number of nodes, edges, and their details.
Graph and edges storage: The graph is stored in both adjacency list (graph) and edge list (edges) formats.
Bellman-Ford algorithm: Runs the algorithm to find shortest paths and detect negative cycles.
Cycle detection: If a negative cycle affects the destination, it is marked, and "UNSAFE" is printed.
Result: Outputs the shortest distance or "UNSAFE".
