#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

/*
 * the implement of algorithm
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current = 0, max = 0, flag = 1;
        for (const auto i : nums) {
            if (flag == i) {
                ++current;
            } else{
                if (current > max) {
                    max = current;
                }
                current = 0;
            }
        }
        if(current > max) {
            max = current;
        }
        return max;
    }
};