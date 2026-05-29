*This project has been created as part of the 42 curriculum by vmistry.*

# push_swap

push_swap is a 42 School algorithmic project focused on sorting integers using two stacks and a strictly limited set of operations. The goal is not just correctness, but *optimisation* – producing the smallest possible sequence of instructions. This project explores data structures, algorithmic complexity, and practical trade-offs between different sorting strategies, all implemented in C under tight constraints.

---
## Description

push_swap sorts a sequence of integers using exactly two stacks (A and B) and a fixed set of operations. Stack A starts with all input values in arbitrary order; the goal is to return them to stack A in ascending order using the fewest possible operations. Both stacks are implemented as singly linked lists.

### Operations with Linked Lists
**Swap (sa, sb, ss)**
Swap first 2 nodes - just swap their values
```
Before: [3] -> [1] -> [5]
After:  [1] -> [3] -> [5]
```

**Push (pa, pb)**
Remove top node from one stack, add to top of other
```
A: [3] -> [1]
B: [5] -> [2]
After pa:
A: [5] -> [3] -> [1]
B: [2]
```

**Rotate (ra, rb, rr)**
Move top node to bottom
```
Before: [3] -> [1] -> [5] -> NULL
After:  [1] -> [5] -> [3] -> NULL
```

**Reverse Rotate (rra, rrb, rrr)**
Move bottom node to top
```
Before: [3] -> [1] -> [5] -> NULL
After:  [5] -> [3] -> [1] -> NULL
```

### Algorithm
push_swap uses a greedy insertion strategy sometimes called the "Turk algorithm" – not a formal CS algorithm, but a approach optimised specifically for this problem's constraints.

#### Strategy
**Phase 1 – Partition:** Push all elements from A to B, except the last 3. While pushing, keep B in descending order (largest on top) by rotating as needed. This sets up B for cheap insertion back into A.

**Phase 2 – Sort base:** Sort the remaining 3 elements in A with at most 2 operations using hardcoded logic.

**Phase 3 – Greedy insertion:** Repeatedly pick the element in B with the lowest total cost to insert into its correct position in A, then execute that move. Repeat until B is empty.

**Phase 4 – Final rotate:** Rotate A until the minimum element is on top.

#### Cost Calculation

Each element in B has a target position in A (where it must be inserted to maintain sorted order). The cost to move it there is:

- **Cost in B** – rotations needed to bring it to top of B (`rb`/`rrb`)
- **Cost in A** – rotations needed to bring its target to top of A (`ra`/`rra`)
- **Combined cost** – if both rotate in the same direction, `rr`/`rrr` handles both simultaneously, so total cost = `max(cost_a, cost_b)` instead of `cost_a + cost_b`

The element with minimum combined cost is moved first.

#### Complexity

O(n²) – for each of n elements in B, scan all n positions in A to find target. Acceptable at the scale this project targets (≤500 elements).

#### Performance

Tested across 10 random trials per input size:

| Input size | Min  | Avg  | Max  | 5pts threshold |
|------------|------|------|------|----------------|
| 100        | 528  | 563  | 605  | ≤700           |
| 500        | 4977 | 5095 | 5203 | ≤5500          |

Results consistently within the top scoring bracket for both sizes.


---
## Instructions

### Compilation

```bash
make        # build push_swap binary
make clean  # remove object files
make fclean # remove objects + binary
make re     # fclean + build
```

Requires `cc` with `-Wall -Wextra -Werror`. No other dependencies.

### Execution

```bash
./push_swap 3 1 4 1 5 9 2 6       # space-separated args
./push_swap "3 1 4 1 5 9 2 6"     # single quoted string also accepted
```

Prints the sorted instruction sequence to stdout, one op per line.

### Verification

Pipe output into the checker binary to confirm correctness:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./tests/checker_Mac $ARG
# OK = sorted correctly
# KO = instructions don't sort the stack
```

Count operations:

```bash
./push_swap $ARG | wc -l
```

### Error cases

Prints `Error` to stderr and exits on: non-integer input, integer overflow, duplicate values.

---
## Resources

- [Linked List Data Structure](https://www.geeksforgeeks.org/dsa/linked-list-data-structure/) – understanding stack structure
- [Sorting algorithm complexity](https://www.bigocheatsheet.com/) – complexity reference
- [42 Norm](https://github.com/42School/norminette) – norminette enforcer used throughout to check compliance

### AI Usage

Claude (claude.ai/claude-code) was used during this project for:

- **Understanding** – explaining algorithmic concepts (greedy selection, cost calculation for combined rotations) and helping reason through edge cases
- **Debugging** – identifying issues in sorting logic and parsing validation
- **README** – drafting and structuring this file

All generated code was reviewed, tested, and understood before inclusion. No code was copied without being able to explain it fully.
