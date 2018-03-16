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


// 层序遍历打印每个节点

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> result;
        q.push(root);

        while (!q.empty()) {
            auto tmp = q.front();
            if (tmp != NULL) {
                result.push_back(tmp->val);
                q.push(tmp->left);
                q.push(tmp->right);
            }
            q.pop();
        }

        return result;
    }
};