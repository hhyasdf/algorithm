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


// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:

    TreeNode *ConvertOp(TreeNode *root, TreeNode **last) {
        
        TreeNode *first = root;

        if (root->left != NULL) {
            first = ConvertOp(root->left, last);
        }

        root->left = *last;
        if (*last != NULL) {
            (*last)->right = root;
        }
        *last = root;

        if (root->right != NULL) {
            ConvertOp(root->right, last);
        }

        return first;
    }


    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL) {
            return NULL;
        }

        TreeNode *lastNode = NULL;                     //emmmmmmm，要记得初始化，不然是随机数
        return ConvertOp(pRootOfTree, &lastNode);
    }
};