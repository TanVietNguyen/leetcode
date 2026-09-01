#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGas;
        int currIndex;
        int length = gas.size();
        for(int i = 0; i < length; i++){
            if(cost[i] > gas[i]){
                continue;
            }
            //3 1 1
            //1 2 2 
            currIndex = i + 1;
            
            currGas = gas[i] - cost[i];

            while(currIndex != i){
                if(currIndex == length){
                    currIndex = 0;
                }
                if(currGas + gas[currIndex] >= cost[currIndex]){
                    currGas += (gas[currIndex] - cost[currIndex]);
                    currIndex ++;
                    if(currIndex == length){
                    currIndex = 0;
                    }
                }
                else{
                    break;
                }
            }
            if(currIndex == i){
                return currIndex;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> gas = {3,1,1};
    vector<int> cost = {1, 2, 2};
    cout << s.canCompleteCircuit(gas, cost) << endl;
}