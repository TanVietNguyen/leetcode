#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return ;
        }
        root = treeToList(root);
    }

    TreeNode* treeToList(TreeNode* root){
        TreeNode* left;
        TreeNode* right;
        TreeNode* temp;
        if(root -> left == nullptr && root -> right == nullptr){
            return root;
        }
        else if(root -> left == nullptr){
            return root;
        }
        else if(root -> right == nullptr){
            root -> right = root -> left;
            root -> left = nullptr;
            return root;
        }
        else{
            left = treeToList(root -> left);
            right = treeToList(root -> right);
            root -> right = left;
            root -> left = nullptr;
            temp = root;
            while(temp -> right != nullptr){
                temp = temp -> right;
            }
            temp -> right = right;
            return root;
        }
    }
};