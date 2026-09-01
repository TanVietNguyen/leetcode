#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int length1 = num1.size();
        int length2 = num2.size();
        vector<string> subProduct = {};
        string added0s = "";
        string sub = "";
        int index = 0;
        int num;
        int carryOver = 0;
        for (int i = length2 - 1; i >= 0; i--){
            sub = added0s;
            for (int j = length1 - 1; j >= 0; j--){
                num = (num1[j] - '0') * (num2[i] - '0') + carryOver;
                carryOver = num / 10;

                sub = std::to_string(num % 10) + sub;
            }
            if (carryOver != 0){
                sub = std::to_string(carryOver) + sub;
                carryOver = 0;
            }
            subProduct.push_back(sub);
            added0s = added0s + '0';
        }

        int length = subProduct.size();
        int num_digits = subProduct[length - 1].size();
        int varied_length;
        string leading_0s;
        for (int i = 0; i < length - 1; i ++){
            varied_length = subProduct[i].size();
            leading_0s.assign(num_digits - varied_length, '0');
            subProduct[i] = leading_0s + subProduct[i];
        }
        
        int sum;
        int carryOver10 = 0;
        int carryOver100 = 0;
        int carryOver1000 = 0;
        string finalChar;
        string finalString = "";
        for (int i = num_digits - 1; i >= 0; i--){
            sum = 0;
            for (int j = 0; j < length; j++){
                sum += (subProduct[j][i] - '0');
            }
            sum += carryOver10;
            carryOver10 = 0;
            if (carryOver100 != 0){
                carryOver10 = carryOver100;
                carryOver100 = 0;
            }
            if (carryOver1000 != 0){
                carryOver100 = carryOver1000;
                carryOver1000 = 0;
            }
            carryOver1000 = sum / 1000;
            carryOver100 += (sum % 1000) / 100;
            carryOver10 += (sum % 100) / 10;
            finalChar = std::to_string(sum % 10);
            finalString = finalChar + finalString;
        }
        if (carryOver10 != 0){
            finalString = std::to_string(carryOver10) + finalString;
        }
        if (carryOver100 != 0){
            finalString = std::to_string(carryOver100) + finalString;
        }
        if (carryOver1000 != 0){
            finalString = std::to_string(carryOver1000) + finalString;
        }

        return finalString;

    }
};

int main() {
    Solution solution;
    string num1 = "123";
    string num2 = "456";
    string result = solution.multiply(num1, num2);
    cout << "Result: " << result << endl; // Output: Result: 6
    return 0;
}