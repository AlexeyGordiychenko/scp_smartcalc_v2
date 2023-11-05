QT       += core gui
QT       += printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    scp_main.cc \
    thirdparty/qcustomplot.cpp \
    view/scp_view_graph.cc \
    view/scp_view.cc \
    model/scp_model.cc \
    controller/scp_controller.cc

HEADERS += \
    thirdparty/qcustomplot.h \
    view/scp_view_graph.h \
    view/scp_view.h \
    model/scp_model.h \
    controller/scp_controller.h


FORMS += \
    view/scp_view_graph.ui \
    view/scp_view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
