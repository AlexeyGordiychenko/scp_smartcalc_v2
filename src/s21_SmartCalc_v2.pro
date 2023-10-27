QT       += core gui
QT       += printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    s21_main.cc \
    qcustomplot.cpp \
    s21_view_graph.cc \
    s21_view.cc \
    s21_controller.cc

HEADERS += \
    qcustomplot.h \
    s21_view_graph.h \
    s21_view.h \
    s21_model.h \
    s21_controller.h


FORMS += \
    s21_view_graph.ui \
    s21_view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
