#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "objloader.h"
#include<QWindow>
#include <QtOpenGL/QGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <GL/glu.h>
#include <vector>
#include "path.h"
#include "rocket.h"
#include <math.h>
#include "quaternion.h"

class QGLShaderProgram;

class GLWidget : public QGLWidget, public QOpenGLFunctions {
    Q_OBJECT

public:
    //! Default constructor
    GLWidget(QWidget *parent = 0);

    //! Default destructor
    ~GLWidget();

private:
    //! Path attribute
    Path *_path;

    //! Rocket attribute
    Rocket *_rocket;

    //! Objloader attribute
    Objloader *_objloader;

    //! (x, y, z) position that is entered by a user
    double _xPoint, _yPoint, _zPoint;

    //! Simulation time interval
    GLdouble _simulationTime;

    //! BezierSpline attribute
    BezierSpline<Vec3d> _bezier;

    //! Camera view rotation on y axi
    float _viewRotatey;

    //! Camera view rotation on x axi
    float _viewRotateVert;

    //! Camera zoom value
    float _zoom;

    //! Camera position in the 3D scene
    Vec3d _cameraPosition;

    //! Object position in the 3D scene
    Vec3d _objectPosition;

    //! List of vertex of a selected rocket model
    std::vector<glm::vec4> _vertices;

    //! List of points in parameter space of curve or surface of a selected rocket model
    std::vector<glm::vec3> _uvs;

    //! List of norms of a selected rocket model
    std::vector<glm::vec4> _normals;

    //! Translation vector
    Vector3D _translateVector;

    //! Head of a Rocket
    Vector3D _heading;

    //! Rotation array
    GLdouble _rotation[16];

    /*! Draw the surface grid */
    void Draw3DGrid();

    /*! Initialize a texture for rocket model */
    void LoadTexture();

    /*! draw a selected rocket modlel */
    void DrawModel();

    /*! Initilize the rotation matrix */
    void InitRotation();

    /*! Convert a matrix to a double list */
    void MatrixToDoubleList(QMatrix4x4 matrix);

    /*! Transform a rocket model from a position to next position */
    void TransformModel(Vector3D newPos, Vector3D nextPos);

protected:
    /// OPENGL
    void initializeGL();
    void paintGL();

signals:
public slots:
private slots:
public slots:
    /*! Clear a path */
    void ClearPath();

    /*! Select a rocket model */
    void SelectRocket();

    /*! Play the animation */
    void StartAnimation();

    /*! Get the simulation time */
    GLdouble getSimulationTime();

    /*! Set simulation time. It means that time frame
     * \ param[in] time
     */
    void setSimulationTime(GLdouble time);

    /*! Get a X position of one point of a path from a user
     * \ param[in] x
     */
    void GetXPosition(double x);

    /*! Get a Y position of one point of a path from a user
     * \ param[in] y
     */
    void GetYPosition(double y);

    /*! Get a Z position of one point of a path from a user
     * \ param[in] z
     */
    void GetZPosition(double z);

    /*! Set a (x,y,z) position to a path points list */
    void SetPosition();

    /*! Animate rocket through the path
     * \ param[in] position of the rocket
     * \ param[in] forward is true or false. If it is true, we will see the animation
     */
    void Animate(GLdouble position, bool forward);

    /*! Reset verything as defualt, and the application is ready to test again */
    void ResetModel();

protected slots:

    /*! When user resizes main window, the scrollArea will be resized and it will call this function from
     * its attached GLWidget
     * \ param[in] widthe and height of the screen
     */
    void resizeGL(int width, int height);

    /*! Handle keybord press event in scrollArea
     * \ param[in] e is keybord event
     */
    void keyPressEvent(QKeyEvent *e);
};

#endif // GLWIDGET_H
