#include <vector>
#include <utility>
#include <climits>
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
    bool isValidBST(TreeNode* root){
        pair<bool, vector<int>> result = findValidBST(root);
        return result.first;
    }
    pair<bool, vector<int>> findValidBST(TreeNode* root) {
        pair<bool, vector<int>> result; //bool, min, max
        if(root -> left == nullptr && root -> right == nullptr){
            result = {true, {root -> val, root -> val}};
            return result;
        }
/*           120
         70           140
      50   100      130    160
    20 55 75 110  119 135 150 170
 */
        else if(root -> left == nullptr){
            if((root -> right -> val) > (root -> val)){
                pair<bool, vector<int>> rightChildNode;
                rightChildNode = findValidBST(root -> right);
                if(!rightChildNode.first){
                    return {false, {0, 0}};
                }
                if(root -> val >= rightChildNode.second[0]){
                    result = {false, {0, 0}};
                    return result;
                }
                result = {true, {root -> val, rightChildNode.second[1]}};
                return result;
            }
            else{
                result = {false, {0, 0}};
                return result;
            }
        }
/*           120
         70           140
      50   100      130    160
    20 55 75 110  119 135 150 170
 */
        else if (root -> right == nullptr){
            if ((root -> left -> val) < (root -> val)){
                pair<bool, vector<int>> leftChildNode;
                leftChildNode = findValidBST(root -> left);
                if(!leftChildNode.first){
                    return {false, {0, 0}};
                }
                if(root -> val < leftChildNode.second[1]){
                    result = {false, {0, 0}};
                    return result;
                }
                result = {true, {leftChildNode.second[0], root -> val}};
                return result;
            }
            else{
                result = {false, {0, 0}};
                return result;
            }
        }
        /*           120
         70           140
      50   100      130    160
    20 55 75 110  119 135 150 170
 */
        else{
            if((root -> val) <= (root -> left -> val)){
                return {false, {0, 0}};
            }

            if((root -> val) >= (root -> right -> val)){
                return {false, {0, 0}};
            }

            pair<bool, vector<int>> leftChildNode, rightChildNode;
            
            leftChildNode = findValidBST(root -> left);
            rightChildNode = findValidBST(root -> right);
            
            if(!leftChildNode.first || !rightChildNode.first){
                return {false, {0, 0}};
            }
            if(root -> val < leftChildNode.second[1]){
                return {false, {0, 0}};
            }
            if(root -> val > rightChildNode.second[0]){
                return {false, {0, 0}};
            }
            return {true, {leftChildNode.second[1], rightChildNode.second[0]}};

        }

    }
};     /*           120
         70           140
      50   100      130    160
    20 55 75 110  119 135 150 170
 */

int main(){
    Solution sol;
    TreeNode* root2 = new TreeNode(120);
    root2 -> left = new TreeNode(70);
    root2 -> right = new TreeNode(140);
    root2 -> left -> left = new TreeNode(50);
    root2 -> left -> right = new TreeNode(100);
    root2 -> right -> left = new TreeNode(130);
    root2 -> right -> right = new TreeNode(160);
    root2 -> left -> left -> left = new TreeNode(20);
    root2 -> left -> left -> right = new TreeNode(60);
    root2 -> left -> right -> left = new TreeNode(80);
    root2 -> left -> right -> right = new TreeNode(110);
    root2 -> right -> left -> left = new TreeNode(119);
    root2 -> right -> left -> right = new TreeNode(135);
    root2 -> right -> right -> left = new TreeNode(150);
    root2 -> right -> right -> right = new TreeNode(170);
    cout << sol.isValidBST(root2) << endl; // should return false

    return 0;
}   