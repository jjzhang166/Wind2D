#include "renderengine.h"

namespace Wind2D
{

RenderEngine* RenderEngine::shared_render_engine_ = nullptr;

RenderEngine::RenderEngine()
    : shader_program_(nullptr)
    , aspect_width_(800.0f)
    , aspect_height_(480.0f)
    , width_(1.0f)
    , height_(1.0f)
    , loc_worldmat_(0)
    , loc_texture_(0)
    , loc_alpha_(0)
    , loc_iscolor_(0)
    , loc_color_(0)
{
    ortho_matrix_.setToIdentity();
}

RenderEngine::~RenderEngine()
{
    if (shader_program_)
    {
        shader_program_->release();
        delete shader_program_;
        shader_program_ = nullptr;
    }
}

RenderEngine* RenderEngine::shared_engine()
{
    if (!shared_render_engine_)
    {
        shared_render_engine_ = new RenderEngine();
    }
    return shared_render_engine_;
}

void RenderEngine::release()
{
    if (shared_render_engine_)
    {
        delete shared_render_engine_;
        shared_render_engine_ = nullptr;
    }
}

bool RenderEngine::init(QGLContext *ctx, float aspectWidth, float aspectHeight)
{
    aspect_width_ = aspectWidth;
    aspect_height_ = aspectHeight;

    initializeGLFunctions(ctx);

    shader_program_ = new QGLShaderProgram(ctx);

    if (!init_shaders(shader_program_,
                      ":/Media/shaders/wind2d_vshader.vsh",
                      ":/Media/shaders/wind2d_fshader.vsh"))
        return false;

    return true;
}

void RenderEngine::on_resize(int w, int h)
{
    width_ = w;
    height_ = h;

    glViewport(0, 0, width_, height_);

    update_ortho_matrix();
}

void RenderEngine::reset_aspect(float aspectWidth, float aspectHeight)
{
    aspect_width_ = aspectWidth;
    aspect_height_ = aspectHeight;

    update_ortho_matrix();
}

bool RenderEngine::init_shaders(QGLShaderProgram *program, const QString &vshader, const QString &fshader)
{
    setlocale(LC_NUMERIC, "C");
    if (!program.addShaderFromSourceFile(QGLShader::Vertex, vshader))  return false;
    if (!program.addShaderFromSourceFile(QGLShader::Fragment, fshader))  return false;
    if (!program.link()) return false;

    loc_worldmat_ = shader_program_->uniformLocation("u_worldMatrix");
    loc_texture_ = shader_program_->uniformLocation("u_texture");
    loc_alpha_ = shader_program_->uniformLocation("u_alpha");
    loc_iscolor_ = shader_program_->uniformLocation("u_iscolor");
    loc_color_ = shader_program_->uniformLocation("u_color");

    if (!program.bind()) return false;
    setlocale(LC_ALL, "");

    return true;
}

void RenderEngine::update_ortho_matrix()
{
    QMatrix4x4 orthoMat;
    orthoMat.setToIdentity();
    orthoMat.ortho(-width_/2, width_/2, -height_/2, height_/2, -100, 100);
    orthoMat.scale(width_/aspect_width_, height_/aspect_height_, 1.0f);
    ortho_matrix_ = orthoMat;
    shader_program_->setUniformValue("u_orthMatrix", ortho_matrix_);
}

}//end namespace Wind2D


