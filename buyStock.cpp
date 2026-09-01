#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int length = prices.size();
    //     int start = length - 1;
    //     for(int i = 1; i < length; i++){
    //         if(prices[i] > prices[i - 1]){
    //             start = i - 1;
    //             break;
    //         }
    //     }
       
    //     vector<vector<int>> result(length - start + 1, vector<int>(length - start + 1, -1));
    //     return maxInvest(prices, result, start, length - 1, start);
    // }
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int start = length - 1;
        bool isDecreased;
        vector<int> startIndices;
        vector<int> endIndices;
        if(length == 1){
            return 0;
        }
        //7,1,5,3,6,4
        else if(length == 2){
            if(prices[1] > prices[0]){
                return (prices[1] - prices[0]);
            }
            else{
                return 0;
            }
        }
        else if(length >= 3){
           if(prices[1] > prices[0]){
            startIndices.push_back(0);
            isDecreased = false;
           } 
           else{
            isDecreased = true;
           }
           //7,1,5,3,6,4
            for(int i = 2; i < length; i++){
                if(prices[i] > prices[i - 1] && isDecreased == true){
                    startIndices.push_back(i - 1);
                    isDecreased = false;
                }
                else if(prices[i] <= prices[i - 1] && isDecreased == false){
                    endIndices.push_back(i - 1);
                    isDecreased = true;
                }
            }
            int resultLength = endIndices.size();
            int currPro = 0;
            for(int i = 0; i < resultLength; i++){
                currPro += (prices[endIndices[i]] - prices[startIndices[i]]);
            }
            return currPro;
        }
     
        // vector<vector<int>> result(length - start + 1, vector<int>(length - start + 1, -1));
        // return maxInvest(prices, result, start, length - 1, start);
    }

    int maxInvest (vector<int>& prices, vector<vector<int>>& result, int start, int end, int offset){
        int temp;
        if(result[start - offset][end - offset] != -1){
            return result[start - offset][end - offset];
        }
       
        else if(end == start){
            result[start - offset][end - offset] = 0;
            return 0;
        }
        else if(end - start == 1){
            temp = prices[end] - prices[start];
            if(temp > 0){
                result[start - offset][end - offset] = temp;
                return temp;
            }
            result[start - offset][end - offset] = 0;
            return 0;
        }
        else if(end - start == 2){
            temp = max({prices[start + 1] - prices[start], prices[end] - prices[start + 1], prices[end] - prices[start]});
            if(temp > 0){
                result[start - offset][end - offset] = temp;
                return temp;
            }
            result[start - offset][end - offset] = 0;
            return 0;
        }
        int maxNum = prices[end] - prices[start];
        int maxNum1, maxNum2, tempMax;
        if(checkSorted(prices, start, end)){
            result[start - offset][end - offset] = 0;
            return 0;
        }
        for(int i = start; i < end; i++){
            if(i != start && prices[i] <= prices[i - 1]){
                continue;
            }
            maxNum1 = maxInvest(prices, result, start, i, offset);
            result[start - offset][i - offset] = maxNum1;
            maxNum2 = maxInvest(prices, result, i + 1, end, offset);
            result[i + 1 - offset][end - offset] = maxNum2;
            tempMax = maxNum1 + maxNum2;
            if(tempMax > maxNum){
                maxNum = tempMax;
            }
        }
        return maxNum;
    }

    bool checkSorted (vector<int>& nums, int start, int end){
        for(int i = start + 1; i < end; i++){
            if(nums[i] > nums[i - 1]){
                return false;
            }
        }
        return true;
    }
};

int main (){
    Solution s;
    vector<int> prices = {7,6,4,3,1};
    int result = s.maxProfit(prices);
    cout << result << endl;
    return 0;
}