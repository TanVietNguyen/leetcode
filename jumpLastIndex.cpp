#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        return nextJump(nums, 0, length);
    }
    bool nextJump (vector<int>& nums, int index, int length){
        if ((nums[index] + index) >= (length - 1)){
            return true;
        }

        bool reachLastIndex = false;//1,1,1,0
        int maxJump = nums[index];
        int nextIndex = index;

        for (int i = 1; i <= nums[index]; i++){
            if ((maxJump + nextIndex) < (nums[i + index] + i + index)){
                maxJump = nums[index + i];
                nextIndex = index + i;
            }
        }
        if(nextIndex == index && maxJump == nums[index]){
            return false;
        }
        reachLastIndex = nextJump(nums, nextIndex, length);
        if(reachLastIndex){
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,0};  
    s.canJump(nums) ? cout << "true" : cout << "false";

}