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

// 在n个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为m，每个物品的大小为A[i]
// 01背包问题


class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        int N = A.size() + 1, M = m + 1;
        int dp[N][M];

        for (auto &item : dp[0]) {                              // 记得第一行要初始化为0，矩阵的求解顺序
            item = 0;
        }

        for (int i = 1; i <= A.size(); i++) {                   // 注意矩阵的求解顺序
            for (int cap = 0; cap <= m; cap ++) {               // 如果是只初始化一行为0的话，cap要从0开始
                int put, unput;
                unput = dp[i - 1][cap];
                if (cap - A[i - 1] >= 0) {                     
                    put = dp[i - 1][cap - A[i - 1]] + A[i - 1]; // 注意此时的价值就是所占的空间
                } else {                                        // 放不进去
                    put = 0;
                }
                dp[i][cap] = put > unput? put: unput;
            }
        }

        return dp[A.size()][m];
    }
};