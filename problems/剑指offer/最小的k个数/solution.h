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



// 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

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

    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k) {

        if (numbers.size() < k || k == 0) {
            return vector<int>();
        }

        int pos = 0;
        int end = numbers.size() - 1, start = 0;

        pos = partition(numbers, start, end);
        while (pos != k - 1) {                       //这里要是k-1，因为当k==n时会死循环，pos始终要小于n
            if (pos > k - 1) {
                end = pos - 1;
            } else {
                start = pos + 1;
            }
            pos = partition(numbers, start, end);
        }

        vector<int> result(numbers.begin(), numbers.begin() + k);  //注意迭代器的范围
        sort(result.begin(), result.end());

        return result;
    }
};