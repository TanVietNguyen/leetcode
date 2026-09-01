#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int length = nums.size();
        int start = 0;
        int end = length - 1;
        int index = findLastElementIndex (nums, 0, length - 1);
        int numRotations = index + 1;
        //if their indices <= (length - 1 - numRotations)
        //currIndex = (their indices + numRotations)
        //if their indices > (length - 1 - numRotations)
        //currIndex = (their indices + numRotations - (length - 1))
        return modifiedSearch(nums, numRotations, start, end, target, length);
    }
    int findLastElementIndex (vector<int>& nums, int start, int end){
        if(end - start == 1){
            if(nums[end] >= nums[start]){
                return end;
            }
            else{
                return start;
            }
        }
        //{2,5,6,0,0,1,2};
        int mid = (start + end) / 2;
        if(nums[mid] > nums[end]){
            start = mid;
        }
        else if(nums[mid] < nums[end]){
            end = mid;
        }
        return findLastElementIndex (nums, start, end);
    }

    bool modifiedSearch (vector<int>& nums, int numRotations, int start, int end, int target, int length){
        int mid = (start + end) / 2;
        int currMid = convertToCurrIndex(mid, numRotations, length);

        if(nums[currMid] > target){
            end = mid - 1;
        }
        else if(nums[currMid] < target){
            start = mid + 1;
        }
        else{
            return true;
        }
        return modifiedSearch(nums, numRotations, start, end, target, length);
    }

    int convertToCurrIndex(int index, int numRotations, int length){
        if(index <= (length - 1 - numRotations)){
            return (index + numRotations);
        }
         //{2,5,6,0,0,1,2};
        else{
            return (index + numRotations - length);
        }
    }
};

int main (){
    Solution s;
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 3;
    cout << s.search(nums, target) << endl;
}   