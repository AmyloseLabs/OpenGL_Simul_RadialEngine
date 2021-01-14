/****************************************************************************/
/*              Amylose Opengl Program #3                                   */
/*              DATE : 2016-11-13                                           */
/*              SOURCE TYPE : SHADER_PROGRAM_BUILDER.H   (HEADER SOURCE)    */
/*              CONTAINED OGL SHADER LANGUAGE COMPILER FUNCTION LIST        */
/****************************************************************************/

/*********************************************************************************************/
/*                   USER OPENGL SHADER_PROGRAM_BUILDER FUNCTION LIST                        */
/*********************************************************************************************/
bool compiledStatus(GLint shaderID); //COMPLILER STATUES CONFIRM BOOL FUNCTION
GLuint makeVertexShader(const unsigned char* shaderSource); //VERTEX SHADER SOURCE COMPLIER FUNCTION
GLuint makeFragmentShader(const unsigned char* shaderSource); //FRAGMENT SHADER SOURCE COMPLIER FUNCTION
GLuint makeShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID); //VERTEX SHADER & FRAGMENT SHADER LINK AND CREATE GPU PROGRAN FUNCTION

/***************************************************************************/
/*               SHADER_PROGRAM_BUILDER.H SOURCE CODE END                  */
/***************************************************************************/
