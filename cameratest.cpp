#include "cameratest.h"
#include "ui_cameratest.h"
#include <QWidget>
#include <QVideoWidget>
#include <QFileDialog>
#include <QDir>

CameraTest::CameraTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CameraTest)
{
    ui->setupUi(this);

    connect(ui->saveBtn,SIGNAL(clicked(bool)),SLOT(onSavePicture()));

    mCamera = new QCamera;//启用系统摄像头
    mCameraImageCapture = new QCameraImageCapture(mCamera);//用摄像头初始化一个QCameraImageCapture用来截图
    mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    mCamera->setCaptureMode(QCamera::CaptureStillImage);//设置摄像头的模式，可以抓取静态图像
    mCamera->setViewfinder( (QVideoWidget*)ui->viewfinder );//设置显示的窗体
    mCamera->start();//摄像头启动
}

CameraTest::~CameraTest()
{
    delete ui;
}

void CameraTest::onSavePicture()
{
    QString fileName = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("保存图片"),
                                                    QDir::currentPath(),
                                                    tr("Images (*.png *.xpm *.jpg)"));
    mCameraImageCapture->capture(fileName);
}
