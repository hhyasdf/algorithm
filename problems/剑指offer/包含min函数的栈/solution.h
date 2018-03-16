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

// 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。


class Solution {
private:
    stack<int> min_stack;
    stack<int> val;
public:
    void push(int value) {
        if (min_stack.empty()) {
            val.push(value);
            min_stack.push(value);
        } else {
            if (value > min_stack.top()) {
                min_stack.push(min_stack.top());
            } else {
                min_stack.push(value);
            }
            val.push(value);
        }
    }
    void pop() {
        min_stack.pop();
        val.pop();
    }
    int top() {
        return val.top();
    }
    int min() {
        return min_stack.top();
    }
};