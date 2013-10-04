#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

#include "core_global.h"

#include <QSizeF>
#include <QRectF>

namespace Wind2D
{

struct TexInfo
{
    QString path;
    QSizeF  size;
    QRectF  texRect;
};

class WIND_CORE_API TextureCache
{
private:
    TextureCache();
    ~TextureCache();

public:
    static TextureCache* shared_cache();

    void create();
    void destroy();

private:
    static TextureCache* shared_cache_;
};

}//end namespace Wind2D

#endif // TEXTURECACHE_H
