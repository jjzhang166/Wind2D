#-------------------------------------------------
#
# Project created by QtCreator 2013-10-03T03:16:02
#
#-------------------------------------------------

QT       += widgets opengl xml multimedia
QT       -= gui

QMAKE_CXXFLAGS += -std=c++0x

TARGET = Core
TEMPLATE = lib

DEFINES += CORE_LIBRARY

SOURCES += \
    texturecache.cpp \
    renderengine.cpp \
    node.cpp \
    sprite.cpp \
    layer.cpp \
    gamewindow.cpp \
    gameapp.cpp

HEADERS +=\
    core_global.h \
    texturecache.h \
    renderengine.h \
    node.h \
    sprite.h \
    layer.h \
    gamewindow.h \
    gameapp.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

RESOURCES += \
    shaders.qrc
