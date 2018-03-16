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
    
    void find(TreeNode *node, int &expect, vector<int> &path, vector<vector<int> > &result) {
        if (node == NULL) {
            return;
        }

        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            int sum = 0;
            for (auto &item : path) {
                sum += item;
            }
            if (sum == expect) {
                result.push_back(path);
            }
            path.pop_back();
            return ;
        }

        find(node->left, expect, path, result);
        find(node->right, expect, path, result);

        path.pop_back();
        
    }

    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> path;
        vector<vector<int> > result;

        find(root, expectNumber, path, result);

        return result;
    }
};