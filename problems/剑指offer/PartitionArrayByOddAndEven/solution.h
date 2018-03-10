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


// 分割一个整数数组，使得奇数在前偶数在后

/*
 * the implement of algorithm
 */

class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here

        int p1, p2, tmp;
        p1 = -1;
        
        for (p2 = 0; p2 < nums.size(); p2 ++) {
            if (nums[p2] & 0x1 != 0) {
                ++p1;
                tmp = nums[p2];
                nums[p2] = nums[p1];
                nums[p1] = tmp;
            }
        }
    }
};