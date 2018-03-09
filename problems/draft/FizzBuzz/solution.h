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

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A list of strings.
     */

    string itoa(int n) {
        char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string res;
        while (n != 0) {
            res += nums[n%10];
            n /= 10;
        }
        reverse(res.begin(), res.end());

        return res;
    }
    
    vector<string> fizzBuzz(int n) {
        // write your code here

        if (n < 1) {
            return vector<string>();
        }

        vector<string> result;

        for (int i=1; i<=n; i++) {
            if (i%3 == 0 && i%5 == 0) {
                result.push_back("fizz buzz");        
            } else if (i%3 == 0) {
                result.push_back("fizz");
            } else if (i%5 == 0) {
                result.push_back("buzz");
            } else {
                result.push_back(itoa(i));
            }
        }

        return result;
    }
};