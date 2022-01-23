#include <random>
#include <ctime>

#ifndef UNIFORM_RANDOM_NUMBERS_  
#define UNIFORM_RANDOM_NUMBERS_  

#define _DEFAULT_RANDOM_SEED_ 3141592
class UniformRandomNumbers
{
public:

	UniformRandomNumbers()
	{
    seed = _DEFAULT_RANDOM_SEED_;
	randomGenerator.seed(seed);

	// Initialize the distribution to be uniform in the interval [-1,1]

	std::uniform_real_distribution<double>::param_type distParams(-1.0,1.0);
	distribution.param(distParams);
	}

	void initialize()
	{
	seed = _DEFAULT_RANDOM_SEED_;
	randomGenerator.seed(seed);

	// Initialize the distribution to be uniform in the interval [-1,1]

	std::uniform_real_distribution<double>::param_type distParams(-1.0,1.0);
	distribution.param(distParams);
	}

    void initialize(double a, double b)
	{
	seed = _DEFAULT_RANDOM_SEED_;
	randomGenerator.seed(seed);

	// Initialize the distribution to be uniform in the interval [a,b]

	std::uniform_real_distribution<double>::param_type distParams(a,b);
	distribution.param(distParams);
	}

	void resetSeed(int seed)
    {
    this->seed = seed;
    randomGenerator.seed(seed);
    }

    void resetWithRandomSeed()
    {
    this->seed = (int)time(0);
    resetSeed(seed);
    }

    double getNextRandomNumber()
    {
    	return distribution(randomGenerator);
    }
	int                                                 seed;
    std::mt19937_64                          randomGenerator;
	std::uniform_real_distribution<double>      distribution;
};

#undef _DEFAULT_RANDOM_SEED_
#endif
