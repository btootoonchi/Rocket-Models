#include "glwidget.h"
#include <QtOpenGL>
#include "foundation.h"

const float cameraStep = 2;
const float projectScale = 1;

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent), _simulationTime(-1) {
    _path = new Path();
    _rocket = new Rocket();
    _objloader = new Objloader();

    _xPoint = 0.0;
    _yPoint = 0.0;
    _zPoint = 0.0;

    _viewRotatey = 0;
    _viewRotateVert = 6;
    _zoom = 0.0;

    _translateVector.setX(0.0);
    _translateVector.setY(0.0);
    _translateVector.setZ(0.0);
    _heading = Vector3D(0.0,1.0,0.0);

    _objectPosition.x = 1.0;
    _objectPosition.y = 3.0;
    _objectPosition.z = 0.0;

    _cameraPosition.x = 0.0;
    _cameraPosition.y = 5.0;
    _cameraPosition.z = 8.0;

    //Initialize the rotation matrix to identity
    InitRotation();
}

GLWidget::~GLWidget() {

}

void GLWidget::Draw3DGrid() {
    glDisable(GL_LIGHTING);
    glLineWidth(1.0f);
    glColor3f(0.3f, 0.6f, 0.3f);
    glPushMatrix();

    for(float i = -10; i <= 10; i += 0.5) {
        glBegin(GL_LINES);

        //along x axis
        glVertex3f(-10, 0, i);
        glVertex3f(10, 0, i);

        //along z axis
        glVertex3f(i, 0, -10);
        glVertex3f(i, 0, 10);

        glEnd();
    }
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

void GLWidget::initializeGL() {
    // initialize
    makeCurrent();
    initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);
    static const GLfloat lightPos[4] = { 2.0f, 2.0f, 2.0f, 1.0f };
    static const GLfloat lightPos2[4] = { -2.0f, 2.0f, -2.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glClearColor(0.5, 0.6, 0.8, 1.0);

}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80, 1.0, 0.5, 500.0 );
    gluLookAt( _cameraPosition.x, _cameraPosition.y, _cameraPosition.z,
               _objectPosition.x, _objectPosition.y, _objectPosition.z,
               0.0, 1.0, 0.0 );

    //camera
    glTranslatef(0, -0.5 * projectScale, _zoom);
    glRotatef(_viewRotateVert, 1, 0, 0);
    glRotatef(_viewRotatey, 0, 1 ,0);

    //Draw the path
    _path->Draw();
    Draw3DGrid();
    DrawModel();
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, w/(float)h, 0.5, 500.0 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    updateGL();
}

void GLWidget::ClearPath() {
    _path->Clear();
    _objectPosition.x = 1.0;
    _objectPosition.y = 3.0;
    _objectPosition.z = 0.0;

    _cameraPosition.x = 0.0;
    _cameraPosition.y = 5.0;
    _cameraPosition.z = 8.0;
    updateGL();
}

void GLWidget::InitRotation() {
    for (size_t i=0; i<16; i++) {
        if (i % 5 == 0)
            _rotation[i] = 1.0;
        else
            _rotation[i] = 0.0;
    }
}

void GLWidget::MatrixToDoubleList(QMatrix4x4 matrix) {
    int k = 0;
    for (size_t i=0; i<4; i++) {
        for (size_t j=0; j<4; j++) {
            _rotation[k++] = matrix(j,i);
        }
    }
}

void GLWidget::DrawModel() {
    if (_vertices.empty())
        return;

    glPushMatrix();

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(glm::vec4), &_vertices[0], GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, _uvs.size() * sizeof(glm::vec3), &_uvs[0], GL_STATIC_DRAW);

    GLuint normalbuffer;
    glGenBuffers(1, &normalbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glBufferData(GL_ARRAY_BUFFER, _normals.size() * sizeof(glm::vec4), &_normals[0], GL_STATIC_DRAW);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,0,(void*)0);

    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);

    // 3rd attribute buffer : normals
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glVertexAttribPointer(2,4,GL_FLOAT,GL_FALSE,0,(void*)0);

    glMultMatrixd(_rotation);
    glScalef(0.1f ,0.1f ,0.1f);

    // Enable Texture Mapping and draw the triangle
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE_2D);

    glBindTexture( GL_TEXTURE_2D, bindTexture(QPixmap("../SpaceRocketGraphics/Textures/Texture.jpg")));
    glDrawArrays(GL_TRIANGLES, 0, _vertices.size());

    // Enable Texture Mapping
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void GLWidget::TransformModel(Vector3D newPos, Vector3D nextPos) {
    //Calculate transformation parameter to move from p1 to p2
    _translateVector = newPos;

    //Calculate the rotation matrix
    Vector3D newHeading = nextPos - newPos;
    newHeading.Normalize();

    //Heading vectors are normalized, no need to calculate norm
    GLdouble rotationAngle = acos(Vector3D::Dot(_heading,newHeading)/(_heading.Norm()*newHeading.Norm()));
    Vector3D rotationAxis;
    if (abs(abs(rotationAngle) - GL_PI) < 0.001) {
        rotationAxis = Vector3D(0,0,1);
    } else {
        rotationAxis = Vector3D::Cross(newHeading,_heading).Normalized();
    }
    Quaternion rotationQ;
    rotationQ.fromRot(rotationAngle,rotationAxis);

    QMatrix4x4 Tr(1, 0, 0, newPos.X(), 0, 1, 0, newPos.Y(), 0, 0, 1, newPos.Z(), 0, 0, 0, 1);

    InitRotation();
    rotationQ.toMatrix(_rotation[0],_rotation[4],_rotation[8],
                       _rotation[1],_rotation[5],_rotation[9],
                       _rotation[2],_rotation[6],_rotation[10]);
    QMatrix4x4 R(_rotation[0],_rotation[1],_rotation[2],_rotation[3],
            _rotation[4],_rotation[5],_rotation[6],_rotation[7],
            _rotation[8],_rotation[9],_rotation[10],_rotation[11],
            _rotation[12],_rotation[13],_rotation[14],_rotation[15]);

    QMatrix4x4 result = Tr * R;
    MatrixToDoubleList(result);
}

