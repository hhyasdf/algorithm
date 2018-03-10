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


// 有两个不同大小的二叉树： T1 有上百万的节点； T2 有好几百的节点。请设计一种算法，判定 T2 是否为 T1的子树。
// 若 T1 中存在从节点 n 开始的子树与 T2 相同，我们称 T2 是 T1 的子树。
// 也就是说，如果在 T1 节点 n 处将树砍断，砍断的部分将与 T2 完全相同。

// 不是树的子结构，而是子树，要注意


// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


class Solution {
public:
    /**
     * @param T1: The roots of binary tree T1.
     * @param T2: The roots of binary tree T2.
     * @return: True if T2 is a subtree of T1, or false.
     */

    bool isRealSubtree(TreeNode * T1, TreeNode * T2) {
        
        if (T1->val != T2->val) {
            return false;
        }

        if (T2->left != NULL) {
            if (T1->left == NULL) {
                return false;
            }
            
            if(!isRealSubtree(T1->left, T2->left)) {
                return false;
            }
        } else {
            if (T1->left != NULL) {           // ！！去掉就变成了子结构
                return false;
            }
        }

        if (T2->right != NULL) {
            if (T1->right == NULL) {
                return false;
            }

            if(!isRealSubtree(T1->right, T2->right)) {
                return false;
            }
        } else {
            if (T1->right != NULL) {         //！！去掉就变成了子结构
                return false;
            }
        }

        return true;
    }


    bool isSubtree(TreeNode * T1, TreeNode * T2) {
        // write your code here

        if (T2 == NULL) {
            return true;           //！！
        }

        if (T1 == NULL) {
            return false;
        }
        
        queue<TreeNode *> recorder;
        recorder.push(T1);

        while(!recorder.empty()) {
            auto item = recorder.front();
            recorder.pop();

            if (item == NULL) {
                continue;
            } else {
                recorder.push(item->left);
                recorder.push(item->right);

                if (isRealSubtree(item, T2)) {
                    return true;
                }
            }
        }

        return false;
    }
};