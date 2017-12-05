TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cranknic.cpp \
    bwdeuler.cpp \
    fwdeuler.cpp \
    trisolver.cpp \
    writetofile.cpp \
    writematfile.cpp \
    fwdeuler2.cpp

INCLUDEPATH += C:/Qt/armadillo-8.100.1/include
DEPENDPATH += C:/Qt/armadillo-8.100.1/include
LIBS += -LC:/Qt/armadillo-8.100.1/examples/lib_win64 -llapack_win64_MT -lblas_win64_MT

HEADERS += \
    methods.h

DISTFILES +=
