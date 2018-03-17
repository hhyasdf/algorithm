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


// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

class Solution {
public:
    
    int partition(vector<int> &numbers, int begin, int end) {
        int start = begin - 1, tmp;
        int base = numbers[end];
        
        for (int i = begin; i < end; i++) {
            if (numbers[i] <= base) {
                ++start;
                tmp = numbers[start];
                numbers[start] = numbers[i];
                numbers[i] = tmp;
            }
        }

        tmp = numbers[++start];
        numbers[start] = numbers[end];
        numbers[end] = tmp;

        return start; 
    }
    
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        
        int pos = 0, middle = numbers.size()/2;
        int end = numbers.size() - 1, start = 0;

        pos = partition(numbers, start, end);
        while (pos != middle) {
            if (pos > middle) {
                end = pos - 1;
            } else {
                start = pos + 1;
            }
            pos = partition(numbers, start, end);
        }

        int result = numbers[pos], count = 0;
        for (int i = 0; i < numbers.size(); i++) {          //有可能不存在这种数，要检查
            if (numbers[i] == result) {
                ++count;
            }
        }
        
        if (count > middle) {
            return result;
        }
        return 0;
    }
};