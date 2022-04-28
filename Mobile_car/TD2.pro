# configuration Qt
QT       += core gui opengl widgets openglwidgets
TEMPLATE  = app
CONFIG += c++17

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}


# nom de l'exe genere
TARGET 	  = TD2

# fichiers sources/headers/ressources
SOURCES += main.cpp myglwidget.cpp \
    Car.cpp \
    Ground.cpp
HEADERS += myglwidget.h \
    Car.h \
    Ground.h
RESOURCES += \
    textures\textures.qrc

DISTFILES += \
    grass.jpg \
    road.jpg \
    sky.jpg \
    barrel.jpg
