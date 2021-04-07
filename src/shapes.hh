#ifndef OCTETOS_MATH_SHAPES_HH
#define OCTETOS_MATH_SHAPES_HH

#include <octetos/math/core.hh>

namespace math::shapes
{

template<class T>
class Triangle
{
public:
	Triangle(const math::Vector<T>& v1,const math::Vector<T>& v2, const math::Vector<T>& v3)
	{
		this->v1 = v1;
		this->v2 = v2;
		this->v3 = v3;
	};

private:
	math::Vector<T> v1;
	math::Vector<T> v2;
	math::Vector<T> v3;
};

}

#endif