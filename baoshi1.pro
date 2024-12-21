QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animationmanager.cpp \
    databasemanager.cpp \
    gameengine.cpp \
    gamescreen.cpp \
    loginscreen.cpp \
    main.cpp \
    mainwindow.cpp \
    rankinglist.cpp \
    shopmanager.cpp \
    skillmanager.cpp \
    soundmanager.cpp \
    startscreen.cpp \
    usermanager.cpp

HEADERS += \
    animationmanager.h \
    databasemanager.h \
    gameengine.h \
    gamescreen.h \
    loginscreen.h \
    mainwindow.h \
    rankinglist.h \
    shopmanager.h \
    skillmanager.h \
    soundmanager.h \
    startscreen.h \
    usermanager.h

FORMS += \
    gamescreen.ui \
    loginscreen.ui \
    mainwindow.ui \
    rankinglist.ui \
    startscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
