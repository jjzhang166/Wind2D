#ifndef SPRITE_H
#define SPRITE_H

#include <QtOpenGL>
#include <QRect>
#include <QPoint>
#include <QSize>

#include "core_global.h"

namespace Wind2D
{

class WIND_CORE_API Sprite
{
public:
    Sprite();
    ~Sprite();

    QPoint position_;

protected:
    GLuint tex_;

    QPoint position_;
    QSize  size_;
};

}//end namespace Wind2D

#endif // SPRITE_H
