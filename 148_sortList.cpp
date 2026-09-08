
#include <iostream>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
//To solve this problem, we can take the inpiration from merge sort algorithm.
//There is one advantage of linklist data structure, we don't need to create new array to store the sorted elements,
// we can just change the pointer of the nodes to sort the list, so the space complexity will be O(1).
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
       ListNode* currNode = head;

       int length = 0;
       int mid = 0;
       while(currNode != nullptr){
            length ++;
            currNode = currNode -> next;
       }

       if(length == 1){
        return head;
       }
       mid = length / 2;
       ListNode* left = head;
       ListNode* right = head;
        int index = 1;
        while(index != mid){
            right = right -> next;
            index ++;
        }
        //this is the mid node, where the current list is plit into two parts
        currNode = right;
        right = right -> next;  
        currNode -> next = nullptr; 

        // 4 2 1 3
        left = sortList(left);
        right = sortList(right);
        if(left -> val > right -> val){
            head = right;
            right = right -> next;
        }
        else{
            head = left;
            left = left -> next;
        }

        currNode = head;

        while(left != nullptr || right != nullptr){
            if(left == nullptr){
                currNode -> next = right;
                currNode = currNode -> next;
                right = right -> next;
            }
            else if(right == nullptr){
                currNode -> next = left;
                currNode = currNode -> next;
                left = left -> next;
            }
            else{
                if(left -> val > right -> val){
                    currNode -> next = right;
                    currNode = currNode -> next;
                    right = right -> next;
                }
                else{
                    currNode -> next = left;
                    currNode = currNode -> next;
                    left = left -> next;
                }
            
            }
        }

        return head;

    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(4);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(1);
    head -> next -> next -> next = new ListNode(3);

    ListNode* result = s.sortList(head);
    while(result != nullptr){
        cout << result -> val << " ";
        result = result -> next;
    }

    return 0;   
}