#include "gameapp.h"

#include "renderengine.h"

namespace Wind2D
{

GameApp::GameApp()
{
}

GameApp::~GameApp()
{
    RenderEngine::release();
}

bool GameApp::init(QGLContext* ctx, float aspectWidth /*= 800.0f*/, float aspectHeight /*= 480.0f*/)
{
    if (!RenderEngine::shared_engine()->init(ctx, aspectWidth, aspectHeight)) return false;

    return true;
}

void GameApp::on_resize(int w, int h)
{
    RenderEngine::shared_engine()->on_resize(w, h);
}

void GameApp::reset_aspect(float aspectWidth, float aspectHeight)
{
    RenderEngine::shared_engine()->reset_aspect(aspectWidth, aspectHeight);
}

void GameApp::update(float /*dt*/)
{
}

void GameApp::draw()
{
}

}//end namespase Wind2D
