#include "node.h"

namespace Wind2D
{

Node::Node(QObject *parent)
    : QObject(parent)
    , position_rect_(0.0f, 0.0f, 0.0f, 0.0f)
    , texcoord_rect_(0.0f, 0.0f, 1.0f, 1.0f)
    , anchor_point_(0.5f, 0.5f)
    , depth_(0.0f)
    , is_transparent_(false)
    , is_visible_(true)
    , scale_(1.0f, 1.0f)
    , translate_(0.0f, 0.0f)
    , rotate_(0.0f)
    , parent_(nullptr)
{
    world_matrix_.setToIdentity();
}

Node::~Node()
{
}

void Node::update(float /*dt*/)
{
    update_world_matrix();
}

void Node::draw()
{
}

void Node::add_node(Node *node)
{
    node->setParent(this);
    node->parent_ = this;
    children_.push_back(node);
}

void Node::update_world_matrix()
{
    world_matrix_.setToIdentity();
    world_matrix_.scale(scale_.width(), scale_.height());
    world_matrix_.rotate(position_rect_.x()+anchor_point_.x()*position_rect_.width(),
                         position_rect_.y()+anchor_point_.y()*position_rect_.height());
    world_matrix_.translate(translate_.x(), translate_.y());

    Node* node = this;
    while(node->parent_)
    {
        world_matrix_ = world_matrix_ * node->parent_->world_matrix_;
        node = node->parent_;
    }
}

}//end namesppace Wind2D

