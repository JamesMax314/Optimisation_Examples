#pragma once

#include <list>
#include <vector>
#include <cmath>
#include <bit>
#include <limits>
#include <cstdint>

#define NUM_ARGS 1e3;
#define NUM_COEF 1e5;

namespace no_opt
{
    float inverseSquareRoot(float argument);
    float someFunction(std::vector<float> arguments, std::vector<float> coefficients, int coefficient_index);
    void complicatedFunction();
}

namespace pass_by_ref
{
    float inverseSquareRoot(float argument);
    float someFunction(std::vector<float> &arguments, std::vector<float> &coefficients, int coefficient_index);
    void complicatedFunction();
} // namespace unopt

namespace contiguous_memory
{
    float inverseSquareRoot(float argument);
    float someFunction(std::vector<float> &arguments, std::vector<float> &coefficients, int coefficient_index);
    void complicatedFunction();
} // namespace opt

namespace magic_square_root
{
    float inverseSquareRoot(float argument);
    float someFunction(std::vector<float> &arguments, std::vector<float> &coefficients, int coefficient_index);
    void complicatedFunction();
} // namespace opt
