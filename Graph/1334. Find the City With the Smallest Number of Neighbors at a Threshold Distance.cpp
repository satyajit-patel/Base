class Solution {
public:
    vector<int> bfs(int node, vector<pair<int, int>> adj[], int n) {
        vector<int> dist(n, INT_MAX);
        dist[node] = 0;
        queue<pair<int, int>> q;
        q.push({node, dist[node]});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int curNode = it.first;
            int curCost = it.second;
            for(auto& child: adj[curNode]) {
                int adjNode = child.first;
                int adjCost = child.second;
                int newCost = curCost + adjCost;
                if(newCost < dist[adjNode]) {
                    dist[adjNode] = newCost;
                    q.push({adjNode, dist[adjNode]});
                }
            }
        }
        return dist;
    }

    void floydWarshall(vector<vector<int>>& grid, int n) {
        for (int i = 0; i < n; i++) {
            grid[i][i] = 0; // Distance to self is 0
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][k] != INT_MAX && grid[k][j] != INT_MAX) {
                        grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                    }
                }
            }
        }
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
        for(auto& it: edges) {
            int i = it[0];
            int j = it[1];
            int c = it[2];
            // undirected
            grid[i][j] = min(grid[i][j], c);
            grid[j][i] = min(grid[j][i], c);
        }
        floydWarshall(grid, n);

        // vector<pair<int, int>> adj[n];
        // for(auto& it: edges) {
        //     int i = it[0];
        //     int j = it[1];
        //     int c = it[2];
        //     // undirected
        //     adj[i].push_back({j, c});
        //     adj[j].push_back({i, c});
        // }
        // vector<vector<int>> grid; // floydWarshall => all source shortest path
        // for(int node=0; node<n; node++) {
        //     vector<int> dist = bfs(node, adj, n); // dijkstra => single source shortest path
        //     grid.push_back(dist);
        // }

        int mini = INT_MAX;
        int ans = -1;
        for(int node=0; node<n; node++) {
            int cityCount = 0;
            for(int i=0; i<n; i++) {
                if(grid[node][i] <= distanceThreshold) {
                    cityCount++;
                }
            }
            if(cityCount <= mini) {
                mini = cityCount;
                ans = node;
            }
        }
        return ans;
    }
};

// FLOYD WARSHALL

// 2976. Minimum Cost to Convert String I
class Solution {
public:
    void floydWarshall(vector<vector<long long>>& grid) {
        for(int k=0; k<26; k++) {
            for(int u=0; u<26; u++) {
                for(int v=0; v<26; v++) {
                    grid[u][v] = std::min(grid[u][v], grid[u][k] + grid[k][v]); // go via k
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long>> grid(26, vector<long long>(26, INT_MAX));

        for(int i=0; i<original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int c = cost[i];
            grid[u][v] = std::min(grid[u][v], (long long)c);
        }

        // all source shortest path
        floydWarshall(grid);

        long long minCost = 0;
        for(int i=0; i<source.size(); i++) {
            if(source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                int c = grid[u][v];
                if(c == INT_MAX) {
                    return -1;
                } else {
                    minCost += c;
                }
            }
        }
        return minCost;
    }
};