#ifndef QUATERNION_H
#define QUATERNION_H

#include "vector3d.h"

//! \struct Matrix3x3
/*! Structure for storing the values of a rotation matrix. **/
struct Matrix3x3 {
    double m[3][3];
};

//! Quaternion class
/*!
  The Quaternion class describes a quaternion denoted by a scalar s and a vector v.
**/
class Quaternion {
public:
    // CONSTRUCTOR
    //! Default constructor
    /*!
        Constructs a quaternion [ s, v ].
        \param[in] s the scalar part
        \param[in] v the vector part
    **/
    Quaternion( const double s = 1.0,
                const vec3&  v = vec3( 0.0, 0.0, 0.0 ) ) : _s( s ), _v( v ) { }

    //! Constructor
    /*!
        Construct a quaternion [ s, ( x, y, z ) ].
        \param[in] s the scalar part
        \param[in] x the x component of the vector part
        \param[in] y the y component of the vector part
        \param[in] z the z component of the vector part
    **/
    Quaternion( const double s,
                const double x,
                const double y,
                const double z ) : _s( s ), _v( x, y, z ) { }

    //! Constructor
    /*!
        Construct a quaternion from a Vector3D in the form [ 0, v ].
        \param[in] v the vector part
    **/
    Quaternion( const vec3& v ) : _s( 0.0 ), _v( v ) { }

    //! Constructor
    /*!
        Construct a quaternion from a Vector3D in the form [ 0, v ].
        \param[in] x the x component of the vector part
        \param[in] y the y component of the vector part
        \param[in] z the z component of the vector part
    **/
    Quaternion( const double x,
                const double y,
                const double z ) : _s( 0.0 ), _v( x, y, z ) { }

    //! Copy constructor
    /*!
        The copy constructor creates a quaternion from another given one.
        \param[in] q a quaternion
    **/
    Quaternion( const Quaternion& q ) : _s( q._s ), _v( q._v ) { }

    // DESTRUCTOR
    //! Destructor
    ~Quaternion() { }

    // COPY
    //! Returns a copy of the quaternion.
    /*!
        \sa Quaternion( const Quaternion& q )
    **/
    inline Quaternion Copy() const { return Quaternion( _s, _v ); }

    // SCALAR
    //! Returns the value of the scalar part of the quaternion.
    /*!
        \sa Quat( double& s, vec3& v ), Quat( double& s, double& x, double& y, double& z )
    **/
    inline double S() const { return _s; }

    //! Returns the value of the scalar part of the quaternion.
    /*!
        \sa Quat( double& s, vec3& v ), Quat( double& s, double& x, double& y, double& z )
    **/
    inline double& S() { return _s; }

    //! Sets the value of the scalar part of the quaternion.
    /*!
        \param[in] s the scalar value
        \sa setQuat( const double s, const vec3& v ), setQuat( const double s, const double x, const double y, const double z )
    **/
    inline void setS( const double s ) { _s = s; }

    // VECTOR
    //! Returns the X component of the quaternion vector part.
    /*!
        \sa V( double& x, double& y, double& z ), Quat( double s&, double& x, double& y, double& z )
    **/
    inline double X() const { return _v.X(); }

    //! Returns the X component of the quaternion vector part.
    /*!
        \sa V( double& x, double& y, double& z ), Quat( double s&, double& x, double& y, double& z )
    **/
    inline double& X() { return _v.X(); }

    //! Sets the X component of the quaternion vector part.
    /*!
        \param[in] x the X value
        \sa setV( const double x, const double y, const double z ), setQuat( const double s,  const double x, const double y, const double z )
    **/
    inline void setX( const double x ) { _v.X() = x; }

    //! Returns the Y component of the quaternion vector part.
    /*!
        \sa V( double& x, double& y, double& z ), Quat( double s&, double& x, double& y, double& z )
    **/
    inline double Y() const { return _v.Y(); }

    //! Returns the Y component of the quaternion vector part.
    /*!
        \sa V( double& x, double& y, double& z ), Quat( double s&, double& x, double& y, double& z )
    **/
    inline double& Y() { return _v.Y(); }

