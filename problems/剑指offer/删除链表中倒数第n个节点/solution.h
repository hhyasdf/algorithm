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


// 给定一个链表，删除链表中倒数第n个节点，返回链表的头节点。
// 给出链表1->2->3->4->5->null和 n = 2.
// 删除倒数第二个节点之后，这个链表将变成1->2->3->5->null.

// 一定要注意删除头结点和尾节点的特殊情况！！！！

// Definition of singly-linked-list:
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
       this->val = val;
       this->next = NULL;
    }
};


class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        // write your code here

        int i = 0;
        ListNode *pos, *npos;
        npos = pos = head;

        for (npos = head; i < n - 1; ++i) {
            if (npos == NULL) {                    // 链表长度可能小于n
                return NULL;
            }
            npos = npos->next;
        }
        npos = npos->next;

        while (npos != NULL) {
            npos = npos->next;
            pos = pos->next;
        }

        auto next = pos->next;
        if (next != NULL) {
            pos->val = next->val;                 // 删到头结点也无所谓
            pos->next = next->next;
            delete next;                          //！！ 记得删
        } else {
            auto pre = head;
            if (head != pos) {
                while (pre->next != pos) {                // 删的是最后一个节点仍然要遍历找到前驱！！！，而且next为NULL
                    pre = pre->next;
                }
                pre->next = NULL;
            } else {
                head = NULL;
            }
            delete pos;
        }

        return head;
    }
};