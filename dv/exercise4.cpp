#include <VExercise4.h>

int main() {
  VExercise4 model;
    // Initialize variables
    model->cs = 0;
    model->sel = 0;  // Initialize select
    model->alpha = 1;
    model->beta = 2;
    model->gamma = 3;

    // Test 1: cs = 0 (Don't Care for sel)
    for (int i = 0; i < 4; i++) {
        model->sel = i;
        model->eval();
        if (model->out != 0) {
            printf("Error: Output should be 0 when cs = 0, sel = %d\n", i);
            return 1;
        }
    }

    // Test 2: cs = 1, sel = 0 -> out = alpha
    model->cs = 1;
    model->sel = 0;
    model->eval();
    if (model->out != model->alpha) {
        printf("Error: Output should be alpha when sel = 0\n");
        return 1;
    }
    // Test 3: cs = 1, sel = 1 -> out = beta
    model->sel = 1;
    model->eval();
    if (model->out != model->beta) {
        printf("Error: Output should be beta when sel = 1\n");
        return 1;
    }

    // Test 4: cs = 1, sel = 2 -> out = gamma
    model->sel = 2;
    model->eval();
    if (model->out != model->gamma) {
        printf("Error: Output should be gamma when sel = 2\n");
        return 1;
    }

    // Test 5: cs = 1, sel = 3 -> out = alpha & (beta | gamma)
    model->sel = 3;
    model->eval();
    if (model->out != (model->alpha & (model->beta | model->gamma))) {
        printf("Error: Output should be alpha & (beta | gamma) when sel = 3\n");
        return 1;
    }

    printf("All tests passed.\n");
    delete model;
    return 0;

}
