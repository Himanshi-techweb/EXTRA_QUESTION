1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int sum=0;
15    
16    void solve(TreeNode* root,vector<int> &arr,int curr){
17      if(root==NULL ){
18         return ;
19      }
20       
21       curr=curr*2 +root->val;
22       if(root->left==NULL && root->right==NULL){
23          sum+=curr;return;
24       }    
25        solve(root->left,arr,curr);
26        solve(root->right,arr,curr);
27    }
28    int sumRootToLeaf(TreeNode* root) {
29        vector<int>arr;
30        solve(root,arr,0);
31        return sum;
32    }
33};