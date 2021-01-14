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
	//쉐이더를 생성하는 함수
	//GLuint GL type unsigned int -> 32bit;
	//GLuint glCreateShader(GLenum ShaderType); create Shader Object with Defied Shader Type;
	glShaderSource(vertexShaderID, 1, (const GLchar**)&shaderSource, NULL);
	//쉐이더 소스코드를 등록하는 함
	//void glShaderSource(Shader Object, count, const GLchar **string, const GLint *length);
	//Shader Object : 소스코드를 대체할 쉐이더 객체 핸들을 지정 -> 쉐이더 오브젝트 소스코드를 넣는 곳
	//count : 문자열 및 배열의 길이요소 숫자를 지정함 -> 쉐이더 소스코드의 숫자를 넣는다 보통 1 지정
	//const GLchar **string : 소스코드의 문자열의 시작주소를 넣는 곳.
	//const GLint *length : 소스코드의 길이의 시작주소를 넣는곳.
	glCompileShader(vertexShaderID);
	//void glCompileShader(GLuint shader);
	//소스코드를 컴파일하는 함수
	//GLuint shader : 컴파일할 쉐이더의 ID만 적어주면됨.
	bool compiledCorrectly = compiledStatus(vertexShaderID);
	if (compiledCorrectly) return vertexShaderID;
	return -1;
}

/********************************************************************/
/*            FRAGMENT SHADER SOURCE COMPLIER FUNCTION              */
/********************************************************************/
GLuint makeFragmentShader(const unsigned char* shaderSource) {
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	//쉐이더를 생성하는 함수
	//GLuint GL type unsigned int -> 32bit;
	//GLuint glCreateShader(GLenum ShaderType); create Shader Object with Defied Shader Type;
	glShaderSource(fragmentShaderID, 1, (const GLchar**)&shaderSource, NULL);
	//쉐이더 소스코드를 등록하는 함
	//void glShaderSource(Shader Object, count, const GLchar **string, const GLint *length);
	//Shader Object : 소스코드를 대체할 쉐이더 객체 핸들을 지정 -> 쉐이더 오브젝트 소스코드를 넣는 곳
	//count : 문자열 및 배열의 길이요소 숫자를 지정함 -> 쉐이더 소스코드의 숫자를 넣는다 보통 1 지정
	//const GLchar **string : 소스코드의 문자열의 시작주소를 넣는 곳.
	//const GLint *length : 소스코드의 길이의 시작주소를 넣는곳.
	glCompileShader(fragmentShaderID);
	//void glCompileShader(GLuint shader);
	//소스코드를 컴파일하는 함수
	//GLuint shader : 컴파일할 쉐이더의 ID만 적어주면됨.
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
	//비어있는 프로그램을 생성, 프로그램의 ID를 반환
	glAttachShader(shaderID, vertexShaderID);
	//void glAttachShader(GLuint program, GLuint shader);
	//GLuint program : 프로그램의 ID를 대입.
	//GLuint Shader : 쉐이더의 ID를 대입.
	glAttachShader(shaderID, fragmentShaderID);
	//void glAttachShader(GLuint program, GLuint shader);
	//GLuint program : 프로그램의 ID를 대입.
	//GLuint Shader : 쉐이더의 ID를 대입.
	glLinkProgram(shaderID);
	//void glLinkProgram(GLuint program);
	//해당 프로그램을 처리해서 파이프라인을 만듬.
	//GLuint program : AttachShader된 프로그램의 ID를 대입.
	return shaderID;
}

/***************************************************************************/
/*           SHADER_PROGRAM_BUILDER.CPP SOURCE CODE END                    */
/***************************************************************************/
