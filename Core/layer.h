#ifndef LAYER_H
#define LAYER_H

#include "node.h"

#include <QColor>

namespace Wind2D
{

class Layer : public Node
{
    Q_OBJECT
public:
    explicit Layer(QObject *parent = 0);
    virtual ~Layer();

    inline const QSizeF& size() const { return size_; }
    inline void set_size(const QSizeF& size) { size_ = size; }

    inline const QPointF& anchor_point() const { return anchor_point_; }
    inline void set_anchor_point(const QPointF& p) { anchor_point_ = p; }

    inline const QColor& bgcolor() const { return bgcolor_; }
    inline void set_bgcolor(const QColor& color) { bgcolor_ = color; }

public:
    bool init(const QColor& color = QColor(0, 0, 0, 0));

protected:
    virtual void update_world_matrix();

private:
    QSizeF      size_;
    QPointF     anchor_point_;
    QColor      bgcolor_;
};

}//end namespace Wind2D

#endif // LAYER_H
