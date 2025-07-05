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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return nullptr;
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        for(int i = 1;i<preorder.size();++i){
            TreeNode* node = new TreeNode(preorder[i]);
            TreeNode* parent = nullptr;

            while(!st.empty() && preorder[i]>st.top()->val){
                parent = st.top();
                st.pop();
            }
            if(parent) parent->right = node;
            else st.top()->left = node;

            st.push(node);
        }
        return root;
    }
};