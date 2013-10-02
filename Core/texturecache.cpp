#include "texturecache.h"

namespace Wind2D
{

TextureCache* TextureCache::shared_cache_ = nullptr;

TextureCache::TextureCache()
{

}

TextureCache::~TextureCache()
{

}

TextureCache* TextureCache::shared_cache()
{
    if (!shared_cache_)
    {
        shared_cache_ = new TextureCache();
    }
    return shared_cache_;
}

void TextureCache::destroy()
{
    if (shared_cache_)
    {
        delete shared_cache_;
        shared_cache_ = nullptr;
    }
}

}//end namespace Wind2D
