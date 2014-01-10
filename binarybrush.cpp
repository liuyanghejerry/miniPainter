#include "binarybrush.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPainter>

BinaryBrush::BinaryBrush() :
    BasicBrush()
{
    typedef BrushFeature BF;
    BF::FeatureBits bits;
    bits.set(BF::WIDTH);
    bits.set(BF::COLOR);
    features_ = bits;

    name_ = QObject::tr("BinaryBrush");
    displayName_ = name_;
    shortcut_ = Qt::Key_2;
}

void BinaryBrush::makeStencil(QColor color)
{
    if(stencil_.isNull() || stencil_.width() != width_){
        stencil_ = QImage(width_, width_, QImage::Format_ARGB32_Premultiplied);
    }
    stencil_.fill(Qt::transparent);
    const int half_width = width_>>1;

    const QPoint center(half_width, half_width);
    QPainter painter;
    if(!painter.begin(&stencil_)){
        return;
    }
    const QPen pen(color, 0);
    const QBrush brush(color);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(center, half_width>>1, half_width>>1);
    painter.end();
}
