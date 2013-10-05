#include "layer.h"

namespace Wind2D
{

Layer::Layer(QObject *parent)
    : Node(parent)
    , size_(0.0f, 0.0f)
    , anchor_point_(0.5f, 0.5f)
    , bgcolor_(0 , 0, 0, 255)
{
}

Layer::~Layer()
{
}

bool Layer::init(const QColor &color)
{
    bgcolor_ = color;

    return true;
}

void Layer::update_world_matrix()
{
    world_matrix_.setToIdentity();
    world_matrix_.scale(scale_.width(), scale_.height());
    world_matrix_.rotate(rotate_, position_.x()+anchor_point_.x()*size_.width(),
                                  position_.y()+anchor_point_.y()*size_.height());
    world_matrix_.translate(translate_.x(), translate_.y());

    Node* node = this;
    while(node->parent_)
    {
        world_matrix_ = world_matrix_ * node->parent_->world_matrix_;
        node = node->parent_;
    }
}

}//end namespace Wind2D
