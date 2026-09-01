#include <string>
#include <vector>  
#include <algorithm>
#include <iostream>
#include <ranges>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> operations = {"+", "-", "*", "/"};
        int length = tokens.size();
        pair<int, int> result = findOp1(tokens, 0, length - 1, operations);
        return result.first;
    }

    pair<int, int> findOp1(vector<string>& tokens, int start, int end, vector<string>& operations){
        pair<int, int> op1, op2;
        string operation;
        if(find(operations.begin(), operations.end(), tokens[end]) != operations.end()){
            operation = tokens[end];
            op2 = findOp1(tokens, start, end - 1, operations);
            op1 = findOp1(tokens, start, op2.second - 1, operations);
            if(tokens[end] == "*"){
                return {op2.first * op1.first, op1.second};
            }
            // "4","13","5","/","+"
            else if(tokens[end] == "/"){
                return {op1.first * op2.first, op1.second};
            }
            else if(tokens[end] == "-"){
                return {op1.first - op2.first, op1.second};
            }
            else{
                return {op2.first + op1.first, op1.second};
            }

        }
        else{
            return {stoi(tokens[end]), end};
        }
        
    }
    int findOp(vector<string>& tokens, int start, int end, vector<string>& operations){
        int op1, op2;
// ,"93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"

        if(end == start){
            return stoi(tokens[end]);
        }

        string operation = tokens[end];

        if(end - start == 2){
            op1 = stoi(tokens[start]);
            op2 = stoi(tokens[end - 1]);
        }
        else{
            if(find(operations.begin(), operations.end(), tokens[end - 1]) != operations.end()){
                if(find(operations.begin(), operations.end(), tokens[end - 2]) == operations.end() && find(operations.begin(), operations.end(), tokens[end - 3]) == operations.end()){
                    op2 = findOp(tokens, end - 3, end - 1, operations);
                    op1 = findOp(tokens, start, end - 4, operations);
                }
// ,"93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"

                else{
                    if(find(operations.begin(), operations.end(), tokens[start + 2]) != operations.end()){
                        op1 = findOp(tokens, start, start + 2, operations);
                        op2 = findOp(tokens, start + 3, end - 1, operations);
                    }
                    else{
                        op1 = stoi(tokens[start]);
                        op2 = findOp(tokens, start + 1, end - 1, operations);
                    }
                }
            }
            else{
                op2 = stoi(tokens[end - 1]);
                op1 = findOp(tokens, start, end - 2, operations);
            }
        }
        
        if(operation == "+"){
            return (op1 + op2);
        }
        else if(operation == "-"){
            return (op1 - op2);
        }
        else if(operation == "*"){
            return (op1 * op2);
        }
        else{
            return (op1 / op2);
        }
    }
};

int main(){
    Solution s;
    // vector<string> tokens = {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};
    vector<string> tokens = {"4","13","5","/","+"};
    cout << s.evalRPN(tokens) << endl;
}   