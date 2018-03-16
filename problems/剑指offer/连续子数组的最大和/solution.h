#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
 * the implement of algorithm
 */

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int N = array.size();
        int dp[N];
        dp[0] = array[0];

        for (int i = 1; i < N; i++) {
            if (dp[i - 1] < 0) {
                dp[i] = array[i];
            } else {
                dp[i] = array[i] + dp[i - 1];
            }
        }

        int max = dp[0];                          //！！不能初始化为0
        for (int i = 1; i < N; i++) {
            max = max > dp[i] ? max : dp[i];
        }

        return max;
    }
};