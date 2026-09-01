#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tempVect;
        vector<vector<int>> result;
        if(k == 1){
            for(int i = 1; i <= n; i++){
                result.push_back({i});
            }
            return result;
        }
        if(k == n){
            for(int i = 1; i <= n; i++){
                tempVect.push_back(i);
            }
            result.push_back(tempVect);
            return result;
        }
        vector<vector<int>> tempResult;
        for(int i = n; i >= k; i --){
            tempResult = combine(i - 1, k - 1);
            for(vector<int> elem : tempResult){
                elem.push_back(i);
                result.push_back(elem);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> result = s.combine(3, 2);
    for(vector<int> elem : result){
        for(int i : elem){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}   