#include <vector>
#include <iostream> 

using namespace std;

class Solution {
public:
    vector<int> largestRectangleArea(vector<int>& distance, vector<int>& isVertical, int w, int h) {
        vector<int> largestArea;
        vector<int> horizontal;
        vector<int> vertical;

        horizontal.push_back(0);
        horizontal.push_back(h);
        vertical.push_back(0);
        vertical.push_back(w);

        int length = distance.size();
        int honLen;
        int verLen; 
        int honMax = 0;
        int verMax = 0;

        for(int i = 0; i < length; i ++){
            if(isVertical[i] == 0){
                honLen = horizontal.size(); 
                for(int j = 0; j < honLen; j ++){
                    if(distance[i] < horizontal[j]){
                        horizontal.insert(horizontal.begin() + j, distance[i]);
                        break;
                    }
                }
                honLen ++;
                for(int j = 1; j < honLen; j ++){
                    if(horizontal[j] - horizontal[j - 1] > honMax){
                        honMax = horizontal[j + 1] - horizontal[j];
                    }
                }
                if(verMax == 0){
                    verMax = w;
                }
                largestArea.push_back(honMax * verMax);
                verMax = 0;

            } else {
                verLen = vertical.size(); 
                for(int j = 0; j < verLen; j ++){
                    if(distance[i] < vertical[j]){
                        vertical.insert(vertical.begin() + j, distance[i]);
                        break;
                    }
                }
                verLen ++;
                for(int j = 1; j < verLen; j ++){
                    if(vertical[j] - vertical[j - 1] > verMax){
                        verMax = vertical[j + 1] - vertical[j];
                    }
                }
                if(honMax == 0){
                    honMax = h;
                }
                largestArea.push_back(honMax * verMax);
                honMax = 0;
            }
        }

        return largestArea;
    }
};