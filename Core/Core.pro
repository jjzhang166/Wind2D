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
    sprite.cpp \
    renderengine.cpp \
    node.cpp

HEADERS +=\
        core_global.h \
    texturecache.h \
    sprite.h \
    renderengine.h \
    node.h

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
