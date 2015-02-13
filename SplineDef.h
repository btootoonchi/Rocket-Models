#ifndef SAMPLEABLE_H
#define SAMPLEABLE_H
#include <vector>

template<typename T>
class SampleableFunction
{
public:
    virtual const T Sample(double parametricPosition) = 0;
    virtual double ParametricStart() = 0;
    virtual double ParametricEnd() = 0;
};

template<typename T>
class Spline : public SampleableFunction<T>
{
public:
    virtual void SetControlPoints(const std::vector<T> & CPList) = 0;
};

#endif // SAMPLEABLE_H
