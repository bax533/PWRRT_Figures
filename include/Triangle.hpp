#ifndef FIGURES_TRIANGLE_HPP
#define FIGURES_TRIANGLE_HPP

#include <exception>
#include "Point.hpp"

namespace Figures
{

struct IncorrectTriangleException : public std::exception {
   const char* what () const throw () {
      return "Given points are in one line!";
   }
};	

class Triangle
{
public:
	Triangle() = default;
	Triangle(const Point& a, const Point& b, const Point& c);

	double GetCircuit() const;
	double GetField() const;

	Point GetA() const;
	Point GetB() const;
	Point GetC() const;

protected:
	Point a_, b_, c_;
};

}

#endif // FIGURES_TRIANGLE_HPP