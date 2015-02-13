#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <qmath.h>
#include <assert.h>

//! Vector3D class
/*!
  The Vector3D class describes a point in 3-dimensional space denoted by its components X, Y and Z.
**/
class Vector3D {
public:
    // CONSTRUCTOR
    //! Default constructor
    /*!
        The default constructor creates a point described by its three components. By default this
        point is the origin O( 0.0, 0.0, 0.0 ).
        \param[in] x the X value
        \param[in] y the Y value
        \param[in] z the Z value
    **/
    Vector3D( const double x = 0.0,
              const double y = 0.0,
              const double z = 0.0 ) : _x( x ), _y( y ), _z( z ) { }

    //! Copy constructor
    /*!
        The copy constructor creates a point from another given one.
        \param[in] v a point in 3D space
    **/
    Vector3D( const Vector3D& v ) : _x( v._x ), _y( v._y ), _z( v._z ) { }

    // DESTRUCTOR
    //! Destructor
    ~Vector3D() { }

    // COPY
    //! Returns a copy of the point.
    /*!
        \sa Vector3D( const Vector3D& v )
    **/
    inline Vector3D Copy() const { return Vector3D( _x, _y, _z ); }

    // VALUE
    //! Returns the value of the X component of the point.
    /*!
        \sa Vec( double& x, double& y, double& z )
    **/
    inline double X() const { return _x; }

    //! Returns the value of the X component of the point.
    /*!
        \sa Vec( double& x, double& y, double& z )
    **/
    inline double& X() { return _x; }

    //! Sets the value of the X component of the point.
    /*!
        \param[in] x the X value
        \sa setVec( const double x, const double y, const double z )
    **/
    inline void setX( const double x ) { _x = x; }

    //! Returns the value of the Y component of the point.
    /*!
        \sa Vec( double& x, double& y, double& z )
    **/
    inline double Y() const { return _y; }

    //! Returns the value of the Y component of the point.
    /*!
        \sa Vec( double& x, double& y, double& z )
    **/
    inline double& Y() { return _y; }

    //! Sets the value of the Y component of the point.
    /*!
        \param[in] y the Y value
        \sa setVec( const double x, const double y, const double z )
    **/
    inline void setY( const double y ) { _y = y; }

    //! Returns the value of the Z component of the point.
    /*!
        \sa Vec( double& x, double& y, double& z )
    **/
    inline double Z() const { return _z; }

    //! Returns the value of the Z component of the point.
    /*!
        \sa Vec( double& x, double& y, double& z )
    **/
    inline double& Z() { return _z; }

    //! Sets the value of the Z component of the point.
    /*!
        \param[in] z the Z value
        \sa setVec( const double x, const double y, const double z )
    **/
    inline void setZ( const double z ) { _z = z; }

    //! Returns the value of the components of the point.
    /*!
        \param[out] x the X component
        \param[out] y the Y component
        \param[out] z the Z component
        \sa X(), Y() and Z()
    **/
    inline void Vec( double& x, double& y, double& z ) const { x = _x; y = _y; z = _z; }

    //! Sets the values of the components of the point.
    /*!
        \param[in] x the X value
        \param[in] y the Y value
        \param[in] z the Z value
        \sa setX( const double x ), setY( const double y ) and setZ( cconst double z )
    **/
    inline void setVec( const double x, const double y, const double z ) { _x = x; _y = y; _z = z; }

    // NORM
    //! Returns the norm of the vector.
    /*!
        \sa NormSqr()
    **/
    inline double Norm() const { return ( qSqrt( ( _x * _x ) + ( _y * _y ) + ( _z * _z ) ) ); }

    //! Returns the squared norm of the vector.
    /*!
        \sa Norm()
    **/
    inline double NormSqr() const { return ( ( _x * _x ) + ( _y * _y ) + ( _z * _z ) ); }

    // NORMALIZATION
    //! Normalizes the vector.
    /*!
        \sa Normalized()
    **/
    inline void Normalize() {
        double norm = Norm();
        if( norm != 0.0 ) { _x /= norm; _y /= norm; _z /= norm; }
    }

