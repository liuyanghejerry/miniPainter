#include "basiceraser.h"

BasicEraser::BasicEraser()
    :brush_(Qt::transparent),
      pen_(Qt::transparent)
{
    pen_.setCapStyle(Qt::RoundCap);
    pen_.setJoinStyle(Qt::RoundJoin);

    typedef BrushFeature BF;
    BF::FeatureBits bits;
    bits.set(BF::WIDTH);
    features_ = bits;

    name_ = QObject::tr("BasicEraser");
    displayName_ = name_;
    shortcut_ = Qt::Key_6;
}

void BasicEraser::drawPoint(const QPoint &p, qreal )
{
    pen_.setWidth(width_);
    painter_.begin(surface_.data());
    painter_.setRenderHint(QPainter::Antialiasing);
    painter_.setCompositionMode(QPainter::CompositionMode_Clear);
    painter_.setPen(pen_);
    painter_.setBrush(brush_);
    painter_.drawPoint(p);
    painter_.end();
    last_point_ = p;
}

void BasicEraser::drawLineTo(const QPoint &end, qreal )
{
    pen_.setWidth(width_);
    painter_.begin(surface_.data());
    painter_.setRenderHint(QPainter::Antialiasing);
    painter_.setCompositionMode(QPainter::CompositionMode_Clear);
    painter_.setPen(pen_);
    painter_.setBrush(brush_);
    painter_.drawLine(last_point_, end);
    painter_.end();
    last_point_ = end;
}
