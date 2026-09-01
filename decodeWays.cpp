#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int length = s.size();
        vector<int> indices;
        for (int i = 0; i < length; i++){
            if(s[i] == '0'){
                indices.push_back(i);
            }
        }
        string temp; //1201234
        vector<string> substrings;
        int lengthIn = indices.size();
        if(lengthIn == 0){
            vector<int> tempResult = decode(s, length);
            return tempResult[2];
        }
        for(int i = 0; i < lengthIn; i++){
            if(indices[i] == 0){
                return 0;
            }
            else if(s[indices[i] - 1] != '1' && s[indices[i] - 1] != '2'){
                return 0;
            }
            else{ //1201234
                if(i == 0){
                    temp = s.substr(0, indices[i] - 1);
                    substrings.push_back(temp);
                }
                else{
                    temp = s.substr(indices[i - 1] + 1, indices[i] - indices[i - 1] - 2);
                    substrings.push_back(temp);
                }
            }
        }
        if(indices[lengthIn - 1] != length - 1){
            temp = s.substr(indices[lengthIn - 1] + 1, length - indices[lengthIn - 1] - 1);
            substrings.push_back(temp);
        }
        int tempSize;
        int result = 1;
        vector<int> tempResult;
        for(string elem : substrings){
            tempSize = elem.size();
            if(tempSize == 0){
                continue;
            }
            tempResult = decode(elem, tempSize);
            result *= tempResult[2];
        }
        return result;
    }
    //{e1, e2, e3}: e1: number of strings end with '1'. e2: number of strings end with '2'. e3: number of total strings
    vector<int> decode(string& s, int length){
        if(length == 1){
            if(s[0] == '1'){
                return {1, 0, 1};
            }
            else if(s[0] == '2'){
                return {0, 1, 1};
            }
            else{
                return {0, 0, 1};
            }
        }

        vector<int> temp;
        vector<int> result(3);

        temp = decode(s, length - 1);
        if((s[length - 1] - '0') <= 6){
            result[2] = temp[0] + temp[1] + temp[2];
        }
        else{
            result[2] = temp[0] + temp[2];
        }

        if(s[length - 1] == '1'){
            result[0] = temp[2];
            result[1] = 0;
        }
        else if(s[length - 1] == '2'){
            result[0] = 0;
            result[1] = temp[2];
        }
        else{
            result[0] = 0;
            result[1] = 0;
        }

        return result;
    }
};

int main() {
    Solution solution;
    string s = "1201234";
    int result = solution.numDecodings(s);
    cout << "Number of ways to decode \"" << s << "\": " << result << endl;
    return 0;
}   