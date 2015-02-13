//-------------------------------------------------------------------------------------------
//  This is a demo. program for open gl vertex arrays
//-------------------------------------------------------------------------------------------
#include "glwidget.h"

#include <QtGui>
#include <QtOpenGL>

#include "window.h"
#include "positioncontroller.h"
#include "velocitycontroller.h"
#include "accelerationcontroller.h"

const double timeStart = 25;
const double timeEnd = 225;
const double timeScale = 2000;
const double timeDrawScale = 200;
const double timeStep = 0.02;   //100ms

const double positionScale = 0.01;
const double positionStart = 25;
const double positionEnd = 125;

const double velocityStart = 75;
const double velocityScale = 10;

#define SIMULATION_STEP 0.05

enum { POSITION, VELOCITY, ACCELERATION };

//------------------------------------------------------------------------------------
// Creates and initializes the main window for application
//------------------------------------------------------------------------------------
Window::Window(QWidget *parent):QDialog(parent)
{
    //We create an instance of GLWidget component we built in glwidget.h
	m_glWidget = new GLWidget;
    m_positionController = new PositionController;
    m_velocityController = new VelocityController;
    m_accelerationController = new AccelerationController;
	
	//Setup application interface. Creates all the required components and sliders.
	setupUi(this);

    //The widget accepts keyboard focus by pushing buttons
    m_glWidget->setFocusPolicy(Qt::ClickFocus);

    //We need to attach our m_glWidget to glWidgetArea
    //All our drawings will be on glWidgetArea
    glWidgetArea->setWidget(m_glWidget);
    controllerArea->setWidget(m_positionController);
    velocityControllerArea->setWidget(m_velocityController);
    accelerationControllerArea->setWidget(m_accelerationController);

    //Setting up all the SIGNALS and SLOTS
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
    connect(clearButton, SIGNAL(clicked()), m_glWidget, SLOT(ClearPath()));
    connect(clearButton, SIGNAL(clicked()), m_glWidget, SLOT(ResetModel()));
    connect(clearButton, SIGNAL(clicked()), m_positionController, SLOT(ClearPositionChart()));
    connect(clearButton, SIGNAL(clicked()), m_velocityController, SLOT(ClearVelocityChart()));
    connect(clearButton, SIGNAL(clicked()), m_accelerationController, SLOT(ClearAccelerationChart()));

    connect(selectButton, SIGNAL(clicked()), m_glWidget, SLOT(SelectRocket()));
    connect(startButton, SIGNAL(clicked()), m_glWidget, SLOT(StartAnimation()));
    connect(xDoubleSpinBox, SIGNAL(valueChanged(double)), m_glWidget, SLOT(GetXPosition(double)));
    connect(yDoubleSpinBox, SIGNAL(valueChanged(double)), m_glWidget, SLOT(GetYPosition(double)));
    connect(zDoubleSpinBox, SIGNAL(valueChanged(double)), m_glWidget, SLOT(GetZPosition(double)));
    connect(setPositionButton, SIGNAL(clicked()), m_glWidget, SLOT(SetPosition()));

    connect(m_positionController, SIGNAL(valueChanged()), this, SLOT(updateVelAccWidgets()));
    connect(m_velocityController, SIGNAL(valueChanged()), this, SLOT(updateAccPosWidgets()));
    connect(m_accelerationController, SIGNAL(valueChanged()), this, SLOT(updatePosVelWidgets()));

    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(Animate()));
    _timer->start(timeStep * timeScale);  //in miliseconds
}

void Window::updateVelAccWidgets() {
    GLdouble time, currentPos, nextPos, currentVel, nextVel, newValue;

    //if the positions have changed, calculate velocities then accelerations
    int i=0;
    m_velocityController->_mouseInputs.clear();
    for(double t=0; t<1; t+=timeStep, i++) {
        time = timeStart + t*timeDrawScale;
        currentPos = m_positionController->getPosition(t);
        if (t+timeStep >= 1.0f)
            nextPos = m_positionController->getPosition(1.0f);
        else
            nextPos = m_positionController->getPosition(t + timeStep);
        newValue = ((nextPos-currentPos)/timeStep)*velocityScale+velocityStart;
        if (i % 5 == 0)
            m_velocityController->_mouseInputs.push_back(Vec2d(time,newValue));
    }
    m_velocityController->_mouseInputs.push_back(Vec2d(time + timeStep*timeDrawScale,newValue));
    m_velocityController->SetControlPoints();

    i=0;
    m_accelerationController->_mouseInputs.clear();
    for(double t=0; t<1; t+=timeStep, i++) {
        time = timeStart + t*timeDrawScale;
        currentVel = m_velocityController->getVelocity(t);
        if (t+timeStep >= 1.0f)
            nextVel = m_velocityController->getVelocity(1.0f);
        else
            nextVel = m_velocityController->getVelocity(t + timeStep);
        newValue = ((nextVel-currentVel)/timeStep)*velocityScale+velocityStart;
        if (i % 5 == 0)
            m_accelerationController->_mouseInputs.push_back(Vec2d(time,newValue));
    }
    m_accelerationController->_mouseInputs.push_back(Vec2d(time + timeStep*timeDrawScale,newValue));
    m_accelerationController->SetControlPoints();

    m_velocityController->updateGL();
    m_accelerationController->updateGL();
}

