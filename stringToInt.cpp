#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool is_leading_char = true;
        bool is_negative = false;
        unordered_set<char> number = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string result;
        int n;
        for (int i = 0; i < s.size(); i++){
            if (is_leading_char && s[i] == ' '){
                continue;
            }
            else if (is_leading_char && s[i] == '-'){
                is_negative = true;
                is_leading_char = false;
                continue;
            }
            else if (is_leading_char && s[i] == '+'){
                is_leading_char = false;
                continue;
            }
            else if (is_leading_char && find(number.begin(), number.end(), s[i]) != number.end()){
                result.push_back(s[i]);
                is_leading_char = false;
                continue;
            }
            else if(is_leading_char && find(number.begin(), number.end(), s[i]) == number.end()){
                return 0;
            }
            else if(!is_leading_char && find(number.begin(), number.end(), s[i]) != number.end()){
                result.push_back(s[i]);
                continue;
            }
            else if(!is_leading_char && find(number.begin(), number.end(), s[i]) == number.end()){
                break;
            }

        }
        if(result.empty()){
            return 0;
        }
        try{
            n = stoi(result);
        }
        catch(exception& e){
            if(is_negative){
                cout <<"Overflow detected, returning minimum integer value." << endl;
                return - pow(2, 31);
            }
            cout <<"Overflow detected, returning maximum integer value." << endl;
            return pow(2,31 - 1);
        }

        if (is_negative){
            return -n;
        }
        return n;
    }
};

int main(){
    Solution solution;
    string input = "+-12";
    int result = solution.myAtoi(input);
    cout << "Converted integer: " << result << endl;
    return 0;
}