#include "accelerationcontroller.h"
#include <math.h>
#include <GL/glu.h>
#include <QMouseEvent>

AccelerationController::AccelerationController(QWidget *parent) :
    QGLWidget(parent) {
    _mouseInputs.push_back(Vec2d(25,75));
    _mouseInputs.push_back(Vec2d(225,75));
}

void AccelerationController::ClearAccelerationChart() {
    _mouseInputs.clear();
    _mouseInputs.push_back(Vec2d(25,75));
    _mouseInputs.push_back(Vec2d(225,75));
    updateGL();
}

void AccelerationController::initializeGL() {
    glClearColor(0.5, 0.55, 0.65, 1.0);
    glShadeModel( GL_SMOOTH );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glPointSize(5);
}

void AccelerationController::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    DrawAxes(Vec2d(25,25),Vec2d(25,75),130,230);
    DrawGrid();
    DrawCurve();
}

void AccelerationController::mousePressEvent(QMouseEvent *e) {
    //Reverse the Y axis in mouse coordinate
    QPoint MouseLocation = e->pos();
    MouseLocation.setY(height() - e->y());
    if (e->button() == Qt::LeftButton) {
        _leftPressed = true;
        _currentPtsId = SelectPoint(MouseLocation);
    }
}

void AccelerationController::mouseReleaseEvent(QMouseEvent *e) {
    //Reverse the Y axis in mouse coordinate
    QPoint MouseLocation = e->pos();
    MouseLocation.setY(height() - e->y());
    if (e->button() == Qt::LeftButton && _leftPressed) {
        if (_currentPtsId >= 0) {
            _mouseInputs[_currentPtsId] = Vec2d(MouseLocation.x(), MouseLocation.y());
            emit(valueChanged());
        }
        _leftPressed = false;
        _currentPtsId = -1;
        updateGL();
    }
}

void AccelerationController::mouseMoveEvent(QMouseEvent *e) {
    //Reverse the Y axis in mouse coordinate
    QPoint MouseLocation = e->pos();
    MouseLocation.setY(height() - e->y());
    if ((e->buttons() & Qt::LeftButton) && _leftPressed) {
        if (_currentPtsId >= 0) {
            _mouseInputs[_currentPtsId] = Vec2d(MouseLocation.x(), MouseLocation.y());
            emit(valueChanged());
        }
    }
    updateGL();
}

void AccelerationController::resizeGL(int w, int h) {
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0,GLdouble(w),0,GLdouble(h),-10.0,10.0);
    glFlush();
    glMatrixMode(GL_MODELVIEW);
    glViewport( 0, 0, (GLint)w, (GLint)h );
    updateGL();
}

GLdouble AccelerationController::getAcceleration(double t) {
    const Vec2d & acceleration = _bezier.Sample(t);
    return (acceleration.y - 75)/100;
}
