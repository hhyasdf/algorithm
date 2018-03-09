#include "../../../include/test.h"
#include "solution.h"

/*
 * create sample input and output
*/

CREAETE_SAMPLE(input, vector<vector<int>>){
    {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    },
    {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    }
};
CREAETE_SAMPLE(output, int){
    7, 7
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

        TEST_VAL_EQUAL(*(sample_output_begin + i), solution.minPathSum(*(sample_input_begin + i)));
        // TEST_SEQ_EQUAL(*(sample_output_begin + i), solution.algorithm(*(sample_input_begin + i)));
        
        /*
         * execute the algorithm
         */

    }
}