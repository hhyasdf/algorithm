#include <iostream>

/*
 * asume the answer and result sequence have size() function
 */
#define TEST_SEQ_EQUAL(target, result) \
do { \
    if(target.size() != result.size()) { \
        std::cout << "size error!" << std::endl; \
    } else { \
        auto seq_size = target.size(); \
        for (int i = 0; i <= seq_size; ++i) { \
            \
        } \
    } \
}while(0)


#define TEST_NUM_EQUAL(target, result) \
do{\
    std::cout << "target: " << answer << std::endl \
    std::cout << "result: " << result << std::endl \
    std::cout << "answer is: " << (answer == result) << std::endl \
}while(0)