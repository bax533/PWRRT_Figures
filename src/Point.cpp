#include "Point.hpp"

#include <math.h>

namespace Figures
{

  Point::Point(double x, double y) : x_(x), y_(y) {}
  Point::Point(const Point& point) : x_(point.GetX()), y_(point.GetY()) {}

	Point Point::MoveByVector(const Vector& v) const
	{
		return Point(x_ + v.GetP(), y_ + v.GetQ());
	}

	Point Point::RotateByAngleAroundPoint(const Point& point, angle_t angle) const
	{
		double newX = x_ - point.GetX();
		double newY = y_ - point.GetY();

	 	newX = newX * std::cos(angle) - newY * std::sin(angle);
	 	newY = newX * std::sin(angle) + newY * std::cos(angle);
	 	return Point(newX, newY);
 	}

 	double Point::DistanceToPoint(const Point& point) const
 	{
 		return std::sqrt(
 			std::pow(point.GetY() - y_, 2)
 			+ std::pow(point.GetX() - x_, 2));
 	}

 	double Point::GetX() const { return x_; }
 	double Point::GetY() const { return y_; }

} // namespace Figures
