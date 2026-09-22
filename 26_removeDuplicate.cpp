#include <vector>
#include <iostream> 

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        for (int i = 1; i < length; i++){
            if(nums[i - 1] == nums[i]){
                nums.erase(nums.begin() + i - 1);
                length --;
            }
        }
        return length;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int newLength = solution.removeDuplicates(nums);
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}