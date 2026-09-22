#include <vector>
#include <iostream> 
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        // first element is the max, second element is the product of a subarray
        pair<int, int> temp = findMax(nums, 0, length - 1);
        return temp.first;
    }

    pair<int, int> findMax (vector<int>& nums, int start, int end){
        int arrayProduct;
        if(start == end){
            return {nums[start], nums[start]};
        }
        else if(start == (end - 1)){
            arrayProduct = nums[start] * nums[end];
            return {max({nums[start], nums[end], arrayProduct}), arrayProduct};
        }
        else if(end - start == 3){
            pair<int, int> left, right;
            right = findMax(nums, start + 1, end);
            left = findMax(nums, start, end - 1);
            arrayProduct = left.second * nums[end];

            return {max({left.first, right.first, arrayProduct}), arrayProduct};

        }
        int startVal = nums[start];
        int endVal = nums[end];
        int maxVal = max(startVal, endVal);
        pair<int, int> value = findMax(nums, start + 1, end - 1);
        arrayProduct = startVal * value.second * endVal ;
        return {max({maxVal, value.first,  startVal * value.second, endVal * value.second, arrayProduct}), arrayProduct};
    }
    
    // int maxProduct(vector<int>& nums) {
    //     int length = nums.size();

    //     vector<vector<pair<int, int>>> result(length, vector<pair<int, int>>(length, {INT_MIN, INT_MIN}));
    //     // first element is the max, second element is the product of a subarray
    //     pair<int, int> temp1 = findMax(nums, result, 0, length - 1);
    //     pair<int, int> temp2 = findMaxInverse(nums, result, 0, length - 1);

    //     return max(temp1.first, temp2.first);
    // }

    // pair<int, int> findMax (vector<int>& nums, vector<vector<pair<int, int>>>& result, int start, int end){
    //     if(result[start][end] != pair<int, int>(INT_MIN, INT_MIN)){
    //         return result[start][end];
    //     }
    //     if(start == end){
    //         result[start][end] = {nums[start], nums[start]};
    //         return result[start][end];
    //     }
    //     pair<int, int> returnedVal;
        
    //     int temp = nums[start];
    //     returnedVal = findMax(nums, result, start + 1, end);
    //     int arrayProduct = temp * returnedVal.second;
    //     result[start][end] = {max({temp, arrayProduct, returnedVal.first}), arrayProduct};

    //     return result[start][end];
    // }
    // pair<int, int> findMaxInverse(vector<int>& nums, vector<vector<pair<int, int>>>& result, int start, int end){
    //     if(result[start][end] != pair<int, int>(INT_MIN, INT_MIN)){
    //         return result[start][end];
    //     }

    //     if(start == end){
    //         result[start][end] = {nums[start], nums[start]};
    //     }

    //     int temp = nums[end];
    //     pair<int, int> returnedVal = findMaxInverse(nums, result, start, end - 1);
    //     int arrayProduct = temp * returnedVal.second;
    //     result[start][end] = {max({temp, returnedVal.first, arrayProduct}), arrayProduct};
    //     return result[start][end];

    // }
};

int main(){
    Solution solution;
    vector<int> nums = { -3, -1, -1 };
    int result = solution.maxProduct(nums);
    cout << result << endl;

    return 0;   
}