#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        set<int> rowIndices;
        set<int> colIndices;
        vector<int> indices;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    rowIndices.insert(i);
                    colIndices.insert(j);
                }
            }//{1, 2, 3}, {4, 0, 6}, {7, 8, 9}}
        }
        for(int element : rowIndices){
            for(int i = 0; i < cols; i++){
                matrix[element][i] = 0;
            }
        }

        for(int element : colIndices){
            for(int i = 0; i < rows; i++){
                matrix[i][element] = 0;
            }
        }
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
    solution.setZeroes(matrix);
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}   