#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string x_string = to_string(x);
        bool overflow_checked = false;
        string x_string_inversed;
        //-2,147,483,648 to 2,147,483,647
        //8,463,847,412
        cout << "current string: " << x_string <<endl;
        int index = x_string.size() - 1;
        if (x_string[0] == '-' && x_string.size() > 11){
            return 0;
        }
        if (x_string[0] == '-' && x_string.size() == 11){
            overflow_checked = true;
            while(overflow_checked && x_string.size() > 1){
                switch (index){
                    case 10:
                        if(x_string[index] > '2'){
                            return 0;
                        }
                        else if (x_string[index] == '2'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 9:
                        if (x_string[index] > '1'){
                            return 0;
                        }
                        else if (x_string[index] == '1'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 8:
                        if (x_string[index] > '4'){
                            return 0;
                        }
                        else if (x_string[index] == '4'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 7: 
                        if (x_string[index] > '7'){
                            return 0;
                        }
                        else if (x_string[index] == '7'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 6:
                        if (x_string[index] > '4'){
                            return 0;
                        }
                        else if (x_string[index] == '4'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 5:
                        if (x_string[index] > '8'){
                            return 0;
                        }
                        else if (x_string[index] == '8'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 4: 
                        if (x_string[index] > '3'){
                            return 0;
                        }
                        else if (x_string[index] == '3'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }  
                    case 3: 
                        if (x_string[index] > '6'){
                            return 0;
                        }
                        else if (x_string[index] == '6'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 2:
                        if (x_string[index] > '4'){
                            return 0;
                        }
                        else if (x_string[index] == '4'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 1:
                        if (x_string[index] > '8'){
                            return 0;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 0:
                        break;
                }
                index--;
            }
        }
        if (x_string[0] != '-' && x_string.size() > 10){
            return 0;
        }
        if (x_string[0] != '-' && x_string.size() == 10){
            overflow_checked = true;
            while(overflow_checked && index >= 0){
                switch (index){
                    case 9:
                        if(x_string[index] > '2'){
                            return 0;
                        }
                        else if (x_string[index] == '2'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 8:
                        if (x_string[index] > '1'){
                            return 0;
                        }
                        else if (x_string[index] == '1'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 7:
                        if (x_string[index] > '4'){
                            return 0;
                        }
                        else if (x_string[index] == '4'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 6: 
                        if (x_string[index] > '7'){
                            return 0;
                        }
                        else if (x_string[index] == '7'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 5:
                        if (x_string[index] > '4'){
                            return 0;
                        }
                        else if (x_string[index] == '4'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 4:
                        if (x_string[index] > '8'){
                            return 0;
                        }
                        else if (x_string[index] == '8'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 3: 
                        if (x_string[index] > '3'){
                            return 0;
                        }
                        else if (x_string[index] == '3'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }  
                    case 2: 
                        if (x_string[index] > '6'){
                            return 0;
                        }
                        else if (x_string[index] == '6'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 1:
                        if (x_string[index] > '4'){
                            return 0;
                        }
                        else if (x_string[index] == '4'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                    case 0:
                        if (x_string[index] > '7'){
                            return 0;
                        }
                        else if (x_string[index] == '7'){
                            overflow_checked = true;
                            break;
                        }
                        else {
                            overflow_checked = false;
                            break;
                        }
                }
                index--;
            }

        }
        for (int i = x_string.size() - 1 ; i >= 0; i--){
            cout << "current_char: " << x_string[i] << endl;
            x_string_inversed.push_back(x_string[i]);
        }
        cout << "inversed string: " << x_string_inversed << endl;
        int x_inversed = stoi(x_string_inversed);
        if(x_string[0] == '-'){
            x_inversed *= -1;
        }
        return x_inversed;
    }
};

int main (){
    Solution solution;
    int x = 123;
    int result = solution.reverse(x);
    cout << "Reversed integer: " << result << endl;
    return 0;
}