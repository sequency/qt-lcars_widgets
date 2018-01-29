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

#include "lcars_slider.h"
#include "lcars_sliderplugin.h"

#include <QtPlugin>

//! [0]
LCARS_SliderPlugin::LCARS_SliderPlugin(QObject *parent)
    : QObject(parent)
    , initialized(false)
{
}
//! [0]

//! [1]
void LCARS_SliderPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}
//! [1]

//! [2]
bool LCARS_SliderPlugin::isInitialized() const
{
    return initialized;
}
//! [2]

//! [3]
QWidget *LCARS_SliderPlugin::createWidget(QWidget *parent)
{
    return new LCARS_Slider(parent);
}
//! [3]

//! [4]
QString LCARS_SliderPlugin::name() const
{
    return "LCARS_Slider";
}
//! [4]

//! [5]
QString LCARS_SliderPlugin::group() const
{
    return "Display Widgets [Examples]";
}
//! [5]

//! [6]
QIcon LCARS_SliderPlugin::icon() const
{
    return QIcon();
}
//! [6]

//! [7]
QString LCARS_SliderPlugin::toolTip() const
{
    return "";
}
//! [7]

//! [8]
QString LCARS_SliderPlugin::whatsThis() const
{
    return "";
}
//! [8]

//! [9]
bool LCARS_SliderPlugin::isContainer() const
{
    return false;
}

//! [9]


//! [10]
QString LCARS_SliderPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"LCARS_Slider\" name=\"LCARS_Sliders\">\n"
//! [11]
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>200</width>\n"
           "    <height>40</height>\n"
           "   </rect>\n"
           "  </property>\n"

            "<property name=\"orientation\">\n"
             "<enum>Qt::Horizontal</enum>\n"
            "</property>\n"

           "  <property name=\"sliderMode\" >\n"
           "   <number>0</number>\n"
           "  </property>\n"

           "  <property name=\"widthDash\" >\n"
           "   <number>5</number>\n"
           "  </property>\n"

           "  <property name=\"distanceDash\" >\n"
           "   <number>5</number>\n"
           "  </property>\n"

           "  <property name=\"customRoundingValue\" >\n"
           "   <number>15</number>\n"
           "  </property>\n"


           "  <property name=\"handleBackground\" >\n"
           "          <color>\n"
           "           <red>255</red>\n"
           "           <green>204</green>\n"
           "           <blue>153</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"handleBackgroundPressed\" >\n"
           "          <color>\n"
           "           <red>255</red>\n"
           "           <green>255</green>\n"
           "           <blue>255</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"handleBorderColor\" >\n"
           "          <color>\n"
           "           <red>0</red>\n"
           "           <green>0</green>\n"
           "           <blue>0</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"barBackgroundTop\" >\n"
           "          <color>\n"
           "           <red>255</red>\n"
           "           <green>153</green>\n"
           "           <blue>0</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"barBackgroundBottom\" >\n"
           "          <color>\n"
           "           <red>255</red>\n"
           "           <green>153</green>\n"
           "           <blue>0</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"bgGradient_Start\" >\n"
           "          <color>\n"
           "           <red>54</red>\n"
           "           <green>52</green>\n"
           "           <blue>150</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"bgGradient_End\" >\n"
           "          <color>\n"
           "           <red>19</red>\n"
           "           <green>17</green>\n"
           "           <blue>40</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"frontGradient_Start\" >\n"
           "          <color>\n"
           "           <red>230</red>\n"
           "           <green>110</green>\n"
           "           <blue>30</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"frontGradient_End\" >\n"
           "          <color>\n"
           "           <red>186</red>\n"
           "           <green>0</green>\n"
           "           <blue>30</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"dividerColor\" >\n"
           "          <color>\n"
           "           <red>0</red>\n"
           "           <green>0</green>\n"
           "           <blue>0</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"handleSize\">\n"
           "   <size>\n"
           "    <width>20</width>\n"
           "    <height>0</height>\n"
           "   </size>\n"
           "  </property>\n"

           "  <property name=\"handleBorderSize\">\n"
           "   <size>\n"
           "    <width>5</width>\n"
           "    <height>0</height>\n"
           "   </size>\n"
           "  </property>\n"

           "  <property name=\"barTopLineSize\">\n"
           "   <size>\n"
           "    <width>0</width>\n"
           "    <height>10</height>\n"
           "   </size>\n"
           "  </property>\n"

           "  <property name=\"barBottomLineSize\">\n"
           "   <size>\n"
           "    <width>0</width>\n"
           "    <height>10</height>\n"
           "   </size>\n"
           "  </property>\n"

           "  <property name=\"customRounding\">\n"
           "   <bool>false</bool>\n"
           "  </property>\n"

           "  <property name=\"roundBorder\">\n"
           "   <bool>false</bool>\n"
           "  </property>\n"

           "  <property name=\"roundHandle_Bar_width\">\n"
           "   <number>10</number>\n"
           "  </property>\n"

           "  <property name=\"border_roundedHandleWidth\">\n"
           "   <number>5</number>\n"
           "  </property>\n"

           "  <property name=\"border_roundedHandleColor\" >\n"
           "          <color>\n"
           "           <red>204</red>\n"
           "           <green>102</green>\n"
           "           <blue>102</blue>\n"
           "          </color>\n"
           "  </property>\n"

           "  <property name=\"size_roundedHandleTop\">\n"
           "   <size>\n"
           "    <width>30</width>\n"
           "    <height>30</height>\n"
           "   </size>\n"
           "  </property>\n"

           "  <property name=\"size_roundedHandleBottom\">\n"
           "   <size>\n"
           "    <width>30</width>\n"
           "    <height>30</height>\n"
           "   </size>\n"
           "  </property>\n"

           "  <property name=\"size_roundedHandle\">\n"
           "   <size>\n"
           "    <width>15</width>\n"
           "    <height>35</height>\n"
           "   </size>\n"
           "  </property>\n"

           "  <property name=\"bar_roundedHandleColor\" >\n"
           "          <color>\n"
           "           <red>255</red>\n"
           "           <green>153</green>\n"
           "           <blue>0</blue>\n"
           "          </color>\n"
           "  </property>\n"

            "  <property name=\"onlyOneRounding\" >\n"
            "          <bool>false</bool>\n"
            "  </property>\n"

            "  <property name=\"TopOrBottomRounding\" >\n"
            "          <number>0</number>\n"
            "  </property>\n"

           " </widget>\n"
           "</ui>\n";
}
//! [10]

//! [12]
QString LCARS_SliderPlugin::includeFile() const
{
    return "lcars_slider.h";
}
//! [12]

/*
 *
*/
