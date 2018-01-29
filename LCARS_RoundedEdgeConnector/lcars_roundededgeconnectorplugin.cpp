/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "lcars_roundededgeconnector.h"
#include "lcars_roundededgeconnectorplugin.h"

#include <QtPlugin>

//! [0]
LCARS_RoundedEdgeConnectorPlugin::LCARS_RoundedEdgeConnectorPlugin(QObject *parent)
    : QObject(parent)
    , initialized(false)
{
}
//! [0]

//! [1]
void LCARS_RoundedEdgeConnectorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}
//! [1]

//! [2]
bool LCARS_RoundedEdgeConnectorPlugin::isInitialized() const
{
    return initialized;
}
//! [2]

//! [3]
QWidget *LCARS_RoundedEdgeConnectorPlugin::createWidget(QWidget *parent)
{
    return new LCARS_RoundedEdgeConnector(parent);
}
//! [3]

//! [4]
QString LCARS_RoundedEdgeConnectorPlugin::name() const
{
    return "LCARS_RoundedEdgeConnector";
}
//! [4]

//! [5]
QString LCARS_RoundedEdgeConnectorPlugin::group() const
{
    return "Display Widgets [Examples]";
}
//! [5]

//! [6]
QIcon LCARS_RoundedEdgeConnectorPlugin::icon() const
{
    return QIcon();
}
//! [6]

//! [7]
QString LCARS_RoundedEdgeConnectorPlugin::toolTip() const
{
    return "";
}
//! [7]

//! [8]
QString LCARS_RoundedEdgeConnectorPlugin::whatsThis() const
{
    return "";
}
//! [8]

//! [9]
bool LCARS_RoundedEdgeConnectorPlugin::isContainer() const
{
    return true;
}

//! [9]

QColor LCARS_RoundedEdgeConnectorPlugin::bgColor()  const
{
    return QColor();
}
int LCARS_RoundedEdgeConnectorPlugin::innerCurveWidth() const {
    return int();
}

int LCARS_RoundedEdgeConnectorPlugin::innerCurveHeight() const {
    return int();
}

int LCARS_RoundedEdgeConnectorPlugin::outerCurveWidth() const {
    return int();
}

int LCARS_RoundedEdgeConnectorPlugin::outerCurveHeight() const{
    return int();
}

int LCARS_RoundedEdgeConnectorPlugin::innerCurveX() const {
    return int();
}

int LCARS_RoundedEdgeConnectorPlugin::innerCurveY() const {
    return int();
}

int LCARS_RoundedEdgeConnectorPlugin::orientation() const {
    return int();
}



//! [10]
QString LCARS_RoundedEdgeConnectorPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"LCARS_RoundedEdgeConnector\" name=\"LCARSRoundedEdgeConnector\">\n"
//! [11]
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>120</width>\n"
           "    <height>60</height>\n"
           "   </rect>\n"
           "  </property>\n"

           "  <property name=\"toolTip\" >\n"
           "   <string>Rounded Edge Connector</string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>Rounded Edge Connector Element.</string>\n"
           "  </property>\n"

           "  <property name=\"bgColor\" >\n"
           "          <color>\n"
           "           <red>255</red>\n"
           "           <green>153</green>\n"
           "           <blue>0</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"RedAlertBgColor\" >\n"
           "          <color>\n"
           "           <red>200</red>\n"
           "           <green>24</green>\n"
           "           <blue>28</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"Active_RedAlertBgColor\" >\n"
           "          <color>\n"
           "           <red>255</red>\n"
           "           <green>255</green>\n"
           "           <blue>255</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"ColorThemeID\" >\n"
           "          <number>0</number>\n"
           "  </property>\n"

           "  <property name=\"innerCurveWidth\" >\n"
           "   <number>40</number>\n"
           "  </property>\n"

           "  <property name=\"innerCurveHeight\" >\n"
           "   <number>40</number>\n"
           "  </property>\n"

           "  <property name=\"innerCurveX\" >\n"
           "   <number>120</number>\n"
           "  </property>\n"

           "  <property name=\"innerCurveY\" >\n"
           "   <number>35</number>\n"
           "  </property>\n"

           "  <property name=\"outerCurveWidth\" >\n"
           "   <number>120</number>\n"
           "  </property>\n"



           "  <property name=\"bottomCurveHeight\" >\n"
           "   <number>0</number>\n"
           "  </property>\n"

           "  <property name=\"bottomCurveLeftWidth\" >\n"
           "   <double>20</double>\n"
           "  </property>\n"

           "  <property name=\"bottomCurveRightWidth\" >\n"
           "   <double>20</double>\n"
           "  </property>\n"

           "  <property name=\"rightCurveWidth\" >\n"
           "   <number>0</number>\n"
           "  </property>\n"

           "  <property name=\"rightCurveTopHeight\" >\n"
           "   <double>7</double>\n"
           "  </property>\n"

           "  <property name=\"rightCurveBottomHeight\" >\n"
           "   <double>7</double>\n"
           "  </property>\n"

          "  <property name=\"endCurves\" >\n"
           "   <bool>false</bool>\n"
           "  </property>\n"

           "  <property name=\"outerCurveHeight\" >\n"
           "   <number>80</number>\n"
           "  </property>\n"

           "  <property name=\"orientation\" >\n"
           "   <number>0</number>\n"
           "  </property>\n"

           "  <property name=\"RedAlertState\" >\n"
           "   <number>0</number>\n"
           "  </property>\n"

           " </widget>\n"
           "</ui>\n";
}
//! [10]

//! [12]
QString LCARS_RoundedEdgeConnectorPlugin::includeFile() const
{
    return "lcars_roundededgeconnector.h";
}
//! [12]

/*
 *
*/
