#ifndef CAMERATEST_H
#define CAMERATEST_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>

namespace Ui {
class CameraTest;
}

class CameraTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit CameraTest(QWidget *parent = 0);
    ~CameraTest();
private slots:
    void onSavePicture();

private:
    QCamera *mCamera;
    QCameraImageCapture *mCameraImageCapture;
    QVideoWidget *widget;
private:
    Ui::CameraTest *ui;
};

#endif // CAMERATEST_H
