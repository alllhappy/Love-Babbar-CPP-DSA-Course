// TC = O((N+E)logN)

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // creating adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i=0; i<g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    // using set easier initilizaiton
    set<pair<int,int>> pq;

    key[1] = 0; // Starting node
    pq.insert({0, 1}); // (weight, node)

    while (!pq.empty()) {
        auto it = *pq.begin();
        int u= it.second;
        pq.erase(pq.begin());

        if (mst[u]) continue;

        mst[u] = true;

        for (const auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (!mst[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.insert({key[v], v});
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i=2; i<=n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;

}
