#ifndef SPRITE_H
#define SPRITE_H

#include "node.h"
#include <QtOpenGL>

namespace Wind2D
{

class Sprite : public Node
{
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = 0);
    virtual ~Sprite();

    bool init(QString texFile, const QRectF& texRect = QRectF(0.0f, 0.0f, 1.0f, 1.0f));
    bool init(const QImage& image, const QRectF& texRect = QRectF(0.0f, 0.0f, 1.0f, 1.0f));

    inline const QSizeF& size() const { return size_; }
    inline void set_size(const QSizeF& size) { size_ = size; }

    inline const QRectF& texcoord_rect() const { return texcoord_rect_; }
    inline void set_texcoord_rect(const QRectF& rect) { texcoord_rect_ = rect; }

    inline const QPointF& anchor_point() const { return anchor_point_; }
    inline void set_anchor_point(const QPointF& p) { anchor_point_ = p; }

    inline GLuint texture_id() const { return texture_id_; }
    inline void set_texture_id(GLuint id) { texture_id_ = id; }

public:
    virtual void draw();

protected:
    virtual void update_world_matrix();

protected:
    QSizeF      size_;
    QRectF      texcoord_rect_;
    QPointF     anchor_point_;

    GLuint      texture_id_;
};

}//end namespace Wind2D

#endif // SPRITE_H
