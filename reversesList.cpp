#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int currPos = 1;
        ListNode* currNode = head;
        ListNode* beforeLeftNode;
        ListNode* afterLeftNode;
        ListNode* beforeRightNode;
        ListNode* afterRightNode;

        if(left == 1){
            beforeLeftNode = currNode;
        }
        while(currNode != nullptr){
            if(currPos == (left - 1)){
                beforeLeftNode = currNode;
                // beforeLeftNode->next = nullptr;
            }
            else if(currPos == left){
                afterLeftNode = currNode;
            }
            else if(currPos == right){
                beforeRightNode = currNode;
            }
            else if(currPos == (right + 1)){
                afterRightNode = currNode;
                break;
                
            }
            currNode = currNode -> next;
            currPos ++;
        }

        if(currPos == 1){
            return head;
        }

        currNode = afterLeftNode;
        ListNode* nextNode = currNode->next;
        ListNode* temp1 = currNode;
        ListNode* temp2 = nextNode;
    
        if(currPos == (right + 1)){
            temp1 -> next = nullptr;
        }
        else {
            temp1 -> next = afterRightNode;
        }

        while(nextNode != afterRightNode && nextNode != nullptr){
            currNode = nextNode;
            nextNode = nextNode->next;
            temp2->next = temp1;
            temp1 = currNode;
            temp2 = nextNode;
        }

        if(left == 1){
            return currNode;
        }
        else{
            beforeLeftNode -> next = currNode;
        }

        return head;
    }
};

int main(){
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2;
    int right = 4;

    ListNode* result = solution.reverseBetween(head, left, right);

    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
}