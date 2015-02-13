#ifndef ROCKET_H
#define ROCKET_H

#include "objloader.h"
#include "vector3d.h"

class Rocket {
public:
    //! Default constructor
    Rocket();

    /*! Get the position of the rocket in scene
     * \ sa returns a position (x, y, z)
     */
    Vector3D GetPosition();

    /*! Set the position of the rocket in scene
     * \ param[in] pos: the new postion
     */
    void SetPosition(Vector3D pos);

    /*! Get the velocity of the rocket in scene
     * \ sa returns a velocity (x, y, z)
     */
    Vector3D GetVelocity();

    /*! Set the velocity of the rocket in scene
     * \ param[in] val: the new velocity
     */
    void SetVelocity(Vector3D vel);

    /*! Get the acceleration of the rocket in scene
     * \ sa returns a acceleration (x, y, z)
     */
    Vector3D GetAcceleration();

    /*! Set the acceleration of rocket in scene
     * \ param[in] pos: the new postion
     */
    void SetAcceleration(Vector3D acc);

private:
    //! A 3D point
    Vector3D _position;

    //! A 3D velocity
    Vector3D _velocity;

    //! A 3D acceleration
    Vector3D _acceleration;
};

#endif // ROCKET_H
