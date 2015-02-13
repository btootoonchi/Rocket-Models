#include <QtGui>
#include <QtOpenGL>
#include <stdio.h>
#include "rocket.h"

Rocket::Rocket() {
    _position.setX(0);
    _position.setY(0);
    _position.setZ(0);
    _velocity.setX(0);
    _velocity.setY(0);
    _velocity.setZ(0);
    _acceleration.setX(0);
    _acceleration.setY(0);
    _acceleration.setZ(0);
}


Vector3D Rocket::GetPosition() {
    return _position;
}

void Rocket::SetPosition(Vector3D pos) {
    _position = pos;
}

