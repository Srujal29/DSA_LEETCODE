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
    // int fsize(TreeNode* root){
    //     if(root == NULL) return 0;

    //     int leftcount = fsize(root->left);
    //     int rightcount = fsize(root->right);

    //     return leftcount + rightcount + 1;
    // }

    // int fsum(TreeNode* root){

    //     if(root == NULL) return 0;

    //     int leftsum = fsum(root->left);
    //     int rightsum = fsum(root->right);

    //     return leftsum + rightsum + root->val;
    // }

    pair<int,int> calculate(TreeNode* root, int &count){
        if(root == NULL) return {0,0};

        pair<int,int>  leftpart = calculate(root->left,count);
        pair<int,int>  rightpart = calculate(root->right,count);

        int sum = leftpart.first + rightpart.first + root->val;
        int size = leftpart.second + rightpart.second + 1;

        if((sum/size) == root->val) count++;
        return {sum,size};
    }
    int averageOfSubtree(TreeNode* root) {
      int count = 0;
      calculate(root, count); 
       return count;
    }
};