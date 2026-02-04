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



---
## Resources



### AI Usage


