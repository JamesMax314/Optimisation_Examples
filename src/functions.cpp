#include "functions.hpp"

namespace no_opt
{
    float inverseSquareRoot(float argument)
    {
        float result = 1/sqrt(argument);
        return result;
    }

    float someFunction(std::vector<float*> arguments, std::vector<float*> coefficients, int coefficient_index)
    {
        int num_terms = arguments.size();
        float result = 0;

        for (int i=0; i<num_terms; i++)
        {
            float inverse_square_root = inverseSquareRoot(*arguments.at(i));
            result += *coefficients.at(coefficient_index);
        }
        return result;
    }

    void complicatedFunction()
    {
        unsigned int number_of_coefficients = NUM_COEF;
        unsigned int number_of_arguments = NUM_ARGS;

        std::vector<float*> arguments(number_of_arguments);
        std::vector<float*> coefficients(number_of_coefficients);
        std::vector<float*> results(number_of_arguments);

        for (int i=0; i<number_of_arguments; i++)
        {
            arguments.at(i) = new float(i*i);
        }

        for (int i=0; i<number_of_coefficients; i++)
        {
            coefficients.at(i) = new float(i);
        }

        auto start_time = std::chrono::high_resolution_clock::now();

        for (int i=0; i<number_of_arguments; i++)
        {
            results.at(i) = new float(someFunction(arguments, coefficients, i));
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto time_taken_chrono = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        double time_taken = time_taken_chrono.count();

        printf("Time taken: %f s \n", time_taken/1e6);

        for (int i=0; i<number_of_arguments; i++)
        {
            delete arguments.at(i);
            delete results.at(i);
        }

        for (int i=0; i<number_of_coefficients; i++)
        {
            delete coefficients.at(i);
        }
    }
}

namespace pass_by_ref
{
    float inverseSquareRoot(float argument)
    {
        float result = 1/sqrt(argument);
        return result;
    }

    float someFunction(std::vector<float*> &arguments, std::vector<float*> &coefficients, int coefficient_index)
    {
        int num_terms = arguments.size();
        float result = 0;

        for (int i=0; i<num_terms; i++)
        {
            float inverse_square_root = inverseSquareRoot(*arguments.at(i));
            result += *coefficients.at(coefficient_index);
        }
        return result;
    }

    void complicatedFunction()
    {
        unsigned int number_of_coefficients = NUM_COEF;
        unsigned int number_of_arguments = NUM_ARGS;

        std::vector<float*> arguments(number_of_arguments);
        std::vector<float*> coefficients(number_of_coefficients);
        std::vector<float*> results(number_of_arguments);

        for (int i=0; i<number_of_arguments; i++)
        {
            arguments.at(i) = new float(i*i);
        }

        for (int i=0; i<number_of_coefficients; i++)
        {
            coefficients.at(i) = new float(i);
        }

        auto start_time = std::chrono::high_resolution_clock::now();

        for (int i=0; i<number_of_arguments; i++)
        {
            results.at(i) = new float(someFunction(arguments, coefficients, i));
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto time_taken_chrono = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        double time_taken = time_taken_chrono.count();

        printf("Time taken: %f s \n", time_taken/1e6);

        for (int i=0; i<number_of_arguments; i++)
        {
            delete arguments.at(i);
            delete results.at(i);
        }

        for (int i=0; i<number_of_coefficients; i++)
        {
            delete coefficients.at(i);
        }
    }
}


namespace contiguous_memory
{
    inline float inverseSquareRoot(float argument)
    {
        float result = 1/sqrt(argument);
        return result;
    }

    float someFunction(std::vector<float> &arguments, std::vector<float> &coefficients, int coefficient_index)
    {
        int num_terms = arguments.size();
        float result = 0;

        for (int i=0; i<num_terms; i++)
        {
            float inverse_square_root = inverseSquareRoot(arguments.at(i));
            result += coefficients.at(coefficient_index);
        }
        return result;
    }

    void complicatedFunction()
    {
        unsigned int number_of_coefficients = NUM_COEF;
        unsigned int number_of_arguments = NUM_ARGS;

        std::vector<float> arguments(number_of_arguments);
        std::vector<float> coefficients(number_of_coefficients);
        std::vector<float> results(number_of_arguments);

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
            results.at(i) = someFunction(arguments, coefficients, i);
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto time_taken_chrono = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        double time_taken = time_taken_chrono.count();

        printf("Time taken: %f s \n", time_taken/1e6);
    }
}



namespace magic_square_root
{
    // https://en.wikipedia.org/wiki/Fast_inverse_square_root
    inline float inverseSquareRoot(float argument)
    {
        static_assert(std::numeric_limits<float>::is_iec559); // (enable only on IEEE 754)

        float const y = std::bit_cast<float>(
            0x5f3759df - (std::bit_cast<std::uint32_t>(argument) >> 1));
        return y * (1.5f - (argument * 0.5f * y * y));
    }

    float someFunction(std::vector<float> &arguments, std::vector<float> &coefficients, int coefficient_index)
    {
        int num_terms = arguments.size();
        float result = 0;

        for (int i=0; i<num_terms; i++)
        {
            float inverse_square_root = inverseSquareRoot(arguments.at(i));
            result += coefficients.at(coefficient_index);
        }
        return result;
    }

    void complicatedFunction()
    {
        unsigned int number_of_coefficients = NUM_COEF;
        unsigned int number_of_arguments = NUM_ARGS;

        std::vector<float> arguments(number_of_arguments);
        std::vector<float> coefficients(number_of_coefficients);
        std::vector<float> results(number_of_arguments);

        for (int i=0; i<number_of_arguments; i++)
        {
            arguments.at(i) = i*i;
        }

        for (int i=0; i<number_of_coefficients; i++)
        {
            coefficients.at(i) = i;
        }

        auto start_time = std::chrono::high_resolution_clock::now();

// #pragma omp parallel for
        for (int i=0; i<number_of_arguments; i++)
        {
            results.at(i) = someFunction(arguments, coefficients, i);
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto time_taken_chrono = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        double time_taken = time_taken_chrono.count();

        printf("Time taken: %f s \n", time_taken/1e6);
    }
}
