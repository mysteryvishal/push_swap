*This project has been created as part of the 42 curriculum by vmistry.*

# push_swap

push_swap is a 42 School algorithmic project focused on sorting integers using two stacks and a strictly limited set of operations. The goal is not just correctness, but *optimisation* – producing the smallest possible sequence of instructions. This project explores data structures, algorithmic complexity, and practical trade-offs between different sorting strategies, all implemented in C under tight constraints.

---
## Description

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
A: [3] -> [1]    B: [5] -> [2]
After pa:
A: [5] -> [3] -> [1]    B: [2]
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

- [push_swap visualiser](https://github.com/o-reo/push_swap_visualizer) — animate the instruction sequence visually
- [Sorting algorithm complexity](https://www.bigocheatsheet.com/) — complexity reference
- [42 Norm](https://github.com/42School/norminette) — norminette style enforcer used throughout

### AI Usage

Claude (claude.ai/claude-code) was used during this project for:

- **Understanding** — explaining algorithmic concepts (greedy selection, cost calculation for combined rotations) and helping reason through edge cases
- **Debugging** — identifying issues in sorting logic and parsing validation
- **README** — drafting and structuring this file

All generated code was reviewed, tested, and understood before inclusion. No code was copied without being able to explain it fully.

