#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * the implement of algorithm
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        int max = 0;
        int temp = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            int profit = prices[i] - temp;
            if (profit > 0) {
                max += profit;
            }
            temp = prices[i];
        }
        return max;
    }
};