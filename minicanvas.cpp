#include "minicanvas.h"
#include "waterbased.h"
#include "maskbased.h"
#include "binarybrush.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtCore/qmath.h>
#include <QDebug>

MiniCanvas::MiniCanvas(QWidget *parent) :
    QWidget(parent),
    pre_size_(1280, 480),
    result_(new QImage(pre_size_, QImage::Format_ARGB32_Premultiplied)),
    mouse_press_(false)
{
    setFocusPolicy(Qt::StrongFocus);
    result_->fill(Qt::white);
    brush_ = new BasicBrush;
    brush_->setSurface(result_);
    brush_->setColor(Qt::green);
    brush_->setWidth(100);
    brush_->setThickness(100);
}

QSize MiniCanvas::sizeHint() const
{
    return pre_size_;
}

QSize MiniCanvas::minimumSizeHint() const
{
    return pre_size_;
}

void MiniCanvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0, 0, *result_.data());
}

void MiniCanvas::mousePressEvent(QMouseEvent *ev)
{
    mouse_press_ = true;
    brush_->drawPoint(ev->pos());
    update();
}

void MiniCanvas::mouseMoveEvent(QMouseEvent *ev)
{
    if(mouse_press_){
        brush_->drawLineTo(ev->pos());
        update();
    }
}

void MiniCanvas::mouseReleaseEvent(QMouseEvent *)
{
    mouse_press_ = false;
}

void MiniCanvas::tabletEvent(QTabletEvent *)
{
    //
}

void MiniCanvas::keyPressEvent(QKeyEvent *ev)
{
    switch(ev->key()){
    case Qt::Key_F1:
        changeToBrush<BasicBrush>();
        break;
    case Qt::Key_F2:
        changeToBrush<WaterBased>();
        break;
    case Qt::Key_F3:
        changeToBrush<MaskBased>();
    {
        MaskBased* m = static_cast<MaskBased*>(brush_);
        m->setMask(QImage("canvas-print.png"));
    }
        break;
    case Qt::Key_F4:
        changeToBrush<BinaryBrush>();
        break;
    case Qt::Key_D:
        result_->fill(Qt::white);
        break;
    }
}

template<typename BrushType>
void MiniCanvas::changeToBrush()
{
    if(std::is_base_of<AbstractBrush, BrushType>::value){
        auto ss = brush_->settings();
        auto surface = brush_->surface();
        delete brush_;
        brush_ = new BrushType;
        brush_->setSettings(ss);
        brush_->setSurface(surface);
    }else{
        qCritical("Abnormal brush change!");
    }
}