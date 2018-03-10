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

//求第n个斐波那契数，索引从第0个开始：0 1 1 2 3...

class Solution {
public:
    int Fibonacci(int n) {

        int tmp1, tmp2, target;
        tmp1 = 0;
        tmp2 = 1;

        if (n == 0) {
            return tmp1; 
        } else if (n == 1) {
            return tmp2;
        }

        for (int i = 0; i < n - 1; i++) {
            target = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = target;    
        }

        return target;
    }
};