*This project has been created as part of the 42 curriculum by lmuler-f*

# Push_Swap

## Description
`push_swap` is a core algorithmic project from the 42 curriculum focused on sorting integers using a highly constrained environment. The program must sort a stack of integers using **two stacks (A and B)** and a **restricted set of operations**, while producing the **smallest possible number of moves**.

This project emphasizes **algorithmic thinking**, **complexity analysis**, and **optimization under constraints**, rather than raw sorting itself.

## Core Concepts
- **Stacks:** Manipulation of two stacks using a limited instruction set.
- **Indexing:** Normalizing values to simplify comparisons and positioning.
- **Chunk-based strategies:** Dividing data to reduce problem complexity.
- **Cost calculation:** Measuring the cost of moving elements between stacks.
- **Operation optimization:** Using combined rotations to reduce total moves.

## Algorithm Justification (Turkish Method)
The chosen strategy is the **Turkish algorithm**, a well-known and efficient approach for the `push_swap` project.  
It works by **splitting the problem into manageable steps**, minimizing unnecessary operations.

### Algorithm Steps

1. **Parsing and Validation**  
   All arguments are validated to ensure they are valid integers, within `int` limits, and without duplicates.

2. **Indexing**  
   Each value is assigned an index based on its position in the sorted array.  
   This allows comparisons to be made using indexes instead of raw values.

3. **Push to B (Chunk Strategy)**  
   Approximately half of the elements (those with the smallest indexes) are pushed from stack A to stack B.  
   This acts as a **single large chunk**, reducing the size of stack A and simplifying the sorting process.

4. **Small Case Handling**  
   When only **three elements remain in stack A**, they are sorted directly using a minimal and deterministic set of operations.

5. **Reinsertion from B to A**  
   While stack B is not empty:
   - The correct **target position** in stack A is calculated for each element in B.
   - `cost_a` and `cost_b` are computed to measure the number of moves required.
   - The element with the **lowest total insertion cost** is selected.
   - **Combined rotations** (`rr` / `rrr`) are used whenever possible to reduce the total number of operations.
   - The element is pushed back to stack A.

6. **Final Shift**  
   Once stack B is empty, stack A is rotated until the element with the **smallest index** is positioned at the top.

This method provides a good balance between simplicity, performance, and explainability during evaluation.

## Instructions

### Compilation
The project must be compiled using `cc` with the flags `-Wall -Wextra -Werror`.

Run the Makefile
```bash
make
```
### Execution
```bash
./push_swap 3 2 1 6 5
```
The program outputs a sequence of instructions that sorts the stack.
### Example
```bash
./push_swap 2 1 3
sa
```
### Checker Usage
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux.sh $ARG
```
If the output is `OK`, the sorting instructions are correct.

## Error Handling

The program prints `Error\n` to the stderr when:
-	An argument is not a valid integer
-	Executes them on the stacks
-	Outputs `OK` if stack A is sorted and B is empty, otherwise `KO`

## Resources
During this project, external resources were used to reinforce understanding of algorithms and memory behavior.

Links:

-	[Stacks Understanding](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
-	[Blog of a 42 Student - A. Yigit Ogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
-	[Youtube Video](https://www.youtube.com/watch?v=wRvipSG4Mmk&t=1s)

## AI Usage
 AI tools were used responsibly to:
-	Clarify algorithmic concepts
-	Review logic and edge cases
-	Assist in documentation writing

All generated content was reviewed, adapted, and fully understood before being used and, more importantly, no ready‑made answers were used.

## Final Notes
This project was essential for developing: 
-	Algorithmic reasoning
-	Optimization strategies
-	Confidence explaining complex logic
-	Strong foundations in C and data structures

#

Thank you for taking the time to read this README until here :D