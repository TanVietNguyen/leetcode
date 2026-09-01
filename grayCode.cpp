#include <vector>
// #include <algorithm>
// #include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        vector<int> temp(pow(2, n - 1));
        if(n == 1){
            return {0b0, 0b1};
        }

        temp = grayCode(n - 1);
        result.insert(result.end(), temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        for(int@ elem:temp){
            elem = (0b1 << (n - 1)) | elem;
        }
        result.insert(result.end(), temp.begin(), temp.end());
        return result;
    }
};

int main(){
    Solution s;
    vector<int> result = s.grayCode(2);
    for(int elem:result){
        cout << elem << " ";
    }
    cout << endl;
    return 0;  
}