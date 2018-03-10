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


// 写出一个高效的算法来搜索m×n矩阵中的值，返回这个值出现的次数。

// 这个矩阵具有以下特性：

// 每行中的整数从左到右是排序的。
// 每一列的整数从上到下是排序的。
// 在每一行或每一列中没有重复的整数。


// 递归还是太慢了。。。。注意返回的是次数

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */

    int search_op(vector<vector<int>> &matrix, int target, int right_up_vertex_r, int right_up_vertex_d, int &counter) {
        if (right_up_vertex_d == matrix.size() || right_up_vertex_r < 0) {
            return -1;
        }
        
        int vertex = matrix[right_up_vertex_d][right_up_vertex_r];
        if (target > vertex) {
            search_op(matrix, target, right_up_vertex_r, right_up_vertex_d + 1, counter);
        } else if (target < vertex){
            search_op(matrix, target, right_up_vertex_r - 1, right_up_vertex_d, counter);
        } else {
            ++counter;
            search_op(matrix, target, right_up_vertex_r - 1, right_up_vertex_d + 1, counter);  // !!同一行同一列的值不相等
        }
    }

    int searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here

        if (matrix.size() == 0) {
            return 0;
        }

        int counter = 0;
        search_op(matrix, target, matrix[0].size() - 1, 0, counter);

        return counter;
    }
};