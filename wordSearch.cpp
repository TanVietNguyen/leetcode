#include <stack>
#include <tuple>
#include <vector>
#include <string>
#include <iostream> 

using namespace std;    

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        stack<tuple<int, int>> container;
        int rows = board.size();
        int cols = board[0].size();
        int rightBorder = cols - 1;
        int leftBorder = 0;
        int topBorder = 0;
        int bottomBorder = rows - 1;   
        int currIndex = 0;
        int count = 0;
        int length = word.size();
        bool isFound = false;
        vector<int> counts(word.size(), 0);
        vector<vector<bool>> isDiscovered(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == word[currIndex]){
                    container.push({i, j});
                    counts[currIndex] ++;
                    isFound = true;
                }
            }
            //'A','B','C','E'    "ABCCED"
            //'S','F','C','S'
            //'A','D','E','E'
        }

        tuple<int, int> temp;
        vector<tuple<int, int>> elemTaken;
        int first, second;
        int above;
        int below;
        int right;
        int left;
        while(!container.empty()){
            if(isFound){
                currIndex ++;
                isFound = false;
            }
            else{
                elemTaken.pop_back();
                while(counts[currIndex - 1] == 0){
                    elemTaken.pop_back();
                    currIndex --;
                }
            }
            if(currIndex == length){
                return true;
            }
            temp = container.top();
            container.pop();
            elemTaken.push_back(temp);
            counts[currIndex - 1] --;

            first = get<0>(temp); //'A','B','C','E'    "ABCB"
            second = get<1>(temp);//'S','F','C','S'
            above = first - 1;    //'A','D','E','E'
            below = first + 1;
            right = second + 1;
            left = second - 1;

            if(above >= topBorder){
                if(find(elemTaken.begin(), elemTaken.end(), make_tuple(above, second)) == elemTaken.end()){
                    if(board[above][second] == word[currIndex]){
                        isFound = true;
                        container.push({above, second});
                        counts[currIndex] ++;
                    }
                }
            }
            if(below <= bottomBorder){
                if(find(elemTaken.begin(), elemTaken.end(), make_tuple(below, second)) == elemTaken.end()){
                    if(board[below][second] == word[currIndex]){
                        isFound = true;
                        container.push({below, second});
                        counts[currIndex] ++;
                    }
                }
            }
            if(right <= rightBorder){
                if(find(elemTaken.begin(), elemTaken.end(), make_tuple(first, right)) == elemTaken.end()){  
                    if(board[first][right] == word[currIndex]){
                        isFound = true;
                        container.push({first, right});
                        counts[currIndex] ++;
                    }
                }
            }
            if(left >= leftBorder){
                if(find(elemTaken.begin(), elemTaken.end(), make_tuple(first, left)) == elemTaken.end()){
                    if(board[first][left] == word[currIndex]){
                        isFound = true;
                        container.push({first, left});
                        counts[currIndex] ++;
                    }
                }
               
            }
        }
        return false;
        
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCB";
    bool result = s.exist(board, word);
    cout << result << endl;
    return 0;
}