    //! Sets the Y component of the quaternion vector part.
    /*!
        \param[in] y the Y value
        \sa setV( const double x, const double y, const double z ), setQuat( const double s,  const double x, const double y, const double z )
    **/
    inline void setY( const double y ) { _v.Y() = y; }

    //! Returns the Z component of the quaternion vector part.
    /*!
        \sa V( double& x, double& y, double& z ), Quat( double& s, double& x, double& y, double& z )
    **/
    inline double Z() const { return _v.Z(); }

    //! Returns the Z component of the quaternion vector part.
    /*!
        \sa V( double& x, double& y, double& z ), Quat( double& s, double& x, double& y, double& z )
    **/
    inline double& Z() { return _v.Z(); }

    //! Sets the Z component of the quaternion vector part.
    /*!
        \param[in] z the Z value
        \sa setV( const double x, const double y, const double z ), setQuat( const double s, const double x, const double y, const double z )
    **/
    inline void setZ( const double z ) { _v.Z() = z; }

    //! Returns the quaternion vector part.
    /*!
        \sa Quat( double& s, vec3& v )
    **/
    inline vec3 V() const { return _v; }

    //! Returns the quaternion vector part.
    /*!
        \sa Quat( double& s, vec3& v )
    **/
    inline vec3& V() { return _v; }

    //! Returns the quaternion vector part.
    /*!
        \param[out] x the X value
        \param[out] y the Y value
        \param[out] z the Z value
        \sa Quat( double s&, double& x, double& y, double& z )
    **/
    inline void V( double& x,
                   double& y,
                   double& z ) const { _v.Vec( x, y, z ); }

    //! Sets the quaternion vector part.
    /*!
        \param[in] v the vector part
        \sa setQuat( const double s, const vec3& v )
    **/
    inline void setV( const vec3& v ) { _v = v; }

    //! Sets the quaternion vector part.
    /*!
        \param[in] x the X value
        \param[in] y the Y value
        \param[in] z the Z value
        \sa setQuat( const double s, const double x, const double y, const double z )
    **/
    inline void setV( const double x,
                      const double y,
                      const double z ) { _v.setVec( x, y, z ); }

    // QUATERNION
    //! Returns the scalar and the vector part of the quaternion.
    /*!
        \param[out] s the scalar part
        \param[out] v the vector part
        \sa S(), X(), Y(), Z(), V()
    **/
    inline void Quat( double& s, vec3& v ) const { s = _s; v = _v; }

    //! Returns the scalar and the vector part of the quaternion.
    /*!
        \param[out] s the scalar part
        \param[out] x the X value
        \param[out] y the Y value
        \param[out] z the Z value
        \sa S(), X(), Y(), Z(), V( double& x, double& y, double& z )
    **/
    inline void Quat( double& s,
                      double& x,
                      double& y,
                      double& z ) const { s = _s; x = _v.X(); y = _v.Y(); z = _v.Z(); }

    //! Sets the quaternion scalar and vector part.
    /*!
        \param[in] s the scalar part
        \param[in] v the vector part
        \sa Quaternion( const double s, const vec3& v ), setS( const double s ), setV( const vec3& v )
    **/
    inline void setQuat( const double s,
                         const vec3& v ) { _s = s; _v = v; }

    //! Sets the quaternion scalar and vector part.
    /*!
        \param[in] s the scalar part
        \param[in] x the X value
        \param[in] y the Y value
        \param[in] z the Z value
        \sa Quaternion( const double s, const double x, const double y, const double z ), setS( const double s ), setX( const double x ), setY( const double y ), setZ( const double z ), setV( const double x, const double y, const double z )
    **/
    inline void setQuat( const double s,
                         const double x,
                         const double y,
                         const double z ) { _s = s; _v.setVec( x, y, z ); }

    //! Creates a quaternion [ 0, v ] from a given Vector3D.
    /*!
        \param[in] v the vector part
        \sa Quaternion( const vec3& v )
    **/
    inline void fromVec( const vec3& v ) { _s = 0.0; _v = v; }

