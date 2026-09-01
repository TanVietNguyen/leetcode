#include <stack>
#include <unordered_map>    
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
    int sumNumbers(TreeNode* root) {
        stack<TreeNode*> myStack;
        unordered_map<TreeNode*, int> nodeLevel;
        string temp = "";
        int sum = 0;
        int level = 0;
        TreeNode* currNode;
        myStack.push(root);
        nodeLevel[root] = 0;
        
        while(!myStack.empty()){

            currNode = myStack.top();
            myStack.pop();
            if(nodeLevel[currNode] != temp.size()){
                temp = temp.substr(0, nodeLevel[currNode]);
                
            }
            temp.push_back('0' + currNode -> val);

            if(currNode -> left == nullptr && currNode -> right == nullptr){
                sum += stoi(temp);

            }
            if(currNode -> left != nullptr){
                myStack.push(currNode -> left);
                nodeLevel[currNode -> left] =  nodeLevel[root] + 1;
            }
            if(currNode -> right != nullptr){
                myStack.push(currNode-> right);
                nodeLevel[currNode -> right] = nodeLevel[root] + 1;
            }
        }
        return sum;
        
    }
};

int main(){
    
        Solution s;
        TreeNode* root = new TreeNode(4);
        root -> left = new TreeNode(9);
        root -> right = new TreeNode(0);
        root -> left -> left = new TreeNode(5);
        root -> left -> right = new TreeNode(1);
        int result = s.sumNumbers(root);
        cout << result << endl;
        return 0;
}