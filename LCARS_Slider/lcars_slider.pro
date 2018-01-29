#! [0]
QT          += widgets uiplugin
#! [0]

QTDIR_build {
# This is only for the Qt build. Do not use externally. We mean it.
PLUGIN_TYPE = designer
PLUGIN_CLASS_NAME = LCARS_SliderPlugin
load(qt_plugin)
} else {
# Public example:

#! [2]
CONFIG      += plugin
TEMPLATE    = lib
#! [2]

TARGET = $$qtLibraryTarget($$TARGET)

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target

}

#! [3]
HEADERS     = \
    lcars_slider.h \
    lcars_sliderplugin.h
SOURCES     = \
    lcars_slider.cpp \
    lcars_sliderplugin.cpp
OTHER_FILES +=
#! [3]

DISTFILES += \
    lcars_slider.json
