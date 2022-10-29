#ifndef FIGURES_TESTS_HPP
#define FIGURES_TESTS_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include "Segment.hpp"
#include "Triangle.hpp"
#include "RectangularTriangle.hpp"

namespace Figures
{

class FiguresTests
{
public:
	FiguresTests() = default;
	void Run();

private:
	void DistanceBetweenTwoPointsTest();
	void MovePointByVectorTest();
	void RotatePointByAngleAroundPointTest();
	void PerpendicularSegmentsTest();
	void ParallelSegmentsTest();

	void AssertWithPrecision(double value, double expectedValue);

	const double precision_ = 1e-5;
};

}

#endif // FIGURES_TESTS_HPP