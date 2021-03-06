#ifndef VELOCITYCONTROLLER_H
#define VELOCITYCONTROLLER_H

#include <QGLWidget>
#include "controllerswidget.h"

class VelocityController : public QGLWidget, public ControllersWidget {
    Q_OBJECT

public:
    //! Default constructor
    VelocityController(QWidget *parent = 0);

    /*! Get velocity in instant t
     * \ param[in] t: time
     */
    GLdouble getVelocity(double t);

protected:
    /// OPENGL
    void initializeGL();
    void paintGL();

signals:
    void valueChanged();

public slots:
    void ClearVelocityChart();

protected slots:

    /*! When user resizes main window, the scrollArea will be resized and it will call this function from
     * its attached GLWidget
     * \ param[in] widthe and height of the screen
     */
    void resizeGL(int width, int height);

    /*! Handle mouse press event in scrollArea
     * \ param[in] event is mouse event
     */
    void mousePressEvent(QMouseEvent *event);

    /*! Handle mouse press button is released in scrollArea
     * \ param[in] event is mouse event
     */
    void mouseReleaseEvent(QMouseEvent *event);

    /*! Handle Mouse Move Event
     * \ param[in] event is mouse event
     */
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // VELOCITYCONTROLLER_H
