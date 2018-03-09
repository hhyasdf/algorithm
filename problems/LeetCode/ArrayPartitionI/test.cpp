#include "../../include/test.h"
#include "solution.h"

/*
 * create sample input and output
*/

CREAETE_SAMPLE(input, vector<int>){
    {1, 4, 3, 2}
};
CREAETE_SAMPLE(output, int){
    4
};

START_TEST(){
    Solution solution;
    auto sample_size = input.size();
    
    if (sample_size != output.size()){
        cout << "sample inputs and outputs have different size!" << endl;
    }

    auto sample_input_begin = input.begin();
    auto sample_output_begin = output.begin();
    
    for (int i = 0; i < sample_size; ++i) {
        cout << "Test " << i + 1 << ":" << endl;

        PRINT_SEQ(*(sample_input_begin + i), "input: ");
        // PRINT_VAL(*(sample_input_begin + i), "input: ");

        TEST_VAL_EQUAL(*(sample_output_begin + i), solution.arrayPairSum(*(sample_input_begin + i)));
        /*
         * execute the algorithm
         */

    }
}