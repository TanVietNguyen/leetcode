#include <vector>
#include <iostream>
using namespace std;

enum class Direction{up, down, right, left};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int count = 1;
        Direction nextMove = Direction::right;
        int currCol = 0;
        int currRow = 0;
        int topBorder = 1;
        int bottomBorder = n - 1;
        int rightBorder = n - 1;
        int leftBorder = 0;
        while(true){
            if ((nextMove == Direction::right && currCol == rightBorder && currRow == bottomBorder) ||
            (nextMove == Direction::down && currCol == leftBorder && currRow == bottomBorder) ||
            (nextMove == Direction::left && currCol == leftBorder && currRow == topBorder) ||
            (nextMove == Direction::up && currCol == rightBorder && currRow == topBorder)){
                result[currRow][currCol] = count;
                break;
            }
            if(nextMove == Direction::right &&currCol < rightBorder){
                result[currRow][currCol] = count;
                currCol ++;
                count++;
            }
            else if(nextMove == Direction::right && currCol == rightBorder){
                result[currRow][currCol] = count;
                nextMove = Direction::down;
                currRow ++;
                count ++;
                rightBorder --;
            }
            else if(nextMove == Direction::down && currRow < bottomBorder){
                result[currRow][currCol] = count;
                count ++;
                currRow ++;
            }
            else if(nextMove == Direction::down && currRow == bottomBorder){
                result[currRow][currCol] = count;
                count ++;
                currCol --;
                nextMove = Direction::left;
                bottomBorder --;
            }
            else if(nextMove == Direction::left && currCol > leftBorder){
                result[currRow][currCol] = count;
                count ++;
                currCol --;
            }
            else if(nextMove == Direction::left && currCol == leftBorder){
                result[currRow][currCol] = count;
                count ++;
                currRow --;
                nextMove = Direction::up;
                leftBorder ++;
            }
            else if(nextMove == Direction::up && currRow > topBorder){
                result[currRow][currCol] = count;
                count ++;
                currRow --;
            }
            else if(nextMove == Direction::up && currRow == topBorder){
                result[currRow][currCol] = count;
                count ++;
                currCol ++;
                nextMove = Direction::right;
                topBorder ++;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> result = s.generateMatrix(2);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}   