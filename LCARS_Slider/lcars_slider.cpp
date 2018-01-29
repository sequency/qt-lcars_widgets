#include "lcars_slider.h"
#include <QSlider>
#include <QMouseEvent>
#include <QPainter>
#include <QEvent>
#include <QDebug>

LCARS_Slider::LCARS_Slider(QWidget *parent) :
QSlider(parent)
{

    //pieHeight=this->property("customRoundingValue").toInt;

temp = QPoint(0,0);
}

void LCARS_Slider::showEvent(QShowEvent *event) {

  //LCARS_Slider::showEvent(event);
  //QTimer::singleShot(120, this, SLOT(window_shown()));
    switch (this->orientation()) {
    case Qt::Horizontal:
        if (temp.x()==0) {
            resultValue=this->value();
            //qDebug() << "ok";
        }
        break;
    case Qt::Vertical:
        if (this->invertedControls()==false) {
            if (temp.y()==0) {
                resultValue=this->value();
                //qDebug() << "ok2";
            }
        } else if (this->invertedControls()==true) {
            if (temp.y()==0) {
                this->setValue(this->maximum()-resultValue);
            }
        }
        break;
    default:
        break;
    }

  return;
}


void LCARS_Slider::paintEvent(QPaintEvent*) {
//resultValue=this->value();
    //p.setX(0);
//qDebug() << p.x() << p.y();
//qDebug() << temp;

    qDebug() << this->value();

switch (this->orientation()) {
case Qt::Horizontal:
    if (temp.x()==0) {
        resultValue=this->value();
        //qDebug() << "ok";
    }
    break;
case Qt::Vertical:
    if (this->invertedControls()==false) {
        if (temp.y()==0) {
            resultValue=this->value();
            //qDebug() << "ok2";
        }
    } else if (this->invertedControls()==true) {
        if (temp.y()==0) {
            this->setValue(this->maximum()-resultValue);
            qDebug() << this->value();
            qDebug() << "ok3";
            this->update();
        }
    }
    break;
default:
    break;
}


QPainter painter(this);


sliderMode=this->property("sliderMode").toInt(); //0;
widthDash = this->property("widthDash").toInt(); //5;
distanceDash = this->property("distanceDash").toInt() + widthDash; //20+widthDash;

if (handleBackground=="") {
    handleBackground = QColor(this->property("handleBackground").toString()); //QColor("#cc6666");
}

/*handleBackground = QColor(this->property("handleBackground").toString()); //QColor("#cc6666");
handleBackgroundPressed = QColor(this->property("handleBackgroundPressed").toString()); //QColor("#ffffff");*/


handleBorderColor = QColor(this->property("handleBorderColor").toString()); //;
barBackgroundTop = QColor(this->property("barBackgroundTop").toString()); //;
barBackgroundBottom = QColor(this->property("barBackgroundBottom").toString()); //
bgGradient_Start=QColor(this->property("bgGradient_Start").toString()); //;
bgGradient_End=QColor(this->property("bgGradient_End").toString()); //;
frontGradient_Start=QColor(this->property("frontGradient_Start").toString()); //;
frontGradient_End=QColor(this->property("frontGradient_End").toString()); //;
dividerColor=QColor(this->property("dividerColor").toString()); //;

handleSize=QSize(this->property("handleSize").toSize()); //;
handleBorderSize=QSize(this->property("handleBorderSize").toSize()); //;
barTopLine=QSize(this->property("barTopLineSize").toSize()); //;
barBottomLine=QSize(this->property("barBottomLineSize").toSize()); //;
customRounding=this->property("customRounding").toBool();
roundBorder=this->property("roundBorder").toBool();
roundHandle_Bar_width=this->property("roundHandle_Bar_width").toInt();
border_roundedHandleWidth=this->property("border_roundedHandleWidth").toInt();
size_roundedHandleTop = QSize(this->property("size_roundedHandleTop").toSize());
size_roundedHandleBottom = QSize(this->property("size_roundedHandleBottom").toSize());;
size_roundedHandle = QSize(this->property("size_roundedHandle").toSize());;
bar_roundedHandleColor=QColor(this->property("bar_roundedHandleColor").toString());
onlyOne=this->property("onlyOneRounding").toBool(); //false
topBottom=this->property("TopOrBottomRounding").toInt(); // 0

    switch (sliderMode) {


    case 0:
{

        paintBar(&painter);
        paintHandle(&painter);
}
        break;

    case 1:
    {
        switch (this->orientation()) {
        case Qt::Horizontal:
             {

            QLinearGradient gradient1(rect().topLeft(), rect().bottomRight());
                gradient1.setColorAt(0, bgGradient_Start); // QColor("#363496")
                gradient1.setColorAt(1, bgGradient_End); //QColor("#131128")

            QBrush rush1 = QBrush(gradient1);
            painter.setBackgroundMode(Qt::OpaqueMode);
            painter.setBackground(rush1);

            painter.fillRect(0,0,this->width(),this->height(),rush1);
            paintBar(&painter);
            paintHandle(&painter);

            int distanceBorder = distanceDash - widthDash;




           for (int i=distanceBorder;i<=this->width()/*-distanceBorder*/;i++) {


                painter.fillRect(i,0,widthDash,this->height(),dividerColor);

            i=i+distanceDash;

           }



            }

            break;
        case Qt::Vertical:
        {


                if (roundBorder == true) {

                    if (onlyOne == false) {

                    painter.setBackgroundMode(Qt::OpaqueMode);

                    if (customRounding == false) {
                        pieHeight=(this->width()/2)*2;
                    } else if (customRounding == true) {
                        pieHeight = this->property("customRoundingValue").toInt()*2;
                    }
                      else
                    {

                        pieHeight=(this->width()/2)*2;
                    }


                    QLinearGradient gradientBackground(0,this->height()-pieHeight,0,pieHeight/2);
                    gradientBackground.setColorAt(0,bgGradient_Start);
                    gradientBackground.setColorAt(1,bgGradient_End);

                    QBrush rush2 = QBrush(gradientBackground);

                    painter.setRenderHint(QPainter::Antialiasing,true);

                    painter.setBrush(QBrush(bgGradient_End));
                    painter.setPen(QPen(bgGradient_End,-1));
                    painter.drawPie(0,0,this->width(),pieHeight,360*16,360*8);


                    painter.fillRect(0,pieHeight/2,this->width(),this->height()-pieHeight,rush2);


                    painter.setBrush(QBrush(bgGradient_Start));
                    painter.setPen(QPen(bgGradient_Start,-1));
                    painter.drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);

                    paintBar(&painter);
                    paintHandle(&painter);



                    int distanceBorder = distanceDash - widthDash;

                   for (int i=this->height()-pieHeight;i>=distanceBorder+pieHeight/*-distanceBorder*/;i--) {

                        painter.fillRect(0,i,this->width(),widthDash,dividerColor); //#000000

                    i=i-distanceDash;

                    painter.fillRect(0,i,this->width(),widthDash,dividerColor); //#000000
                   }
                    } else if (onlyOne==true) {


                        switch (topBottom) {

                        case 0:
                        {

                        painter.setBackgroundMode(Qt::OpaqueMode);

                        if (customRounding == false) {
                            pieHeight=(this->width()/2)*2;
                        } else if (customRounding == true) {
                            pieHeight = this->property("customRoundingValue").toInt()*2;
                        }
                          else
                        {

                            pieHeight=(this->width()/2)*2;
                        }
                        //pieHeight=pieHeight/2;

                        QLinearGradient gradientBackground(0,this->height()-pieHeight,0,pieHeight/2);
                        gradientBackground.setColorAt(0,bgGradient_Start);
                        gradientBackground.setColorAt(1,bgGradient_End);

                        QBrush rush2 = QBrush(gradientBackground);

                        painter.setRenderHint(QPainter::Antialiasing,true);

                        painter.setBrush(QBrush(bgGradient_End));
                        painter.setPen(QPen(bgGradient_End,-1));
                        painter.drawPie(0,0,this->width(),pieHeight,360*16,360*8);


                        painter.fillRect(0,pieHeight/2,this->width(),this->height(),rush2);




                        paintBar(&painter);
                        paintHandle(&painter);



                        int distanceBorder = distanceDash - widthDash;

                       for (int i=this->height();i>=distanceBorder+pieHeight-distanceBorder;i--) {

                            painter.fillRect(0,i,this->width(),widthDash,dividerColor); //#000000

                        i=i-distanceDash;

                        //painter.fillRect(0,i,this->width(),widthDash,dividerColor); //#000000
                       }
                        }
                       break;
                        case 1:
                        {
                            if (this->invertedAppearance()==false) {
                        painter.setBackgroundMode(Qt::OpaqueMode);

                        if (customRounding == false) {
                            pieHeight=(this->width()/2)*2;
                        } else if (customRounding == true) {
                            pieHeight = this->property("customRoundingValue").toInt()*2;
                        }
                          else
                        {

                            pieHeight=(this->width()/2)*2;
                        }
                        //pieHeight=pieHeight/2;

                        QLinearGradient gradientBackground(0,this->height()-pieHeight,0,pieHeight/2);
                        gradientBackground.setColorAt(0,bgGradient_Start);
                        gradientBackground.setColorAt(1,bgGradient_End);

                        QBrush rush2 = QBrush(gradientBackground);

                        painter.setRenderHint(QPainter::Antialiasing,true);

                        painter.setBrush(rush2);
                        painter.setPen(QPen(rush2,-1));
                        painter.drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);


                        painter.fillRect(0,0,this->width(),this->height()-pieHeight/2,rush2);




                        paintBar(&painter);
                        paintHandle(&painter);



                        int distanceBorder = distanceDash - widthDash;

                       for (int i=this->height()-pieHeight;i>=0;i--) {

                            painter.fillRect(0,i,this->width(),widthDash,dividerColor); //#000000

                        i=i-distanceDash;

                        //painter.fillRect(0,i,this->width(),widthDash,dividerColor); //#000000
                                }
                            } else if (this->invertedAppearance()==true) {

                                painter.setBackgroundMode(Qt::OpaqueMode);

                                if (customRounding == false) {
                                    pieHeight=(this->width()/2)*2;
                                } else if (customRounding == true) {
                                    pieHeight = this->property("customRoundingValue").toInt()*2;
                                }
                                  else
                                {

                                    pieHeight=(this->width()/2)*2;
                                }
                                //pieHeight=pieHeight/2;

                                QLinearGradient gradientBackground(0,this->height()-pieHeight,0,pieHeight/2);
                                gradientBackground.setColorAt(1,bgGradient_Start);
                                gradientBackground.setColorAt(0,bgGradient_End);

                                QBrush rush2 = QBrush(gradientBackground);

                                painter.setRenderHint(QPainter::Antialiasing,true);

                                painter.setBrush(rush2);
                                painter.setPen(QPen(rush2,-1));
                                painter.drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);


                                painter.fillRect(0,0,this->width(),this->height()-pieHeight/2,rush2);




                                paintBar(&painter);
                                paintHandle(&painter);



                                int distanceBorder = distanceDash - widthDash;

                               for (int i=this->height()-pieHeight;i>=0;i--) {

                                    painter.fillRect(0,i,this->width(),widthDash,dividerColor); //#000000

                                i=i-distanceDash;
                               }

                            }
                       }
                       break;
                        default:
                           break;
                        }
                    }

                } else {

                    QLinearGradient gradient1(rect().bottomLeft(), rect().topRight());
                        gradient1.setColorAt(0, bgGradient_Start);//QColor("#363496")
                        gradient1.setColorAt(1, bgGradient_End); //QColor("#131128")

                    QBrush rush1 = QBrush(gradient1);
                    painter.setBackgroundMode(Qt::OpaqueMode);
                    painter.setBackground(rush1);

                    painter.setRenderHint(QPainter::Antialiasing,true);


                    painter.fillRect(0,0,this->width(),this->height(),rush1);

                    paintBar(&painter);
                    paintHandle(&painter);



                    int distanceBorder = distanceDash - widthDash;

                   for (int i=this->height();i>=distanceBorder/*-distanceBorder*/;i--) {

                        painter.fillRect(0,i,this->width(),widthDash,dividerColor); //#000000

                    i=i-distanceDash;

                    painter.fillRect(0,i,this->width(),widthDash,dividerColor); //#000000
                   }


                }

        }
            break;
        default:
            break;
        }

    }
        break;
    case 2:
                {

                        paintBar(&painter);
                        paintHandle(&painter);

                }
    break;
    default:
        break;
    }
}

