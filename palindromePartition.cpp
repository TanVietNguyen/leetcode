#include <vector>
#include <string>
#include <algorithm>    
#include <iostream>

using namespace std;    

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int length = s.size();
        vector<vector<string>> tempRe;
        vector<vector<string>> result;
        string leftSub;
        string rightSub;
        if(length == 0){
            return {{}};
        }
        else if(length == 1){
            return {{s}};
        }
        for(int i = 0; i < length; i++){
            leftSub = s.substr(0, i + 1);
            if(isPalindrome(leftSub)){
                tempRe = partition(s.substr(i + 1, length - i - 1));
                for(vector<string> elem : tempRe){
                    elem.push_back(leftSub);
                    result.push_back(elem);
                }
            }

        }
        return result;
    }

    bool isPalindrome (string s){
        r
        string reversed(s.begin(), s.end());
        return reversed == s;
    }
};

int main (){
    Solution s;
    string str = "aab";
    vector<vector<string>> result = s.partition(str);
    for(vector<string> elem : result){
        for(string subElem : elem){
            cout << subElem << " ";
        }
        cout << endl;
    }
}