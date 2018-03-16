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


//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

//！！！！要考虑负数的情况

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) {
            return 1.0;
        } else if (exponent == 1) {
            return base;
        } else if (exponent == -1) {
            return 1.0 / base;
        }
        
        double tmp = Power(base, exponent / 2);      //　注意不是int 是double
        
        if (exponent % 2) {                          // -3/2等于-1。。。。。。。
            if (exponent < 0) {
                return tmp * tmp / base;
            }
            return tmp * base * tmp;
        } else {
            return tmp * tmp;
        }
    }
};