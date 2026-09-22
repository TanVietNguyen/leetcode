#include <vector>
#include <iostream>

using namespace std;    

class solution {
    public:
    int sortedSum(vector<int> &nums){
        int length = nums.size();
        vector<long int> sum(length, 0);
        bool isInserted = false;      
        vector<int> sortedNums; 
        for(int i = 0; i < length; i++){
            if(i == 0){
                sortedNums.push_back(nums[i]);
                sum[i] = nums[i];
                continue;
            }
            for(int j = 0; j < i; j++){
                if(nums[i] < sortedNums[j]){
                    sortedNums.insert(sortedNums.begin() + j, nums[i]);
                    if(j == 0){
                        sum[j] = nums[i];
                    } else {
                        sum[j] = sum[j - 1] + nums[i]*(j + 1);
                    }
                    for(int k = j + 1; k < i; k++){
                        sum[k] = sum[k - 1] + sortedNums[k]*(k + 1);
                    }
                    isInserted = true;
                    break;
                }
            }
            if(isInserted == false){
                sortedNums.push_back(nums[i]);
                sum[i] = sum[i - 1] + nums[i]*(i + 1);
            }
            isInserted = false;
        }
        sum[length - 1] = sum[length - 1] % (int)(1e9 + 7);
        return sum[length - 1];
    }
};

int main(){
    solution sol;
    vector<int> nums = {1, 2, 3};
    int result = sol.sortedSum(nums);
    cout << "Sorted sum: " << result << endl;
    return 0;   
}