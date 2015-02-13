#ifndef CONTROLLERSWIDGET_H
#define CONTROLLERSWIDGET_H

#include <QGLWidget>
#include <QtOpenGL/QGLWidget>
#include <vector>
#include "foundation.h"
#include "Bezier.h"

class ControllersWidget {
public:
    //! Default constructor
    ControllersWidget();

    //! Default destructor
    ~ControllersWidget();

    /*! Set control points */
    void SetControlPoints();

    std::vector<Vec2d> _mouseInputs;

protected:
    /*! Draw axes (x and y)
     * \ param[in] vertical sart point
     * \ param[in] horizantal sart point
     * \ param[in] hight
     * \ param[in] width
     */
    void DrawAxes(Vec2d vertStart, Vec2d horzStart, GLdouble h, GLdouble w);

    /*! Add a new point
     * \ param[in] mouse position
     */
    void AddPoint(QPoint mousePts);

    /*! Select a point
     * \ param[in] mouse position
     */
    int SelectPoint(QPoint mousePts);

    /*! Draw an arrow
     * \ param[in] x1: start position
     * \ param[in] y1: start position
     * \ param[in] z1: start position
     * \ param[in] x2: end position
     * \ param[in] y2: end position
     * \ param[in] z2: end position
     * \ param[in] D: solidity
     */
    void Arrow(GLdouble x1,GLdouble y1,GLdouble z1,GLdouble x2,GLdouble y2,GLdouble z2,GLdouble D);

    /*! Draw a 2D grid */
    void DrawGrid();

    /*! Draw a list of points */
    void DrawPoints();

    /*! Draw a line
     * \ param[in] start: start position
     * \ param[in] end: end position
     * \ param[in] width: width of line
     */
    void DrawLine(Vec2d start, Vec2d end, int width);

    /*! Draw a curve based on Bezier
     * \
     */
    void DrawCurve();

    //! Current position ID
    int _currentPtsId;

    //! Left key of a mouse is pressed
    bool _leftPressed;

    //! Radius of a curve
    const double RADIUS;

    //! Steps of getting a sample
    const double SAMPLESTEP;

    //! BezierSpline attribute
    BezierSpline<Vec2d> _bezier;

};

#endif // CONTROLLERSWIDGET_H
