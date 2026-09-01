#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;    

class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if (length == 1){
            return;
        }
        vector<int> temp;
        bool isSorted;
        int tempLength;
        int tempVal;
        int i;
        for(i = length - 2; i >= 0; i --){
            temp.assign(nums.begin() + i, nums.end());
            isSorted = is_sorted(temp.begin(), temp.end(), greater<int>());
            if(isSorted){
                if(i == 0){
                    sort(nums.begin(), nums.end());
                    return;
                }
                continue;
            }
//1, 3, 2
            tempLength = temp.size();
            int j;
            for(j = tempLength - 1; j > 0; j--){
                if (temp[j] > temp[0]){
                    break;
                }
            }

            tempVal = temp[j];
            temp.erase(temp.begin() + j);
            sort(temp.begin(), temp.end());
            nums.insert(nums.begin() + i, tempVal);
            nums.insert(nums.begin() + i + 1,temp.begin(), temp.end());
            nums.erase(nums.begin() + length, nums.begin() + length + tempLength);
            break;
        }
        // vector<vector<int>> result;
        // vector<int> sortedNums = nums;
        // sort(sortedNums.begin(), sortedNums.end());
        // result = permutation(sortedNums);
        // int length = result.size();
        // int i;
        // for(i = 0; i < length; i++){
        //     if(result[i] == nums){
        //         break;
        //     }
        // }
        // if (i == (length - 1)){
        //     nums = result[0];
        // }
        // else{
        //     nums = result[i + 1];
        // }
    }

    vector<vector<int>> permutation (vector<int>& nums){
        if(nums.size() == 1){
            return {nums};
        }
        vector<int> tempVect;
        vector<vector<int>> result;
        vector<vector<int>> temp;
        int index = 0;
        for(int element : nums){
            tempVect = nums;
            tempVect.erase(tempVect.begin() + index);
            temp = permutation(tempVect);
            for(vector<int> vecElem : temp){
                vecElem.insert(vecElem.begin(), element);
                result.push_back(vecElem);
            }
            index ++;
        }

        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1, 3, 2};
    solution.nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}