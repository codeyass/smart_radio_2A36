QT       += sql
QT       += core gui charts
QT       += core gui multimedia multimediawidgets
QT       += core gui printsupport
QT       +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    arduino.cpp \
    connection.cpp \
    dialog.cpp \
    emission.cpp \
    invites.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcode.cpp \
    secdialog.cpp \
    smtp.cpp \
    sponsors.cpp

HEADERS += \
    arduino.h \
    connection.h \
    dialog.h \
    emission.h \
    invites.h \
    mainwindow.h \
    qrcode.hpp \
    secdialog.h \
    smtp.h \
    sponsors.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    secdialog.ui

# Default rules for deployment.
target.path = $$[QT_INSTALL_EXAMPLES]/charts/donutchart
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc