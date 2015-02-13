QT       += core gui opengl widgets declarative

TARGET   = SpaceRocketGraphics
TEMPLATE = app


SOURCES += main.cpp\
    glwidget.cpp \
    rocket.cpp \
    path.cpp \
    window.cpp \
    objloader.cpp \
    controllerswidget.cpp \
    positioncontroller.cpp \
    velocitycontroller.cpp \
    accelerationcontroller.cpp


HEADERS  += \
    glwidget.h \
    rocket.h \
    path.h \
    Bezier.h \
    foundation.h \
    SplineDef.h \
    window.h \
    ui_MainWindow.h \
    objloader.h \
    quaternion.h \
    vector3d.h \
    controllerswidget.h \
    positioncontroller.h \
    velocitycontroller.h \
    accelerationcontroller.h

#FORMS    +=
QT += widgets


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../SpaceRocket/glew/lib/Release/Win32/ -lglew32
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../SpaceRocket/glew/lib/Release/Win32/ -lglew32d
#else:unix: LIBS += -L$$PWD/../SpaceRocket/glew/lib/Release/Win32/ -lglew32

INCLUDEPATH += $$PWD/../SpaceRocket/glew/lib/Release/Win32
DEPENDPATH += $$PWD/../SpaceRocket/glew/lib/Release/Win32

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../SpaceRocket/glew/lib/Release/Win32/ -lglew32s
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../SpaceRocket/glew/lib/Release/Win32/ -lglew32sd
#else:unix: LIBS += -L$$PWD/../SpaceRocket/glew/lib/Release/Win32/ -lglew32s

INCLUDEPATH += $$PWD/../SpaceRocket/glew/lib/Release/Win32
DEPENDPATH += $$PWD/../SpaceRocket/glew/lib/Release/Win32