void Window::updatePosVelWidgets() {
    GLdouble time, currentPos, nextPos, newValue;

    //if the acceleration points have changed, calculate positions then velocities
    int i=0;
    currentPos = 0.0f;
    m_positionController->_mouseInputs.clear();
    for(double t=0; t<1; t+=timeStep, i++) {
        time = timeStart + t*timeDrawScale;
        currentPos = 0.5 * m_accelerationController->getAcceleration(t) * pow(t,2) +
                    m_velocityController->getVelocity(t-timeStep) * t + currentPos;
        if (i % 5 == 0)
            m_positionController->_mouseInputs.push_back(Vec2d(time,currentPos*velocityScale + positionStart));
    }
    m_positionController->_mouseInputs.push_back(Vec2d(time + timeStep*timeDrawScale,currentPos*velocityScale + positionStart));
    m_positionController->SetControlPoints();

    i=0;
    m_velocityController->_mouseInputs.clear();
    for(double t=0; t<1; t+=timeStep, i++) {
        time = timeStart + t*timeDrawScale;
        currentPos = m_positionController->getPosition(t);
        if (t+timeStep >= 1.0f)
            nextPos = m_positionController->getPosition(1.0f);
        else
            nextPos = m_positionController->getPosition(t + timeStep);
        newValue = ((nextPos-currentPos)/timeStep)*velocityScale+velocityStart;
        if (i % 5 == 0)
            m_velocityController->_mouseInputs.push_back(Vec2d(time,newValue));
    }
    m_velocityController->_mouseInputs.push_back(Vec2d(time + timeStep*timeDrawScale,newValue));
    m_velocityController->SetControlPoints();

    m_positionController->updateGL();
    m_velocityController->updateGL();
}


void Window::updateAccPosWidgets() {
    GLdouble time, currentPos, currentVel, nextVel, newValue;

    //if the velocities have changed, calculate accelerations then positions
    int i=0;
    m_accelerationController->_mouseInputs.clear();
    for(double t=0; t<1; t+=timeStep, i++) {
        time = timeStart + t*timeDrawScale;
        currentVel = m_velocityController->getVelocity(t);
        if (t+timeStep >= 1.0f)
            nextVel = m_velocityController->getVelocity(1.0f);
        else
            nextVel = m_velocityController->getVelocity(t + timeStep);
        newValue = ((nextVel-currentVel)/timeStep)*velocityScale+velocityStart;
        if (i % 5 == 0)
            m_accelerationController->_mouseInputs.push_back(Vec2d(time,newValue));
    }
    m_accelerationController->_mouseInputs.push_back(Vec2d(time + timeStep*timeDrawScale,newValue));
    m_accelerationController->SetControlPoints();

    i=0;
    currentPos = 0.0f;
    m_positionController->_mouseInputs.clear();
    for(double t=0; t<1; t+=timeStep, i++) {
        time = timeStart + t*timeDrawScale;
        currentPos = 0.5 * m_accelerationController->getAcceleration(t) * pow(t,2) +
                    m_velocityController->getVelocity(t-timeStep) * t + currentPos;
        if (i % 5 == 0)
            m_positionController->_mouseInputs.push_back(Vec2d(time,currentPos*velocityScale + positionStart));
    }
    m_positionController->_mouseInputs.push_back(Vec2d(time + timeStep*timeDrawScale,currentPos*velocityScale + positionStart));
    m_positionController->SetControlPoints();

    m_accelerationController->updateGL();
    m_positionController->updateGL();
}


void Window::Animate() {
    GLdouble time = m_glWidget->getSimulationTime();

    //if rocket is moving
    if (time < 1 && time >= 0) {
        time += timeStep;
        GLdouble currentPos = m_positionController->getPosition(time);
        GLdouble nextPos = m_positionController->getPosition(time + timeStep);
        emit(m_glWidget->Animate(currentPos, nextPos > currentPos));
        m_glWidget->setSimulationTime(time);

    }
}


