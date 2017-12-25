#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cmath>

using namespace std;

/*
 * the implement of algorithm
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        int dp[M][N];

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j - 1 < 0) {
                    if (i - 1 < 0) {
                        dp[i][j] = grid[0][0];
                        continue;
                    }
                    else {
                        dp[i][j] = dp[i - 1][j];
                    }
                } else {
                    if (i - 1 < 0) {
                        dp[i][j] = dp[i][j - 1];
                    } else {
                        dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];
                    }
                }
                
                dp[i][j] += grid[i][j];
                // cout << i << " " << j << " " << dp[i][j]<< endl; 
            }
        }

        return dp[M - 1][N - 1];
    }
};