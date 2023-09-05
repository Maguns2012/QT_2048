QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core/myboard.cpp \
    core/mygame.cpp \
    core/myobject.cpp \
    core/myobserver.cpp \
    core/mytile.cpp \
    gui/myqgameboard.cpp \
    gui/myqgameoverwindow.cpp \
    gui/myqresetbutton.cpp \
    gui/myqtile.cpp \
    gui/myqwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    core/myboard.h \
    core/mygame.h \
    core/myobject.h \
    core/myobserver.h \
    core/mytile.h \
    gui/myqgameboard.h \
    gui/myqgameoverwindow.h \
    gui/myqresetbutton.h \
    gui/myqtile.h \
    gui/myqwindow.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
