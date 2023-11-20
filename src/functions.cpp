#include "functions.hpp"

inline double unopt::inverseSquareRoot(double argument)
{
    double result = 1/sqrt(argument);
    return result;
}

double unopt::someFunction(std::vector<double> arguments, std::vector<double> coefficients, int coefficient_index)
{
    int num_terms = arguments.size();
    double result = 0;

    for (int i=0; i<num_terms; i++)
    {
        double inverse_square_root = inverseSquareRoot(arguments.at(i));
        result += coefficients.at(coefficient_index);
    }
    return result;
}

inline double opt::inverseSquareRoot(double argument)
{
    double result = 1/sqrt(argument);
    return result;
}

double opt::someFunction(std::vector<double> &arguments, std::vector<double> &coefficients, int coefficient_index)
{
    int num_terms = arguments.size();
    double result = 0;

    for (int i=0; i<num_terms; i++)
    {
        double inverse_square_root = inverseSquareRoot(arguments.at(i));
        result += coefficients.at(coefficient_index);
    }
    return result;
}