#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

/*
 * the implement of algorithm
 */

// 和最大子串和类似

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int N = prices.size();
        int dp[N][2];
        dp[0][1] = 0;
        dp[0][0] = prices[0];  // dp[i][0]存(0,i)子串中最小的值， dp[i][1]存(0,i)子串的最大profit

        for (int i = 1; i < N; ++i) {
            auto last = dp[i - 1];
            int min = last[0];
            int next_price = prices[i];
            auto t = dp[i];

            t[0] = min < next_price ? min : next_price;

            if (next_price - min > last[1]) {
                t[1] = next_price - min;
            } else {
                t[1] = last[1];
            }

            cout << i << " " << dp[i][1] << endl;
        }

        auto result = dp[N - 1][1];

        if (result < 0) {
            return 0;
        }
        return result;
    }
};