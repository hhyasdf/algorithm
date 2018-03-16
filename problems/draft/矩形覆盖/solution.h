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


// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？


class Solution {
public:
    int rectCover(int number) {
        // if (number == 1) {
        //     return 1;
        // } else if (number == 2) {
        //     return 2;
        // }
        // return rectCover(number - 1) + rectCover(number - 2);

        // 用递归会栈溢出

        int dp[number + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= number; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[number];
    }
};