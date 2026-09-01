#include <vector>
#include <iostream>

using namespace std; 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int rowIndex = searchRow(matrix, target, 0, rows - 1, cols);
        return searchTarget(matrix, target, 0, cols - 1, rowIndex);
    }//{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}

    int searchRow(vector<vector<int>>& matrix, int target, int start, int end, int cols){
        if(start == end){
            return start;
        }
        int mid = (start + end) / 2;
        if(matrix[mid][cols - 1] < target){
            return searchRow(matrix, target, mid + 1, end, cols);
        }
        else{
            return searchRow(matrix, target, start, mid, cols);
        }
    }

    bool searchTarget (vector<vector<int>>& matrix, int target, int start, int end, int index){
        if(start > end){
            return false;
        }
        int mid = (start + end) / 2;
        if(matrix[index][mid] == target){
            return true;
        }
        else if(matrix[index][mid] > target){
            return searchTarget(matrix, target, start, mid - 1, index);
        }
        else{
            return searchTarget(matrix, target,mid + 1, end, index);
        }
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix = {{1}};
    int target = 3;
    bool result = solution.searchMatrix(matrix, target);
    cout << (result ? "true" : "false") << endl;
    return 0;
}