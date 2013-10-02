#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include <QtOpengl>
#include <QGLWidget>
#include <QGLFunctions>
#include <QGLShaderProgram>
#include <QMatrix4x4>

#include "core_global.h"

namespace Wind2D
{

class WIND_CORE_API RenderEngine : protected QGLFunctions
{
public:
    RenderEngine();
    virtual ~RenderEngine();

    bool init(QGLContext* ctx, float aspectWidth = 800.0f, float aspectHeight = 480.0f);
    void on_resize(int w, int h);

    void reset_aspect(float aspectWidth, float aspectHeight);

protected:
    bool init_shaders(QGLShaderProgram* program, const QString& vshader, const QString& fshader);
    void update_ortho_matrix();

protected:
    QGLShaderProgram* shader_program_;
    QMatrix4x4 ortho_matrix_;

    float alpha_;
    float aspect_width_;
    float aspect_height_;
    float width_;
    float height_;
};

}//end namespace Wind2D

#endif // RENDERENGINE_H
