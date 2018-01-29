#! [0]
QT          += widgets uiplugin
#! [0]

QTDIR_build {
# This is only for the Qt build. Do not use externally. We mean it.
PLUGIN_TYPE = designer
PLUGIN_CLASS_NAME = LCARS_RoundedEdgeConnectorPlugin
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
HEADERS     = lcars_roundededgeconnector.h \
    lcars_roundededgeconnectorplugin.h
SOURCES     = lcars_roundededgeconnector.cpp \
    lcars_roundededgeconnectorplugin.cpp
OTHER_FILES += lcars_roundededgeconnector.json
#! [3]