    //! Creates a quaternion [ 0, v ] from a given vector.
    /*!
        \param[in] x the X value
        \param[in] y the Y value
        \param[in] z the Z value
        \sa Quaternion( const double x, const double y, const double z )
    **/
    inline void fromVec( const double x,
                         const double y,
                         const double z ) { _s = 0.0; _v.setVec( x, y, z ); }

    //! Creates a quaternion [ cos(angle/2), sin(angle/2)v ] from a given axis and angle of rotation.
    /*!
        \param[in] angle angle of rotation
        \param[in] axis axis of rotation
    **/
    inline void fromRot( const double angle,
                         const vec3& axis ) { _s = qCos( angle / 2.0 ); _v = qSin( angle / 2.0) * axis; }

    //! Creates a quaternion [ cos(angle/2), sin(angle/2)( x, y, z ) ] from a given axis and angle of rotation.
    /*!
        \param[in] angle angle of rotation
        \param[in] x the X value
        \param[in] y the Y value
        \param[in] z the Z value
    **/
    inline void fromRot( const double angle,
                         const double x,
                         const double y,
                         const double z ) { _s = qCos( angle / 2.0 ); _v = qSin( angle / 2.0) * vec3( x, y, z ); }

    //! Creates a quaternion from a given set of Euler angles.
    /*!
        \param[in] angle Euler angles
    **/
    inline void fromEuler( const vec3& angle ) {
        double cx = qCos( angle.X() / 2.0 ); double cy = qCos( angle.Y() / 2.0 ); double cz = qCos( angle.Z() / 2.0 );
        double sx = qSin( angle.X() / 2.0 ); double sy = qSin( angle.Y() / 2.0 ); double sz = qSin( angle.Z() / 2.0 );
        _s = ( cx * cy * cz ) + ( sx * sy * sz );
        _v = vec3( ( ( cy * cz * sx ) + ( cx * sy * sz ) ),
                   ( ( cx * cz * sy ) - ( cy * sx * sz ) ),
                   ( ( cx * cy * sz ) + ( cz * sx * sy ) ) );
    }

    //! Creates a quaternion from a given set of Euler angles.
    /*!
        \param[in] x_angle rotation around X axis
        \param[in] y_angle rotation around Y axis
        \param[in] z_angle rotation around Z axis
    **/
    inline void fromEuler( const double x_angle,
                           const double y_angle,
                           const double z_angle ) {
        double cx = qCos( x_angle / 2.0 ); double cy = qCos( y_angle / 2.0 ); double cz = qCos( z_angle / 2.0 );
        double sx = qSin( x_angle / 2.0 ); double sy = qSin( y_angle / 2.0 ); double sz = qSin( z_angle / 2.0 );
        _s = ( cx * cy * cz ) + ( sx * sy * sz );
        _v = vec3( ( ( cy * cz * sx ) + ( cx * sy * sz ) ),
                   ( ( cx * cz * sy ) - ( cy * sx * sz ) ),
                   ( ( cx * cy * sz ) + ( cz * sx * sy ) ) );
    }

    //! Returns a quaternion [ 0, v ] from a given Vector3D.
    /*!
        \param[in] v the vector part
        \sa Quaternion( const vec3& v )
    **/
    static Quaternion VecToQuat( const vec3& v ) { return Quaternion( 0.0, v ); }

    //! Returns a quaternion [ 0, v ] from a given vector.
    /*!
        \param[in] x the X value
        \param[in] y the Y value
        \param[in] z the Z value
        \sa Quaternion( const double x, const double y, const double z )
    **/
    static Quaternion VecToQuat( const double x,
                                 const double y,
                                 const double z ) { return Quaternion( 0.0, x, y, z ); }

    //! Returns a quaternion [ cos(angle/2), sin(angle/2)v ] from a given axis and angle of rotation.
    /*!
        \param[in] angle angle of rotation
        \param[in] axis axis of rotation
    **/
    static Quaternion QuatRot( const double angle,
                               const vec3& axis ) {
        return Quaternion( qCos( angle / 2.0 ), ( qSin( angle / 2.0) * axis ) );
    }

