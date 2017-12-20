#include <iostream>

#ifndef SIMPLE_TEST_HEAD
#define SIMPLE_TEST_HEAD

/*
 * asume the answer and result sequence have size() method
 */
#define TEST_SEQ_EQUAL(target, result) \
do { \
    if(target.size() != result.size()) { \
        std::cout << "size error!" << std::endl; \
    } else { \
        auto seq_size = target.size(); \
        bool flag = true; \
        \
        std::cout << "target sequence: ["; \
        for (int i = 0; i < seq_size; ++i) { \
            auto temp = *(target.begin() + i); \
            if (i != seq_size - 1) { \
                std::cout << temp << ", "; \
            } else { \
                std::cout << temp; \
            } \
        } \
        std::cout << "]" << endl; \
        \
        std::cout << "result sequence: ["; \
        for (int i = 0; i < seq_size; ++i) { \
            auto temp = *(result.begin() + i); \
            if (*(target.begin() + i) != temp) { \
                std::cout << "\033[31m" << temp << "\033[0m" << ", "; \
                flag = false; \
            } else { \
                if (i != seq_size - 1) { \
                    std::cout << temp << ", "; \
                } else { \
                    std::cout << temp; \
                } \
            } \
        } \
        std::cout << "]" << endl; \
        std::cout << "answer is " << boolalpha << flag << std::endl; \
        std::cout << endl; \
    } \
}while(0)

/*
 * string or number test 
 * the target and result is a single value that support = operation
 */
#define TEST_VAL_EQUAL(target, result) \
do{\
    std::cout << "target value: " << target << std::endl; \
    if (target != result) { \
        std::cout << "result value: " << "\033[31m" << result << "\033[0m" << std::endl; \
    } else { \
        std::cout << "result value: " << result << std::endl; \
    } \
    std::cout << "answer is " << boolalpha << (target == result) << std::endl; \
    std::cout << endl; \
}while(0)

#define START_TEST() int main()

#endif