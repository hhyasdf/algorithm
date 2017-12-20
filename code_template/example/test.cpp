#include "../../include/test.h"
#include "solution.h"

/*
 * create sample input and output
*/

CREAETE_SAMPLE(input, vector<int>){

};
CREAETE_SAMPLE(output, int){

};

START_TEST(){
    auto sample_size = input.size();
    
    if (sample_size != output.size()){
        cout << "sample inputs and outputs have different size!" << endl;
    }

    auto sample_input_begin = input.begin();
    for (int i = 0; i < sample_size; ++i) {
        cout << "Test " << i + 1 << ":" << endl;

        PRINT_SEQ(*(sample_input_begin + i), "input: ");
        // PRINT_VAL(*(sample_input_begin + i), "input: ");

        /*
         * execute the algorithm
         */

    }
}