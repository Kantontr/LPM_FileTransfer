#-------------------------------------------------
#
# Project created by QtCreator 2019-10-24T15:18:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LPM_TCP
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

QMAKE_LFLAGS += -static -static-libgcc
QMAKE_CFLAGS_RELEASE -= -O2
QMAKE_CFLAGS_RELEASE += -Os -momit-leaf-frame-pointer
DEFINES += QT_STATIC_BUILD

CONFIG += c++17
CONFIG+=static

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    w_add_user.cpp \
    get_string.cpp \
    edit_config.cpp

HEADERS += \
        mainwindow.h \
    install.h \
    utility.h \
    class_user.h \
    w_add_user.h \
    get_string.h \
    class_config.h \
    edit_config.h \
    lpm_wl_lib.h \
    exec_python.h

FORMS += \
        mainwindow.ui \
    w_add_user.ui \
    get_string.ui \
    edit_config.ui




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_FILE = LPM_Icon.rc

DISTFILES +=
