#include <stdio.h>
#include <iostream>

using namespace std;
int fib (int n){
    if (n <= 2){
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result = {};
        int length = candidates.size();
        int temp_sum = 0;
        result = findSum(candidates, length, target, 0, 0);
        if (!result.empty()){
            for(auto& row : result){
            std::reverse(row.begin(), row.end());
            }
        }
        
        return result;

    }
    vector<vector<int>> findSum (vector<int> candidates, int length, int target, int index, int tempSum){
        int localSum;
        vector<vector<int>> result = {};
        vector<vector<int>> temp_result;
        for (int i = index; i < length; i++){
            
            localSum = tempSum;
            localSum += candidates[i];
            if (localSum == target){
                result.push_back({candidates[i]});
            }
            else if (localSum > target){
                continue;
            }
            else {
                temp_result = findSum(candidates, length, target, i, localSum);
                if (!temp_result.empty()){
                    for (auto& row: temp_result){
                        row.push_back(candidates[i]);
                    }
                    result.insert(result.end(), temp_result.begin(), temp_result.end());
                }
            }
        }
        return result;
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        int length1 = num1.size();
        int length2 = num2.size();
        vector<string> subProduct = {};
        string added0s = "";
        string sub = "";
        int index = 0;
        int num;
        int carryOver = 0;
        for (int i = length2 - 1; i >= 0; i--){
            sub = added0s;
            for (int j = length1 - 1; j >= 0; j--){
                num = (num1[j] - '0') * (num2[i] - '0') + carryOver;
                carryOver = num / 10;

                sub = std::to_string(num % 10) + sub;
            }
            if (carryOver != 0){
                sub = std::to_string(carryOver) + sub;
                carryOver = 0;
            }
            subProduct.push_back(sub);
            added0s = added0s + '0';
        }

        int length = subProduct.size();
        int num_digits = subProduct[length - 1].size();
        int varied_length;
        string leading_0s;
        for (int i = 0; i < length; i ++){
            varied_length = subProduct[i].size();
            leading_0s.assign(num_digits - varied_length, '0');
            subProduct[i] = leading_0s + subProduct[i];
        }
        
        int sum;
        int carryOver10 = 0;
        int carryOver100 = 0;
        int carryOver1000 = 0;
        string finalChar;
        string finalString = "";
        for (int i = num_digits; i >= 0; i--){
            sum = 0;
            for (int j = 0; j < length; j++){
                sum += (subProduct[j][i] - '0');
            }
            sum += carryOver10;
            if (carryOver100 != 0){
                carryOver10 = carryOver100;
                carryOver100 = 0;
            }
            if (carryOver1000 != 0){
                carryOver100 = carryOver1000;
                carryOver1000 = 0;
            }
            carryOver1000 = sum / 1000;
            carryOver100 += (sum % 1000) / 100;
            carryOver10 += (sum % 100) / 10;
            finalChar = std::to_string(sum % 10);
            finalString = finalChar + finalString;
        }
        if (carryOver10 != 0){
            finalString = std::to_string(carryOver10) + finalString;
        }
        if (carryOver100 != 0){
            finalString = std::to_string(carryOver100) + finalString;
        }
        if (carryOver1000 != 0){
            finalString = std::to_string(carryOver1000) + finalString;
        }

        return finalString;

    }
};
int main(){
    Solution s;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    cout << "Result: " << endl;
    for (auto& row : result){
        for (auto& col : row){
            cout << col << " ";
        }
        cout << endl;
    }
}