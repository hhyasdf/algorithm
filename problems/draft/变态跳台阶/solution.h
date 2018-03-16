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


// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。



class Solution {
public:
    int jumpFloorII(int number) {
        int dp[number + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= number; i++) {
            dp[i] = 0;
            for (int k = 0; k < i; k++) {
                dp[i] += dp[k];
            }
        }

        return dp[number];
    }
};