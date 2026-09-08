#include <vector>
#include <iostream> 

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();

        vector<vector<pair<int, int>>> result(length, vector<pair<int, int>>(length, {INT_MIN, INT_MIN}));
        // first element is the max, second element is the product of a subarray
        pair<int, int> temp1 = findMax(nums, result, 0, length - 1);
        pair<int, int> temp2 = findMaxInverse(nums, result, 0, length - 1);

        return max(temp1.first, temp2.first);
    }

    pair<int, int> findMax (vector<int>& nums, vector<vector<pair<int, int>>>& result, int start, int end){
        if(result[start][end] != pair<int, int>(INT_MIN, INT_MIN)){
            return result[start][end];
        }
        if(start == end){
            result[start][end] = {nums[start], nums[start]};
            return result[start][end];
        }
        pair<int, int> returnedVal;
        
        int temp = nums[start];
        returnedVal = findMax(nums, result, start + 1, end);
        int arrayProduct = temp * returnedVal.second;
        result[start][end] = {max({temp, arrayProduct, returnedVal.first}), arrayProduct};

        return result[start][end];
    }
    pair<int, int> findMaxInverse(vector<int>& nums, vector<vector<pair<int, int>>>& result, int start, int end){
        if(result[start][end] != pair<int, int>(INT_MIN, INT_MIN)){
            return result[start][end];
        }

        if(start == end){
            result[start][end] = {nums[start], nums[start]};
        }

        int temp = nums[end];
        pair<int, int> returnedVal = findMaxInverse(nums, result, start, end - 1);
        int arrayProduct = temp * returnedVal.second;
        result[start][end] = {max({temp, returnedVal.first, arrayProduct}), arrayProduct};
        return result[start][end];

    }
};

int main(){
    Solution solution;
    vector<int> nums = {2, 3, -2, 4};
    int result = solution.maxProduct(nums);
    cout << result << endl;

    return 0;   
}