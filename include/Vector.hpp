#ifndef FIGURES_VECTOR_HPP
#define FIGURES_VECTOR_HPP

#include <math.h>

namespace Figures
{

class Vector
{
public:
	Vector() = default;
	Vector(double p, double q) : p_(p), q_(q) {}

	inline double Cross(const Vector& otherVector) const
	{
		return std::pow(p_ * otherVector.GetQ() - q_ * otherVector.GetP(), 2) == 0;
	}

	inline double operator*(const Vector& otherVector)
	{
		return p_ * otherVector.GetP() + q_ * otherVector.GetQ();
	}

	inline double GetP() const { return p_; }
	inline double GetQ() const { return q_; }

private:
	double p_, q_;
};

} // namespace Figures

#endif // FIGURES_VECTOR_HPP