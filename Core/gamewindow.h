#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGLWidget>
#include <QBasicTimer>
#include <QTime>

#include "gameapp.h"

namespace Wind2D
{

class GameWindow : public QGLWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = 0);
    virtual ~GameWindow();

    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

    virtual void timerEvent(QTimerEvent *);

private:
    GameApp*    app_;

    QBasicTimer game_timer_;

    QTime       time_counter_;
    float       last_time_;
};

}//end namespace Wind2D

#endif // GAMEWINDOW_H
