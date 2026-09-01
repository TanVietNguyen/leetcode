#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int length = nums.size();
        return recursive(nums, length);
    }
    vector<vector<int>> recursive(vector<int> nums, int length){
        vector<vector<int>> result = {};
        vector<vector<int>> tempResult;
        if (length == 1){
            return {nums};
        }
        vector<int> tempVect;
        int tempVal;
        for(int i = 0; i < length; i++){
            tempVect = nums;
            tempVal = tempVect[i];
            tempVect[i] = tempVect[length - 1];
            tempVect.pop_back();
            tempResult = recursive(tempVect, length - 1);
            for(auto& row:tempResult){
                row.push_back(tempVal);
            }
            result.insert(result.end(), tempResult.begin(), tempResult.end());
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.permute(nums);
    cout << "Permutations: " << endl;
    for (const auto& perm : result) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i < perm.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}