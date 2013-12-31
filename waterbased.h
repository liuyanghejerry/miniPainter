#ifndef WATERBASED_H
#define WATERBASED_H

#include <QPoint>
#include "basicbrush.h"

class WaterBased: public BasicBrush
{
public:
//    const static int WATER_MAX = 100;
//    const static int WATER_MIN = 0;
//    const static int EXTEND_MAX = 100;
//    const static int EXTEND_MIN = 0;
//    const static int MIXIN_MAX = 100;
//    const static int MIXIN_MIN = 0;
    enum: int {
        WATER_MAX = 100,
        WATER_MIN = 0,
        EXTEND_MAX = 100,
        EXTEND_MIN = 0,
        MIXIN_MAX = 100,
        MIXIN_MIN = 0
    };
    explicit WaterBased();
    int water() const;
    void setWater(int water);
    int extend() const;
    void setExtend(int extend);
    int mixin() const;
    void setMixin(int mixin);

    virtual void drawPoint(const QPoint& p, qreal pressure=1) Q_DECL_OVERRIDE;
    virtual void drawLineTo(const QPoint& end, qreal pressure=1) Q_DECL_OVERRIDE;

    void setSettings(const BrushSettings &settings) Q_DECL_OVERRIDE;

protected:
    int water_;
    int extend_;
    int mixin_;
    QColor mingled_color_;
    QColor last_color_;
    int color_remain_;
    virtual QColor mingleColor(const QColor& new_c);
    virtual QColor fetchColor(const QPoint& center) const;
    template<typename COLOR_FUNC>
    int mingleSubColor(const QColor& color1, const QColor& color2, COLOR_FUNC f) const;
    virtual int mingleValue(int a, int b) const;
};

#endif // WATERBASED_H
