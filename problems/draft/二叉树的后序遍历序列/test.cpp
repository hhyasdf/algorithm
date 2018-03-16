#include "../../../include/test.h"
#include "solution.h"

/*
 * create sample input and output
*/

CREAETE_SAMPLE(input, vector<int>){
    {4,8,6,12,16,14,10}
};
CREAETE_SAMPLE(output, bool){
    true
};

START_TEST(){
    auto sample_size = input.size();
    
    // if (sample_size != output.size()){
    //     cout << "sample inputs and outputs have different size!" << endl;
    // }

    auto sample_input_begin = input.begin();
    auto sample_output_begin = output.begin();

    for (int i = 0; i < sample_size; ++i) {
        Solution solution;
        cout << "Test " << i + 1 << ":" << endl;

        // PRINT_SEQ(*(sample_input_begin + i), "input: ");
        // PRINT_VAL(*(sample_input_begin + i), "input: ");

        TEST_VAL_EQUAL(*(sample_output_begin + i), solution.VerifySquenceOfBST(*(sample_input_begin + i)));
        // TEST_SEQ_EQUAL(*(sample_output_begin + i), solution.algorithm(*(sample_input_begin + i)));
        
        /*
         * execute the algorithm
         */

    }
}