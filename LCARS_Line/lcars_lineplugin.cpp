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

#include "lcars_line.h"
#include "lcars_lineplugin.h"

#include <QtPlugin>

//! [0]
LCARS_LinePlugin::LCARS_LinePlugin(QObject *parent)
    : QObject(parent)
    , initialized(false)
{
}
//! [0]

//! [1]
void LCARS_LinePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}
//! [1]

//! [2]
bool LCARS_LinePlugin::isInitialized() const
{
    return initialized;
}
//! [2]

//! [3]
QWidget *LCARS_LinePlugin::createWidget(QWidget *parent)
{
    return new LCARS_Line(parent);
}
//! [3]

//! [4]
QString LCARS_LinePlugin::name() const
{
    return "LCARS_Line";
}
//! [4]

//! [5]
QString LCARS_LinePlugin::group() const
{
    return "Display Widgets [Examples]";
}
//! [5]

//! [6]
QIcon LCARS_LinePlugin::icon() const
{
    return QIcon();
}
//! [6]

//! [7]
QString LCARS_LinePlugin::toolTip() const
{
    return "";
}
//! [7]

//! [8]
QString LCARS_LinePlugin::whatsThis() const
{
    return "";
}
//! [8]

//! [9]
bool LCARS_LinePlugin::isContainer() const
{
    return true;
}

//! [9]


//! [10]
QString LCARS_LinePlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"LCARS_Line\" name=\"LCARS_Lines\">\n"
//! [11]
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>200</width>\n"
           "    <height>150</height>\n"
           "   </rect>\n"
           "  </property>\n"

           "  <property name=\"Size_TopLeft\">\n"
           "   <size>\n"
           "    <width>7</width>\n"
           "    <height>7</height>\n"
           "   </size>\n"
           "  </property>\n"

           "  <property name=\"Size_BottomLeft\" stdset=\"15\">\n"
           "   <size>\n"
           "    <width>7</width>\n"
           "    <height>7</height>\n"
           "   </size>\n"
           "  </property>\n"

           "  <property name=\"Size_TopRight\">\n"
           "   <size>\n"
           "    <width>7</width>\n"
           "    <height>7</height>\n"
           "   </size>\n"
           "  </property>\n"

           "  <property name=\"Size_BottomRight\">\n"
           "   <size>\n"
           "    <width>7</width>\n"
           "    <height>7</height>\n"
           "   </size>\n"
           "  </property>\n"


           "  <property name=\"Center_Color\" >\n"
           "          <color>\n"
           "           <red>255</red>\n"
           "           <green>153</green>\n"
           "           <blue>0</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"Edge_Left_Color\" >\n"
           "          <color>\n"
           "           <red>255</red>\n"
           "           <green>153</green>\n"
           "           <blue>0</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"Edge_Right_Color\" >\n"
           "          <color>\n"
           "           <red>255</red>\n"
           "           <green>153</green>\n"
           "           <blue>0</blue>\n"
           "          </color>\n"
           "  </property>\n"



//! [ RED ]


                        "  <property name=\"Red_Center_Color\" >\n"
                        "          <color>\n"
                        "           <red>200</red>\n"
                        "           <green>24</green>\n"
                        "           <blue>28</blue>\n"
                        "          </color>\n"
                        "  </property>\n"

                       "  <property name=\"Red_Edge_Left_Color\" >\n"
                       "          <color>\n"
                       "           <red>200</red>\n"
                       "           <green>24</green>\n"
                       "           <blue>28</blue>\n"
                       "          </color>\n"
                       "  </property>\n"

                       "  <property name=\"Red_Edge_Right_Color\" >\n"
                       "          <color>\n"
                       "           <red>200</red>\n"
                       "           <green>24</green>\n"
                       "           <blue>28</blue>\n"
                       "          </color>\n"
                       "  </property>\n"


//! [ / RED ]



            //! [ ACTIVE ]


                        "  <property name=\"Active_Center_Color\" >\n"
                        "          <color>\n"
                        "           <red>255</red>\n"
                        "           <green>255</green>\n"
                        "           <blue>255</blue>\n"
                        "          </color>\n"
                        "  </property>\n"

                       "  <property name=\"Active_Edge_Left_Color\" >\n"
                       "          <color>\n"
                       "           <red>255</red>\n"
                       "           <green>255</green>\n"
                       "           <blue>255</blue>\n"
                       "          </color>\n"
                       "  </property>\n"

                       "  <property name=\"Active_Edge_Right_Color\" >\n"
                       "          <color>\n"
                       "           <red>255</red>\n"
                       "           <green>255</green>\n"
                       "           <blue>255</blue>\n"
                       "          </color>\n"
                       "  </property>\n"



            //! [ / ACTIVE ]


            "  <property name=\"RedAlertState\" stdset=\"0\">\n"
            "          <number>0</number>\n"
            "  </property>\n"

            "  <property name=\"Color_Theme_ID\" stdset=\"0\">\n"
            "          <number>0</number>\n"
            "  </property>\n"


           " </widget>\n"
           "</ui>\n";
}
//! [10]

//! [12]
QString LCARS_LinePlugin::includeFile() const
{
    return "lcars_line.h";
}
//! [12]

/*
 *
*/
