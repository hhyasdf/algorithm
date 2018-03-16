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

// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果
// 。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution {
public:

    bool judge(vector<int> &seq, int begin, int end) {

        if (begin >= end) {
            return true;
        }

        int root = seq[end];
        int root_pos = begin - 1;
        for (int i = end - 1; i >= begin; i--) {
            if (root_pos < begin && seq[i] < root) {        //!!条件判断要全面
                root_pos = i;
            }
            if (root_pos >= begin && seq[i] > root) {
                return false;
            }
        }
        
        return judge(seq, begin, root_pos) && judge(seq, root_pos + 1, end - 1);
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) {
            return false;
        } else if (sequence.size() == 1) {
            return true;
        }

        return judge(sequence, 0, sequence.size() - 1);
    }
};