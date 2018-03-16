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

// 输入一个链表，从尾到头打印链表每个节点的值。


struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};



class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        auto p = head;
        vector<int> result;
        stack<int> stac;
        while (p != NULL) {
            stac.push(p->val);
            p = p->next;
        }
        while (!stac.empty()) {
            result.push_back(stac.top());
            stac.pop();
        }
        return result;
    }
};