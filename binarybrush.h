#ifndef BINARYBRUSH_H
#define BINARYBRUSH_H

#include "basicbrush.h"

class BinaryBrush : public BasicBrush
{
public:
    explicit BinaryBrush();

signals:

public slots:

protected:
    void makeStencil(QColor color) Q_DECL_OVERRIDE;

};

#endif // BINARYBRUSH_H
