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
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        auto begin = nums.begin();
        auto size = nums.size();

        sort(begin, nums.end());
        
        for (int i = 0; i < size; i += 2) {
            sum += *(begin + i);
        }

        return sum;
    }
};