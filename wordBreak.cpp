#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // A naive approach is plitting a string in every possible ways, then in each way, determine if every splitted segments of the string are in wordDict.
    //This approach seem impossible in the first place, but it seems to be feasible with recursive approach, where we just cut the string off one character at a time until it becomes a one-char string. To speed up, use memoization (dynamic programming in other word)
    bool wordBreak(string s, vector<string>& wordDict) {
        int length = s.size();
        if(length == 0){
            return true;
        }

        vector<vector<int>> result(length + 1, vector<int>(length + 1, -1));
        return isFound(s, wordDict, result, 0, length - 1);

    }

    bool isFound (string& s, vector<string>& wordDict, vector<vector<int>>& result, int start, int end){
        if(result[start][end] != -1){
            return result[start][end];
        }
        if(end < start){
            return true;
        }
        else if(start == end){
            string temp = s.substr(start, 1);
            if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()){
                result[start][end] = 1;
                return true;
            }
            else{
                result[start][end] = 0;
                return false;
            }
        }
        else{
            int length = end - start + 1;
            string initString;
            bool found = false;
            for(int i = start; i < end + 1; i++){
                initString = s.substr(start, i + 1 - start);
                if(find(wordDict.begin(), wordDict.end(), initString) == wordDict.end()){
                    continue;
                }
                found = isFound(s, wordDict, result, i + 1, end);
                if(found){
                    result[start][end] = 1;
                    return true;
                    break;
                }
            }

            result[start][end] = 0;
            return false;
        }
    }   
};

int main (){
    Solution s;
    string str = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout << s.wordBreak(str, wordDict) << endl;
}  