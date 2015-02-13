#include "path.h"

const double SAMPLESTEP = 0.02;

Path::Path() {
}

void Path::AddPoint(Vec3d Point) {
    _mouseInputs.push_back(Point);
}

vector<Vec3d> Path::GetMouseInputs() {
    return _mouseInputs;
}

void Path::Clear() {
    _mouseInputs.clear();
}

void Path::Draw() {
    if (_mouseInputs.size() > 0) {
        glPushMatrix();
        //Draw the points and dots
        glColor3f(1.0f, 0.0f, 0.0f);
        glPointSize(5.0);
        glBegin (GL_POINTS);
        glVertex3f(_mouseInputs[0].x , _mouseInputs[0].y, _mouseInputs[0].z);
        for (size_t i=0; i<_mouseInputs.size(); i++) {
            glVertex3f(_mouseInputs[i].x , _mouseInputs[i].y, _mouseInputs[i].z);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
        //Draw path
        if (_mouseInputs.size() > 1) {
            _bezier.SetControlPoints(_mouseInputs);
            glLineWidth(4);
            glColor3f(0.2f, 0.5f, 0.2f);
            Vec3d lastPoint = _mouseInputs[0];
            glBegin(GL_LINES);
            for (double pos=_bezier.ParametricStart()+SAMPLESTEP; pos<_bezier.ParametricEnd(); pos += SAMPLESTEP) {
                const Vec3d & sampledPoint = _bezier.Sample(pos);
                glVertex3f(lastPoint.x, lastPoint.y, lastPoint.z);
                glVertex3f(sampledPoint.x, sampledPoint.y, sampledPoint.z);
                lastPoint = sampledPoint;
            }
            glEnd();
        }
        glPopMatrix();
    }
}
