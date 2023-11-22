#include <vector>
#include <chrono>

#include "functions.hpp"

int main()
{
    no_opt::complicatedFunction();
    pass_by_ref::complicatedFunction();
    contiguous_memory::complicatedFunction();
    magic_square_root::complicatedFunction();
    return 0;
}