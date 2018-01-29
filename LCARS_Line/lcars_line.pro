#! [0]
QT          += widgets uiplugin
#! [0]

QTDIR_build {
# This is only for the Qt build. Do not use externally. We mean it.
PLUGIN_TYPE = designer
PLUGIN_CLASS_NAME = LCARS_LinePlugin
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
    lcars_line.h \
    lcars_lineplugin.h
SOURCES     = \
    lcars_line.cpp \
    lcars_lineplugin.cpp
OTHER_FILES +=
#! [3]

DISTFILES += \
    lcars_line.json
