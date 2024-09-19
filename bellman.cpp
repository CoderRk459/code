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