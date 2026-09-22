#include <vector>   
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string answer;
        long num = numerator;
        long den = denominator;
        long int quotient = num / den;
        long int remainder = num % den;
        string temp;
        vector<long> numeratorList;
        int length;

        if(quotient == 0){
            if((num < 0 && den > 0) || (num > 0 && den < 0)){
                answer.push_back('-');
            }
            answer.push_back('0');
            if(num == 0){
                return answer;
            }
            answer.push_back('.');
            num = remainder * 10;
        }
        else{
            temp = to_string(quotient);
            answer.insert(answer.end(), temp.begin(), temp.end());
            if(remainder == 0){
                return answer;
            }
            answer.push_back('.');
            num = remainder * 10;
        }
        if(num < 0){
            num = - num;
        }
        if(den < 0){
            den = - den;
        }

        numeratorList.push_back(num);

        while(remainder != 0){
            quotient = num / den;

            answer.push_back(quotient + '0');
            remainder = num % den;
            num = remainder * 10;
            auto it = find(numeratorList.begin(), numeratorList.end(), num);
            if(it != numeratorList.end()){
                auto index = distance(numeratorList.begin(), it);
                length = numeratorList.size() - index;
                answer.insert(answer.end() - length, '(');
                answer.push_back(')');
                return answer;
            }
            
            numeratorList.push_back(num);

        }
        return answer;
    }
};

int main(){
    Solution solution;
    int numerator = -1;
    int denominator = -2147483648;
    string answer = solution.fractionToDecimal(numerator, denominator);
    return 0;
}
