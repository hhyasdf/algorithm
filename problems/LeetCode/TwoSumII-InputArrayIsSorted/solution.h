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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int diffrence;
        int size = numbers.size();

        for (int i = 0; i < size; ++i) {
            diffrence = target - numbers[i];
            for (int j = i + 1; j < size; ++j) {
                if (diffrence == numbers[j]) {
                    return {i + 1, j + 1};
                }
                if (diffrence < numbers[j]) {
                    break;
                }
            }
        }
    }
};

/*
 * better solution
 * 因为数组中有且只有一对目标，并且数组已经排序，所以肯定是小的在前，大的在后
 * 从两端开始查找，如果当前目标对之和小于target就后移前面的指针（此时当前指针指向目标对中较小值时肯定是大于target），
 * 大于就前移后面的指针（此时当后指针指向目标对中较大值时肯定是小于target）
 * 逐渐趋向于目标对
 */


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         vector<int> res;
//         int sz = numbers.size();
//         int p = 0, q = sz-1;
//         while (p<q) {
//             int sum = numbers[p]+numbers[q];
//             if (sum==target) {
//                 res.push_back(p+1);
//                 res.push_back(q+1);
//                 return res;
//             } else if (sum<target) {
//                 p++;
//             } else {
//                 q--;
//             }
//         }
//         return res;
//     }
// };