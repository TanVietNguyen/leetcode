#include <string>
#include <vector>
#include <iostream> 

using namespace std;    

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int length = nums.size();
        vector<string> stringList;
        bool isZero = true;
        for(int i = 0; i < length; i++){
            if(nums[i] != 0){
                isZero = false;
            }
            stringList.push_back(to_string(nums[i]));
        }

        if(isZero){
            return "0";
        }
        vector<string> result = sortStrings(stringList, 0, length - 1);
        string finalResult = "";

        for(int i = length - 1; i >= 0; i--){
            finalResult += result[i];
        }

        return finalResult;

    }

    vector<string> sortStrings(vector<string> & stringList, int start, int end){
        if(start == end){
            return {stringList[start]};
        }

        vector<string> left, right;
        int mid = (start + end) / 2;
        
        left = sortStrings(stringList, start, mid);
        right = sortStrings(stringList, mid + 1, end);

        int leftIndex = 0;
        int rightIndex = 0;
        int length1 = mid - start + 1;
        int length2 = end - mid;
        vector<string> result;

        while(leftIndex != length1 || rightIndex != length2){
            if(leftIndex == length1){
                result.push_back(right[rightIndex]);
                rightIndex ++;
            }
            else if(rightIndex == length2){
                result.push_back(left[leftIndex]);
                leftIndex ++;
            }
            else{
                if(isFirstSmaller(left[leftIndex], right[rightIndex])){
                    result.push_back(left[leftIndex]);
                    leftIndex ++;
                }
                else{
                    result.push_back(right[rightIndex]);
                    rightIndex ++;
                }
            }
        }
        return result;
    }

    bool isFirstSmaller (string s1, string s2){
        int length1 = s1.size();
        int length2 = s2.size();
        int index1 = 0;
        int index2 = 0;
        int backupIndex1 = 0;
        int backupIndex2 = 0;
        while(backupIndex1 != length2 || backupIndex2 != length1){
            
            if(index1 == length1 && index2 == length2){
                if(s2[backupIndex1] == s1[backupIndex2]){
                    backupIndex1 ++;
                    backupIndex2 ++;
                    continue;
                }
                else{
                    return (s2[backupIndex1] < s1[backupIndex2]);
                }
            }
            else if(index1 == length1){
                if(s2[backupIndex1] == s2[index2]){
                    backupIndex1 ++;
                    index2 ++;
                    continue;
                }
                else{
                    return (s2[backupIndex1] < s2[index2]);
                }
            }
            else if(index2 == length2){
                if(s1[index1] == s1[backupIndex2]){
                    backupIndex2 ++;
                    index1 ++;
                    continue;
                }
                else{
                    return (s1[index1] < s1[backupIndex2]);
                }
            }
            else{
                if(s1[index1] == s2[index2]){
                    index1 ++;
                    index2 ++;
                    continue;
                }
                else{
                    return (s1[index1] < s2[index2]);
                }
            }
        }
        return true;
    }
    
};

int main(){
    Solution sol;
    vector<int> nums = {3, 30, 34, 5, 9};
    string result = sol.largestNumber(nums);
    cout << "Largest number: " << result << endl;
    return 0;   
}