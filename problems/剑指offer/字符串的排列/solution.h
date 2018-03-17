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


// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

class Solution {
public:

    void printStr(vector<string> &result, string &str, int begin, int end) {
        
        if (begin == end) {

            for (auto &item : result) {
                if (item == str) return;
            }
            result.push_back(str);
            return ;
        }

        for (int i = begin; i <= end; i++) {
            auto tmp = str[i];
            str[i] = str[begin];
            str[begin] = tmp;

            printStr(result, str, begin + 1, end);

            str[begin] = str[i];
            str[i] = tmp;
        }
    }

    vector<string> Permutation(string str) {
        vector<string> result;

        printStr(result, str, 0, str.length() - 1);
        sort(result.begin(), result.end());

        return result;
    }
};