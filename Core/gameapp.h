#ifndef GLAPP_H
#define GLAPP_H

namespace Wind2D
{

class GameApp
{
public:
    GameApp();
    virtual ~GameApp();

    virtual bool init(QGLContext* ctx, float aspectWidth = 800.0f, float aspectHeight = 480.0f);
    virtual void on_resize(int w, int h);
    virtual void update(float dt);
    virtual void draw();

    inline void set_fps(float fps) { fps_ = fps; }
    inline float fps() const { return fps_; }

    void reset_aspect(float aspectWidth, float aspectHeight);

private:
    float fps_;
};

}//end namespace Wind2D

#endif // GLAPP_H
