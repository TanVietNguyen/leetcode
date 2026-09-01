#include <vector>
#include <string>   
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return findAddress(s, 3);
    }
    vector<string> findAddress (string s, int numDots){
        int length = s.size();
        if (numDots == 0){
           if(isStringValid(s)){
                return {s};
           }
            else{
                return {};
            }
        }
        string s1;
        string s2;
        vector<string> temp;
        vector<string> result;
        int tempLength;
        for(int i = 0; i < (length - 1); i++){
            if(i > 3){
                break;
            }
            s1 = s.substr(0, i - 0 + 1);
            if(!isStringValid(s1)){
                break;
            }  //25525511135
            s2 = s.substr(i + 1, length - 1 - i);
            temp = findAddress(s2, numDots - 1);
            s1.push_back('.');
            for(string elem : temp){
                elem.insert(elem.begin(), s1.begin(), s1.end());
                result.push_back(elem);
            }
        }

        return result;
    }

    bool isStringValid (string s){
        int length = s.size();
         if(length == 1){
                return true;
            }
            else if(length == 2){
                if(s[0] == '0'){
                    return false;
                }
                else{
                    return true;
                }
            }
            else if(length == 3){
                if(s[0] == '1'){
                    return true;
                }
                else if(s[0] == '2'){
                    if((s[1] - '0') < 5){
                        return true;
                    }
                    else if(s[1] == '5'){
                        if((s[2] - '0') < 6){
                            return true;
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
    }
};

int main(){
    Solution s;
    vector<string> result = s.restoreIpAddresses("25525511135");
    for(string elem : result){
        cout << elem << endl;
    }
    return 0;
}   