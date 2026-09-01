
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
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
    vector<TreeNode*> generateTrees(int n) {
        vector<int> nums;
        for(int i = 1; i < n + 1; i++){
            nums.push_back(i);
        }
        return formTrees(nums);
       
    }

    vector<TreeNode*> formTrees (vector<int>& nums){
        int length = nums.size();
        TreeNode* temp;
    
        if(length == 0){
            return {nullptr};
        }
        else if(length == 1){
            temp = new TreeNode(nums[0]);
            return {temp};
        }

        vector<TreeNode*> result;
        vector<TreeNode*> largerResult;
        vector<TreeNode*> smallerResult;
        TreeNode* currNode;
        vector<int> remainder;
        int remainLen;
        vector<int> smaller;
        vector<int> larger;
        for(int i = 0; i < length; i++){
            remainder = nums;
            smaller.clear();
            larger.clear();
            remainder.erase(remainder.begin() + i);
            remainLen = remainder.size();
            for(int j = 0; j < remainLen; j++){
                if(remainder[j] > nums[i]){
                    larger.push_back(remainder[j]);
                }
                else{
                    smaller.push_back(remainder[j]);
                }
            }
            
            largerResult = formTrees(larger);
            smallerResult = formTrees(smaller);
            for(TreeNode* elem1 : largerResult){
                for(TreeNode* elem2 : smallerResult){
                    currNode = new TreeNode(nums[i]);
                    currNode -> left = elem2;
                    currNode -> right = elem1;
                    result.push_back(currNode);
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<TreeNode*> result = s.generateTrees(3);
    cout << "Number of unique BSTs: " << result.size() << endl;
    return 0;
}   
