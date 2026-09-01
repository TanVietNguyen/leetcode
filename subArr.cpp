#include <vector>
#include <iostream>
#include <ranges>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> matrix (length, vector<int>(length, INT_MIN));
        for (int i = 0; i < length; i++){
            sumArr(nums, i, length - 1, matrix);
        }
        int maxVal = INT_MIN;
        int temp_max;
        for (int i = 0; i < length; i++){
            for (int j = i; j < length; j++){ 
                temp_max = matrix[i][j];
                if (temp_max > maxVal){
                    maxVal = temp_max;
                }
            }
        }
        
        return maxVal;
    }
    void sumArr (vector<int> nums, int start, int end, vector<vector<int>>& sumTable){
        for(int i = start; i <= end; i++){
            if (sumTable[start][i] != INT_MIN){
                continue;
            }    //-2,1,-3,4,-1,2,1,-5,4
            if(i == start){
                sumTable[start][i] = nums[start];
                continue;
            }
            else{
                sumTable[start][i] = nums[i] + sumTable[start][i - 1];
                continue;
            }
           
        }
        return;
    }
    int maxSum (vector<int> nums, int start, int end){
        if(start == end){
            return nums[start];
        }
        int max = nums[start];
        int temp_max;
        for (int i = start + 1; i <= end; i++){
            temp_max = nums[start] + maxSum(nums, start + 1, i);
            if (temp_max > max){
                max = temp_max;
            }
        }
        return max;
    }
};  

int main() {
    Solution solution;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = solution.maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl; // Output: 6
    return 0;
}