#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int length = triangle.size();
       vector<vector<int>> result = minPath(triangle, 0, length);
        int min = INT_MAX;
        int rows = result.size();
        int cols = result[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(result[i][j] < min){
                    min = result[i][j];
                }
            }
        }

        return min;
    }
    vector<vector<int>> minPath(vector<vector<int>>& triangle, int level, int length){
        
        int elemSize = triangle[level].size();
        vector<vector<int>> result;
        vector<vector<int>> tempResult;
        if(level == (length - 1)){
            for(int i = 0; i < elemSize; i++){
                result[i].push_back({triangle[level][i]});
            }
            return result;
        }

        tempResult = minPath(triangle, level + 1, length);
        vector<vector<int>> temp;
        int tempSize = tempResult[0].size();
        for(int i = 0; i < elemSize; i++){
            temp = tempResult;
            for(int j = 0; j < tempSize; j++){
                temp[i][j] += triangle[level][i];
                temp[i + 1][j] +=  triangle[level][i];
            }
            result.push_back(temp[i]);

            result[i].insert(result[i].end(), temp[i + 1].begin(), temp[i + 1].end());
        }

        return result;
        
    }
};

int main(){
    Solution s;
    vector<vector<int>> triangle = {{2},{3,4}};
    int result = s.minimumTotal(triangle);
    cout << result << endl;
    return 0;
}   