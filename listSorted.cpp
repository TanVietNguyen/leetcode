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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = head;
        ListNode* currNode = newHead;
        ListNode* prevNode;
        ListNode* tempNode;
        head = head -> next;
        newHead -> next = nullptr;
        bool isAdded = false;
// [-1,5,3,4,0]
        while(head != nullptr){
            tempNode = head;
            head = head -> next;
            tempNode -> next = nullptr;

            currNode = newHead;
            if(currNode -> val >= tempNode -> val){
                tempNode -> next = currNode;
                newHead = tempNode;
                continue;
            }
            prevNode = currNode;
            currNode = currNode -> next;
            while(currNode != nullptr){
                if(tempNode -> val <= currNode -> val){
                    prevNode -> next = tempNode;
                    tempNode -> next = currNode;
                    isAdded = true;
                }
                prevNode = currNode;
                currNode = currNode -> next;
            }

            if(!isAdded){
                prevNode -> next = tempNode;
            }
            isAdded = false;

        }

        return newHead;
    }
};

int main(){
    Solution s;
    // [-1,5,3,4,0]
    ListNode* head = new ListNode(-1);
    head -> next = new ListNode(5);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(0);

    ListNode* sortedList = s.insertionSortList(head);

    while(sortedList != nullptr){
        cout << sortedList -> val << " ";
        sortedList = sortedList -> next;
    }
}