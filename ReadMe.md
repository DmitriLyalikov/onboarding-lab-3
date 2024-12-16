# Week 3 Lab: Verification
### Notes on Testing Strategy for Exercise 2

**Testing Strategy**:  
For Exercise 2, I adopted a strategy that combines **representative test cases** with **randomized testing** to ensure coverage without testing the entire input space, which is computationally infeasible. The key steps in this strategy include:  

1. **Boundary Testing**:  
   - Selected minimum, maximum, and edge values for each input to validate behavior at limits.
   - This ensures robustness against corner cases.

2. **Randomized Input Testing**:  
   - Generated a set of random input combinations to cover a broader spectrum of scenarios.
   - Randomization helps uncover unexpected bugs that deterministic tests might miss.

3. **Known Edge Cases**:  
   - Included specific input values based on the module's expected behavior, such as transitions or special cases.
   - These were derived from analyzing the module’s functional description.

**Decisions and Rationale**:  
- Focused on **functional correctness** while maintaining a reasonable execution time for tests.  
- Balanced **manual input selection** and **randomized testing** for thorough yet efficient validation.  
- Assumed the module’s correctness based on its documentation and focused on identifying unexpected behavior in future modifications.

---

### Notes on Testing a Don’t Care (Exercise 4)

**How Testing a Don’t Care Works**:  
A "Don't Care" (denoted as `X`) means the value of an input should have no impact on the output. To test this:  
1. **Override Conditions**: Ensure other inputs (e.g., `cs`) enforce behavior where the "Don't Care" input is irrelevant.  
2. **Randomize "Don't Care" Values**: Assign various random values to the "Don't Care" input and verify the output remains unchanged.

**Steps to Ensure Proper Testing**:  
- **Isolate the Condition**: Test scenarios where the "Don't Care" input is irrelevant. For example:
  - For `cs = 0`, the output should always be `0` regardless of the `sel` value.
- **Stress Testing**: Assign extreme or randomized values to the "Don't Care" input and confirm no effect on the output.
- **Assertions**: Use assertions to verify that the output is independent of the "Don't Care" input under the specified condition.

**Key Considerations**:  
- Avoid assumptions about "Don't Care" behavior being naturally handled; explicitly verify independence.  
- Ensure the testing setup mimics realistic conditions, as improper handling of "Don't Care" inputs can lead to unexpected behavior in hardware.

