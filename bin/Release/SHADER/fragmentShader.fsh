#version 330 core

in vec4 fragmentColor;
in vec4 fN;
in vec4 fL;

out vec4 color;

void main() {
	vec4 N = normalize(fN);
	vec4 L = normalize(fL);
	float diffuse_intensity = max(dot(N, L), 0.0);

	if ( diffuse_intensity == 0) {
		color = vec4(0.05, 0.05, 0.05, 1.0);
	}
	else {
		color = vec4(diffuse_intensity, diffuse_intensity, diffuse_intensity, 0.5) * fragmentColor;
	}

}
