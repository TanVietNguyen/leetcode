#include <vector>
#include <queue>
#include <unordered_map>    
#include <string>
#include <iostream> 

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return nullptr;
        }
        queue<Node*> nodeQueue;
        Node* currNode;
        Node* prevNode;
        bool transferringLevel = false;
        int level = 0;
        unordered_map<int, int> levelTable;
        nodeQueue.push(root);
        levelTable[0] = 1;

        while(!nodeQueue.empty()){
            currNode = nodeQueue.front();
            nodeQueue.pop();
            levelTable[level] --;

            if(currNode -> left != nullptr){
                nodeQueue.push(currNode -> left);
                levelTable[level + 1] ++;
            }

            if(currNode -> right != nullptr){
                nodeQueue.push(currNode -> right);
                levelTable[level + 1] ++;
            }

            if(transferringLevel){
                transferringLevel = false;
            }
            else{
                prevNode -> next = currNode;
            }

            if(levelTable[level] == 0){
                level ++;
                transferringLevel = true;
            }
            
            prevNode = currNode;
        }

        return root;
    }
};

int main (){
    Solution s;
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> right = new Node(7);

    Node* result = s.connect(root);

    cout << "Node 2 next: " << (result->left->next ? result->left->next->val : -1) << endl; // Should print 3
    cout << "Node 4 next: " << (result->left->left->next ? result->left->left->next->val : -1) << endl; // Should print 5
    cout << "Node 5 next: " << (result->left->right->next ? result->left->right->next->val : -1) << endl; // Should print 7
    cout << "Node 7 next: " << (result->right->right->next ? result->right->right->next->val : -1) << endl; // Should print -1

    return 0;
}