    //! Returns the normalized version of the vector.
    /*!
        \sa Normalize()
    **/
    inline Vector3D Normalized() const {
        double norm = Norm();
        if( norm != 0.0 ) { return Vector3D( ( _x / norm ), ( _y / norm ), ( _z / norm ) ); }
        return Vector3D();
    }

    // ZERO
    //! Transforms the point into the origin O( 0.0, 0.0, 0.0 ).
    /*!
        \sa Vector3D( const double x, const double y, const double z ), Zero()
    **/
    inline void setZero(){ _x = 0.0; _y = 0.0; _z = 0.0; }

    //! Checks if the point is the origin.
    inline bool isZero() const { return ( ( _x == 0.0 ) && ( _y == 0.0 ) && ( _z == 0.0 ) ); }

    //! Returns the origin O( 0.0, 0.0, 0.0 ).
    /*!
        \sa Vector3D( const double x, const double y, const double z ), setZero()
    **/
    static Vector3D Zero() { return Vector3D( 0.0, 0.0, 0.0 ); }

    // AXIS
    //! Transforms the point into the versor X( 1.0, 0.0, 0.0 ).
    /*!
        \sa Vector3D( const double x, const double y, const double z ), AxisX()
    **/
    inline void setAxisX() { _x = 1.0; _y = 0.0; _z = 0.0; }

    //! Checks if the point is the versor X
    inline bool isAxisX() const { return ( ( _x == 1.0 ) && ( _y == 0.0 ) && ( _z == 0.0 ) ); }

    //! Returns the versor X( 1.0, 0.0, 0.0 ).
    /*!
        \sa Vector3D( const double x, const double y, const double z ), setAxisX()
    **/
    static Vector3D AxisX() { return Vector3D( 1.0, 0.0, 0.0 ); }

    //! Transforms the point into the versor Y( 0.0, 1.0, 0.0 ).
    /*!
        \sa Vector3D( const double x, const double y, const double z ), AxisY()
    **/
    inline void setAxisY() { _x = 0.0; _y = 1.0; _z = 0.0; }

    //! Checks if the point is the versor Y
    inline bool isAxisY() const { return ( ( _x == 0.0 ) && ( _y == 1.0 ) && ( _z == 0.0 ) ); }

    //! Returns the versor Y( 0.0, 1.0, 0.0 ).
    /*!
        \sa Vector3D( const double x, const double y, const double z ), setAxisY()
    **/
    static Vector3D AxisY() { return Vector3D( 0.0, 1.0, 0.0 ); }

    //! Transforms the point into the versor Z( 0.0, 0.0, 1.0 ).
    /*!
        \sa Vector3D( const double x, const double y, const double z ), AxisZ()
    **/
    inline void setAxisZ() { _x = 0.0; _y = 0.0; _z = 1.0; }

    //! Checks if the point is the versor Z
    inline bool isAxisZ() const { return ( ( _x == 0.0 ) && ( _y == 0.0 ) && ( _z == 1.0 ) ); }

    //! Returns the versor Z( 0.0, 0.0, 1.0 ).
    /*!
        \sa Vector3D( const double x, const double y, const double z ), setAxisZ()
    **/
    static Vector3D AxisZ() { return Vector3D( 0.0, 0.0, 1.0 ); }

    // DOT PRODUCT
    //! Returns the Dot Product of the two given vectors.
    /*!
        \param[in] v0 the first vector
        \param[in] v1 the second vector
    **/
    static double Dot( const Vector3D& v0, const Vector3D& v1 ) {
        return ( ( v0._x * v1._x ) + ( v0._y * v1._y ) + ( v0._z * v1._z ) );
    }

    // CROSS PRODUCT
    //! Returns the Cross Product of the two given vectors.
    /*!
        \param[in] v0 the first vector
        \param[in] v1 the second vector
    **/
    static Vector3D Cross( const Vector3D& v0, const Vector3D& v1 ) {
        return Vector3D( ( ( v0._y * v1._z ) - ( v0._z * v1._y ) ),
                         ( ( v0._z * v1._x ) - ( v0._x * v1._z ) ),
                         ( ( v0._x * v1._y ) - ( v0._y * v1._x ) ) );
    }

