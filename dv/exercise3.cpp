#include <VExercise3.h>

int main() {
  VExercise3 model;

  uint8_t a, out;
  uint16_t b, c, d;

  // Init clk/reset
  bool clk = 0;
  model->reset = 1; // Reset high
  model->a = 0;
  model->b = 0b10101010;
  model->c = 0b11001100;
  model->a_in = 0xAA;
  model->b_in = 0x55;


  auto toggleClock = [&]() {
        clk = !clk;
        model->clk = clk;
        model->eval();
  }

  auto step = [&]() {
        toggleClock();
        toggleClock();
  }
  model->a = 0;
  step();
  if (model->d != (0b00 << 6 | (model->b & 0x07) << 3 | (model->c & 0x07))) {
        printf("Error: Mystery1 failed for a = 0\n");
        return 1;
  }

  model->a = 1;
  step();
  if (model->d != (0b01 << 6 | (model->c & 0x07) << 3 | (model->b & 0x07))) {
        printf("Error: Mystery1 failed for a=1\n");
        return 1;
   }

    // Test case for a = 2
    model->a = 2;
    step();
    if (model->d != model->b) {
        printf("Error: Mystery1 failed for a=2\n");
        return 1;
    }

    // Test case for a = 3
    model->a = 3;
    step();
    if (model->d != model->c) {
        printf("Error: Mystery1 failed for a=3\n");
        return 1;
    }

   // Test Mystery2
    // Set reset high and test initialization
    model->reset = 1;
    step();
    if (model->out != ((model->b_in << 8) | model->a_in)) {
        printf("Error: Mystery2 initialization failed\n");
        return 1;
    }

    // Now cycle through states with reset low
    model->reset = 0;

    // State 0
    step();
    if (model->out != ((model->a_in << 8) | (model->out & 0xFF))) {
        printf("Error: Mystery2 failed at state 0\n");
        return 1;
    }

    // State 1
    step();
    if (model->out != ((model->out >> 8) | (model->b_in << 8))) {
        printf("Error: Mystery2 failed at state 1\n");
        return 1;
    }

    // State 2
    step();
    if (model->out != ((model->out & 0xFF) << 8) | (model->out >> 8)) {
        printf("Error: Mystery2 failed at state 2\n");
        return 1;
    }

    // State 3
    step();
    uint16_t out_tmp = ((model->out & 0xF) << 12) | ((model->out >> 4) & 0xF) << 8 |
                       ((model->out >> 8) & 0xF) << 4 | ((model->out >> 12) & 0xF);
    if (model->out != out_tmp) {
        printf("Error: Mystery2 failed at state 3\n");
        return 1;
    }

    // State 4
    step();
    if (model->out != (0x0 | __builtin_popcount(model->out) & 1)) {
        printf("Error: Mystery2 failed at state 4\n");
        return 1;
    }

    printf("All tests passed.\n");
    delete model;
    return 0;


}
