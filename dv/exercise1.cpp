#include <iostream>
#include "VExercise1.h"

int main() {
    VExercise1 model;
    bool test_result = true;  // Start with true (all tests pas>

    // Iterate through each operation case
    // 0: ^ (XOR), 1: << (left shift), 2: % (modulus), 3: ~ (bi>    for (int op = 0; op < 4; op++) {
        // Iterate through each value of a
        for (int a = 0; a < 256; a++) {
            // Iterate through each value of b
            for (int b = 0; b < 256; b++) {
                model.a = a;
                model.b = b;
                model.op = op;

                // Commit inputs
                model.eval();  // Evaluate the model based on t>
                // Check the result based on the operation
                switch (op) {
                    case 0:  // XOR
                        if (model.out != (a ^ b)) {
                            test_result = false;
                            std::cout << "Test failed for XOR a>                        }
                        break;
                    case 1:  // Left shift (only valid when b <>
                        if (b < 8) {
                            if (model.out != (a << b)) {
                                test_result = false;
                                std::cout << "Test failed for <>                            }
                        }
                        break;
                    case 2:  // Modulus
                        if (b != 0) {  // Avoid division by zero
                            if (model.out != (a % b)) {
                                test_result = false;
                                std::cout << "Test failed for %>                            }
                        }
                        break;
                    case 3:  // Bitwise NOT (unary operator, ig>
                        if (model.out != (~a)) {
                            test_result = false;
                            std::cout << "Test failed for ~ at >                        }
                        break;
                }
            }
        }
    }
 if (test_result) {
        std::cout << "All tests passed!" << std::endl;
        return 0;  // Return 0 if no tests failed
    } else {
        std::cout << "Some tests failed." << std::endl;
        return 1;  // Return 1 if there was at least one failure    }
}
