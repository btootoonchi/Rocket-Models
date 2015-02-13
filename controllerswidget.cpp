#include "controllerswidget.h"
#include <math.h>
#include <GL/glu.h>

#define RADPERDEG 0.0174533

ControllersWidget::ControllersWidget()
    : RADIUS(5.0), SAMPLESTEP(0.02) {
}

ControllersWidget::~ControllersWidget() {
}

void ControllersWidget::AddPoint(QPoint mousePts) {
    std::vector<Vec2d> temp;
    Vec2d point;

    int i=_mouseInputs.size();
    while (i>0 && _mouseInputs[--i].x > mousePts.x()) {
        point = _mouseInputs[i];
        temp.push_back(point);
        _mouseInputs.pop_back();
    }
    _mouseInputs.push_back(Vec2d(mousePts.x(), mousePts.y()));
    i = temp.size()-1;
    while (i>=0) {
        _mouseInputs.push_back(temp[i--]);
    }
    temp.clear();
}

int ControllersWidget::SelectPoint(QPoint mousePts) {
    for (size_t i = 0; i < _mouseInputs.size(); ++ i) {
        const Vec2d & currentPts = _mouseInputs[i];
        if ( (currentPts.x - RADIUS < mousePts.x() && currentPts.x + RADIUS > mousePts.x())
             &&(currentPts.y - RADIUS < mousePts.y() && currentPts.y + RADIUS > mousePts.y())) {
            return (int)i;
        }
    }
    return -1;
}

void ControllersWidget::SetControlPoints() {
    _bezier.SetControlPoints(_mouseInputs);
}

void ControllersWidget::Arrow(GLdouble x1,GLdouble y1,GLdouble z1,GLdouble x2,GLdouble y2,GLdouble z2,GLdouble D) {
    double x = x2 - x1;
    double y = y2 - y1;
    double z = z2 - z1;
    double L = sqrt(x * x + y * y + z * z);

    GLUquadricObj *quadObj;

    glPushMatrix ();

    glTranslated(x1,y1,z1);

    if((x != 0.0)||(y != 0.0)) {
        glRotated(atan2(y,x)/RADPERDEG,0.0,0.0,1.0);
        glRotated(atan2(sqrt(x*x+y*y),z)/RADPERDEG,0.0,1.0,0.0);
    } else if (z < 0){
        glRotated(180,1.0,0.0,0.0);
    }

    glTranslatef(0,0,L - 4 * D);

    quadObj = gluNewQuadric ();
    gluQuadricDrawStyle (quadObj, GLU_FILL);
    gluQuadricNormals (quadObj, GLU_SMOOTH);
    gluCylinder(quadObj, 2 * D, 0.0, 4 * D, 32, 1);
    gluDeleteQuadric(quadObj);

    quadObj = gluNewQuadric ();
    gluQuadricDrawStyle (quadObj, GLU_FILL);
    gluQuadricNormals (quadObj, GLU_SMOOTH);
    gluDisk(quadObj, 0.0, 2 * D, 32, 1);
    gluDeleteQuadric(quadObj);

    glTranslatef(0,0,-L + 4 * D);

    quadObj = gluNewQuadric ();
    gluQuadricDrawStyle (quadObj, GLU_FILL);
    gluQuadricNormals (quadObj, GLU_SMOOTH);
    gluCylinder(quadObj, D, D, L - 4 * D, 32, 1);
    gluDeleteQuadric(quadObj);

    quadObj = gluNewQuadric ();
    gluQuadricDrawStyle (quadObj, GLU_FILL);
    gluQuadricNormals (quadObj, GLU_SMOOTH);
    gluDisk(quadObj, 0.0, D, 32, 1);
    gluDeleteQuadric(quadObj);

    glPopMatrix ();

}

void ControllersWidget::DrawAxes(Vec2d vertStart, Vec2d horzStart, GLdouble h, GLdouble w) {
    glPushMatrix();
    glColor3f(0.6f, 0.7f, 0.8f);
    Arrow(vertStart.x,vertStart.y,0, vertStart.x,h,0, 3);
    Arrow(horzStart.x,horzStart.y,0, w,horzStart.y,0, 3);
    glPopMatrix();
}

void ControllersWidget::DrawGrid() {
    glPushMatrix();
    glLineWidth(0.5f);
    glColor3f(0.7f, 0.7f, 0.8f);

    glBegin(GL_LINES);
    for(float i = 45; i <= 230; i += 20) {
        //horizental lines
        glVertex2f(27,i / 2 + 12);
        glVertex2f(225,i / 2 + 12);

        //vertical lines
        glVertex2f(i,27);
        glVertex2f(i,125);
    }
    glEnd();
    glPopMatrix();
}

void ControllersWidget::DrawLine(Vec2d start, Vec2d end, int width) {
    glPushMatrix();
    glColor3f(1.0f, 0.9f, 0.0f);
    glLineWidth(width);
    glBegin(GL_LINES);
    glVertex2f(start.x, start.y);
    glVertex2f(end.x, end.y);
    glEnd();
    glPopMatrix();
}

void ControllersWidget::DrawPoints() {
    //Draw the points and dots
    glPushMatrix();
    glColor3f(1.0f, 0.6f, 0.0f);
    glPointSize(5.0);
    glBegin (GL_POINTS);
    glVertex2f(_mouseInputs[0].x , _mouseInputs[0].y);
    for (size_t i = 0; i < _mouseInputs.size(); i++) {
        glVertex2f(_mouseInputs[i].x , _mouseInputs[i].y);
    }
    glEnd();
    glPopMatrix();
}

void ControllersWidget::DrawCurve() {
    glPushMatrix();
    //Draw the Bezier spline
    if (_mouseInputs.size() > 1)
    {
        _bezier.SetControlPoints(_mouseInputs);
        glLineWidth(4);
        glColor3f(1.0f, 0.9f, 0.0f);
        Vec2d lastPoint = _mouseInputs[0];
        for (double parametricPos = _bezier.ParametricStart() + SAMPLESTEP;
             parametricPos < _bezier.ParametricEnd();
             parametricPos += SAMPLESTEP)
        {
            const Vec2d & sampledPoint = _bezier.Sample(parametricPos);
            glBegin(GL_LINES);
            glVertex2f(lastPoint.x, lastPoint.y);
            glVertex2f(sampledPoint.x, sampledPoint.y);
            lastPoint = sampledPoint;
            glEnd();
        }
    }
    glPopMatrix();

    //Draw the points and dots
    if (_mouseInputs.size() > 0)
        DrawPoints();

}

