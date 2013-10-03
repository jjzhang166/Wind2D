attribute mediump vec4 a_position;
attribute mediump vec4 a_texCoord;

uniform mediump mat4 u_orthMatrix;
uniform mediump mat4 u_worldMatrix;

varying mediump vec4 v_texCoord;

void main(void)
{
    v_texCoord = a_texCoord;
    gl_Position = u_orthMatrix * u_worldMatrix * a_position;
}
