#version 330 core

layout(location = 0) in vec4 s_vPosition;
layout(location = 1) in vec4 s_vColor;
layout(location = 2) in vec4 s_vNormal;

uniform mat4 MVP;
uniform mat4 mRotations;
uniform vec4 vLight;

out vec4 fragmentColor;
out vec4 fN;
out vec4 fL;

void main() {
	fN = mRotations * s_vNormal;
	fL = vLight;
	gl_Position = MVP * s_vPosition;
	fragmentColor = s_vColor;
}