    //! Returns a quaternion [ cos(angle/2), sin(angle/2)( x, y, z ) ] from a given axis and angle of rotation.
    /*!
        \param[in] angle angle of rotation
        \param[in] x the X value
        \param[in] y the Y value
        \param[in] z the Z value
    **/
    static Quaternion QuatRot( const double angle,
                               const double x,
                               const double y,
                               const double z ) {
        return Quaternion( qCos( angle / 2.0 ), ( qSin( angle / 2.0) * vec3( x, y, z ) ) );
    }

    //! Returns a quaternion from a given set of Euler angles.
    /*!
        \param[in] angle Euler angles
    **/
    static Quaternion EulerToQuat( const vec3& angle ) {
        double cx = qCos( angle.X() / 2.0 ); double cy = qCos( angle.Y() / 2.0 ); double cz = qCos( angle.Z() / 2.0 );
        double sx = qSin( angle.X() / 2.0 ); double sy = qSin( angle.Y() / 2.0 ); double sz = qSin( angle.Z() / 2.0 );
        return Quaternion( ( ( cx * cy * cz ) + ( sx * sy * sz ) ),
                           vec3( ( ( cy * cz * sx ) + ( cx * sy * sz ) ),
                                 ( ( cx * cz * sy ) - ( cy * sx * sz ) ),
                                 ( ( cx * cy * sz ) + ( cz * sx * sy ) ) ) );
    }

    //! Returns a quaternion from a given set of Euler angles.
    /*!
        \param[in] x_angle rotation around X axis
        \param[in] y_angle rotation around Y axis
        \param[in] z_angle rotation around Z axis
    **/
    static Quaternion EulerToQuat( const double x_angle,
                                   const double y_angle,
                                   const double z_angle ) {
        double cx = qCos( x_angle / 2.0 ); double cy = qCos( y_angle / 2.0 ); double cz = qCos( z_angle / 2.0 );
        double sx = qSin( x_angle / 2.0 ); double sy = qSin( y_angle / 2.0 ); double sz = qSin( z_angle / 2.0 );
        return Quaternion( ( ( cx * cy * cz ) + ( sx * sy * sz ) ),
                           vec3( ( ( cy * cz * sx ) + ( cx * sy * sz ) ),
                                 ( ( cx * cz * sy ) - ( cy * sx * sz ) ),
                                 ( ( cx * cy * sz ) + ( cz * sx * sy ) ) ) );
    }

    // ANGLE
    //! Returns the angle of the rotation defined by the quaternion.
    inline double Angle() const { return ( 2.0 * qAcos( Normalized()._s ) ); }

    // AXIS
    //! Returns the axis of rotation defined by the quaternion.
    inline vec3 Axis() const {
        Quaternion n = Normalized();
        double theta = 2.0* qAcos( n._s );
        return ( n._v / qSin( theta ));
    }

    // MATRIX
    //! Returns the rotation matrix defined by the quaternion.
    inline Matrix3x3 toMatrix() const {
        double x = _v.X();
        double y = _v.Y();
        double z = _v.Z();
        double w = _s;
        Matrix3x3 M;
        M.m[0][0] = 1.0 - ( 2.0 * y * y ) - ( 2.0 * z * z );
        M.m[0][1] =       ( 2.0 * x * y ) - ( 2.0 * z * w );
        M.m[0][2] =       ( 2.0 * x * z ) + ( 2.0 * y * w );
        M.m[1][0] =       ( 2.0 * x * y ) + ( 2.0 * z * w );
        M.m[1][1] = 1.0 - ( 2.0 * x * x ) - ( 2.0 * z * z );
        M.m[1][2] =       ( 2.0 * y * z ) - ( 2.0 * x * w );
        M.m[2][0] =       ( 2.0 * x * z ) - ( 2.0 * y * w );
        M.m[2][1] =       ( 2.0 * y * z ) + ( 2.0 * x * w );
        M.m[2][2] = 1.0 - ( 2.0 * x * x ) - ( 2.0 * x * x );
        return M;
    }

