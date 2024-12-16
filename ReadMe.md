# Week 3 Lab: Verification
### Notes on Testing Strategy for Exercise 2

**MN 1: Testing Strategy Based on Exercise 2**:  
For Exercise 2, I adopted a strategy that combines **representative test cases** with **randomized testing** to ensure coverage without testing the entire input space, which is computationally infeasible because of the large input spac. 

1. **Boundary Testing**:  
   - Selected minimum, maximum, and edge values for each input to validate behavior at limits.
   - Handles corner cases

2. **Randomized Input Testing**:  
   - Generated a set of random input combinations.
   - Randomization helps uncover unexpected bugs.


### MN 2: Notes on Testing a Don’t Care (Exercise 4)

A "Don't Care" means the value of an input should have no impact on the output. To test this:  
1. **Override Conditions**: Ensure other inputs (e.g., `cs`) enforce behavior where the "Don't Care" input is irrelevant.  
2. **Randomize "Don't Care" Values**: Assign various random values to the "Don't Care" input and verify the output remains unchanged.
ues to the "Don't Care" input and confirm no effect on the output.
- **Assertions**: Use assertions to verify that the output is independent of the "Don't Care" input under the specified condition.

