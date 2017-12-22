#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * the implement of algorithm
 */


// use the Depth-First Search with stack (iterative)

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int num_r = grid.size();
        int num_c = grid[0].size();

        int foot_r = 0, foot_c = 0;
        stack<pair<int, int>> foot_stack;           // ！要先拷贝一个二维bool数组再操作，不改变原数组
                                                    // emmm 加了cout效率变狗爬。。。
        int max = 0, current = 0;

        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                if (grid[r][c] == 1) {
                    current = 0;
                    foot_r = r;
                    foot_c = c;
                    int up, down, left, right;
                    pair<int, int> up_point, down_point, left_point, right_point;

                    while(1) {
                        ++current;
                        grid[foot_r][foot_c] = 0; // visit the node

                        if (foot_r + 1 < num_r) {
                            up = grid[foot_r + 1][foot_c];
                            up_point = {foot_r + 1, foot_c};
                        } else {
                            up = 0;
                        }
                        if (foot_c - 1 >= 0) {
                            left = grid[foot_r][foot_c - 1];
                            left_point = {foot_r, foot_c - 1};
                        } else {
                            left = 0;
                        }
                        if (foot_r - 1 >= 0) {
                            down = grid[foot_r - 1][foot_c];
                            down_point = {foot_r - 1, foot_c};
                        } else {
                            down = 0;
                        }
                        if (foot_c + 1 < num_c) {
                            right = grid[foot_r][foot_c + 1];
                            right_point = {foot_r, foot_c + 1};
                        } else {
                            right = 0;
                        }
                        
                        if (right) {  // right move
                            if (down) {
                                foot_stack.push(down_point);
                            }
                            if (left) {
                                foot_stack.push(left_point);
                            }
                            if (up) {
                                foot_stack.push(up_point);
                            }

                            ++foot_c;
                        } else if (down) {  // down move
                            if (right) {
                                foot_stack.push(right_point);
                            }
                            if (left) {
                                foot_stack.push(left_point);
                            }
                            if (up) {
                                foot_stack.push(up_point);
                            }

                            --foot_r;
                        } else if (left) { // left move
                            if (down) {
                                foot_stack.push(down_point);
                            }
                            if (right) {
                                foot_stack.push(right_point);
                            }
                            if (up) {
                                foot_stack.push(up_point);
                            }

                            --foot_c;
                        } else if (up) {  //  up move
                            if (down) {
                                foot_stack.push(down_point);
                            }
                            if (left) {
                                foot_stack.push(left_point);
                            }
                            if (right) {
                                foot_stack.push(right_point);
                            }

                            ++foot_r;
                        } else if (!foot_stack.empty()) {
                            auto temp = foot_stack.top();
                            foot_stack.pop();

                            while (grid[temp.first][temp.second] == 0) {  // the node in stack probably have alredy been visited
                                if (foot_stack.empty()) break;

                                temp = foot_stack.top();
                                foot_stack.pop();
                            }

                            if (grid[temp.first][temp.second] == 0) break;

                            foot_r = temp.first;
                            foot_c = temp.second;
                        } else break;
                        
                    }

                    if (current > max) {
                        max = current;
                    }
                }
            }
        }

        return max;
    }
};


