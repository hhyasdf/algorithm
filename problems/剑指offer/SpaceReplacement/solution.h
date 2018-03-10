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

// 设计一种方法，将一个字符串中的所有空格替换成 %20 。
// 你可以假设该字符串有足够的空间来加入新的字符，且你得到的是“真实的”字符长度。

// 对于字符串"Mr John Smith", 长度为 13

// 替换空格之后，参数中的字符串需要变为"Mr%20John%20Smith"，并且把新长度 17 作为结果返回。

class Solution {
public:
    /*
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // write your code here

        if (string == nullptr || length == 0) {
            return 0;
        }

        int p1, p2, space_count, last_space, result_len;
        p1 = length - 1;
        p2 = 0;

        for (; p2 < length; ++p2) {
            if (string[p2] == ' ') {
                ++space_count;
            }
        }
        p2 = p1;

        result_len = length + space_count*2;

        for (; p2 >= 0; --p2) {
            if (string[p2] == ' ') {
                int k1 = p1 + space_count*2;
                int k2 = p1;
                for (; k2 > p2; --k2, --k1) {
                    string[k1] = string[k2];
                }
                --space_count;
                string[k1] = '0';
                string[--k1] = '2';
                string[--k1] = '%';

                p1 = p2 - 1;
            }
        }

        return result_len;
    }
};