void GLWidget::SelectRocket() {
    QString qsFileName = QFileDialog::getOpenFileName(this, tr("Select Rocket"), QString(), tr("Obj Files (*.obj)"));
    if (!qsFileName.isEmpty()) {
        // Clear the buffers
        _vertices.clear();
        _uvs.clear();
        _normals.clear();

        // Set the path
        QByteArray byteArray = qsFileName.toUtf8();
        const char *path = byteArray.constData();

        // Read the obj file
        bool res = _objloader->LoadObj3D(path, _vertices, _uvs, _normals);
        printf("%s vertices.size:%d, uvs.size:%d, normals.size:%d\n", res? "success":"fail", _vertices.size(), _uvs.size(), _normals.size());
    }
}

void GLWidget::StartAnimation() {
    //If empty path do nothing
    if (_path->GetMouseInputs().size() == 0)
        return;

    //Set bezier
    _bezier.SetControlPoints(_path->GetMouseInputs());
    _simulationTime = 0;
}

GLdouble GLWidget::getSimulationTime() {
    return _simulationTime;
}

void GLWidget::setSimulationTime(GLdouble time) {
    _simulationTime = time;
}

void GLWidget::GetXPosition(double x) {
    _xPoint = x;
}

void GLWidget::GetYPosition(double y) {
    _yPoint = y;
}

void GLWidget::GetZPosition(double z) {
    _zPoint = z;
}

void GLWidget::SetPosition() {
    Vec3d vPoint(_xPoint, _yPoint, _zPoint);
    _path->AddPoint(vPoint);
    updateGL();
}

void GLWidget::Animate(GLdouble position, bool forward) {
    Vector3D newPos, nextPos;
    GLdouble headingStep = 0.01;

    if (_path->GetMouseInputs().size() > 1 && position > 0 && position < _bezier.ParametricEnd()) {
        const Vec3d & sampledPoint = _bezier.Sample(position);
        newPos.setX(sampledPoint.x);
        newPos.setY(sampledPoint.y);
        newPos.setZ(sampledPoint.z);

        const Vec3d & nextPoint = _bezier.Sample(forward ? position + headingStep : position - headingStep);
        nextPos.setX(nextPoint.x);
        nextPos.setY(nextPoint.y);
        nextPos.setZ(nextPoint.z);

        TransformModel(newPos, nextPos);
        _rocket->SetPosition(newPos);

        _cameraPosition.x = 3 + sampledPoint.x;
        _cameraPosition.y = 3 + sampledPoint.y;
        _cameraPosition.z = 3 + sampledPoint.z;

        _objectPosition.x = sampledPoint.x;
        _objectPosition.y = sampledPoint.y;
        _objectPosition.z = sampledPoint.z;
        updateGL();
    }
}

void GLWidget::ResetModel() {
    TransformModel(Vector3D(0,0,0), _heading);
    updateGL();
}

void GLWidget::keyPressEvent(QKeyEvent *e) {
    switch(e->key()) {
    case Qt::Key_D:
        _viewRotatey += cameraStep;
        updateGL();
        break;

    case Qt::Key_A:
        _viewRotatey -= cameraStep;
        updateGL();
        break;

    case Qt::Key_R:
        if(_viewRotateVert < 89) {
            _viewRotateVert += cameraStep;
            updateGL();
        }
        break;

    case Qt::Key_F:
        if(_viewRotateVert > 5) {
            _viewRotateVert -= cameraStep;
            updateGL();
        }
        break;

    case Qt::Key_S:
        if(_zoom > -58*projectScale) {
            _zoom -= cameraStep*projectScale;
            updateGL();
        }
        break;

    case Qt::Key_W:
        if(_zoom <= -2*projectScale) {
            _zoom += cameraStep*projectScale;
            updateGL();
        }
        break;
    }
}

void GLWidget::LoadTexture() {
  QImage b;
  if (!b.load("../SpaceRocketGraphics/Textures/Texture.jpg")) {
      printf("load failed \n");
  }

  QImage t = QGLWidget::convertToGLFormat( b );

  glBindTexture( GL_TEXTURE_2D, bindTexture(QPixmap("../SpaceRocketGraphics/Textures/6.jpg")));
  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, t.width(), t.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, t.bits() );
}
