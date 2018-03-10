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


//根据前序遍历和中序遍历树构造二叉树.


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
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here

        if (inorder.size() == 0) {
            return NULL;
        }

        TreeNode *root = new TreeNode(inorder[0]);

        auto index = inorder.begin();           //前序遍历中右子树的第一个元素
        auto root_p_post = postorder.begin();   //中序遍历中root的位置
        
        while (*root_p_post != inorder[0] && root_p_post != postorder.end()) {
            ++root_p_post;
        }

        index = index + (root_p_post - postorder.begin()) + 1;

        auto left_inorder = vector<int>(inorder.begin() + 1, index);
        auto left_postorder = vector<int>(postorder.begin(), root_p_post);

        auto right_inorder = vector<int>(index, inorder.end());
        auto right_postorder = vector<int>(root_p_post + 1, postorder.end());

        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);

        return root; 
    }
};