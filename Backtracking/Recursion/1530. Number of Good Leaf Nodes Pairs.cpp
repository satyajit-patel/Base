/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void f(TreeNode* root, set<TreeNode*>& l, TreeNode* prevNode, map<TreeNode*, set<TreeNode*>>& adj) {
        // base case
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            l.insert(root);
        }
        if(prevNode) {
            adj[root].insert(prevNode);
            adj[prevNode].insert(root);
        }

        // transiton
        f(root->left, l, root, adj);
        f(root->right, l, root, adj);
    }

    void bfs(TreeNode* root, map<TreeNode*, set<TreeNode*>>& adj, set<TreeNode*>& l, int D, int& pairs) {
        map<TreeNode*, bool> vis;
        vis[root] = true;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int d = it.second;
            if((node != root) && (l.find(node) != l.end()) && (d <= D)) {
                pairs++;
            }
            if(d > D) {
                return; // OPTI
            }
            for(auto& child: adj[node]) {
                if(!vis[child]) {
                    vis[child] = true;
                    q.push({child, d + 1});
                }
            }
        }
    }

    int usingBfs(TreeNode* root, int distance) {
        set<TreeNode*> l;
        map<TreeNode*, set<TreeNode*>> adj;
        f(root, l, NULL, adj);
        int pairs = 0;
        for(auto& it: l) {
            bfs(it, adj, l, distance, pairs);
        }
        return pairs / 2;
    }

    pair<vector<int>, int> dfs(TreeNode* root, int distance) {
        // base case
        if(!root) {
            return {{}, 0};
        }
        if(!root->left && !root->right) {
            return {{1}, 0}; 
            // i.e telling your parent that you have 1 leaf node so far which dist is 1
        }

        // transition
        pair<vector<int>, int> left = dfs(root->left, distance);
        pair<vector<int>, int> right = dfs(root->right, distance);

        // ans
        vector<int> v1 = left.first;
        vector<int> v2 = right.first;
        int ans = 0;
        for(auto& i: v1) {
            for(auto& j: v2) {
                if(i + j <= distance) {
                    ans++;
                }
            }
        }
        int newAns = ans + left.second + right.second;
        vector<int> newVec;
        for(auto& it: v1) {
            int newEle = it + 1;
            if(newEle < distance) { // OPTI
                newVec.push_back(newEle);
            }
        }
        for(auto& it: v2) {
            int newEle = it + 1;
            if(newEle < distance) {
                newVec.push_back(newEle);
            }
        }
        return {newVec, newAns};
    }

    int usingDfs(TreeNode* root, int distance) {
        return dfs(root, distance).second;
	/*
		TC => O(n * m^2)
			where 
			n = #nodes
			m = #leaf nodes
			so in each node we are doing m^2 operation

		SC => O(n * m) + recursion stack
			in each node we are having information of leaf node
				
	*/
    }

    int countPairs(TreeNode* root, int distance) {
        // return usingBfs(root, distance);
        return usingDfs(root, distance); // WOAH
    }
};