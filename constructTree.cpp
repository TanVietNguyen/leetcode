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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int length = inorder.size();
        return constructTree(inorder, postorder, length);
    }

    TreeNode* constructTree (vector<int>& inorder, vector<int>& postorder, int length){
        TreeNode* root;
        if(length == 0){
            return nullptr;
        }
        else if(length == 1){
            root = new TreeNode(inorder[0]);
            return root;
        }
        else if(length == 2){
            if(inorder == postorder){
                root = new TreeNode(postorder[1]);
                root -> left = new TreeNode (postorder[0]);
                return root;
            }//9,3,15,20,7
            // 9,15,7,20,3
            else{
                root = new TreeNode (postorder[1]);
                root -> right = new TreeNode(postorder[0]);
                return root;
            }
        }
        else{
            root = new TreeNode(postorder[length - 1]);
            int rootIndex;
            for(int i = 0; i < length; i++){
                if(inorder[i] == postorder[length - 1]){
                    rootIndex = i;
                    break;
                }
            }

            vector<int> leftChildrenInorder(inorder.begin() + 0, inorder.begin() + rootIndex);
            vector<int> rightChildrenInorder(inorder.begin() + rootIndex + 1, inorder.end());
            vector<int> leftChildrenPostorder(postorder.begin(), postorder.begin() + rootIndex);
            vector<int> rightChildrenPostorder(postorder.begin() + rootIndex, postorder.end() - 1);

            root -> left = constructTree (leftChildrenInorder, leftChildrenPostorder, leftChildrenInorder.size());
            root -> right = constructTree (rightChildrenInorder, rightChildrenPostorder, rightChildrenInorder.size());
            return root;

        }
    }
};

int main(){
    vector<int> inorder = {9,3,15,20,7}; 
    vector<int> postorder = {9,15,7,20,3};  
    Solution s;
    s.buildTree(inorder, postorder);
    
}