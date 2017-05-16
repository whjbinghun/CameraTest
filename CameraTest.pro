TEMPLATE = app

QT += qml quick concurrent multimedia
#CONFIG += c++11



RESOURCES += qml.qrc \
    JQQRCodeReaderQml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    JQQRCodeReader.h \
    JQQRCodeReaderForQml.h \
    QZXing.h \
    QZXing_global.h

SOURCES += main.cpp \
    JQQRCodeReader.cpp \
    JQQRCodeReaderForQml.cpp