void LCARS_Slider::mouseMoveEvent(QMouseEvent *e)
{



    switch (this->orientation()) {
    case Qt::Horizontal:
    {
        if(e->buttons() == Qt::LeftButton)
            p = this->mapFromGlobal(QCursor::pos());

        int maxVal = this->maximum();

        //! ((LOWER NUMBER)/(BIGGER NUMBER)*100)*(MAXIMUM/100)
        resultValue = (int)((((double)p.x()/(double)this->width())*100)*(double)maxVal/100);

        if (this->hasTracking() == true) {
            if (resultValue >= this->minimum() && resultValue <=this->maximum()) {
                this->setValue(resultValue);
                emit valueChanged(resultValue);
                emit sliderMoved(resultValue);
                temp.setX(p.x());
            }
        }


    }
        break;
    case Qt::Vertical: {
        if(e->buttons() == Qt::LeftButton) {

            if (this->invertedControls()==false) {
            p = this->mapFromGlobal(QCursor::pos());


        int maxVal = this->maximum();

        //! ((LOWER NUMBER)/(BIGGER NUMBER)*100)*(MAXIMUM/100)
        //if (p.y()>=pieHeight+widthDash && p.y()<=this->height()-pieHeight+widthDash) {
        resultValue = (int)((((double)(this->height()-p.y())/(double)this->height())*100)*(double)maxVal/100);

        if (this->hasTracking() == true) {
            if (resultValue >= this->minimum() && resultValue <=this->maximum()) {
                this->setValue(resultValue);
                emit valueChanged(resultValue);
                emit sliderMoved(resultValue);
                temp.setY(p.y());
            }
        }
            } else if(this->invertedControls()==true) {

                p = this->mapFromGlobal(QCursor::pos());


            int maxVal = this->maximum();

            //! ((LOWER NUMBER)/(BIGGER NUMBER)*100)*(MAXIMUM/100)
            //if (p.y()>=pieHeight+widthDash && p.y()<=this->height()-pieHeight+widthDash) {


            resultValue = (int)((((double)(this->height()-p.y())/(double)this->height())*100)*(double)maxVal/100);




            if (this->hasTracking() == true) {
                if (resultValue >= this->minimum() && resultValue <=this->maximum()) {
                     //qDebug() << "thisvalue" << this->maximum()-resultValue;

                    this->setValue(this->maximum()-resultValue);

                    emit valueChanged(resultValue);
                    emit sliderMoved(resultValue);
                    temp.setY(p.y());
                }
            }

}
            }

    }
    default:
        break;
    }


    this->repaint();
}



