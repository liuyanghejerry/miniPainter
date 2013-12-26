#include "maskbased.h"
#include <QPainter>
#include <QDebug>

MaskBased::MaskBased(QObject *parent) :
    BasicBrush(parent)
{
}

void MaskBased::makeStencil(QColor color)
{
    BasicBrush::makeStencil(color);
    if(mask_.isNull()){
        return;
    }
    QPainter painter(&stencil_);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter.drawImage(0, 0, mask_);
}

void MaskBased::drawPointInternal(const QPoint &p, const QImage &stencil, QPainter *painter)
{
    QImage copied_stencil = stencil;
    bool need_delete = false;
    if(!painter) {
        painter = new QPainter;
        need_delete = true;
        painter->setRenderHint(QPainter::Antialiasing);
        painter->begin(surface_.data());
    }

    QPainter painter2(&copied_stencil);
    painter2.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter2.drawImage(0, 0, mask_, p.x() % mask_.width(), p.y() % mask_.height());

    painter->drawImage(p.x(), p.y(), copied_stencil);

    if(need_delete) {
        painter->end();
        delete painter;
    }
}
QImage MaskBased::mask() const
{
    return mask_;
}

void MaskBased::setMask(const QImage &mask)
{
    mask_ = mask;
    if(mask_.isNull()){
        qDebug()<<"null mask";
        return;
    }
    makeStencil(color_);
}


