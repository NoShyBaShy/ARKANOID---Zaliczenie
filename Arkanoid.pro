TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:\Users\grzeg_yffe4kv\Downloads\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1/include"
LIBS += -L"C:\Users\grzeg_yffe4kv\Downloads\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        background.cpp \
        ball.cpp \
        block.cpp \
        functions.cpp \
        game.cpp \
        main.cpp \
        mod.cpp \
        object.cpp \
        player.cpp

HEADERS += \
    background.h \
    ball.h \
    block.h \
    class.h \
    game.h \
    mod.h \
    object.h \
    player.h
