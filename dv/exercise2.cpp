#include <iostream>
#include "VExercise2.h"

int main() {
    VExercise2 model;
    bool test_result = true;  // Assume all tests pass initially

    // Test 1: Initialize with a simple value and check reset b>
    uint16_t init_value = 0x0001;  // A simple initial value
    model.init = init_value;

    // Apply reset
    model.reset = 1;
    model.clk = 0;
    model.eval();  // Evaluate the model with reset active
    model.clk = 1;
    model.eval();  // Evaluate the model with rising clock edge

    // Check if out is equal to ~init_value
    if (model.out != static_cast<uint16_t>(~init_value)) {
        std::cout << "Test failed: Initialization with init = ">                  << ", expected: " << static_cast<uint16_t>(~i>                  << ", got: " << model.out << std::endl;
        test_result = false;
    }

    // Release reset
    model.reset = 0;
    model.clk = 0;
    model.eval();
    model.clk = 1;
    model.eval();

    // Test LFSR behavior for a few clock cycles
    for (int i = 0; i < 10; ++i) {
        // Clock the LFSR
        model.clk = 0;
        model.eval();  // Evaluate the model on the falling edg>        model.clk = 1;
        model.eval();  // Evaluate the model on the rising edge>

        // Manually compute the expected next value
        uint16_t expected = (model.out << 1) | ((model.out >> 1>

        // Compare with the actual output
        if (model.out != expected) {
            std::cout << "Test failed: LFSR mismatch at cycle ">                      << ", expected: " << std::hex << expected
                      << ", got: " << model.out << std::endl;
            test_result = false;
        }
    }

    // Test with a different initialization value (e.g., all 1s)    init_value = 0xFFFF;
    init_value = 0xFFFF;
    model.init = init_value;

    // Apply reset
    model.reset = 1;
    model.clk = 0;
    model.eval();
    model.clk = 1;
    model.eval();

    // Check if out is equal to ~init_value
    if (model.out != static_cast<uint16_t>(~init_value)) {
        std::cout << "Test failed: Initialization with init = ">                  << ", expected: " << static_cast<uint16_t>(~i>                  << ", got: " << model.out << std::endl;
        test_result = false;
    }

    // Release reset and clock for a few cycles
    model.reset = 0;
    for (int i = 0; i < 10; ++i) {
        model.clk = 0;
        model.eval();
        model.clk = 1;
        model.eval();

        // Compute expected next value for this init_value
        uint16_t expected = (model.out << 1) | ((model.out >> 1>

        if (model.out != expected) {
            std::cout << "Test failed: LFSR mismatch with init=>                      << ", expected: " << std::hex << expected
                      << ", got: " << model.out << std::endl;
            test_result = false;
        }
    }

    // Final test result
    if (test_result) {
        std::cout << "All tests passed!" << std::endl;
        return 0;  // Return 0 if all tests passed
    } else {
        std::cout << "Some tests failed." << std::endl;
        return 1;  // Return 1 if any test failed
    }
}

