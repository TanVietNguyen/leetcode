#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> substring;
        int starting_index = 0;
        int longest_length = 0;
        int current_index = 0;
        bool duplicate_found = false;
        bool duplicate_found_left = false;
        bool duplicate_found_right = false;
        int left = 0;
        vector <char> left_substring;
        vector <char> right_substring;
        int right = s.size() - 1;
        // while (true){
        //     for (int i = left; i < s.size(); i++){
        //         for (int j = 0; j < left_substring.size(); j++){
        //             if (left_substring[j] == s[i]){
        //                 duplicate_found_left = true;
        //                 break;
        //             }
        //         }
        //         if(duplicate_found_left){
        //             if(longest_length < left_substring.size()){
        //                 longest_length = left_substring.size();
        //                 left_substring.clear();
        //             }
        //         }
        //         left_substring.push_back(s[i]);
        //     }

        //     for (int m = right; m < s.size(); m++){
        //         for (int n = 0; n < right_substring.size(); n++){
        //             if(right_substring[n] == s[m]){
        //                 duplicate_found_right = true;
        //                 break;
        //             }
        //         }
        //         if(duplicate_found_right){
        //             if (longest_length < right_substring.size()){
        //                 longest_length = right_substring.size();
        //                 right_substring.clear();
        //                 break;
        //             }
        //         }
        //         right_substring.push_back(s[m])
        //     }


        // }
        for (starting_index = 0; starting_index < s.length(); starting_index++){
            if(longest_length >= s.length() - starting_index){
                break;
            }
            substring.clear();
            cout << "Starting index: " << starting_index << endl;
            current_index = starting_index;
            while(current_index < s.length()){
                if (substring.empty()){
                    if (longest_length == 0){
                        longest_length = 1;
                    }
                    cout << "Current character: " << s[current_index] << " ";
                    substring.push_back(s[current_index]);
                    current_index++;
                    continue;
                }
                for (int i = 0; i < substring.size(); i++){
                    if (s[current_index] == substring[i]){
                        if (longest_length < substring.size()){
                            longest_length = substring.size();

                        }
                        substring.clear();
                        duplicate_found = true;
                        break;
                    }
                }
                
                if (!duplicate_found){
                    cout << "Current character: " << s[current_index] << " ";
                    substring.push_back(s[current_index]);
                    if (longest_length < substring.size()){
                        longest_length = substring.size();
                    }
                    current_index++;
                
                }
                else{
                    duplicate_found = false;
                    break;

                } 
               
            }
        }
        return longest_length;
    }
};

int main(){
    Solution solution;
    string s = "pwwkew";
    int result = solution.lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}