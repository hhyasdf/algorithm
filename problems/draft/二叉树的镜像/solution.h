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

// 操作给定的二叉树，将其变换为源二叉树的镜像。


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
    void Mirror(TreeNode *pRoot) {

        if (pRoot == NULL) {
            return;
        }

        auto tmp = pRoot->right;                 //　只能前序或者后序，中序会对左子树换两次
        pRoot->right = pRoot->left;
        pRoot->left = tmp;
        
        if (pRoot->left != NULL) {
            Mirror(pRoot->left);
        }

        if (pRoot->right != NULL) {
            Mirror(pRoot->right);
        }
    }
};