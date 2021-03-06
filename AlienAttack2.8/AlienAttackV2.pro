#-------------------------------------------------
#
# Project created by QtCreator 2018-12-05T13:29:57
#
#-------------------------------------------------

QT       += core gui widgets serialport \
            sql
QT+=multimedia

TARGET = AlienAttackV2
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
    myscene.cpp \
    player.cpp \
    bullet.cpp \
    enemy.cpp \
    granade.cpp \
    explotion.cpp \
    menu.cpp \
    level1.cpp \
    level2.cpp \
    options.cpp \
    level1multiplayer.cpp \
    level2multiplayer.cpp \
    level3.cpp \
    level3multiplayer.cpp \
    optsave.cpp

HEADERS += \
    myscene.h \
    player.h \
    bullet.h \
    enemy.h \
    granade.h \
    explotion.h \
    menu.h \
    level1.h \
    level2.h \
    options.h \
    level1multiplayer.h \
    level2multiplayer.h \
    level3.h \
    level3multiplayer.h \
    optsave.h

FORMS += \
    menu.ui \
    level2.ui \
    level1.ui \
    options.ui \
    level1multiplayer.ui \
    level2multiplayer.ui \
    level3.ui \
    level3multiplayer.ui \
    optsave.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
