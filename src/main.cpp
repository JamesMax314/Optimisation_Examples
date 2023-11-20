#include <vector>
#include <chrono>

#include "functions.hpp"

int main()
{
    unsigned int number_of_coefficients = 1e6;
    unsigned int number_of_arguments = 1e4;

    std::vector<double> arguments(number_of_arguments);
    std::vector<double> coefficients(number_of_coefficients, 0);
    std::vector<double> results(number_of_arguments);

    for (int i=0; i<number_of_arguments; i++)
    {
        arguments.at(i) = i*i;
    }

    for (int i=0; i<number_of_coefficients; i++)
    {
        coefficients.at(i) = i;
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i=0; i<number_of_arguments; i++)
    {
        results.at(i) = opt::someFunction(arguments, coefficients, i);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_taken_chrono = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    double time_taken = time_taken_chrono.count();

    printf("Time taken: %f s \n", time_taken/1e6);
    return 0;
}