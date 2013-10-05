#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include <QtOpengl>
#include <QGLWidget>
#include <QGLFunctions>
#include <QGLShaderProgram>
#include <QMatrix4x4>
#include <QColor>

#include "core_global.h"

namespace Wind2D
{

class WIND_CORE_API RenderEngine : protected QGLFunctions
{
private:
    RenderEngine();
    virtual ~RenderEngine();

public:
    static RenderEngine* shared_engine();
    static void release();

public:
    bool init(QGLContext* ctx, float aspectWidth = 800.0f, float aspectHeight = 480.0f);
    void on_resize(int w, int h);

    void reset_aspect(float aspectWidth, float aspectHeight);

    inline void set_world_matrix(const QMatrix4x4& world) { shader_program_->setUniformValue(loc_worldmat_, world); }
    inline void set_alpha(float alpha) { shader_program_->setUniformValue(loc_alpha_, alpha); }
    inline void set_color(const QColor& color) { shader_program_->setUniformValue(loc_color_, color); }
    inline void set_color_render() { shader_program_->setUniformValue(loc_iscolor_, true); }
    inline void set_texture_render() { shader_program_->setUniformValue(loc_iscolor_, false); }

protected:
    bool init_shaders(QGLShaderProgram* program, const QString& vshader, const QString& fshader);
    void update_ortho_matrix();

private:
    static RenderEngine* shared_render_engine_;

protected:
    QGLShaderProgram* shader_program_;
    QMatrix4x4 ortho_matrix_;

    int loc_worldmat_;
    int loc_texture_;
    int loc_alpha_;
    int loc_iscolor_;
    int loc_color_;

    float aspect_width_;
    float aspect_height_;
    float width_;
    float height_;
};

}//end namespace Wind2D

#endif // RENDERENGINE_H
