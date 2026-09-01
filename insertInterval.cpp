#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int length = intervals.size();
        if(length == 0){
            return {newInterval};
        }
        int index1 = findIndex(intervals, newInterval[0], 0, length - 1);
        int index2 = findIndex(intervals, newInterval[1], 0, length - 1);
        vector<vector<int>> result;
        if(index1 == -1){
            if (index2 == -1){
                result.push_back(newInterval);
                result.insert(result.end(), intervals.begin(), intervals.end());
            }
            else if(newInterval[1] <= intervals[index2][1]){
                newInterval = {newInterval[0], intervals[index2][1]};
                result.push_back(newInterval);
                if(length > (index2 + 1)){
                    result.insert(result.end(), intervals.begin() + index2 + 1, intervals.end());
                }
                
            }
            else{
                result.push_back(newInterval);
                if(length > (index2 + 1)){
                    result.insert(result.end(), intervals.begin() + index2 + 1, intervals.end());
                }
            }
        }
        else{
        
            if(index1 == 0){
                if(newInterval[0] <= intervals[index1][1]){
                    if(newInterval[1] <= intervals[index2][1]){
                        newInterval = {intervals[index1][0], intervals[index2][1]};
                    }
                    else{
                        newInterval = {intervals[index1][0], newInterval[1]};
                    }
                }
                else{
                    result.push_back(intervals[0]);
                    if(newInterval[1] <= intervals[index2][1]){
                        newInterval = {newInterval[0], intervals[index2][1]};
                    }
                    else{
                        //Do nothing. Keep newInterval the same.
                    }
                }
              
                result.push_back(newInterval);
                if(length > (index2 + 1)){
                    result.insert(result.end(), intervals.begin() + index2 + 1, intervals.end());
                }
                
            }
            else{
                result.push_back(intervals[0]);
                if(index1 > 2){
                    result.insert(result.end(), intervals.begin() + 1, intervals.begin() + index1 - 1 );
                }
//{{0,1},{5,5},{6,7},{9,11}};
                if(newInterval[0] <= intervals[index1][1]){
                    if(newInterval[1] <= intervals[index2][1]){
                        newInterval = {intervals[index1][0], intervals[index2][1]};
                    }
                    else {
                        newInterval = {intervals[index1][0], newInterval[1]};
                    }
                }
                else{
                    result.push_back(intervals[index1]);
                    if(newInterval[1] < intervals[index2][1]){
                        newInterval = {newInterval[0], intervals[index2][1]};
                    }
                    else{
                        //Do nothing.
                    }
                }
                result.push_back(newInterval);
                if(length > (index2 + 1)){
                    result.insert(result.end(), intervals.begin() + index2 + 1, intervals.end());
                }
            }
        }
        return result;

    }

    int findIndex (vector<vector<int>> & intervals, int target, int start, int end){
        if(start > end){
            return end;
        }
        int mid = (start + end) / 2;
        if(target > intervals[mid][0]){
            return findIndex(intervals, target, mid + 1, end);
        }
        else if(target  < intervals[mid][0]){
            return findIndex(intervals, target, start, mid - 1);
        }
        else{
            return mid;
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{0,1},{5,5},{6,7},{9,11}};
    vector<int> newInterval = {12,21};
    vector<vector<int>> result = s.insert(intervals, newInterval);
    for (int i = 0; i < result.size(); i++){
        cout << "[" << result[i][0] << "," << result[i][1] << "] ";
    }
}