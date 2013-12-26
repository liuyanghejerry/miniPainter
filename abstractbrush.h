#ifndef ABSTRACTBRUSH_H
#define ABSTRACTBRUSH_H

#include <QObject>
#include <QPoint>
#include <QImage>
#include <QColor>
//#include <QMultiHash>
#include <QSharedPointer>
#include "brushfeature.h"

#include "brushsettings.h"
typedef QSharedPointer<QImage> Surface;

class AbstractBrush
{
public:
//    typedef std::function<void()> HOOK_FUNC;
    const static int WIDTH_MAX = 100;
    const static int WIDTH_MIN = 0;
    const static int THICKNESS_MAX = 100;
    const static int THICKNESS_MIN = 0;


    explicit AbstractBrush();
    // we don't need virtual dstor, because we have no resource to delete
    virtual ~AbstractBrush();

    virtual int width() const;
    virtual void setWidth(int width);
    virtual int thickness() const;
    virtual void setThickness(int thickness);
    virtual QColor color() const;
    virtual void setColor(const QColor &color);

    virtual Surface surface() const;
    // Brush does NOT take ownership of surface
    virtual void setSurface(Surface surface);

    virtual void drawPoint(const QPoint& p, qreal pressure=1)=0;
    virtual void drawLineTo(const QPoint& end, qreal pressure=1)=0;

    virtual BrushSettings settings() const;
    virtual void setSettings(const BrushSettings &settings);

signals:

public slots:

protected:
    int width_;
    int thickness_;
    QColor color_;
    Surface surface_;
    QImage stencil_;
    QPoint last_point_;
    BrushSettings settings_;
    BrushFeature features_;
//    QMultiHash<QString, HOOK_FUNC> hooks_;
};

#endif // ABSTRACTBRUSH_H
