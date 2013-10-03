uniform sampler2D u_texture;        //default value of "u_texture" is 0 in fragment shader
uniform mediump float u_alpha = 1.0;

varying mediump vec4 v_texCoord;

void main(void)
{
    mediump vec4 baseColor = texture2D(u_texture, v_texCoord.st);
    gl_FragColor = vec4(baseColor.r, baseColor.g, baseColor.b, baseColor.a * u_alpha);
}
