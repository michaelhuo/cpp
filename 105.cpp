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
#include <unordered_map>
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    TreeNode* helper(const vector<int>&preorder, const vector<int>& inorder, int inorder_low, int inorder_high);
private:
    unordered_map<int, int> inorder_maps;
    int preorder_index;
};
TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
            return nullptr;
        }
        int size = preorder.size();
        int i = 0;
        for (auto& v : inorder) {
            inorder_maps[v] = i ++;
        }
        return helper(preorder, inorder, 0, size);
    }

TreeNode* Solution::helper(const vector<int>&preorder, const vector<int>& inorder, int inorder_low, int inorder_high) {
    if (inorder_low == inorder_high) {
        return nullptr;
    }
    int root_value = preorder[preorder_index];
    int index = inorder_maps[root_value];
    TreeNode* root = new TreeNode(root_value);
    preorder_index ++;
    root->left = helper(preorder, inorder, inorder_low, index);
    root->right = helper(preorder, inorder, index + 1, inorder_high);
    return root;
    
}
