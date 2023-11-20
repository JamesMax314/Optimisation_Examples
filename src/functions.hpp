#pragma once

#include <vector>
#include <cmath>
#include <bit>
#include <limits>
#include <cstdint>

namespace no_opt
{
    float inverseSquareRoot(float argument);
    float someFunction(std::vector<float> arguments, std::vector<float> coefficients, int coefficient_index);
    void complicatedFunction();
}

namespace level_one
{
    float inverseSquareRoot(float argument);
    float someFunction(std::vector<float> &arguments, std::vector<float> &coefficients, int coefficient_index);
    void complicatedFunction();
} // namespace unopt

namespace level_two
{
    float inverseSquareRoot(float argument);
    float someFunction(std::vector<float> &arguments, std::vector<float> &coefficients, int coefficient_index);
    void complicatedFunction();
} // namespace opt

namespace level_three
{
    float inverseSquareRoot(float argument);
    float someFunction(std::vector<float> &arguments, std::vector<float> &coefficients, int coefficient_index);
    void complicatedFunction();
} // namespace opt