void LCARS_Slider::mousePressEvent ( QMouseEvent * e ) {

    /*if(event->buttons() == Qt::LeftButton) {
            qDebug() << "Only right button";
    }*/

    switch (this->orientation()) {
    case Qt::Horizontal:
    {
        if(e->buttons() == Qt::LeftButton)
            p = this->mapFromGlobal(QCursor::pos());

        int maxVal = this->maximum();

        //! ((LOWER NUMBER)/(BIGGER NUMBER)*100)*(MAXIMUM/100)
        resultValue = (int)((((double)p.x()/(double)this->width())*100)*(double)maxVal/100);

        if (this->hasTracking() == true) {
            if (resultValue >= this->minimum() && resultValue <=this->maximum()) {
                this->setValue(resultValue);
                emit valueChanged(resultValue);
                emit sliderMoved(resultValue);
                temp.setX(p.x());
            }
        }


    }
        break;
    case Qt::Vertical: {
        if(e->buttons() == Qt::LeftButton) {

            if (this->invertedControls()==false) {
            p = this->mapFromGlobal(QCursor::pos());


        int maxVal = this->maximum();

        //! ((LOWER NUMBER)/(BIGGER NUMBER)*100)*(MAXIMUM/100)
        //if (p.y()>=pieHeight+widthDash && p.y()<=this->height()-pieHeight+widthDash) {
        resultValue = (int)((((double)(this->height()-p.y())/(double)this->height())*100)*(double)maxVal/100);

        if (this->hasTracking() == true) {
            if (resultValue >= this->minimum() && resultValue <=this->maximum()) {
                this->setValue(resultValue);
                emit valueChanged(resultValue);
                emit sliderMoved(resultValue);
                temp.setY(p.y());
            }
        }
            } else if(this->invertedControls()==true) {

                p = this->mapFromGlobal(QCursor::pos());


            int maxVal = this->maximum();

            //! ((LOWER NUMBER)/(BIGGER NUMBER)*100)*(MAXIMUM/100)
            //if (p.y()>=pieHeight+widthDash && p.y()<=this->height()-pieHeight+widthDash) {


            resultValue = (int)((((double)(this->height()-p.y())/(double)this->height())*100)*(double)maxVal/100);




            if (this->hasTracking() == true) {
                if (resultValue >= this->minimum() && resultValue <=this->maximum()) {
                     //qDebug() << "thisvalue" << this->maximum()-resultValue;

                    this->setValue(this->maximum()-resultValue);

                    emit valueChanged(resultValue);
                    emit sliderMoved(resultValue);

                    temp.setY(p.y());
                }
            }

}
            }

    }
    default:
        break;
    }



    handleBackground = QColor(this->property("handleBackgroundPressed").toString());
    this->repaint();
}

