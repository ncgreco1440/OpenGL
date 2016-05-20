#ifndef RAND_TMP_H_
#define RAND_TMP_H_
/*************************************************************************
* Simple Random Number Generator
*
* SRNG is a pair of two template classes that will generate random 
* numbers the C++11 way for integral and floating point data types
*
*************************************************************************/

#include <algorithm>
#include <random>
#include <type_traits>

namespace SRNG
{
    /*********************************************************************
     * Random Number Generator for Integral Types
     ********************************************************************/
	template<class T>
	class iRandomGen
	{
	public:
		// Constructor
		iRandomGen(T min, T max) : _min(min), _max(max) {};
		// Change range
		void setRange(T min, T max)
		{
			_min = min;
			_max = max;
		};
		// Return a random value
		T random_integral()
		{
			std::random_device random_device;
			std::mt19937 mt(random_device());
			std::uniform_int_distribution<T> dist(_min, _max);
			return dist(mt);
		};
	private:
		T _min, _max;
	};

    /*********************************************************************
     * Random Number Generator for Floating Point Types
     ********************************************************************/
	template<class T>
	class fRandomGen
	{
	public:
		// Constructor
		fRandomGen(T min, T max) : _min(min), _max(max) {};
		// Change range
		void setRange(T min, T max)
		{
			_min = min;
			_max = max;
		};
		// Return a random value
		T random_floating()
		{
			std::random_device random_device;
			std::mt19937 mt(random_device());
			std::uniform_real_distribution<T> dist(_min, _max);
			return dist(mt);
		};
	private:
		T _min, _max;
	};

}
#endif