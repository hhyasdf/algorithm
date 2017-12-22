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
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int org_r = nums.size();
        int org_c = nums[0].size();
                
        if (r * c != org_r * org_c) {
            return nums;
        } else {
            vector<vector<int>> reshaped(r);
            
            for (int i = 0; i < r * c ; ++i) {
                reshaped[i / c].push_back(nums[i / org_c][i % org_c]);
            }
            return reshaped;
        }
    }
};