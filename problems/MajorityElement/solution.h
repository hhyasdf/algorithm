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
    int majorityElement(vector<int>& nums) {
        map<int, int> recorder;
        auto n = nums.size() / 2;

        for (auto &item : nums) {
            recorder[item] ++;
        }
        for (auto &item : recorder) {
            if (item.second > n) {
                return item.first;
            }
        }
    }
};