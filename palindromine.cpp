#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int longest_length = 0;
        int current_length = 0;
        int inverse_index;
        int current_last_string_index;
        bool palindrome_found = true;
        int starting_index = 0;
        for (int i = 0;  i < s.size(); i++){
            current_length = 1;
            if(longest_length >= s.size() - i){
                return s.substr(starting_index, longest_length);
            }
            while (current_length <= s.size() - i){
                cout << "i: " << i << " current_length: " << current_length << endl;
                current_last_string_index = i + current_length - 1;
                cout << "current_last_string_index: " << current_last_string_index << endl;
                for (int j = i; j <= current_last_string_index; j++){
                    cout << s[j] << " " << s[current_last_string_index - j + i] << endl;
                    if (s[j] != s[current_last_string_index - j + i]){
                        palindrome_found = false;
                        break;
                    }
                }
                if(palindrome_found && longest_length < current_length){
                    cout   <<"longest_length: " << longest_length << " i: " << i << endl;
                    starting_index = i;
                    longest_length = current_length;
                }
                palindrome_found = true;
                current_length ++;
            }

        }
        return s.substr(starting_index, longest_length);
        
    }
};

int main(){
    Solution solution;
    string input = "a";
    string result = solution.longestPalindrome(input);
    cout << "Longest Palindrome: " << result << endl;
    return 0;
}