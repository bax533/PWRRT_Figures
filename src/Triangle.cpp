#include "Triangle.hpp"

#include <math.h>

namespace Figures
{
	Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	: a_(a), b_(b), c_(c)
	{
		if(a.DistanceToPoint(b) + b.DistanceToPoint(c)
			== a.DistanceToPoint(c))
			throw IncorrectTriangleException();
	}

	double Triangle::GetCircuit() const
	{
		return a_.DistanceToPoint(b_)
			+ b_.DistanceToPoint(c_)
			+ c_.DistanceToPoint(a_);
	}

	double Triangle::GetField() const
	{
		const double p = this->GetCircuit()/2.0;
		return std::sqrt(
			p * (p - a_.DistanceToPoint(b_))
			* (p - b_.DistanceToPoint(c_))
			* (p - c_.DistanceToPoint(a_))
		);
	}

 	Point Triangle::GetA() const { return a_; }
 	Point Triangle::GetB() const { return b_; }
 	Point Triangle::GetC() const { return c_; }

} // namespace Figures