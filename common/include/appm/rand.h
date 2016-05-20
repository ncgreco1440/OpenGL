#ifndef RAND_TMP_H_
#define RAND_TMP_H_

#include <algorithm>
#include <random>
#include <type_traits>

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
        if(std::is_floating_point<T>::value)
        {
            std::uniform_real_distribution<T> dist(_min, _max);
            return dist(mt);
        }
        std::uniform_int_distribution<T> dist(_min, _max);
        return dist(mt);
    };
private:
    T _min, _max;
};

#endif