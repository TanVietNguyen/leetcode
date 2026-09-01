#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <int> resulting_indices;
        vector <int> current_element;
        vector <int> temp_resulting_indices;
        vector <vector<int>> resulting_indices_vector; 
        int sum_3;
        int m, n;
        bool duplicate_found = false;
        sort(nums.begin(), nums.end());
        cout << "Sorted nums: ";
        for (int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
        for (int i = 1; i < nums.size() - 1; i++){
            m = 0;
            n = nums.size() - 1;
            while (true){
                if ( n == i || m == i){
                    break;
                }
                sum_3 = nums[i] + nums[m] + nums[n];
                cout << "i: " << i << " m: " << m << " n: " << n << " sum_3: " << sum_3 << endl;
                if (sum_3 > 0){
                    n--;
                }
                else if(sum_3 < 0){
                    m++;
                }
                else{
                    resulting_indices.push_back(nums[m]);
                    resulting_indices.push_back(nums[i]);
                    resulting_indices.push_back(nums[n]);
                    cout << "nums[i]: " << nums[i] << " nums[m]: " << nums[m] << " nums[n]: " << nums[n] << endl;

                    for (int i = 0; i < resulting_indices_vector.size(); i++){
                        if (resulting_indices_vector[i] == resulting_indices){
                            duplicate_found = true;
                            resulting_indices.clear();
                            break;
                        }
                    }
                    if (duplicate_found){
                        duplicate_found = false;
                        continue;
                    }
                    resulting_indices_vector.push_back(resulting_indices);
                    resulting_indices.clear();
                    continue;
                }

            }
           

            
        }
        return resulting_indices_vector;
    }
};

int main(){
    vector<int> vect = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    Solution sol;
    vector<vector<int>> result = sol.threeSum(vect);
    for (const auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

