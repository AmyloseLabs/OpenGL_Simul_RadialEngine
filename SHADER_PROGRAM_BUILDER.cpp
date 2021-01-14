/****************************************************************************/
/*              Amylose Opengl Program #3                                   */
/*              DATE : 2016-11-13                                           */
/* SOURCE TYPE : SHADER_PROGRAM_BUILDER.CPP(USING SHADER_PROGRAM_BUILDER.H) */
/*              CONTAINED OGL SHADER_PROGRAM_BUILDER FUNCTION LIST          */
/****************************************************************************/
/*********************************************************************************************/
/*                                  REFERENCE HEADER LIST                                    */
/*********************************************************************************************/
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>

/*********************************************************************************************/
/*                  USER OPENGL SHADER_PROGRAM_BUILDER FUNCTION LIST                         */
/*********************************************************************************************/
/********************************************************************/
/*              COMPLILER STATUES CONFIRM BOOL FUNCTION             */
/********************************************************************/
bool compiledStatus(GLint shaderID) {
	GLint compiled = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiled);
	if (compiled) return true;
	else {
		GLint logLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
		char* msgBuffer = (char*)calloc((logLength+1),sizeof(char));
		glGetShaderInfoLog(shaderID, logLength, NULL, msgBuffer);
		printf("%s\n",msgBuffer);
		return false;
	}
}

/********************************************************************/
/*            VERTEX SHADER SOURCE COMPLIER FUNCTION                */
/********************************************************************/
GLuint makeVertexShader(const unsigned char* shaderSource) {
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	//���̴��� �����ϴ� �Լ�
	//GLuint GL type unsigned int -> 32bit;
	//GLuint glCreateShader(GLenum ShaderType); create Shader Object with Defied Shader Type;
	glShaderSource(vertexShaderID, 1, (const GLchar**)&shaderSource, NULL);
	//���̴� �ҽ��ڵ带 ����ϴ� ��
	//void glShaderSource(Shader Object, count, const GLchar **string, const GLint *length);
	//Shader Object : �ҽ��ڵ带 ��ü�� ���̴� ��ü �ڵ��� ���� -> ���̴� ������Ʈ �ҽ��ڵ带 �ִ� ��
	//count : ���ڿ� �� �迭�� ���̿�� ���ڸ� ������ -> ���̴� �ҽ��ڵ��� ���ڸ� �ִ´� ���� 1 ����
	//const GLchar **string : �ҽ��ڵ��� ���ڿ��� �����ּҸ� �ִ� ��.
	//const GLint *length : �ҽ��ڵ��� ������ �����ּҸ� �ִ°�.
	glCompileShader(vertexShaderID);
	//void glCompileShader(GLuint shader);
	//�ҽ��ڵ带 �������ϴ� �Լ�
	//GLuint shader : �������� ���̴��� ID�� �����ָ��.
	bool compiledCorrectly = compiledStatus(vertexShaderID);
	if (compiledCorrectly) return vertexShaderID;
	return -1;
}

/********************************************************************/
/*            FRAGMENT SHADER SOURCE COMPLIER FUNCTION              */
/********************************************************************/
GLuint makeFragmentShader(const unsigned char* shaderSource) {
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	//���̴��� �����ϴ� �Լ�
	//GLuint GL type unsigned int -> 32bit;
	//GLuint glCreateShader(GLenum ShaderType); create Shader Object with Defied Shader Type;
	glShaderSource(fragmentShaderID, 1, (const GLchar**)&shaderSource, NULL);
	//���̴� �ҽ��ڵ带 ����ϴ� ��
	//void glShaderSource(Shader Object, count, const GLchar **string, const GLint *length);
	//Shader Object : �ҽ��ڵ带 ��ü�� ���̴� ��ü �ڵ��� ���� -> ���̴� ������Ʈ �ҽ��ڵ带 �ִ� ��
	//count : ���ڿ� �� �迭�� ���̿�� ���ڸ� ������ -> ���̴� �ҽ��ڵ��� ���ڸ� �ִ´� ���� 1 ����
	//const GLchar **string : �ҽ��ڵ��� ���ڿ��� �����ּҸ� �ִ� ��.
	//const GLint *length : �ҽ��ڵ��� ������ �����ּҸ� �ִ°�.
	glCompileShader(fragmentShaderID);
	//void glCompileShader(GLuint shader);
	//�ҽ��ڵ带 �������ϴ� �Լ�
	//GLuint shader : �������� ���̴��� ID�� �����ָ��.
	bool compiledCorrectly = compiledStatus(fragmentShaderID);
	if (compiledCorrectly) return fragmentShaderID;
	return -1;

}

/****************************************************************************/
/*   VERTEX SHADER & FRAGMENT SHADER LINK AND CREATE GPU PROGRAN FUNCTION   */
/****************************************************************************/
GLuint makeShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID) {
	GLuint shaderID = glCreateProgram();
	//GLuint glCreateProgram(void);
	//����ִ� ���α׷��� ����, ���α׷��� ID�� ��ȯ
	glAttachShader(shaderID, vertexShaderID);
	//void glAttachShader(GLuint program, GLuint shader);
	//GLuint program : ���α׷��� ID�� ����.
	//GLuint Shader : ���̴��� ID�� ����.
	glAttachShader(shaderID, fragmentShaderID);
	//void glAttachShader(GLuint program, GLuint shader);
	//GLuint program : ���α׷��� ID�� ����.
	//GLuint Shader : ���̴��� ID�� ����.
	glLinkProgram(shaderID);
	//void glLinkProgram(GLuint program);
	//�ش� ���α׷��� ó���ؼ� ������������ ����.
	//GLuint program : AttachShader�� ���α׷��� ID�� ����.
	return shaderID;
}

/***************************************************************************/
/*           SHADER_PROGRAM_BUILDER.CPP SOURCE CODE END                    */
/***************************************************************************/
