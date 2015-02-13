#ifndef foundation_h
#define foundation_h

#define EPSILON 0.00001
#define SEP << " " <<
#define NL  << "\n"

using namespace std;

// I can't seem to make the -LANG:bool=ON switch work so :

//---------------------------------------------------------------------------
// if C++ type `bool' is not defined with compiler being used ...

#ifdef NOBOOL
typedef int bool;

#define true  1
#define false 0
#endif


//---------------------------------------------------------------------------

#include <stddef.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <qmath.h>

static const double GL_PI = 3.14159265358979323846264338327950288419717;

class Vec2d
{
public:
    double x, y;

    /// CONSTRUCTOR
    Vec2d() { x = y = 0; }

    /// CONSTRUCTOR
    Vec2d(double x_in, double y_in) { x = x_in; y = y_in;}

    /// CONSTRUCTOR
    Vec2d(const Vec2d & rhs) { x = rhs.x; y = rhs.y; }

    /*! Overwrite operatore += for Vec3d class
     * \
     */
    Vec2d & operator+=(const Vec2d & rhs) { x += rhs.x; y += rhs.y; return * this; }
};

/*! Overwrite operatore * for Vec3d class
 * \
 */
inline Vec2d operator * (const double & lhs, const Vec2d & rhs)
{
    return Vec2d(rhs.x * lhs, rhs.y * lhs);
}

class Vec3d
{
public:

    /// CONSTRUCTOR
    double x, y, z;
    Vec3d() { x = y = z = 0; }

    /// CONSTRUCTOR
    Vec3d(double x_in, double y_in, double z_in) { x = x_in; y = y_in; z = z_in; }

    /// CONSTRUCTOR
    Vec3d(const Vec3d & rhs) { x = rhs.x; y = rhs.y; z = rhs.z; }

    /*! Overwrite operatore += for Vec3d class
     * \
     */
    Vec3d & operator+=(const Vec3d & rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return * this; }
};

/*! Overwrite operatore * for Vec3d class
 * \
 */
inline Vec3d operator * (const double & lhs, const Vec3d & rhs)
{
    return Vec3d(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}


#endif

