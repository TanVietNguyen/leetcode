#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:

    int jump(vector<int>& nums) {
        int length = nums.size();
        vector<int>value(length, -1);
        return nextJump(nums, 0, length, value);
    }
    int nextJump (vector<int> nums, int index, int length, vector<int>& value){
        if(value[index] != -1){
            return value[index]; 
        }
        value[index] = length;
        if (index == (length - 1)){
            value[index] = 0;
            return 0;
        }
        else if ((index + nums[index]) >= (length - 1)){
            value[index] = 1;
            return 1;
        }
        int biggestStep = nums[index]; // 10,9,8,7,6,5,4,3,2,1,1,0
        int nextIndex = index;
        for (int i = 1; i <= nums[index]; i++){
            if ((nums[i+index] + i) > biggestStep){
                biggestStep = nums[i+index] + i;
                nextIndex = i + index;
            }
        }
        if (nextIndex == index){
            for (int i = 1; i <= nums[index]; i++){
                value[index] = min(value[index], 1 + nextJump(nums, i + index, length, value));
            }
        }
        else{
            value[index] = 1 + nextJump(nums, nextIndex, length, value);
        }
        return value[index];
    }
};

int main(){
    Solution solution;
    vector<int> nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    int result = solution.jump(nums);
    cout << "Minimum number of jumps: " << result << endl;
    return 0;
}