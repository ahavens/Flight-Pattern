TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    interpretdata.cpp \
    stacktraversing.cpp \
    adjlistnode.cpp \
    adjlist.cpp

HEADERS += \
    interpretdata.h \
    stacktraversing.h \
    adjlistnode.h \
    adjlist.h

