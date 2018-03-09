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

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int size = bits.size();

        int i = 0;
        while(i < size){
            if (bits[i] == 1) {
                i += 2;
                if (i >= size) {       // !!
                    return false;
                }
            } else {
                ++i;
            }
        }
        return true;
    }
};