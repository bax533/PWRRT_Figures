#include "Segment.hpp"

#include <math.h>

namespace Figures
{
	Segment::Segment(const Point &a, const Point &b) : a_(a), b_(b) {}

	double Segment::GetLength() const
	{
		return a_.DistanceToPoint(b_);
	}

	bool Segment::IsPerpendicular(const Segment& otherSegment) const
	{
		Vector thisVector(
			b_.GetX() - a_.GetX(),
			b_.GetY() - a_.GetY());

		Vector otherVector(
			otherSegment.GetB().GetX() - otherSegment.GetA().GetX(),
			otherSegment.GetB().GetY() - otherSegment.GetA().GetY());

		return thisVector * otherVector == 0.0;
	}

	bool Segment::IsParallel(const Segment& otherSegment) const
	{
		Vector thisVector(
			b_.GetX() - a_.GetX(),
			b_.GetY() - a_.GetY());

		Vector otherVector(
			otherSegment.GetB().GetX() - otherSegment.GetA().GetX(),
			otherSegment.GetB().GetY() - otherSegment.GetA().GetY());

		return thisVector.Cross(otherVector) == 0;
	}

 	Point Segment::GetA() const { return a_; }
 	Point Segment::GetB() const { return b_; }

} // namespace Figures