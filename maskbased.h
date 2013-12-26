#ifndef MASKBASED_H
#define MASKBASED_H

#include "basicbrush.h"

class MaskBased : public BasicBrush
{
    Q_OBJECT
public:
    explicit MaskBased(QObject *parent = 0);

    QImage mask() const;
    void setMask(const QImage &mask);

signals:

public slots:
protected:
    void makeStencil(QColor color) Q_DECL_OVERRIDE;
    void drawPointInternal(const QPoint& p,
                           const QImage &stencil,
                           QPainter *painter) Q_DECL_OVERRIDE;
    QImage mask_;
};

#endif // MASKBASED_H
