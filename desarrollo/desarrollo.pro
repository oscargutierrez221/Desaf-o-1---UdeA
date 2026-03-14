TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fin_juego.cpp \
        main.cpp \
        movimiento.cpp \
        panel_control.cpp \
        piezas.cpp

HEADERS += \
    fin_juego.h \
    movimiento.h \
    panel_control.h \
    piezas.h
