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
    int fsize(TreeNode* root){
        if(root == NULL) return 0;

        int leftcount = fsize(root->left);
        int rightcount = fsize(root->right);

        return leftcount + rightcount + 1;
    }

    int fsum(TreeNode* root){

        if(root == NULL) return 0;

        int leftsum = fsum(root->left);
        int rightsum = fsum(root->right);

        return leftsum + rightsum + root->val;
    }

    int calculate(TreeNode* root, int count){

         if(root == NULL) return count;
        int size = fsize(root);
        int sum = fsum(root);

        if((sum / size) == root->val) count++;

        count = calculate(root->left,count);
        count = calculate(root->right,count);
        return count;
    }
    int averageOfSubtree(TreeNode* root) {
      
       int ans = calculate(root, 0); 
       return ans;
    }
};