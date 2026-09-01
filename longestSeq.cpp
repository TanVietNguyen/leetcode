#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;    

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        int theLongest = 0;
        int currLongest = 0;
        bool isFirst = true;
        for(int i = 1; i < length; i++){
            if(nums[i] == (nums[i - 1] + 1)){
                if(isFirst){
                    currLongest = 2;
                    isFirst = false;
                }
                else{
                    currLongest ++;
                }
                
            }
            else if(nums[i] == nums[i - 1]){
                continue;
            }
            else{
                if(currLongest > theLongest){
                    theLongest = currLongest;   
                }
                currLongest = 0;
                isFirst = true;
            }
        }
        if(currLongest > theLongest){
            theLongest = currLongest;   
        }
        return theLongest;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    int result = s.longestConsecutive(nums);
    cout << result << endl;
    return 0;
}   