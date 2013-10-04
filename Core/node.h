#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QRectF>
#include <QSizeF>
#include <QPoint>
#include <QMatrix4x4>
#include <QVector>

namespace Wind2D
{

class Node : public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = 0);
    virtual ~Node();

    inline const QPointF& position() const { return position_; }
    inline void set_position(const QPointF& p) { position_ = p; }

    inline float depth() const { return depth_; }
    inline void set_depth(float d) { depth_ = d; }

    inline bool is_transparent() const { return is_transparent_; }
    inline void set_transparent(bool t) { is_transparent_ = t; }

    inline bool is_visible() const { return is_visible_; }
    inline void set_visible(bool v) { is_visible_ = v; }

    inline void set_scale(const QSizeF& size) { scale_ = size; }
    inline const QSizeF& scale() const { return scale_; }

    inline void set_translate(const QPointF& p) { translate_ = p; }
    inline const QPointF& translate() const { return translate_; }

    inline void set_rotate(float r) { rotate_ = r; }
    inline float rotate() const { return rotate_; }

public:
    void update(float dt);
    virtual void draw();

public:
    void add_node(Node* node);

protected:
    virtual void update_world_matrix();
    virtual void update_user_data(float dt);

protected:
    QPointF     position_;
    float       depth_;

    bool        is_transparent_;
    bool        is_visible_;

    QMatrix4x4  world_matrix_;

    QSizeF      scale_;
    QPointF     translate_;
    float       rotate_;

protected:
    QVector<Node*>  children_;
    Node*           parent_;
};

}//end namespace Wind2D


#endif // NODE_H
