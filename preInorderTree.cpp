#include <vector>
#include <iostream>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int length = inorder.size();
        TreeNode* preNode = new TreeNode(inorder[0]);
        TreeNode* root;
        if(inorder[0] == preorder[0]){
            root = preNode;
        }
        bool isNextTheHigherNode = false;
        for(int i = 1; i < length; i++){
            TreeNode* currNode = new TreeNode(inorder[i]);
            if(inorder[i] == preorder[0]){
                root = currNode;
            }//{3,9,20,15,7};
            // {9,3,15,20,7};
            if(isNextTheHigherNode){
                currNode -> left = preNode;
                preNode = currNode;
                isNextTheHigherNode = false;
                continue;
            }
            for(int j = 0; j < length; j++){
                if(inorder[i - 1] == preorder[j]){
                    preNode -> right = currNode;
                    isNextTheHigherNode = true;
                    break;
                }
                else if(inorder[i] == preorder[j]){
                    currNode -> left = preNode;
                    preNode = currNode;
                    break;

                }
            }
        }

        return root;

    }
};

int main (){
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = s.buildTree(preorder, inorder);
    cout << "Root: " << root->val << endl;
    cout << "Left Child: " << root->left->val << endl;
    cout << "Right Child: " << root->right->val << endl;
    cout << "Left-Left Child: " << root->left->left->val << endl;
    cout << "Left-Right Child: " << root->left->right->val << endl;
    cout << "Right-Left Child: " << root->right->left->val << endl;
    cout << "Right-Right Child: " << root->right->right->val << endl;
}