void LCARS_Slider::mouseReleaseEvent ( QMouseEvent * e ) {

    switch (this->orientation()) {
    case Qt::Horizontal:
    {
        if(e->buttons() == Qt::LeftButton)
            p = this->mapFromGlobal(QCursor::pos());

        int maxVal = this->maximum();

        //! ((LOWER NUMBER)/(BIGGER NUMBER)*100)*(MAXIMUM/100)
        resultValue = (int)((((double)p.x()/(double)this->width())*100)*(double)maxVal/100);
        temp.setX(p.x());

        if (this->hasTracking() == true) {
            if (resultValue >= this->minimum() && resultValue <=this->maximum()) {
                this->setValue(resultValue);
                emit valueChanged(resultValue);
                emit sliderMoved(resultValue);

            }
        }


    }
        break;
    case Qt::Vertical: {
        if(e->buttons() == Qt::LeftButton) {

            if (this->invertedControls()==false) {
            p = this->mapFromGlobal(QCursor::pos());


        int maxVal = this->maximum();

        //! ((LOWER NUMBER)/(BIGGER NUMBER)*100)*(MAXIMUM/100)
        //if (p.y()>=pieHeight+widthDash && p.y()<=this->height()-pieHeight+widthDash) {
        resultValue = (int)((((double)(this->height()-p.y())/(double)this->height())*100)*(double)maxVal/100);
        temp.setY(p.y());

        if (this->hasTracking() == true) {
            if (resultValue >= this->minimum() && resultValue <=this->maximum()) {
                this->setValue(resultValue);
                emit valueChanged(resultValue);
                emit sliderMoved(resultValue);

            }
        }
            } else if(this->invertedControls()==true) {

                p = this->mapFromGlobal(QCursor::pos());


            int maxVal = this->maximum();

            //! ((LOWER NUMBER)/(BIGGER NUMBER)*100)*(MAXIMUM/100)
            //if (p.y()>=pieHeight+widthDash && p.y()<=this->height()-pieHeight+widthDash) {


            resultValue = (int)((((double)(this->height()-p.y())/(double)this->height())*100)*(double)maxVal/100);

            temp.setY(p.y());


            if (this->hasTracking() == true) {
                if (resultValue >= this->minimum() && resultValue <=this->maximum()) {
                     //qDebug() << "thisvalue" << this->maximum()-resultValue;

                    this->setValue(this->maximum()-resultValue);

                    emit valueChanged(resultValue);
                    emit sliderMoved(resultValue);

                }
            }

}
            }

    }
    default:
        break;
    }




    handleBackground = QColor(this->property("handleBackground").toString());
    emit sliderReleased();
    this->repaint();
    /*p.setX(0);
    p.setY(0);*/
    temp.setX(0);
    temp.setY(0);
}


