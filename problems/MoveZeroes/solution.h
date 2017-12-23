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

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto pointer1 = nums.begin();
        for (; pointer1 != nums.end(); ++pointer1) {
            if (*pointer1 == 0) {
                auto pointer2 = pointer1;
                for (; pointer2 != nums.end(); ++pointer2) {
                    if (*pointer2 != 0) {
                        auto temp = *pointer2;
                        *pointer2 = *pointer1;
                        *pointer1 = temp;
                        break;
                    }
                }
            }
        }
    }
};


// 更好的方法，i和k从第一个开始，i持续递增直到尾后，遇到一个不等于0的数就和k指向的数互换（每次互换k++）最后k和i就代表了末尾的0区间，然后填充
// 属于数组变换类的问题，两个条件是互斥的（前面填充为非零，后面填充为0）先满足一个再满足后一个

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         for (int i = 0, k = 0; i < nums.size(); i++) {
//             if (nums[i]) {
//                 if (i != k) {
//                     swap(nums[i], nums[k]);
//                 }
//                 k++;
//             }
//         }
//     }
// };