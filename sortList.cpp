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
    ListNode* sortList(ListNode* head) {
        vector<int> vals;
        if(head == nullptr){
            return head;
        }
        ListNode* currNode = head;
        while(currNode != nullptr){
            vals.push_back(currNode -> val);
            currNode = currNode -> next;
        }

        vector<int> result = mergeSort(vals, 0, vals.size() - 1);
        currNode = head;
        int currIndex = 0;
        while(currNode != nullptr){
            currNode -> val = result[currIndex];
            currIndex ++;
            currNode = currNode -> next;
        }

        return head;

    }


    vector<int> mergeSort(vector<int> nums, int start, int end){
        if(start == end){
            return {nums[start]};
        }
        vector<int> left, right, whole;
        int leftIndex = 0;
        int rightIndex = 0;
        int mid = (start + end) / 2;
        left = mergeSort(nums, start, mid);
        int leftLen = mid - start + 1;
        right = mergeSort(nums, mid + 1, end);
        int rightLen = end - mid;

        while(leftIndex != leftLen || rightLen != rightLen){
            if(leftIndex == leftLen){
                whole.push_back(right[rightIndex]);
                rightIndex ++;
            }
            else if(rightIndex == rightLen){
                whole.push_back(left[leftIndex]);
                leftIndex ++;
            }
            else{
                if(left[leftIndex] > right[rightIndex]){
                    whole.push_back(right[rightIndex]);
                    rightIndex ++;
                }
                else{
                    whole.push_back(left[leftIndex]);
                    leftIndex ++;
                }
            }
        }

        return whole;
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
}