    //! Returns the rotation matrix defined by the quaternion.
    /*!
        \param[out] m11 matrix element
        \param[out] m12 matrix element
        \param[out] m13 matrix element
        \param[out] m21 matrix element
        \param[out] m22 matrix element
        \param[out] m23 matrix element
        \param[out] m31 matrix element
        \param[out] m32 matrix element
        \param[out] m33 matrix element
    **/
    inline void toMatrix( double& m11, double& m12, double& m13,
                          double& m21, double& m22, double& m23,
                          double& m31, double& m32, double& m33 ) const {
        double x = _v.X();
        double y = _v.Y();
        double z = _v.Z();
        double w = _s;
        m11 = 1.0 - ( 2.0 * y * y ) - ( 2.0 * z * z );
        m12 =       ( 2.0 * x * y ) - ( 2.0 * z * w );
        m13 =       ( 2.0 * x * z ) + ( 2.0 * y * w );
        m21 =       ( 2.0 * x * y ) + ( 2.0 * z * w );
        m22 = 1.0 - ( 2.0 * x * x ) - ( 2.0 * z * z );
        m23 =       ( 2.0 * y * z ) - ( 2.0 * x * w );
        m31 =       ( 2.0 * x * z ) - ( 2.0 * y * w );
        m32 =       ( 2.0 * y * z ) + ( 2.0 * x * w );
        m33 = 1.0 - ( 2.0 * x * x ) - ( 2.0 * x * x );
    }

    //! Returns the rotation matrix defined by the quaternion.
    /*!
        \param[out] r0 first matrix row
        \param[out] r1 second matrix row
        \param[out] r2 third matrix row
    **/
    inline void toMatrix( vec3& r0,
                          vec3& r1,
                          vec3& r2 ) const {
        double x = _v.X();
        double y = _v.Y();
        double z = _v.Z();
        double w = _s;
        r0[0] = 1.0 - ( 2.0 * y * y ) - ( 2.0 * z * z );
        r0[1] =       ( 2.0 * x * y ) - ( 2.0 * z * w );
        r0[2] =       ( 2.0 * x * z ) + ( 2.0 * y * w );
        r1[0] =       ( 2.0 * x * y ) + ( 2.0 * z * w );
        r1[1] = 1.0 - ( 2.0 * x * x ) - ( 2.0 * z * z );
        r1[2] =       ( 2.0 * y * z ) - ( 2.0 * x * w );
        r2[0] =       ( 2.0 * x * z ) - ( 2.0 * y * w );
        r2[1] =       ( 2.0 * y * z ) + ( 2.0 * x * w );
        r2[2] = 1.0 - ( 2.0 * x * x ) - ( 2.0 * x * x );
    }

    //! Returns the rotation matrix defined by a given quaternion q.
    /*!
        \param[in] q a quaternion
    **/
    static Matrix3x3 QuatToMatrix( const Quaternion& q ) {
        double x = q._v.X();
        double y = q._v.Y();
        double z = q._v.Z();
        double w = q._s;
        Matrix3x3 M;
        M.m[0][0] = 1.0 - ( 2.0 * y * y ) - ( 2.0 * z * z );
        M.m[0][1] =       ( 2.0 * x * y ) - ( 2.0 * z * w );
        M.m[0][2] =       ( 2.0 * x * z ) + ( 2.0 * y * w );
        M.m[1][0] =       ( 2.0 * x * y ) + ( 2.0 * z * w );
        M.m[1][1] = 1.0 - ( 2.0 * x * x ) - ( 2.0 * z * z );
        M.m[1][2] =       ( 2.0 * y * z ) - ( 2.0 * x * w );
        M.m[2][0] =       ( 2.0 * x * z ) - ( 2.0 * y * w );
        M.m[2][1] =       ( 2.0 * y * z ) + ( 2.0 * x * w );
        M.m[2][2] = 1.0 - ( 2.0 * x * x ) - ( 2.0 * x * x );
        return M;
    }

    // NORM
    //! Returns the norm of the quaternion.
    inline double Norm() const { return ( qSqrt( ( _s * _s ) + _v.NormSqr() ) ); }

