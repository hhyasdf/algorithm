#include <iostream>

#ifndef SIMPLE_TEST_HEAD
#define SIMPLE_TEST_HEAD

/*
 * asume the sequence is container
 */
#define TEST_SEQ_EQUAL(t, r) \
do { \
    auto target = t; \
    auto result = r; \
    if(target.size() != result.size()) { \
        std::cout << "error size: " << result.size() << std::endl; \
        std::cout << endl; \
    } else { \
        auto seq_size = target.size(); \
        bool flag = true; \
        \
        std::cout << "target sequence: ["; \
        auto target_begin = terget.begin(); \
        for (int i = 0; i < seq_size; ++i) { \
            auto temp = *(target_begin + i); \
            if (i != seq_size - 1) { \
                std::cout << temp << ", "; \
            } else { \
                std::cout << temp; \
            } \
        } \
        std::cout << "]" << endl; \
        \
        std::cout << "result sequence: ["; \
        auto result_begin = result.begin(); \
        for (int i = 0; i < seq_size; ++i) { \
            auto temp = *(result_begin + i); \
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
#define TEST_VAL_EQUAL(t, r) \
do{\
    auto target = t; \
    auto result = r; \
    std::cout << "target value: " << target << std::endl; \
    if (target != result) { \
        std::cout << "result value: " << "\033[31m" << result << "\033[0m" << std::endl; \
    } else { \
        std::cout << "result value: " << result << std::endl; \
    } \
    std::cout << "answer is " << boolalpha << (target == result) << std::endl; \
    std::cout << endl; \
}while(0)

/*
 * print a sequence with message
 */
#define PRINT_SEQ(sequence, message) \
do{ \
    auto seq = sequence; \
    auto seq_begin = seq.begin(); \
    std::cout << message << "["; \
    for (int i = 0; i < seq.size(); ++i) { \
        auto temp = *(seq_begin + i); \
        if (i != seq.size() - 1) { \
            std::cout << temp << ", "; \
        } \
    } \
    std::cout << "]" << endl; \
}while(0)

/*
 * print single number or string
 */
#define PRINT_VAL(v, message) \
do{ \
    auto value = v; \
    std::cout << message << value << endl; \
}


#define START_TEST() int main()

#define CREAETE_SAMPLE(name, type) std::vector<type> name = 

#endif