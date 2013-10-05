#include "node.h"

namespace Wind2D
{

Node::Node(QObject *parent)
    : QObject(parent)
    , position_(0.0f, 0.0f)
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

void Node::update(float dt)
{
    update_world_matrix();
    update_user_data(dt);
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
    world_matrix_.rotate(rotate_, position_.x(), position_.y());
    world_matrix_.translate(translate_.x(), translate_.y());

    Node* node = this;
    while(node->parent_)
    {
        world_matrix_ = world_matrix_ * node->parent_->world_matrix_;
        node = node->parent_;
    }
}

void Node::update_user_data(float /*dt*/)
{
}

}//end namesppace Wind2D