    //! Returns the squared norm of the quaternion.
    inline double NormSqr() const { return ( ( _s * _s ) + _v.NormSqr() ); }

    // NORMALIZATION
    //! Normalizes the quaternion.
    inline void Normalize() {
        double norm = Norm();
        if( norm != 0.0 ) { _s /= norm; _v /= norm; }
    }

    //! Returns a normalized version of the quaternion.
    inline Quaternion Normalized() const {
        double norm = Norm();
        if( norm != 0.0 ) { return Quaternion( ( _s / norm),( _v / norm ) ); }
        return Quaternion( 0.0, 0.0, 0.0, 0.0 );
    }

    // ZERO
    //! Transforms the quaternion into the null quaternion.
    inline void setZero() { _s = 0.0; _v.setZero(); }

    //! Returns true if the quaternion is the null quaternion.
    inline bool isZero() const { return ( ( _s == 0.0 ) && ( _v.isZero() ) ); }

    //! Returns the null quaternion.
    static Quaternion Zero() { return Quaternion( 0.0, 0.0, 0.0, 0.0 ); }

    // IDENTITY
    //! Transforms the quaternion into the identity quaternion.
    inline void setIdentity() { _s = 1.0; _v.setZero(); }

    //! Returns true if the quaternion is equal to the identity one.
    inline bool isIdentity() const { return ( ( _s == 1.0 ) && ( _v.isZero() ) ); }

    //! Returns the identity quaternion.
    static Quaternion Identity() { return Quaternion( 1.0, 0.0, 0.0, 0.0 ); }

    // DOT PRODUCT
    //! Returns the Dot Product of two given quaternions.
    /*!
        \param[in] q0 a quaternion
        \param[in] q1 a quaternion
    **/
    static double Dot( const Quaternion& q0,
                       const Quaternion& q1 ) {
        return ( ( q0._s * q1._s ) + ( vec3::Dot( q0._v, q1._v ) ) );
    }

    // CONJUGATION
    //! Conjugates the quaternion.
    inline void Conjugate() { _v = -_v; }

    //! Returns the conjugate version of the quaternion.
    inline Quaternion Conjugated() const { return Quaternion( _s, -_v ); }

    // INVERSION
    //! Inverts the quaternion.
    inline void Invert() {
        double ns = NormSqr();
        if( ns != 0.0 ) { _s /= ns; _v = -_v / ns; }
    }

    //! Returns the inverted version of the quaternion.
    inline Quaternion Inverse() const {
        double ns = NormSqr();
        if( ns != 0.0 ) { return Quaternion( ( _s / ns ), ( -_v / ns ) ); }
        return Quaternion( 0.0, 0.0, 0.0, 0.0 );
    }

    // EXPONENTIATION
    //! Exponentiates the quaternion q^t.
    /*!
        \param[in] t power exponent
    **/
    inline void Exp( const double t ) {
        Quaternion q = t * Logged();
        double theta = q.Norm();
        _s = qCos( theta );
        _v = ( q._v / theta ) / qSin( theta );
    }

    //! Returns the exponentiated version of the quaternion q^t.
    /*!
        \param[in] t power exponent
    **/
    inline Quaternion Exped( const double t ) const {
        Quaternion q = t * Logged();
        double theta = q.Norm();
        q._s = qCos( theta );
        q._v = ( q._v / theta ) / qSin( theta );
        return q;
    }

    // LOGARITHM
    //! Transforms the quaternion into log(q).
    inline void Log() {
        Normalize();
        double theta = qAcos( _s );
        _s = 0.0;
        _v = ( _v / qSin( theta ) ) * theta;
    }

    //! Returns the log version of the quaternion.
    inline Quaternion Logged() const {
        Quaternion q = Normalized();
        double theta = qAcos( q._s );
        return Quaternion( 0.0, ( ( q._v / qSin( theta ) * theta ) ) );
    }

    // ROTATION
    //! Rotates a point by the rotation defined by this quaternion.
    /*!
        \param[in] v a point in 3D space
    **/
    inline vec3 Rot( const vec3& v ) const { return ( ( *this ) * v * Inverse() )._v; }

