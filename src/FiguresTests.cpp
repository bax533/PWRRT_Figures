#include "FiguresTests.hpp"
#include <math.h>
#include <assert.h>
#include <iostream>

namespace Figures
{
	void FiguresTests::Run()
	{
		DistanceBetweenTwoPointsTest();
		MovePointByVectorTest();
		RotatePointByAngleAroundPointTest();
		PerpendicularSegmentsTest();
		ParallelSegmentsTest();
	}

	void FiguresTests::DistanceBetweenTwoPointsTest()
	{
		Point a(1.0, 2.0);
		Point b(0.0, 3.0);

		AssertWithPrecision(a.DistanceToPoint(b), std::sqrt(2.0));
    std::cout << "DistanceBetweenTwoPointsTest passed" << std::endl;
	}

	void FiguresTests::MovePointByVectorTest()
	{
		Point a(1.0, 1.0);
		Point movedA = a.MoveByVector({1.0, 1.0});

		AssertWithPrecision(movedA.GetX(), 2.0);
		AssertWithPrecision(movedA.GetY(), 2.0);
    std::cout << "MovePointByVectorTest passed" << std::endl;
	}

	void FiguresTests::RotatePointByAngleAroundPointTest()
	{
		Point a(0.0, 1.0);
		Point rotatedA = a.RotateByAngleAroundPoint(Point(0.0, 0.0), 1.57);

		AssertWithPrecision(rotatedA.GetX(), 1.0);
		AssertWithPrecision(rotatedA.GetY(), 0.0);
    std::cout << "RotatePointByAngleAroundPointTest passed" << std::endl;
	}

	void FiguresTests::PerpendicularSegmentsTest()
	{
		Segment segmentA(Point(0.0, 2.0), Point(2.0, 2.0));
		Segment segmentB(Point(1.0, 0.5), Point(1.0, 6.0));

		assert(segmentA.IsPerpendicular(segmentB));

		Segment segmentC(Point(5.0, 5.0), Point(2.5, 6.0));

		assert(!segmentA.IsPerpendicular(segmentC));
    std::cout << "PerpendicularSegmentsTest passed" << std::endl;
	}

	void FiguresTests::ParallelSegmentsTest()
	{
		Segment segmentA(Point(0.0, 2.0), Point(2.0, 3.0));
		Segment segmentB(Point(1.0, 5.0), Point(2.0, 6.0));

		assert(segmentA.IsParallel(segmentB));

		Segment segmentC(Point(5.0, 5.0), Point(2.5, 6.0));

		assert(!segmentA.IsParallel(segmentC));
    std::cout << "ParallelSegmentsTest passed" << std::endl;
	}

	void FiguresTests::AssertWithPrecision(double value, double expectedValue)
	{
		assert(value_less < expectedValue + precision_ && value > expectedValue - precision_);
	}
}