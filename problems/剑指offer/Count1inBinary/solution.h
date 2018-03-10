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

// 计算在一个 32 位的整数的二进制表示中有多少个 1.

class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        // write your code here
        if (num == 0) {
            return 0;
        }
        
        int counter = 0;
        while (num != 0) {
            num &= (num - 1);
            ++counter;
        }

        return counter;
    }
};