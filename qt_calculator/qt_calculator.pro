QT += core widgets

CONFIG += c++11

TARGET = qt_calculator
TEMPLATE = app

SOURCES += \
    main.cpp \
    calculator.cpp

HEADERS += \
    calculator.h

DEFINES += QT_DEPRECATED_WARNINGS