    //! Rotates a Vector3D v by the rotation defined by Quaternion q.
    /*!
        \param[in] q a rotation quaternion
        \param[in] v a point in 3D space
    **/
    static vec3 Rot( const Quaternion& q,
                     const vec3& v ) { return ( q * v * q.Inverse() )._v; }

    // INTERPOLATION
    //! Returns the quaternion resulting in the linear interpolation of q0 and q1.
    /*!
        \param[in] q0 the first quaternion
        \param[in] q1 the second quaternion
        \param[in] t interpolation parameter
    **/
    static Quaternion LErp( const Quaternion& q0,
                            const Quaternion& q1,
                            const double t ) {
        if( t <= 0.0 ) return q0; if( t >= 1.0 ) return q1;
        return ( ( q0 * ( 1.0 - t ) ) + ( q1 * t ) );
    }

    //! Returns the quaternion resulting in the normalized linear interpolation of q0 and q1.
    /*!
        \param[in] q0 the first quaternion
        \param[in] q1 the second quaternion
        \param[in] t interpolation parameter
    **/
    static Quaternion NLErp( const Quaternion& q0,
                             const Quaternion& q1,
                             const double t ) {
        if( t <= 0.0 ) return q0; if( t >= 1.0 ) return q1;
        return ( ( q0 * ( 1.0 - t ) ) + ( q1 * t ) ).Normalized();
    }

    //! Returns the quaternion resulting in the spherical linear interpolation of q0 and q1.
    /*!
        \param[in] q0 the first quaternion
        \param[in] q1 the second quaternion
        \param[in] t interpolation parameter
    **/
    static Quaternion SLErp( const Quaternion& q0,
                             const Quaternion& q1,
                             const double t ) {
        if( t <= 0.0 ) return q0; if( t >= 1.0 ) return q1;
        double theta = Dot( q0, q1 );
        Quaternion q = q1;
        if( theta < 0.0 ) { theta = qAcos( -theta ); q = -q; } else { theta = qAcos( theta ); }
        return ( ( ( q0 * qSin( ( 1.0 - t ) * theta ) ) + ( q * qSin( t * theta ) ) ) / qSin( theta ) );
    }

    //! Returns the quaternion resulting in the interpolation of q0, q1, q2 and q3.
    /*!
        \param[in] q0 the first quaternion
        \param[in] q1 the second quaternion
        \param[in] q2 the first quaternion
        \param[in] q3 the second quaternion
        \param[in] t interpolation parameter
    **/
    static Quaternion Squad( const Quaternion& q0,
                             const Quaternion& q1,
                             const Quaternion& q2,
                             const Quaternion& q3,
                             const double t ) {
        return SLErp( SLErp( q0, q1, t ), SLErp( q2, q3, t ), ( ( 2.0 * t ) * ( 1.0 - t ) ) );
    }

    // OPERATOR
    //! Returns the vector component specified by i index i.e. v[0] returns the x component.
    /*!
        \param[in] i the index of the component
        \sa S(), X(), Y(), Z(), V( double& x, double& y, double& z ), Quat( double& s, double& x, double& y, double& z )
    **/
    inline double& operator[]( const int i ) {
        assert( i > 0 ); assert( i < 4 );
        if( i == 0 ) { return _s; }
        return _v[i - 1];
    }

    //! Transforms this quaternion into q and returns a reference to this quaternion.
    inline Quaternion& operator=( const Quaternion& q ) { _s  = q._s; _v  = q._v; return *this; }

    //! Adds q to this quaternion and returns a reference to this quaternion.
    inline Quaternion& operator+=( const Quaternion& q ) { _s += q._s; _v += q._v; return *this; }

    //! Subtracts q to this quaternion and returns a reference to this quaternion.
    inline Quaternion& operator-=( const Quaternion& q ) { _s -= q._s; _v -= q._v; return *this; }

