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

// 假设一个旋转排序的数组其起始位置是未知的（比如0 1 2 4 5 6 7 可能变成是4 5 6 7 0 1 2）。
// 你需要找到其中最小的元素。
// 你可以假设数组中不存在重复的元素。
// 原题假设没有重复的元素


class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here

        if (*(nums.end() - 1) > *nums.begin()) {
            return *nums.begin();
        } 

        int start = 0, end, middle;
        end = nums.size() - 1;

        if (end - start == 1) {
            return nums[0] > nums[1] ? nums[1]:nums[0];
        }

        while (end - start != 1) {
            middle = (start + end) / 2;

            if (nums[middle] > nums[0]) {
                start = middle;
            } else if (nums[middle] < nums[0]){
                end = middle;
            } else {                   // 考虑有重复元素的情况！！
                int min = nums[0];
                for (int i = start; i <= end ; i++) {
                    min = nums[i] > min ? min:nums[i];
                }
                return min;
            }
        }

        return nums[end];
    }
};