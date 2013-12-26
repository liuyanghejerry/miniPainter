#include "abstractbrush.h"
#include <QDebug>

AbstractBrush::AbstractBrush(QObject *parent) :
    QObject(parent),
    width_(10),
    thickness_(THICKNESS_MAX),
    color_(Qt::black),
    surface_(nullptr)
{
    typedef BrushFeature BF;
    features_.set(BF::WIDTH);
    features_.set(BF::COLOR);
}

int AbstractBrush::width() const
{
    return width_;
}

void AbstractBrush::setWidth(int width)
{
    width_ = qBound(WIDTH_MIN, width, WIDTH_MAX);
    settings_.insert("width", width_);
}
int AbstractBrush::thickness() const
{
    return thickness_;
}

void AbstractBrush::setThickness(int thickness)
{
    thickness_ = qBound(THICKNESS_MIN, thickness, THICKNESS_MAX);
    settings_.insert("thickness", thickness_);
}

Surface AbstractBrush::surface() const
{
    return surface_;
}

void AbstractBrush::setSurface(Surface surface)
{
    surface_ = surface;
}
BrushSettings AbstractBrush::settings() const
{
    return settings_;
}

void AbstractBrush::setSettings(const BrushSettings &settings)
{
    const BrushSettings& s = settings;
    setColor(s.value("color", color_).value<QColor>());
    setWidth(s.value("width", width_).toInt());
    setThickness(s.value("thickness", thickness_).toInt());
    settings_ = s;
}

QColor AbstractBrush::color() const
{
    return color_;
}

void AbstractBrush::setColor(const QColor &color)
{
    color_ = color;
    settings_.insert("color", color_);
}
