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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return {};
        }
        return isPath(root, targetSum, root -> val);
    }

    vector<vector<int>> isPath (TreeNode* root, int target, int currSum){
        vector<vector<int>> left, right;
        if(root -> left == nullptr && root -> right == nullptr){
            if(currSum == target){
                return {{root -> val}};
            }
            return {{}};
        }

        else if(root -> right == nullptr){
            left = isPath(root -> left, target, currSum + root -> left -> val);
            if(!left.empty()){
                for(vector<int> &elem : left){
                    elem.push_back(root -> val);
                }
            }
            return left;
        }
        else if(root -> left == nullptr){
            right = isPath(root -> right, target, currSum + root -> right -> val);
            if(!right.empty()){
                for(vector<int>& elem : right){
                    elem.push_back(root -> val);
                }
            }
            return right;
        }
        else{
            left = isPath(root -> left, target, currSum + root -> left -> val);
            right = isPath(root -> right, target, currSum + root -> right -> val);
            left.insert(left.end(), right.begin(), right.end());
            for(vector<int>& elem : left){
                elem.push_back(root -> val);
            }
            return left;
        }

    }
};

int main (){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);

    vector<vector<int>> result = s.pathSum(root, 5);
    cout << "Paths with sum 3: " << endl;
    for (const auto& path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
}