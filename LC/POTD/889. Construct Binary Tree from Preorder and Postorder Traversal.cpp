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
    TreeNode* f(int& i, int& j, vector<int>& pre, vector<int>& post) {
        TreeNode* newNode = new TreeNode(pre[i++]);

        if(newNode->val != post[j]) {
            newNode->left = f(i, j, pre, post);
        }
        // backtrack
        if(newNode->val != post[j]) {
            newNode->right = f(i, j, pre, post);
        }

        j++; // if leaf node
        return newNode;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int i = 0, j = 0;
        return f(i, j, preorder, postorder);
    }
};