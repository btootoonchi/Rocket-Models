#ifndef BEZIER_H
#define BEZIER_H
#include "SplineDef.h"

template<typename T>
class BezierSpline : public Spline<T>
{
public:
    //! Default constructor
    BezierSpline() { BernsteinCoef = BinomialCoef = NULL; degree = 0; }

    //! Default destructor
    ~BezierSpline() { delete BernsteinCoef; delete BinomialCoef; }

    /*! Returns the start parameter which is zero
     * \ returns 0.0
     */
    virtual double ParametricStart() { return 0.0; }

    /*! Returns the end parameter which is one
     * \ returns 1.0
     */
    virtual double ParametricEnd() { return 1.0; }

    /*! Set a series of control points in bezier
     * \
     */
    virtual void SetControlPoints(const std::vector<T> & CPList)
    {
        cpList.assign(CPList.begin(), CPList.end());
        PrepareBernstein((int)CPList.size() - 1);
    }

    /*! Get a sample for bezier path
     * \
     */

    virtual const T Sample(double parametricPosition)
    {

        T Result;
        if (cpList.size() == 0 || degree < 1) return Result;
        if ((parametricPosition < 0) || (parametricPosition > 1)) return Result;

        //Construct the Bernstein Coefficients
        int i;
        for (i = 0; i <= degree; ++ i)
        {
           BernsteinCoef[i] = BinomialCoef[i];
        }

        double para = parametricPosition;
        double minusPara = 1 - parametricPosition;
        double powPara = para;
        double powMinusPara = minusPara;
        for (i = 1; i <= degree; ++ i)
        {
           BernsteinCoef[i] *= powPara;
           BernsteinCoef[degree - i] *= powMinusPara;
           powPara *= para;
           powMinusPara *= minusPara;
        }

        //Construct the sampled point
        for (i = 0; i <= degree; ++ i)
        {
            Result += BernsteinCoef[i] * cpList[i];
        }

        return Result;
    }

private:
    std::vector<T> cpList;
    double * BernsteinCoef;
    double * BinomialCoef;
    int degree;

    /*! Calculate Bernstein basis function
     * \
     */
    void PrepareBernstein(int deg)
    {
        if (deg < 1) return;

        if (deg != degree)
        {
            //re-initialize binomial coefficients
            delete [] BernsteinCoef;
            BernsteinCoef = NULL;
            delete [] BinomialCoef;
            BinomialCoef = NULL;

            degree = deg;
            BernsteinCoef = new double[degree + 1];
            BinomialCoef = new double[degree + 1];

            double factorialN = factorial(degree);
            for (int i = 0; i <= degree; ++ i)
            {
                BinomialCoef[i] = factorialN / (double)(factorial(i) * factorial(degree - i));
            }
        }
    }

    /*! Calculate factorial of n
     * \
     */
    int factorial(int n)
    {
        int result = 1;
        for (int i = 1; i <= n; ++ i) result = result * i;
        return result;
    }
};

#endif // BEZIER_H
