/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Sun Sep 28 20:17:55 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include <QCoreApplication>
#include <QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_frmMain {
public:
    QScrollArea *glWidgetArea;
    QScrollArea *controllerArea;
    QScrollArea *velocityControllerArea;
    QScrollArea *accelerationControllerArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *controllerWidgetContents;
    QWidget *velocityControllerWidgetContents;
    QWidget *accelerationControllerWidgetContents;
    QGroupBox *groupBox;
    QPushButton *btnClose;
    QPushButton *clearButton;
    QPushButton *selectButton;
    QPushButton *startButton;
    QPushButton *setPositionButton;
    QDoubleSpinBox *xDoubleSpinBox;
    QDoubleSpinBox *yDoubleSpinBox;
    QDoubleSpinBox *zDoubleSpinBox;
    QLabel *PositionLabel;
    QLabel *VelocityLabel;
    QLabel *AccelerationLabel;
    QLabel *xLabel;
    QLabel *yLabel;
    QLabel *zLabel;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QString::fromUtf8("frmMain"));
        frmMain->resize(1300, 750);
        glWidgetArea = new QScrollArea(frmMain);
        glWidgetArea->setObjectName(QString::fromUtf8("glWidgetArea"));
        glWidgetArea->setGeometry(QRect(0, 0, 1030, 750));
        controllerArea = new QScrollArea(frmMain);
        controllerArea->setObjectName(QString::fromUtf8("controllerArea"));
        controllerArea->setGeometry(QRect(1040, 230, 250, 150));
        velocityControllerArea = new QScrollArea(frmMain);
        velocityControllerArea->setObjectName(QString::fromUtf8("velocityControllerArea"));
        velocityControllerArea->setGeometry(QRect(1040, 410, 250, 150));
        accelerationControllerArea = new QScrollArea(frmMain);
        accelerationControllerArea->setObjectName(QString::fromUtf8("accelerationControllerArea"));
        accelerationControllerArea->setGeometry(QRect(1040, 590, 250, 150));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(glWidgetArea->sizePolicy().hasHeightForWidth());
        glWidgetArea->setSizePolicy(sizePolicy);
        glWidgetArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        glWidgetArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        glWidgetArea->setWidgetResizable(true);
        controllerArea->setSizePolicy(sizePolicy);
        controllerArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        controllerArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        controllerArea->setWidgetResizable(true);
        velocityControllerArea->setSizePolicy(sizePolicy);
        velocityControllerArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        velocityControllerArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        velocityControllerArea->setWidgetResizable(true);
        accelerationControllerArea->setSizePolicy(sizePolicy);
        accelerationControllerArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        accelerationControllerArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        accelerationControllerArea->setWidgetResizable(true);

        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1030, 750));
        glWidgetArea->setWidget(scrollAreaWidgetContents);

        controllerWidgetContents = new QWidget();
        controllerWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        controllerWidgetContents->setGeometry(QRect(1045, 230, 250, 140));
        glWidgetArea->setWidget(controllerWidgetContents);

        velocityControllerWidgetContents = new QWidget();
        velocityControllerWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        velocityControllerWidgetContents->setGeometry(QRect(1045, 410, 250, 140));
        glWidgetArea->setWidget(velocityControllerWidgetContents);
        accelerationControllerWidgetContents = new QWidget();
        accelerationControllerWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        accelerationControllerWidgetContents->setGeometry(QRect(1045, 590, 250, 140));
        glWidgetArea->setWidget(accelerationControllerWidgetContents);

        groupBox = new QGroupBox(frmMain);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(1035, 15, 260, 180));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        btnClose = new QPushButton(groupBox);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(150, 140, 100, 30));
        clearButton = new QPushButton(groupBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(150, 105, 100, 30));
        selectButton = new QPushButton(groupBox);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setGeometry(QRect(150, 35, 100, 30));
        startButton= new QPushButton(groupBox);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(150, 70, 100, 30));

        PositionLabel = new QLabel("Position controller:",frmMain);
        PositionLabel->setGeometry(QRect(1045, 210, 150, 20));
        VelocityLabel = new QLabel("Velocity controller:",frmMain);
        VelocityLabel->setGeometry(QRect(1045, 390, 150, 20));
        AccelerationLabel = new QLabel("Acceleration controller:",frmMain);
        AccelerationLabel->setGeometry(QRect(1045, 570, 150, 20));
        xLabel = new QLabel("X:", groupBox);
        xLabel->setGeometry(QRect(10, 40, 10, 25));
        yLabel = new QLabel("Y:", groupBox);
        yLabel->setGeometry(QRect(10, 70, 10, 25));
        zLabel = new QLabel("Z:", groupBox);
        zLabel->setGeometry(QRect(10, 105, 10, 25));
        xDoubleSpinBox = new QDoubleSpinBox(groupBox);
        xDoubleSpinBox->setObjectName(QString::fromUtf8("xSpinBox"));
        xDoubleSpinBox->setGeometry(QRect(25, 40, 110, 25));
        xDoubleSpinBox->setValue(0);
        xDoubleSpinBox->setSingleStep(0.5);
        xDoubleSpinBox->setRange(-20.0,20.0);
        yDoubleSpinBox = new QDoubleSpinBox(groupBox);
        yDoubleSpinBox->setObjectName(QString::fromUtf8("ySpinBox"));
        yDoubleSpinBox->setGeometry(QRect(25, 70, 110, 25));
        yDoubleSpinBox->setValue(0);
        yDoubleSpinBox->setSingleStep(0.5);
        yDoubleSpinBox->setRange(-20.0,20.0);
        zDoubleSpinBox = new QDoubleSpinBox(groupBox);
        zDoubleSpinBox->setObjectName(QString::fromUtf8("zSpinBox"));
        zDoubleSpinBox->setGeometry(QRect(25, 105, 110, 25));
        zDoubleSpinBox->setValue(0);
        zDoubleSpinBox->setSingleStep(0.5);
        zDoubleSpinBox->setRange(-20.0,20.0);
        setPositionButton = new QPushButton(groupBox);
        setPositionButton->setObjectName(QString::fromUtf8("SetPositionButton"));
        setPositionButton->setGeometry(QRect(25, 140, 100, 30));
        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QCoreApplication::translate("frmMain", "Qt OpenGl Framework", 0, 1));
        groupBox->setTitle(QApplication::translate("frmMain", " Add points to the path: ", 0, 1));
        btnClose->setText(QApplication::translate("frmMain", "Close", 0, 1));
        clearButton->setText(QApplication::translate("frmMain", "Reset", 0, 1));
        selectButton->setText(QApplication::translate("frmMain", "Select Rokect", 0, 1));
        startButton->setText(QApplication::translate("frmMain", "Play", 0, 1));
        setPositionButton->setText(QApplication::translate("frmMain", "Add Point", 0, 1));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
