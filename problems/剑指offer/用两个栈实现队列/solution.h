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

// 使用两个栈来实现队列的一些操作。

// 队列应支持push(element)，pop() 和 top()，其中pop是弹出队列中的第一个(最前面的)元素。

// pop和top方法都应该返回第一个元素的值。

class MyQueue {
public:

    stack<int> in_stack;
    stack<int> out_stack;

    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        in_stack.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        int result = out_stack.top();
        out_stack.pop();
        return result;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        return out_stack.top();
    }
};