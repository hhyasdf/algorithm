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


// 计算a^n % b，其中a，b和n都是32位的整数
// 要实现O(log(n))的算法。。。。。。。。。。。。。。。。不会做 需要回顾

class Solution {  
public:  
    /* 
     * @param a, b, n: 32bit integers 
     * @return: An integer 
     */  
    int fastPower(int a, int b, int n) {  
        // write your code here  
        if(n == 0)  
            return 1 % b;  
        if(n == 1)  
            return a % b;  
        long long temp = fastPower(a, b, n/2);         // 分治思想    
        if(n & 1)                                      // n是奇数
            return ((temp * temp) % b) * a % b;        
        else                                           // n是偶数
            return temp * temp % b;  
    }  
}; 