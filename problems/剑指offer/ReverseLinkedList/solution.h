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


//给出一个链表1->2->3->null，这个翻转后的链表为3->2->1->null
//翻转一个单向链表

class Solution {
public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        // write your code here
        ListNode *next, *nnext, *pre;

        if (head == NULL) {
            return NULL;
        } else if (head->next == NULL) {
            return head;
        }

        pre = head;
        next = head->next;

        head->next = NULL;

        while (next != NULL) {
            nnext = next->next;
            next->next = pre;
            pre = next;
            next = nnext;
        }

        return pre;
    }
};