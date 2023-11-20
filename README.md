# Optimisation_Examples

## Level 1 - Easy
- [ ] Compiler Optimisation (-O2 -O3);
- [ ] Avoid data copying (Pass by referance);

## Level 2 - More Effort
- [ ] Use cach-friendly data structures (contiguous in memory);
- [ ] Use stack varibles where possible (allocation and deallocation is faster on stack);
- [ ] Reduce number of function calls (inline small functions);

## Level 3 - Considerable Effort
- [ ] Parallelisation (OpenMP MPI GP-GPU);
- [ ] Algorithmic optimisation.

## Compilation
```bash
g++ ./src/main.cpp ./src/functions.cpp -o main -I ./src/ -O3 -std=c++20 -fopenmp
```
