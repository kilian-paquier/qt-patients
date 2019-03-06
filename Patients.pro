#-------------------------------------------------
#
# Project created by QtCreator 2019-02-12T19:16:39
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Patients
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    model/informaticien.cpp \
    model/patient.cpp \
    model/personnel.cpp \
    model/centre.cpp \
    model/typemedecin.cpp \
    model/utils.cpp \
    model/c_init_bd.cpp \
    controler/controler.cpp \
    view/mainwindow.cpp \
    view/loginwindow.cpp \
    view/aproposwindow.cpp \
    view/personnelwindow.cpp \
    view/patientwindow.cpp

HEADERS += \
    model/informaticien.h \
    model/patient.h \
    model/personnel.h \
    model/centre.h \
    model/typemedecin.h \
    model/utils.h \
    model/c_init_bd.h \
    controler/controler.h \
    view/mainwindow.h \
    view/patientwindow.h \
    view/personnelwindow.h \
    view/aproposwindow.h \
    view/loginwindow.h

FORMS += \
    view/mainwindow.ui \
    view/loginwindow.ui \
    view/personnelwindow.ui \
    view/aproposwindow.ui \
    view/patientwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    Patients.pro

DISTFILES += \
    README.md
RESOURCES += \
    polytech.qrc
