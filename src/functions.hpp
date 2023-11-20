#pragma once

#include <vector>
#include <cmath>

namespace unopt
{
    double inverseSquareRoot(double argument);
    double someFunction(std::vector<double> arguments, std::vector<double> coefficients, int coefficient_index);
} // namespace unopt

namespace opt
{
    double inverseSquareRoot(double argument);
    double someFunction(std::vector<double> &arguments, std::vector<double> &coefficients, int coefficient_index);
} // namespace opt
