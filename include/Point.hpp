#ifndef FIGURES_POINT_HPP
#define FIGURES_POINT_HPP

#include "Vector.hpp"

namespace Figures
{

using angle_t = double; // radians

class Point
{
public:
	Point(double x, double y);
	Point(const Point& p);

	Point MoveByVector(const Vector& v) const;
	Point RotateByAngleAroundPoint(const Point& point, angle_t angle) const;

	double DistanceToPoint(const Point& point) const;

	double GetX() const;
	double GetY() const;

private:
	double x_, y_;
};

} // namespace Figures

#endif // FIGURES_POINT_HPP 
