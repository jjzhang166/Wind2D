uniform sampler2D u_texture;        //default value of "u_texture" is 0 in fragment shader
uniform mediump float u_alpha = 1.0;
uniform mediump bool  u_iscolor = false;
uniform mediump vec4  u_color;

varying mediump vec4 v_texCoord;

void main(void)
{
    if (u_iscolor)
    {
        gl_FragColor = u_color;
    }
    else
    {
        mediump vec4 baseColor = texture2D(u_texture, v_texCoord.st);
        gl_FragColor = vec4(baseColor.r, baseColor.g, baseColor.b, baseColor.a * u_alpha);
    }
}
