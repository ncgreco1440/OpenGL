#include <random>
#include <algorithm>

/* ===================================================================================
PROTOTYPE RANDOM GENERATOR CLASS

Remember that random generators always return from a range that includes the
minimum value but excludes the maximum value.
=================================================================================== */
template<class T>
class RandomGen
{
public:
// Constructor
    RandomGen(T min, T max): _min(min), _max(max) {};
// Change range
    void setRange(T min, T max)
    {
        _min = min;
        _max = max;
    };
// Return a random value
    T getRandom()
    {
        std::random_device random_device;
        std::mt19937 mt(random_device());
        std::uniform_int_distribution<T> dist(_min, _max);
        return dist(mt);
    };
private:
    T _min, _max;
};