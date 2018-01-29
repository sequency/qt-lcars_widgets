#! [0]
QT          += widgets uiplugin
#! [0]

QTDIR_build {
# This is only for the Qt build. Do not use externally. We mean it.
PLUGIN_TYPE = designer
PLUGIN_CLASS_NAME = LCARS_ButtonPlugin
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
HEADERS     = lcars_button.h \
    lcars_buttonplugin.h
SOURCES     = lcars_button.cpp \
    lcars_buttonplugin.cpp
OTHER_FILES += lcars_button.json
#! [3]
