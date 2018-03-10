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

// 给定一个单链表中的一个等待被删除的节点(非表头或表尾)。请在在O(1)时间复杂度删除该链表节点。
// 讲的是一个小技巧：就是把下一个节点的内容复制到要删除的节点上，这样就不需要改变要删除节点的前驱的内容，也就不需要O(n)来查找前驱


// Definition of ListNode
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
    /*
     * @param node: the node in the list should be deletedt
     * @return: nothing
     */
    void deleteNode(ListNode * node) {
        // write your code here


        if (node == NULL) {
            return;
        }

        auto next = node->next;

        if (next == NULL) {
            // 这个地方仍然要遍历找到前驱节点 ！！！就懒得写了
            delete node;
            return;
        }

        node->val = next->val;
        node->next = next->next;

        delete next;                   //！！ 记得删
    }
};