    // OPERATOR
    //! Returns the vector component specified by i index i.e. v[0] returns the x component.
    /*!
        \param[in] i the index of the component
        \sa X(), Y(), Z(), Vec( double& x, double& y, double& z )
    **/
    inline double& operator[]( const int i ) {
        switch( i ) {
        case 0: return _x;
        case 1: return _y;
        case 2: return _z;
        default: assert( false );
        }
    }

    //! Transforms this vector into v and returns a reference to this vector.
    inline Vector3D& operator=( const Vector3D& v ) { _x  = v._x; _y  = v._y; _z  = v._z; return *this; }

    //! Adds v to this vector and returns a reference to this vector.
    inline Vector3D& operator+=( const Vector3D& v ) { _x += v._x; _y += v._y; _z += v._z; return *this; }

    //! Subtracts v from this vector and returns a reference to this vector.
    inline Vector3D& operator-=( const Vector3D& v ) { _x -= v._x; _y -= v._y; _z -= v._z; return *this; }

    //! Multiplies this vector by the scalar s and returns a reference to this vector.
    inline Vector3D& operator*=( const double s ) { _x *= s; _y *= s; _z *= s; return *this; }

    //! Divides this vector by the scalar s and returns a reference to this vector. Cause the algorithm to stop if s equals 0.
    inline Vector3D& operator/=( const double s ) { assert( s != 0.0 ); _x /= s; _y /= s; _z /= s; return *this; }

    //! Returns a Vector3D that is the negation of v.
    friend inline Vector3D operator-( const Vector3D& v ) { return Vector3D( -v._x, -v._y, -v._z ); }

    //! Returns a Vector3D that is formed by adding v1 to v0.
    friend inline Vector3D operator+( const Vector3D& v0, const Vector3D& v1 ) {
        return Vector3D( ( v0._x + v1._x ), ( v0._y + v1._y ), ( v0._z + v1._z ) );
    }

    //! Returns a Vector3D that is formed by subtracting v1 from v0.
    friend inline Vector3D operator-( const Vector3D& v0, const Vector3D& v1 ) {
        return Vector3D( ( v0._x - v1._x ), ( v0._y - v1._y ), ( v0._z - v1._z ) );
    }

    //! Returns the Dot Product of v0 and v1
    /*!
        \sa Dot( const Vector3D& v0, const Vecotr3D& v1 )
    **/
    friend inline double operator*( const Vector3D& v0, const Vector3D& v1 ) { return Dot( v0, v1 ); }

    //! Returns a Vector3D that is formed by v multiplied by the scalar s.
    friend inline Vector3D operator*( const Vector3D& v, const double s ) {
        return Vector3D( ( v._x * s ), ( v._y * s ), ( v._z * s ) );
    }

    //! Returns a Vector3D that is formed by v multiplied by the scalar s.
    friend inline Vector3D operator*( const double s, const Vector3D& v ) {
        return Vector3D( ( v._x * s ), ( v._y * s ), ( v._z * s ) );
    }

    //! Returns a Vector3D that is formed by v divided by the scalar s. Cause the algorithm to stop if s equals 0.
    friend inline Vector3D operator/( const Vector3D& v, const double s ) {
        assert( s != 0.0 ); return Vector3D( ( v._x / s ), ( v._y / s ), ( v._z / s ) );
    }

    //! Returns true if v0 is equal to v1, otherwise returns false.
    friend inline bool operator==( const Vector3D& v0, const Vector3D& v1 ) {
        return ( ( v0._x == v1._x  ) && ( v0._y == v1._y ) && ( v0._z == v1._z ) );
    }

    //! Returns true if v0 is not equal to v1, otherwise returns false.
    friend inline bool operator!=( const Vector3D& v0, const Vector3D& v1 ) {
        return ( ( v0._x != v1._x  ) || ( v0._y != v1._y ) || ( v0._z != v1._z ) );
    }

protected:
    //! \cond
    // VARIABLE
    double _x;
    double _y;
    double _z;
    //! \endcond
};

//! \typedef A more compact way for using Vector3D.
typedef Vector3D vec3;

#endif // VECTOR3D_H
