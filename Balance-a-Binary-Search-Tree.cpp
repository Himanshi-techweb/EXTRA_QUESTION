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
14    int height(TreeNode* root){
15        if(root==NULL)return 0;
16        int left=height(root->left);
17        int right=height(root->right);
18        return max(left,right)+1;
19    }
20    TreeNode* leftrotate(TreeNode* root){
21        if(root==NULL || root->right==NULL)return root;
22        TreeNode* B=root->right;
23        TreeNode* C=B->left;
24        B->left=root;
25        root->right=C;
26        return B;  
27        
28    }
29    TreeNode* rightrotate(TreeNode* root){
30        if(root==NULL || root->left==NULL)return root;
31        TreeNode* B=root->left;
32        TreeNode* C=B->right;
33        B->right=root;
34        root->left=C;
35        return B;  
36        
37    }
38    TreeNode* check(TreeNode* root){
39        if(root==NULL)return root;
40        root->left=check(root->left);
41        root->right=check(root->right);
42        int balance=height(root->left)-height(root->right);
43        if(abs(balance)<=1)return root;
44        //left
45        if(balance>1){
46            if(root->left){
47                //ll
48            if(height(root->left->left)>=height(root->left->right)){
49                root=rightrotate(root);
50            }
51            //lr
52            else{
53                root->left=leftrotate(root->left);
54                root=rightrotate(root);
55            }
56            }
57            
58        }
59        else{
60            if(root->right!=NULL){
61               //rl
62            if(height(root->right->left)>height(root->right->right)){
63                root->right=rightrotate(root->right);
64                root=leftrotate(root);
65            }
66            //rr
67            else{
68                root=leftrotate(root);
69            }
70            }
71            
72        }
73        return check(root);
74    }
75    TreeNode* balanceBST(TreeNode* root) {
76        return check(root);
77    }
78};