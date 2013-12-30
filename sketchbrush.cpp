#include "sketchbrush.h"
#include <QPainterPath>
#include <QPainter>

SketchBrush::SketchBrush()
{
}

void SketchBrush::setColor(const QColor &c)
{
    AbstractBrush::setColor(c);
    preparePen();
}

void SketchBrush::drawPoint(const QPoint &p, qreal pressure)
{
//    preparePen();
    points.clear();
    points.push_back(p);
    last_point_ = p;
}

void SketchBrush::drawLineTo(const QPoint &end, qreal pressure)
{
    if(last_point_.isNull()){
        drawPoint(end, pressure);
        return;
    }
    points.push_back(end);
    sketch();
    last_point_ = end;
}

void SketchBrush::setSettings(const BrushSettings &settings)
{

}

void SketchBrush::preparePen()
{
    QColor subColor = color_;
    subColor.setAlphaF(this->thickness()/100.0);
    sketchPen.setColor(subColor);
    sketchPen.setWidth(width_);
    sketchPen.setCapStyle(Qt::RoundCap);
    sketchPen.setJoinStyle(Qt::RoundJoin);
}

void SketchBrush::sketch()
{
    if(points.count() > 10){
        QPainterPath path;
        path.moveTo(points[0]);
        for(int i=0;i<points.count()-10;i+=4){
            path.cubicTo(points[i], points[i+2], points[i+9]);
        }
        points.pop_front();

        QPainter painter;
        if(!painter.begin(surface_.data())){
            return;
        }
        painter.setRenderHint(QPainter::Antialiasing);
        painter.strokePath(path, sketchPen);
        painter.end();
    }
}
