#ifndef FIGURES_SEGMENT_HPP
#define FIGURES_SEGMENT_HPP

#include "Point.hpp"

namespace Figures
{

class Segment
{
public:
	Segment(const Point& a, const Point& b);

	double GetLength() const;
	bool IsPerpendicular(const Segment& otherSegment) const;
	bool IsParallel(const Segment& otherSegment) const;

	Point GetA() const;
	Point GetB() const;

private:
	Point a_, b_;

};

}

#endif // FIGURES_SEGMENT_HPP