#ifndef MINICANVAS_H
#define MINICANVAS_H

#include <QWidget>
#include <QSize>
#include <QList>
#include "abstractbrush.h"

class MiniCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit MiniCanvas(QWidget *parent = 0);
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;

signals:

public slots:
protected:
    QSize pre_size_;
    Surface result_;
    bool mouse_press_;
    AbstractBrush *brush_;

    template<typename BrushType>
    void changeToBrush();

    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *) Q_DECL_OVERRIDE;
    void tabletEvent(QTabletEvent *) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *) Q_DECL_OVERRIDE;

};

#endif // MINICANVAS_H
