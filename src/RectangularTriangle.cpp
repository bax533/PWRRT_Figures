#include "RectangularTriangle.hpp"

#include <math.h>

namespace Figures
{
	double RectangularTriangle::HypotenuseLength()
	{
		return std::sqrt(
			std::pow(a_.DistanceToPoint(b_), 2)
			+ std::pow(a_.DistanceToPoint(c_), 2));
	}

} // namespace Figures