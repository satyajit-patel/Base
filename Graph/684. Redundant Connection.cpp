class DSU {
private:
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n, -1);
    }

    int findParent(int node) {
        if(parent[node] == -1) {
            return node;
        }

        // keep updating
        return parent[node] = findParent(parent[node]);
    }

    void merge(int u, int v) {
        int nu = findParent(u);
        int nv = findParent(v);
        if(nu == nv) {
            return;
        }
        parent[max(u, v)] = min(u, v);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU* dsu = new DSU(n+1);
        for(auto& it: edges) {
            int u = it[0];
            int v = it[1];
            if(dsu->findParent(u) == dsu->findParent(v)) {
                return {u, v};
            }
            dsu->merge(u, v);
        }
        return {};
    }
};