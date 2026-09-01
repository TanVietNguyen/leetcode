#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int length = s.size();
        if(length == 0){
            return true;
        }

        string temp1, temp2;
        bool result = false;
        for(int i = 0; i < length; i++){
            temp1 = s.substr(0, i + 1);
            if(find(wordDict.begin(), wordDict.end(), temp1) == wordDict.end()){
                continue;
            }

            temp2 = s.substr(i + 1, length - i);
            result = result || wordBreak(temp2, wordDict);
            if(result){
                return result;
            }
        }
        return false;
    }
};

int main (){
    Solution s;
    string str = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << s.wordBreak(str, wordDict) << endl;
}  