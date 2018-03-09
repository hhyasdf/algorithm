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

//单例模式的写法，这里写懒汉
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */

    //static Solution *instance; 这样只是一个声明，并且c++的类静态成员一般不能在类内初始化，
    //在未定义的情况下使用这个名字会发生链接错误，因为这个名字是未定义的(U)弱符号

    static Solution* getInstance() {
        // write your code here
        static Solution *instance = NULL;            //！！注意单例模式的写法，这样定义的是一个全局变量，而不是一个static member
                                                     //！！只能这么写
        if (instance == NULL) {
            instance = new Solution();
        }
        return instance;
    }
};

//Solution* Solution::instance = NULL; 这样才能提供一个定义，并且只能在一个源文件里定义

//并且如果一个源文件的全局变量用到另一个源文件的全局变量来初始化的话，无法保证两个编译模块中的全局变量的初始化顺序，
//可能会导致一个全局变量使用另一个源文件中未初始化的全局变量来初始化。。。见effective cpp
//如果用类外定义的写法的话，在饿汉写法（返回引用）中会出现上述问题，所以只能这么写



//饿汉写法
// class Solution {
// public:
//     /**
//      * @return: The same instance of this class every time
//      */

//     static Solution* getInstance() {
//         // write your code here
        
//         static Solution *instance=new Solution();
    
//         return instance;
//     }
// };