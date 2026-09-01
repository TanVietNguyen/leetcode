#include <iostream> 
#include <string>   
#include <vector>   

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int length1 = word1.size();
        int length2 = word2.size();
        if(length1 > length2){
            return testFunction(word1, word2, 0, 0);
        }
        else{
            return testFunction(word2, word1, 0, 0);
        }
    }

    int testFunction (string word1, string word2, int index1, int index2){
        int length1 = word1.size();
        int length2 = word2.size();
        // assume word1 has longer length than word2, should arrange this before calling this function.
        int numActions;
        int tempActions1, tempActions2, tempActions3;

        if(index1 == length1 && index2 != length2){
            numActions = testFunction(word1, word2, index1, index2 + 1);
            return (numActions + 1);
        }
        if(index1 == length1 && index2 == length2){
            return 0;
        }
        if(index1 != length1 && index2 == length2){
            numActions = testFunction(word1, word2, index1 + 1, index2);
            numActions ++;
            return numActions;
        }
        else{
            if(word1[index1] != word2[index2]){
                //either delete the char in word 1 or replace it
                //case 1: delete char
                tempActions1 = testFunction(word1, word2, index1 + 1, index2);
                // case 2: replace the char with char from word2
                tempActions2 = testFunction(word1, word2, index1 + 1, index2 + 1);

                if(tempActions1 > tempActions2){
                    return (tempActions2 + 1);
                }

                return (tempActions1 + 1);

            }

            else{
                numActions = testFunction(word1, word2, index1 + 1, index2 + 1);
                return numActions;
            }
        }
    }
};

int main(){
    Solution s;
    string word1 = "sea";
    string word2 = "eat";
    cout << s.minDistance(word1, word2) << endl;
}