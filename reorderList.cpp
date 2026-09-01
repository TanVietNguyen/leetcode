
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
    void reorderList(ListNode* head) {
        ListNode* currNode;
        ListNode* currHead = head;
        ListNode* tempNode = head;
        ListNode* prevNode;
        ListNode* newCurrNode;
        bool isFirst = true;
        bool isEven = false;

        while(tempNode->next != nullptr){
            currNode = tempNode;
            while(currNode->next != nullptr){
                prevNode = currNode;
                currNode = currNode -> next;
            }
            if(tempNode == prevNode){
                isEven = true;
                break;
            }
            else{
                prevNode -> next = nullptr;
            }

            if(isFirst){
                tempNode = tempNode -> next;
                currHead -> next = currNode;
                currHead = currHead -> next;
                isFirst = false;
            }
            else{
                currHead -> next = tempNode;
                tempNode = tempNode -> next;
                currHead = currHead -> next;
                currHead -> next = currNode;
                currHead = currHead -> next;
                
            }
            isEven = false;
        }
        if(isEven){
                currHead -> next = tempNode;
                tempNode = tempNode -> next;
                currHead = currHead -> next;
                currHead -> next = currNode;
        }
        else{
            currHead -> next = tempNode;
        }
                
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);

    s.reorderList(head);

    ListNode* currNode = head;
    while(currNode != nullptr){
        cout << currNode -> val << " ";
        currNode = currNode -> next;
    }
}