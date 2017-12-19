#include <iostream>

#define TEST_SEQ_EQUAL(answer, result, size) \
for (int i = 0; i <= size; ++i) {\
}

#define TEST_NUM_EQUAL(answer, result) \
do{\
    std::cout << "target: " << answer << std::endl \
    std::cout << "result: " << result << std::endl \
    std::cout << "answer is: " << (answer == result) << std::endl \
}while(0)