void LCARS_Slider::paintHandle(QPainter *painter) {

        switch (sliderMode) {
        case 0:

        {


            int handleWidth = handleSize.width();//20;
            int handleBorder = handleBorderSize.width(); //5;

            //int handleX=this->value()+handleBorder;
            int handleY=0;

            int handleX = ((int)((double)resultValue/(double)this->maximum()*100)*(double)this->width()/100);

            if (handleX+handleWidth>=this->width()) {


                handleX=this->width()-(handleWidth);
            } else if (p.x()<0) {
                /*qDebug() << p.x() << this->width();
                    qDebug() << "lol" << handleX;
                */
                    handleX=0;
            }



            /*if (p.x()-(handleWidth)+handleBorder>=0) {
                handleX=p.x()-(handleWidth)/2+handleBorder/2;

            }*/

            /*if (p.x()+(handleWidth/2+handleBorder)>=this->width()) {
                handleX=this->width()-(handleWidth+handleBorder);

            }*/

            painter->fillRect(handleX,handleY,handleWidth,this->height(),handleBackground);
            painter->fillRect(handleX-handleBorder,handleY,handleBorder,this->height(),handleBorderColor);
            painter->fillRect(handleX+handleWidth,handleY,handleBorder,this->height(),handleBorderColor);
        }

            break;
        case 1:
        {
            switch (this->orientation()) {
            case Qt::Horizontal:
            {
                int handleY=0;
                int handleX = ((int)((double)resultValue/(double)this->maximum()*100)*(double)this->width()/100);

                QLinearGradient gradient1(rect().topLeft(), rect().bottomRight());
                gradient1.setColorAt(0, frontGradient_Start); //QColor("#e66e1e")
                gradient1.setColorAt(1, frontGradient_End); //QColor("#ba001e")

                QBrush rush1 = QBrush(gradient1);

                int distanceBorder = distanceDash - widthDash;

                if (p.x()<handleX) {
                    for (int i=distanceBorder;i<=handleX;i++) {

                        painter->fillRect(0,handleY,i,this->height(),rush1);
                        i=i+distanceDash;
                        painter->fillRect(0,handleY,i,this->height(),rush1);
                    }
                } else if(p.x()==handleX) {

                    for (int i=distanceBorder;i<=p.x();i++) {

                        painter->fillRect(0,handleY,i,this->height(),rush1);
                        i=i+distanceDash;
                        painter->fillRect(0,handleY,i,this->height(),rush1);
                    }
                } else if(p.x() > handleX) {

                    for (int i=distanceBorder;i<=p.x();i++) {

                        painter->fillRect(0,handleY,i,this->height(),rush1);
                        i=i+distanceDash;
                        painter->fillRect(0,handleY,i,this->height(),rush1);
                    }
                } else if (p.x()-widthDash<handleX) {
                    for (int i=distanceBorder;i<=p.x();i++) {

                        painter->fillRect(0,handleY,i,this->height(),rush1);
                        i=i+distanceDash;


                    }
                }
            }
                break;
            case Qt::Vertical:
                {
                    //! [ ---- ROUND BORDER TRUE ---- ]
                    if (roundBorder == false) {

                        int handleY = ((int)((double)resultValue/(double)this->maximum()*100)*(double)this->height()/100);

                        QLinearGradient gradient1(rect().bottomLeft(), rect().topRight());
                        gradient1.setColorAt(0, frontGradient_Start); //QColor("#e66e1e")
                        gradient1.setColorAt(1, frontGradient_End); //QColor("#ba001e")

                        QBrush rush1 = QBrush(gradient1);

                        int distanceBorder = distanceDash - widthDash;

                    if (p.y()<handleY) {
                        for (int i=distanceBorder;i<=handleY;i++) {
                            painter->fillRect(0,this->height(),this->width(),i*-1,rush1);
                            i=i+distanceDash;
                            painter->fillRect(0,this->height(),this->width(),i*-1,rush1);
                        }
                    }
                    else if (p.y()<=widthDash+distanceDash) {
                        for (int i=distanceBorder;i<=p.y();i++) {
                            painter->fillRect(0,i,this->width(),handleY*-1,rush1);
                            i=i+distanceDash;
                        }
                    }
                    else if(p.y()==handleY) {

                        for (int i=distanceBorder;i<=p.y();i++) {
                            painter->fillRect(0,this->height(),this->width(),i*-1,rush1);
                            i=i+distanceDash;
                            painter->fillRect(0,this->height(),this->width(),i*-1,rush1);
                        }
                    } else if(p.y() > handleY) {

                        for (int i=distanceBorder;i<=handleY;i++) {

                            painter->fillRect(0,this->height(),this->width(),i*-1,rush1);
                            i=i+distanceDash;
                            painter->fillRect(0,this->height(),this->width(),i*-1,rush1);
                        }
                    } else if (p.y()-widthDash<this->height()) {

                        for (int i=distanceBorder;i<=p.y();i++) {
                            painter->fillRect(0,this->height(),this->width(),i*-1,rush1);
                            i=i+distanceDash;
                        }
                    }

                    }
                    //! [ ---- ROUND BORDER TRUE ---- ]
                    else if(roundBorder == true) {
                        if (onlyOne == false) {

                        int handleY = ((int)((double)resultValue/(double)this->maximum()*100)*(double)this->height()/100);

                        QLinearGradient gradient1(rect().bottomLeft(), rect().topRight());
                        gradient1.setColorAt(0, frontGradient_Start); //QColor("#e66e1e")
                        gradient1.setColorAt(1, frontGradient_End); //QColor("#ba001e")

                        QBrush rush1 = QBrush(gradient1);

                        int distanceBorder = distanceDash - widthDash;

                        if (p.y()>pieHeight && p.y() < this->height()-pieHeight) {
                            for (int i=pieHeight;i<this->height()-pieHeight;i++) {
                            i=i+distanceBorder;
                        }
                    }

                    if (p.y()<=pieHeight && p.y()!=0) {

                        painter->setBrush(rush1);
                        painter->setPen(QPen(rush1,-1));
                        painter->drawPie(0,0,this->width(),pieHeight,360*16,360*8);

                        painter->fillRect(0,pieHeight/2,this->width(),pieHeight/2,rush1);

                        painter->fillRect(0,pieHeight,this->width(),this->height()-pieHeight*2,rush1);
                        painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                        painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);

                    }
                    else if(p.y()==0 && handleY==this->height()) {

                        painter->setBrush(rush1);
                        painter->setPen(QPen(rush1,-1));
                        painter->drawPie(0,0,this->width(),pieHeight,360*16,360*8);

                        painter->fillRect(0,pieHeight/2,this->width(),pieHeight/2,rush1);

                        painter->fillRect(0,pieHeight,this->width(),this->height()-pieHeight*2,rush1);
                        painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                        painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);

                    }
                    else if (p.y()>=this->height()-pieHeight && p.y()<this->height()) {

                        painter->setBrush(rush1);
                        painter->setPen(QPen(rush1,-1));
                        painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                        painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);
                    }
                    else if ((p.y()>pieHeight && p.y() < this->height()-pieHeight) || p.y()<handleY-pieHeight /*p.y()==0*/) {
                        for (int i=0;i<handleY-pieHeight;i++) {
                            painter->fillRect(0,this->height()-pieHeight,this->width(),-i-distanceDash,rush1);
                            i=i+distanceDash;
                        }

                        painter->setBrush(rush1);
                        painter->setPen(QPen(rush1,-1));
                        painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                        painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);
                    }
                }

                        //! ONLY ONE
                        else if (onlyOne==true) {
                        switch (topBottom) {

                        case 0:
                            {
                            int handleY = ((int)((double)resultValue/(double)this->maximum()*100)*(double)this->height()/100);

                            QLinearGradient gradient1(rect().bottomLeft(), rect().topRight());
                            gradient1.setColorAt(0, frontGradient_Start); //QColor("#e66e1e")
                            gradient1.setColorAt(1, frontGradient_End); //QColor("#ba001e")

                            QBrush rush1 = QBrush(gradient1);

                            int distanceBorder = distanceDash - widthDash;

                            if (p.y()>pieHeight && p.y() < this->height()-pieHeight) {
                                for (int i=pieHeight;i<this->height()-pieHeight;i++) {
                                i=i+distanceBorder;
                            }
                        }

                            if(handleY+pieHeight>this->height()) {
                                painter->setBrush(rush1);
                                painter->setPen(QPen(rush1,-1));
                                painter->drawPie(0,0,this->width(),pieHeight,360*16,360*8);

                                painter->fillRect(0,pieHeight/2,this->width(),pieHeight/2,rush1);
                                painter->fillRect(0,pieHeight,this->width(),this->height()-pieHeight,rush1);
                            }
                        else if (p.y()<=pieHeight && p.y()!=0) {

                            painter->setBrush(rush1);
                            painter->setPen(QPen(rush1,-1));
                            painter->drawPie(0,0,this->width(),pieHeight,360*16,360*8);

                            painter->fillRect(0,pieHeight/2,this->width(),pieHeight/2,rush1);
                            painter->fillRect(0,pieHeight,this->width(),this->height()-pieHeight,rush1);



                        }

                        else if ((p.y()>pieHeight && p.y() < this->height()-pieHeight/2+distanceBorder) || p.y()<handleY-pieHeight ) {
                            for (int i=0;i<handleY-pieHeight/2+distanceBorder;i++) {
                                painter->fillRect(0,this->height(),this->width(),-i-distanceDash,rush1);
                                i=i+distanceDash;
                            }
                        }


                        qDebug() << "py" << this->height()-p.y() << "handle y" << handleY << "pieheight" << pieHeight << "this" << this->height();
                        } //! ERSTE ENDE
                        break;
                        case 1:
                        {
                        if (this->invertedAppearance()==false) {


                            int handleY = ((int)((double)resultValue/(double)this->maximum()*100)*(double)this->height()/100);

                            QLinearGradient gradient1(rect().bottomLeft(), rect().topRight());
                            gradient1.setColorAt(0, frontGradient_Start); //QColor("#e66e1e")
                            gradient1.setColorAt(1, frontGradient_End); //QColor("#ba001e")

                            QBrush rush1 = QBrush(gradient1);

                            int distanceBorder = distanceDash - widthDash;

                            if (p.y()>pieHeight && p.y() < this->height()-pieHeight) {
                                for (int i=pieHeight;i<this->height()-pieHeight;i++) {
                                i=i+distanceBorder;
                            }
                        }

                        /*if (p.y()<=pieHeight && p.y()!=0) {

                            painter->setBrush(rush1);
                            painter->setPen(QPen(rush1,-1));
                            painter->drawPie(0,0,this->width(),pieHeight,360*16,360*8);

                            painter->fillRect(0,pieHeight/2,this->width(),pieHeight/2,rush1);

                            painter->fillRect(0,pieHeight,this->width(),this->height()-pieHeight*2,rush1);
                            painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                            painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);

                        }
                        else*/ /*if(p.y()==0 && handleY==this->height()) {

                            painter->setBrush(rush1);
                            painter->setPen(QPen(rush1,-1));
                            painter->drawPie(0,0,this->width(),pieHeight,360*16,360*8);

                            painter->fillRect(0,pieHeight/2,this->width(),pieHeight/2,rush1);

                            painter->fillRect(0,pieHeight,this->width(),this->height()-pieHeight*2,rush1);
                            painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                            painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);

                        }
                        else*/ if (p.y()>=this->height()-pieHeight && p.y()<this->height()) {

                            painter->setBrush(rush1);
                            painter->setPen(QPen(rush1,-1));
                            painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                            painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);
                        }
                        else if ((p.y()>pieHeight && p.y() < this->height()-pieHeight) || p.y()<handleY-pieHeight /*p.y()==0*/) {
                            for (int i=0;i<handleY-pieHeight;i++) {
                                painter->fillRect(0,this->height()-pieHeight,this->width(),-i-distanceDash,rush1);
                                i=i+distanceDash;
                            }

                            painter->setBrush(rush1);
                            painter->setPen(QPen(rush1,-1));
                            painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                            painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);
                        }
                        }else if(this->invertedAppearance()==true) {

                            if (this->invertedControls()==false) {

                            int handleY = ((int)((double)resultValue/(double)this->maximum()*100)*(double)this->height()/100);

                            QLinearGradient gradient1(rect().bottomLeft(), rect().topRight());
                            gradient1.setColorAt(1, frontGradient_Start); //QColor("#e66e1e")
                            gradient1.setColorAt(0, frontGradient_End); //QColor("#ba001e")

                            QBrush rush1 = QBrush(gradient1);

                            int distanceBorder = distanceDash - widthDash;

                            if (p.y()>pieHeight && p.y() < this->height()-pieHeight) {
                                for (int i=pieHeight;i<this->height()-pieHeight;i++) {
                                i=i+distanceBorder;
                            }
                        }

                         if (p.y()>=this->height()-pieHeight && p.y()<this->height()) {

                            painter->setBrush(rush1);
                            painter->setPen(QPen(rush1,-1));
                            painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                            painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);
                        }
                        else if ((p.y()>pieHeight && p.y() < this->height()-pieHeight) || p.y()<handleY-pieHeight /*p.y()==0*/) {
                            for (int i=0;i<handleY-pieHeight;i++) {
                                painter->fillRect(0,this->height()-pieHeight,this->width(),-i-distanceDash,rush1);
                                i=i+distanceDash;
                            }

                            painter->setBrush(rush1);
                            painter->setPen(QPen(rush1,-1));
                            painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                            painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);
                        }

                        }else if (this->invertedControls() == true) {


                                qDebug() << "changed";
                                int handleY = ((int)((double)resultValue/(double)this->maximum()*100)*(double)this->height()/100);

                                QLinearGradient gradient1(rect().bottomLeft(), rect().topRight());
                                gradient1.setColorAt(1, frontGradient_Start); //QColor("#e66e1e")
                                gradient1.setColorAt(0, frontGradient_End); //QColor("#ba001e")

                                QBrush rush1 = QBrush(gradient1);

                                int distanceBorder = distanceDash - widthDash;

                               /* if (p.y()>pieHeight && p.y() < this->height()-pieHeight) {
                                    for (int i=pieHeight;i<this->height()-pieHeight;i++) {
                                    i=i+distanceBorder;
                                }
                            }*/

                            /*if (p.y()<=pieHeight && p.y()!=0) {

                                painter->setBrush(rush1);
                                painter->setPen(QPen(rush1,-1));
                                painter->drawPie(0,0,this->width(),pieHeight,360*16,360*8);

                                painter->fillRect(0,pieHeight/2,this->width(),pieHeight/2,rush1);

                                painter->fillRect(0,pieHeight,this->width(),this->height()-pieHeight*2,rush1);
                                painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                                painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);

                            }
                            else*/ /*if(p.y()==0 && handleY==this->height()) {

                                painter->setBrush(rush1);
                                painter->setPen(QPen(rush1,-1));
                                painter->drawPie(0,0,this->width(),pieHeight,360*16,360*8);

                                painter->fillRect(0,pieHeight/2,this->width(),pieHeight/2,rush1);

                                painter->fillRect(0,pieHeight,this->width(),this->height()-pieHeight*2,rush1);
                                painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                                painter->fillRect(0,this->height()-pieHeight,this->width(),pieHeight/2,rush1);

                            }
                            else*/

                               /* if (p.y()>0 && p.y() < this->height()-pieHeight) {
                                    for (int i=pieHeight;i<this->height()-pieHeight;i++) {

                                    painter->fillRect(0,0,this->width(),i,rush1);
                                    i=i+distanceBorder;
                                    qDebug() << "irgendwo hier" ;


                                }
                            }*/

                            if ((p.y()>=this->height()-pieHeight && p.y()<=this->height() )|| p.y()>=this->height()) {


                                painter->setBrush(rush1);
                                painter->setPen(QPen(rush1,-1));
                                painter->drawPie(0,this->height()-pieHeight,this->width(),pieHeight,360*8,360*8);
                                painter->fillRect(0,0,this->width(),this->height()-pieHeight/2,rush1);
                            }
                            //else if ((p.y()>pieHeight && p.y() < this->height()-pieHeight) || p.y()<handleY-pieHeight /*p.y()==0*/) {
                             else if (p.y()<this->height()-pieHeight  ) {
                                for (int i=this->height()-handleY;i>0;i++) {
                                    //qDebug() << this->height()-handleY;

                                    painter->fillRect(0,0,this->width(),i,rush1);
                                    i=i-distanceDash;
                                }
                              }

                            }
                        } //! INVERTED APPEAREANCE

                        }
                            break;
                        default:
                            break;
                        } //! SWITCH ENDE




                        }

                }
            }
                break;
            default:
                break;
            }

        }
            break;

        case 2:
                {

                    switch (orientation()) {
                    case Qt::Horizontal:
                    {

                    }
                        break;
                    case Qt::Vertical:
                    {
                        switch (this->layoutDirection()) {
                        case Qt::LeftToRight:
                        {

                            int handleY = ((int)((double)resultValue/(double)this->maximum()*100)*(double)this->height()/100);

                            /*int border_roundedHandleWidth=5;
                            QSize size_roundedHandleTop(30,30);
                            QSize size_roundedHandleBottom(30,30);
                            QSize size_roundedHandle(15,35);*/

                            QPoint point_roundedHandle(this->width(),handleY);

                            if (p.y()<=0 || p.y()<=size_roundedHandle.height()/2) {
                                point_roundedHandle.setY(0);
                            } else if (p.y()>=this->height()|| p.y()>=this->height()-size_roundedHandle.height()/2) {
                                point_roundedHandle.setY(this->height()-size_roundedHandle.height());
                            }
                            else {
                                     //point_roundedHandle=QPoint(this->width(),p.y()-size_roundedHandle.height()/2);
                                    point_roundedHandle.setY(this->height()-handleY-size_roundedHandle.height()/2);
                            }

                            QRect rect_roundedHandle(point_roundedHandle,size_roundedHandle);


                            QPoint point_roundedHandlePieTop(rect_roundedHandle.x()-rect_roundedHandle.width()-size_roundedHandleTop.width()/2,
                                                             rect_roundedHandle.y());


                            QPoint point_roundedHandlePieBottom(rect_roundedHandle.x()-rect_roundedHandle.width()-size_roundedHandleTop.width()/2,
                                                                rect_roundedHandle.y()+rect_roundedHandle.height()-size_roundedHandleBottom.height());

                            QRect rect_roundedHandleTop(point_roundedHandlePieTop,
                                                        size_roundedHandleTop);

                            QRect rect_roundedHandleBottom(point_roundedHandlePieBottom,
                                                        size_roundedHandleBottom);

                            QRect rect_roundedHandleFillerRect(rect_roundedHandle.x()-rect_roundedHandle.width(),
                                                               point_roundedHandlePieTop.y()+size_roundedHandleTop.height()/2,
                                                               -1*(size_roundedHandleTop.width()/2),
                                                               rect_roundedHandle.height()-size_roundedHandleBottom.height()/2-size_roundedHandleTop.height()/2);


                            painter->setRenderHint(QPainter::Antialiasing,true);




                            painter->setBrush(handleBorderColor);
                            painter->setPen(QPen(handleBorderColor,border_roundedHandleWidth*2));


                            painter->drawRect(rect_roundedHandle.x(),rect_roundedHandle.y(),-1*(rect_roundedHandle).width(),rect_roundedHandle.height());

                            painter->drawPie(rect_roundedHandleTop,360*4,360*4);
                            painter->drawPie(rect_roundedHandleBottom,360*8,360*4);

                            painter->drawRect(rect_roundedHandleFillerRect);




                            painter->setBrush(handleBackground);
                            painter->setPen(QPen(handleBackground,-1));

                            painter->fillRect(rect_roundedHandle.x(),rect_roundedHandle.y(),-1*(rect_roundedHandle).width(),rect_roundedHandle.height(),handleBackground);

                            painter->drawPie(rect_roundedHandleTop,360*4,360*4);
                            painter->drawPie(rect_roundedHandleBottom,360*8,360*4);

                            painter->fillRect(rect_roundedHandleFillerRect,handleBackground);

                        }
                            break;
                        case Qt::RightToLeft:
                        {

                            int handleY = ((int)((double)resultValue/(double)this->maximum()*100)*(double)this->height()/100);


                            /*int border_roundedHandleWidth=5;
                            QSize size_roundedHandleTop(30,30);
                            QSize size_roundedHandleBottom(30,30);
                            QSize size_roundedHandle(15,35);*/

                            QPoint point_roundedHandle(0,handleY);

                            /*if (p.y()<=0 || p.y()<=size_roundedHandle.height()/2) {
                                point_roundedHandle.y()=0;
                            } else if (p.y()>=this->height()|| p.y()>=this->height()-size_roundedHandle.height()/2) {
                                point_roundedHandle= QPoint(0,this->height()-size_roundedHandle.height());
                            }
                            else {
                                     point_roundedHandle=QPoint(0,p.y()-size_roundedHandle.height()/2);
                            }*/

                            if (p.y()<=0 || p.y()<=size_roundedHandle.height()/2) {
                                point_roundedHandle.setY(0);
                            } else if (p.y()>=this->height()|| p.y()>=this->height()-size_roundedHandle.height()/2) {
                                point_roundedHandle.setY(this->height()-size_roundedHandle.height());
                            }
                            else {
                                     //point_roundedHandle=QPoint(this->width(),p.y()-size_roundedHandle.height()/2);
                                    point_roundedHandle.setY(this->height()-handleY-size_roundedHandle.height()/2);
                            }

                            QRect rect_roundedHandle(point_roundedHandle,size_roundedHandle);


                            QPoint point_roundedHandlePieTop(rect_roundedHandle.x()+rect_roundedHandle.width()-size_roundedHandleTop.width()/2,
                                                             rect_roundedHandle.y());


                            QPoint point_roundedHandlePieBottom(rect_roundedHandle.x()+rect_roundedHandle.width()-size_roundedHandleTop.width()/2,
                                                                rect_roundedHandle.y()+rect_roundedHandle.height()-size_roundedHandleBottom.height());

                            QRect rect_roundedHandleTop(point_roundedHandlePieTop,
                                                        size_roundedHandleTop);

                            QRect rect_roundedHandleBottom(point_roundedHandlePieBottom,
                                                        size_roundedHandleBottom);

                            QRect rect_roundedHandleFillerRect(rect_roundedHandle.x()+rect_roundedHandle.width(),
                                                               point_roundedHandlePieTop.y()+size_roundedHandleTop.height()/2,
                                                               size_roundedHandleTop.width()/2,
                                                               /*rect_roundedHandle.height()-size_roundedHandleTop.height()/2-size_roundedHandleBottom.height()/2*/
                                                               /*rect_roundedHandle.y()+rect_roundedHandle.height()-size_roundedHandleBottom.height()*/
                                                               rect_roundedHandle.height()-size_roundedHandleBottom.height()/2-size_roundedHandleTop.height()/2);


                            painter->setRenderHint(QPainter::Antialiasing,true);




                            painter->setBrush(handleBorderColor);
                            painter->setPen(QPen(handleBorderColor,border_roundedHandleWidth*2));


                            painter->drawRect(rect_roundedHandle.x(),rect_roundedHandle.y(),rect_roundedHandle.width(),rect_roundedHandle.height());

                            painter->drawPie(rect_roundedHandleTop,360*16,360*4);
                            painter->drawPie(rect_roundedHandleBottom,360*12,360*4);

                            painter->drawRect(rect_roundedHandleFillerRect);


                            painter->setBrush(handleBackground);
                            painter->setPen(QPen(handleBackground,-1));

                            painter->fillRect(rect_roundedHandle.x(),rect_roundedHandle.y(),rect_roundedHandle.width(),rect_roundedHandle.height(),handleBackground);

                            painter->drawPie(rect_roundedHandleTop,360*16,360*4);
                            painter->drawPie(rect_roundedHandleBottom,360*12,360*4);

                            painter->fillRect(rect_roundedHandleFillerRect,handleBackground);
                        }
                            break;
                        default:
                            //painter->fillRect(0,0,this->width()/2,this->height(),barBackgroundTop);
                            break;
                        }
                    }
                    default:
                        break;
                    }


                }
        default:
            break;
        }
}

void LCARS_Slider::paintBar(QPainter *painter) {

    switch (sliderMode) {
    case 0:{
        int height1 = barTopLine.height();
        int height2 = barBottomLine.height();

        int y1 = (this->height()/2-height1)/2;
        int y2 = ((this->height()/2-height1)/2)+this->height()/2;
        painter->fillRect(0,y1+1,this->width(),height1,barBackgroundTop); //QColor("#ff9900")
        painter->fillRect(0,y2+1,this->width(),height2,barBackgroundBottom);
    }
    case 1: {
    }
        break;
    case 2:
            {

                switch (orientation()) {
                case Qt::Horizontal:
                {

                }
                    break;
                case Qt::Vertical:
                {
                    switch (this->layoutDirection()) {
                    case Qt::LeftToRight:
                    {

                        painter->fillRect(this->width(),0,-1*(roundHandle_Bar_width),this->height(),bar_roundedHandleColor);
                    }
                        break;
                    case Qt::RightToLeft:
                    {
                        painter->fillRect(0,0,roundHandle_Bar_width,this->height(),bar_roundedHandleColor);
                    }
                        break;
                    default:
                        break;
                    }
                }
                default:
                    break;
                }


            }
    default:
        break;
    }



}
