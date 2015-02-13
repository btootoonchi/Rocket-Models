#ifndef PATH_H
#define PATH_H

#include <QtOpenGL/QGLWidget>
#include <GL/glu.h>
#include <vector>
#include "foundation.h"
#include "Bezier.h"

class Path {
public:
    //! Default constructor
    Path();

    //! Default destructor
    ~Path();

    /*! Add a new point to a list of points
     * \ param[in] Point: a new point
     */
    void AddPoint(Vec3d Point);

    /*! Get mouse inputs
     * \ sa return a list of points
     */
    vector<Vec3d> GetMouseInputs();

    /*! Clear path, and remove all points */
    void Clear();

    /*! Draw a bezier path if there are more than one point
     * \
     */
    void Draw();

private:
    //! A list of 3D points (x,y,z)
    vector<Vec3d> _mouseInputs;

    //! BezierSpline attribute
    BezierSpline<Vec3d> _bezier;
};

#endif // PATH_H
