#include "gamewindow.h"

namespace Wind2D
{

GameWindow::GameWindow(QWidget *parent)
    : QGLWidget(parent)
    , app_(nullptr)
{
}

GameWindow::~GameWindow()
{
}

void GameWindow::initializeGL()
{
    Q_ASSERT(app_);

    if (!app_->init(context(), aspect_width_, aspect_height_)) return;

    game_timer_.start(app_->fps(), this);
}

void GameWindow::resizeGL(int w, int h)
{
    Q_ASSERT(app_);

    app_->on_resize(w, h);
}

void GameWindow::paintGL()
{
    Q_ASSERT(app_);
    time_counter_.start();

    app_->update(last_time_);
    app_->draw();

    last_time_ = time_counter_.elapsed() / 1000.0f;
}

void GameWindow::timerEvent(QTimerEvent *e)
{
    updateGL();
}

}//end namespace Wind2D

