# Optimisation_Examples

## Major Speed Up
- [ ] Compiler Optimisation (Magic);
- [ ] Pass by reference;
- [ ] Parralelism (OpenMP MPI GP-GPU);
- [ ] Algorithmic optimisation.

## Other Considerations
- [ ] Use cach-friendly data structures (contiguous in memory);
- [ ] Use stack varibles where possible (allocation and deallocation is faster on stack);
- [ ] Reduce number of function calls (inline small functions);

## Compilation
```bash
g++ ./src/main.cpp ./src/functions.cpp -o main -I ./src/ -O3 -std=c++20 -fopenmp
```
