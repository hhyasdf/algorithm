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


class Solution {
public:
    map<int, int> recorder;

    int minCostClimbingStairs(vector<int>& cost) {
        auto begin = cost.begin(), end = cost.end();
        if (begin == end || end - begin == 1) {       // !! 子问题的参数是接下来要踩的楼梯的cost，如果只有一阶有cost就直接跨两步
            return 0;
        }

        auto onestep = vector<int>(begin + 1, end);
        auto twostep = vector<int>(begin + 2, end);

        int onestep_cost, twostep_cost;
        
        if (recorder.find(cost.size()) == recorder.end()) {
            onestep_cost = (minCostClimbingStairs(onestep) + *(begin));
            twostep_cost = (minCostClimbingStairs(twostep) + *(begin + 1));
        } else {
            return recorder[cost.size()];
        }

        auto min_cost = onestep_cost > twostep_cost ? twostep_cost : onestep_cost;
        recorder[cost.size()] = min_cost;
        return min_cost;
    }
};