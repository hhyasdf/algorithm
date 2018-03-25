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

// 从一个数组中找出满足符合条件的元素:它大于或等于前面所有元素,小于或等于后面所有元素


// prefixMax数组记录每个前缀的最小值，suffixMax数组记录每个后缀的最小值，遍历两个数组找到
// 其中等于nums对应位置的元素相同元素的个数即可


class Solution {
    int findTheRightNum(vector<int> nums) {
        vector<int> prefixMax;
        vector<int> suffixMax;

        int tmpMax = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            tmpMax > nums[i]? tmpMax : nums[i];
            prefixMax[i] = tmpMax;
        }

        tmpMax = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i >= 0; i--) {
            tmpMax > nums[i]? tmpMax : nums[i];
            suffixMax[i] = tmpMax;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (prefixMax[i] == suffixMax[i] && prefixMax[i] == nums[i]) {
                return i;
            }
        }
    }
};