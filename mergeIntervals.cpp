#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int length = intervals.size();
        int value;
        for(int i = 0; i < length - 1; i++){
            for(int j = i + 1; j < length; j++){
                value = overlapVector(intervals[i], intervals[j]);
                switch (value){
                    case 1:
                        intervals[i] = {intervals[j][0], intervals[i][1]};
                        intervals[j] = intervals[length - 1];
                        length --;
                        j --;
                        break;
                    case 2:
                        intervals[i] = {intervals[j][0], intervals[j][1]};
                        intervals[j] = intervals[length - 1];
                        length --;
                        j --;
                        break;
                    case 3:
                        intervals[i] = {intervals[i][0], intervals[i][1]};
                        intervals[j] = intervals[length - 1];
                        length --;
                        j --;
                        break;
                    case 4:
                        intervals[i] = {intervals[i][0], intervals[j][1]};
                        intervals[j] = intervals[length - 1];
                        length --;
                        j --;
                        break;
                    default:
                        continue;
                }

            }
        }
        intervals.resize(length);
        return intervals;
    }
    int overlapVector (vector<int>& vect1, vector<int> vect2){
        if((vect2[0] <= vect1[0]) && (vect2[1] >= vect1[0]) && (vect2[1] <= vect1[1])){
            return 1; //overlap {vect2[0], vect1[1]}
        }
        else if((vect2[0] <= vect1[0]) && (vect2[1] >= vect1[1])){
            return 2;
        }
        else if((vect2[0] >= vect1[0]) && (vect2[1] <= vect1[0])){
            return 3;
        }
        else if((vect2[0] >= vect1[0]) && (vect2[0] <= vect1[1]) && (vect2[1] >= vect1[1])){
            return 4;
        }
        else{
            return 5;
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> mergedIntervals = s.merge(intervals);
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}