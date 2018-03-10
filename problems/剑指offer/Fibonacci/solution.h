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

//求第n个斐波那契数

class Solution {
public:
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int tmp1, tmp2, target;
        tmp1 = 0;
        tmp2 = 1;

        if (n == 1) {
            return tmp1; 
        } else if (n == 2) {
            return tmp2;
        }

        for (int i = 0; i < n - 2; i++) {
            target = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = target;    
        }

        return target;
    }
};