#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * the implement of algorithm
 */

// 连续量的hash性质和中间变量的用法
// 总的想法是数组中让每个变量代表的对应位置都减去 n + 1，但减的过程中相互会有影响，怎样用中间变量消除影响（保留下一个要减的位置）

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();          // cannot use auto here!! because the value "n" (unsigned int)
                                      //  will transfer int to the same type in next expretions
        
        if (nums.size() == 0) {       // handle exception!!!
            return result;
        }
        int temp = nums[0], position = 0;
        do{
            int t = temp;
            temp = nums[t - 1];
            nums[t - 1] -= (n + 1);       
            if (temp < 0) {
                for (int i = position; i < n; ++i) {
                    if (nums[i] > 0) {
                        temp = nums[i];
                        position = i + 1;
                        break;
                    }
                }
            }
        }while(temp > 0);

        for (int i = 0; i < n; ++i) {
            if(nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};