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

// 用递归的方法找到从1到最大的N位整数。并且使得递归的深度最多只有 N 层。

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An array storing 1 to the largest number with n digits.
     */
    
    void printNumbers(int n, int base, vector<int> &result) {
        if (n == 0) {
            if (base != 0) {
                result.push_back(base);
            }
            return ;
        }

        int power = 1;
        for (int i = 1; i < n; ++i, power *= 10);

        for (int i = 0; i < 10; i++) {
            printNumbers(n - 1, power * i + base, result);
        }
    }
    
    
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> result;
        
        printNumbers(n, 0, result);

        return result;
    }
};