    //! Multiplies this quaternion by q and returns a reference to this quaternion.
    inline Quaternion& operator*=( const Quaternion& q ) {
        setQuat( ( ( _s * q._s ) - ( _v * q._v ) ),
                 ( ( _s * q._v ) + ( q._s * _v ) + vec3::Cross( _v, q._v ) ) );
        return *this;
    }

    //! Multiplies this quaternion by [0, v] and returns a reference to this quaternion.
    inline Quaternion& operator*=( const vec3& v ) {
        setQuat( ( - ( _v * v ) ), ( ( _s * v ) + vec3::Cross( _v, v ) ) ); return *this;
    }

    //! Multiplies this quaternion by scalar s and returns a reference to this quaternion.
    inline Quaternion& operator*=( const double s ) { _s *= s; _v *= s; return *this; }

    //! Divides this quaternion by scalar s and returns a reference to this quaternion. Cause the algorithm to stop if s equals 0.
    inline Quaternion& operator/=( const double s ) { assert( s != 0.0 ); _s /= s; _v /= s; return *this; }

    //! Returns a Quaternion that is the negation of q.
    friend inline Quaternion operator-( const Quaternion& q ) { return Quaternion( -q._s, -q._v ); }

    //! Returns a Quaternion that is formed by adding q1 to q0.
    friend inline Quaternion operator+( const Quaternion& q0, const Quaternion& q1 ) {
        return Quaternion( ( q0._s + q1._s ), ( q0._v + q1._v ) );
    }

    //! Returns a Quaternion that is formed by subtracting q1 to q0.
    friend inline Quaternion operator-( const Quaternion& q0, const Quaternion& q1 ) {
        return Quaternion( ( q0._s - q1._s ), ( q0._v - q1._v ) );
    }

    //! Returns a Quaternion that is formed by multiplying q0 by q1.
    friend inline Quaternion operator*( const Quaternion& q0, const Quaternion& q1 ) {
        return Quaternion( ( ( q0._s * q1._s ) - ( q0._v * q1._v ) ),
                           ( ( q0._s * q1._v ) + ( q1._s * q0._v ) + vec3::Cross( q0._v, q1._v ) ) );
    }

    //! Returns a Quaternion that is formed by multiplying q by [0, v].
    friend inline Quaternion operator*( const Quaternion& q, const vec3& v ) {
        return Quaternion( ( - ( q._v * v ) ),
                           ( ( q._s * v ) + vec3::Cross( q._v, v ) ) );
    }

    //! Returns a Quaternion that is formed by multiplying [0, v] by q.
    friend inline Quaternion operator*( const vec3& v, const Quaternion& q ) {
        return Quaternion( ( - ( v * q._v ) ), ( ( q._s * v ) + vec3::Cross( v, q._v ) ) );
    }

    //! Returns a Quaternion that is formed by multiplying q by scalar s.
    friend inline Quaternion operator*( const Quaternion& q, const double s ) {
        return Quaternion( ( q._s * s ), ( q._v * s ) );
    }

    //! Returns a Quaternion that is formed by multiplying q by scalar s.
    friend inline Quaternion operator*( const double s,  const Quaternion& q ) {
        return Quaternion( ( q._s * s ), ( q._v * s ) );
    }

    //! Returns a Quaternion that is formed by dividing q by scalar s. Cause the algorithm to stop if s equals 0.
    friend inline Quaternion operator/( const Quaternion& q, const double s ) {
        assert( s != 0.0 ); return Quaternion( ( q._s / s ), ( q._v / s ) );
    }

    //! Returns true if q0 is equal to q1, false otherwise.
    friend inline bool operator==( const Quaternion& q0, const Quaternion& q1 ) {
        return ( ( q0._s == q1._s ) && ( q0._v == q1._v ) );
    }

    //! Returns true if q0 is not equal to q1, false otherwise.
    friend inline bool operator!=( const Quaternion& q0, const Quaternion& q1 ) {
        return ( ( q0._s != q1._s ) || ( q0._v != q1._v ) );
    }

protected:
    //! \cond
    // VARIABLE
    double _s;
    vec3   _v;
    //! \endcond
};

//! \typedef A more compact way for using Quaternion.
typedef Quaternion quat;

#endif // QUATERNION_H
