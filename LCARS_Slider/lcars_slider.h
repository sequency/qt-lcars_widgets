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

#ifndef LCARS_SLIDER_H
#define LCARS_SLIDER_H

#include <QPushButton>
#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

#include <QSlider>
#include <QWidget>

class QDESIGNER_WIDGET_EXPORT LCARS_Slider : public QSlider
{
    Q_OBJECT

public:
    explicit LCARS_Slider(QWidget *parent=0);
    QPoint p;

    QPoint temp;

    int resultValue;
    int widthDash;
    int distanceDash;
    int pieHeight;
    bool customRounding;

    bool roundBorder;

    QColor handleBackground;
    QColor handleBackgroundPressed;
    QColor handleBorderColor;
    QColor barBackgroundTop;
    QColor barBackgroundBottom;
    QColor bgGradient_Start;
    QColor bgGradient_End;
    QColor frontGradient_Start;
    QColor frontGradient_End;
    QColor dividerColor;

    QSize handleSize;
    QSize handleBorderSize;

    QSize barTopLine;
    QSize barBottomLine;

    int sliderMode;

    int roundHandle_Bar_width;
    int border_roundedHandleWidth;
    QSize size_roundedHandleTop;
    QSize size_roundedHandleBottom;
    QSize size_roundedHandle;
    QColor bar_roundedHandleColor;

    bool onlyOne;
    int topBottom;

signals:


public slots:
    void paintHandle(QPainter *painter);
    void paintBar(QPainter *painter);



protected:

    void showEvent(QShowEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent * event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent * event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
};


#endif
