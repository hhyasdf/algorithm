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

//　输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
//　假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
//　但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

//　注意直接从入栈序列开始想，尝试能不能通过辅助栈构造出栈序列就好了，反过来顺序会有些麻烦

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
        if (pushV.size() != popV.size()) {
            return false;
        }
        stack<int> ref;
        auto begin = popV.begin();
        
        for (auto i = pushV.begin(); i != pushV.end(); ++i) {
            ref.push(*i); 
            while (!ref.empty() && ref.top() == *begin) {     //！！要先empty再top注意求值顺序
                begin += 1;
                ref.pop();
            }
        }
        if (!ref.empty()) {
            return false;
        }
        return true;
    }
};