//-------------------------------------------------------------------------------------------
//  University of Victoria Computer Science Department 
//	FrameWork for OpenGL application under QT
//  Course title: Computer Animation CSC 578A
//-------------------------------------------------------------------------------------------
#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <GL/glu.h>
#include "ui_MainWindow.h"
#include "foundation.h"

class GLWidget;
class PositionController;
class VelocityController;
class AccelerationController;

//Create a window and load the components from generated code ui_MainWindow.h
class Window : public QDialog, public Ui::frmMain {
	Q_OBJECT;

public:
    //! Default constructor
	Window(QWidget *parent = 0);
	
private:
    //! GLWidget attribute. It hold the GLWidget instance
    GLWidget *m_glWidget;

    //! PositionController attribute. It hold the PositionController instance
    PositionController *m_positionController;

    //! VelocityController attribute. It hold the VelocityController instance
    VelocityController *m_velocityController;

    //! AccelerationController attribute. It hold the AccelerationController instance
    AccelerationController *m_accelerationController;

    //! Simulation timer
    QTimer *_timer;

private slots:
    /*! Update the velocity and acceleration widgets */
    void updateVelAccWidgets();

    /*! Update the position and velocity widgets */
    void updatePosVelWidgets();

    /*! Update the acceleration and position widgets */
    void updateAccPosWidgets();

    /*! Start animation. */
    void Animate();
};


#endif
