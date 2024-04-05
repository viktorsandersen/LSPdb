QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += sql
LIBS += -lpq -lpqxx

SOURCES += \
    main.cpp \
    database_functions.cpp

HEADERS += \
    database_functions.h \
    mainwindow.h \
    datelineeditdelegate.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
