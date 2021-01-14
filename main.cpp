//sudo gcc -o gl_project.exe main.cpp -s -lglut -lGL  -lGLU -lGLEW -Wall -lX11
/****************************************************************************/
/*                        Amylose Opengl Program #3                         */
/*                        DATE : 2016-11-13                                 */
/*                        SOURCE TYPE : MAIN.CPP                            */
/****************************************************************************/

/*********************************************************************************************/
/*                                  REFERENCE HEADER LIST                                    */
/*********************************************************************************************/
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*********************************************************************************************/
/*                                     USER HEADER LIST                                      */
/*********************************************************************************************/
#include "EXTERNAL_FILE_LOADER.hpp" //File I/O function list
#include "SHADER_PROGRAM_BUILDER.hpp" //GL_Shader Language Complier Function

using namespace glm;


/*********************************************************************************************/
/*                                   GLOBAL VARIABLE LIST                                    */
/*********************************************************************************************/
glm::mat4 MATRIX_PROJECTION = glm::mat4(1.0f);
glm::mat4 MATRIX_VIEW = glm::mat4(1.0f);
glm::mat4 MATRIX_VIEW_TEMP = glm::mat4(1.0f);
glm::mat4 MATRIX_VIEW_rotX = glm::mat4(1.0f);
glm::mat4 MATRIX_VIEW_rotY = glm::mat4(1.0f);
glm::mat4 MATRIX_VIEW_rotZ = glm::mat4(1.0f);
glm::mat4 MATRIX_VIEW_ROTATION = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION = glm::mat4(1.0f);
/********************************************************************/
/*                     MATRIX LIST OF BASE                          */
/********************************************************************/
glm::mat4 MATRIX_MODEL_BASE_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_BASE = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_BASE = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_BASE;

/********************************************************************/
/*                    MATRIX LIST OF CRANK_SHAFT                    */
/********************************************************************/
glm::mat4 MATRIX_MODEL_CRANK_SHAFT_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_CRANK_SHAFT = glm::mat4(1.0f);
glm::mat4 MATRIX_rotZ_CRANK_SHAFT = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_CRANK_SHAFT = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_CRANK_SHAFT;

/********************************************************************/
/*                   MATRIX LIST OF MASTER_ROD                      */
/********************************************************************/
glm::mat4 MATRIX_MODEL_MASTER_ROD_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_MASTER_ROD = glm::mat4(1.0f);
glm::mat4 MATRIX_rotZ_MASTER_ROD = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_MASTER_ROD = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION_MASTER_ROD = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_MASTER_ROD;

/********************************************************************/
/*                   MATRIX LIST OF PISTON1                      */
/********************************************************************/
glm::mat4 MATRIX_MODEL_PISTON1_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_PISTON1 = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_PISTON1 = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION_PISTON1 = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_PISTON1;

/********************************************************************/
/*                   MATRIX LIST OF PISTON2                      */
/********************************************************************/
glm::mat4 MATRIX_MODEL_PISTON2_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_PISTON2 = glm::mat4(1.0f);
glm::mat4 MATRIX_rotZ_PISTON2 = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_PISTON2 = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION_PISTON2 = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_PISTON2;

/********************************************************************/
/*                   MATRIX LIST OF PISTON3                      */
/********************************************************************/
glm::mat4 MATRIX_MODEL_PISTON3_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_PISTON3 = glm::mat4(1.0f);
glm::mat4 MATRIX_rotZ_PISTON3 = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_PISTON3 = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION_PISTON3 = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_PISTON3;

/********************************************************************/
/*                   MATRIX LIST OF PISTON4                      */
/********************************************************************/
glm::mat4 MATRIX_MODEL_PISTON4_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_PISTON4 = glm::mat4(1.0f);
glm::mat4 MATRIX_rotZ_PISTON4 = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_PISTON4 = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION_PISTON4 = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_PISTON4;

/********************************************************************/
/*                   MATRIX LIST OF PISTON5                      */
/********************************************************************/
glm::mat4 MATRIX_MODEL_PISTON5_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_PISTON5 = glm::mat4(1.0f);
glm::mat4 MATRIX_rotZ_PISTON5 = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_PISTON5 = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION_PISTON5 = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_PISTON5;

/********************************************************************/
/*                   MATRIX LIST OF SLAVE_ROD 1                     */
/********************************************************************/
glm::mat4 MATRIX_MODEL_SLAVE_ROD_1_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_SLAVE_ROD_1 = glm::mat4(1.0f);
glm::mat4 MATRIX_rotZ_SLAVE_ROD_1 = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_SLAVE_ROD_1 = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION_SLAVE_ROD_1 = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_SLAVE_ROD_1;

/********************************************************************/
/*                   MATRIX LIST OF SLAVE_ROD 2                     */
/********************************************************************/
glm::mat4 MATRIX_MODEL_SLAVE_ROD_2_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_SLAVE_ROD_2 = glm::mat4(1.0f);
glm::mat4 MATRIX_rotZ_SLAVE_ROD_2 = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_SLAVE_ROD_2 = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION_SLAVE_ROD_2 = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_SLAVE_ROD_2;

/********************************************************************/
/*                   MATRIX LIST OF SLAVE_ROD 3                     */
/********************************************************************/
glm::mat4 MATRIX_MODEL_SLAVE_ROD_3_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_SLAVE_ROD_3 = glm::mat4(1.0f);
glm::mat4 MATRIX_rotZ_SLAVE_ROD_3 = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_SLAVE_ROD_3 = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION_SLAVE_ROD_3 = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_SLAVE_ROD_3;

/********************************************************************/
/*                   MATRIX LIST OF SLAVE_ROD 4                     */
/********************************************************************/
glm::mat4 MATRIX_MODEL_SLAVE_ROD_4_ORIGIN = glm::mat4(1.0f);
glm::mat4 MATRIX_MODEL_SLAVE_ROD_4 = glm::mat4(1.0f);
glm::mat4 MATRIX_rotZ_SLAVE_ROD_4 = glm::mat4(1.0f);
glm::mat4 MATRIX_RotALL_SLAVE_ROD_4 = glm::mat4(1.0f);
glm::mat4 MATRIX_TRANSLATION_SLAVE_ROD_4 = glm::mat4(1.0f);
glm::mat4 MATRIX_MVP_SLAVE_ROD_4;

/********************************************************************/
/*                  ADDRESS FOR UPLOADING GPU                       */
/********************************************************************/
GLuint shaderProgramID;
GLuint MVPID;
GLuint allRotsMatID;
GLuint lightID;
GLuint PositionID, colorID, normalID;

/********************************************************************/
/*                    VAO & VBO VARIABLE LIST                       */
/********************************************************************/
GLuint VertexArrayID[12];
GLuint vertexBuffer[12];
GLuint colorBuffer[12];
GLuint indexBuffer[12];
GLuint normalBuffer[12];

int ARRAY_ADDR_ENGINE_BASE = 0; // 1/12 ARRAY : ENGINE BASE (BASE.STL);
int ARRAY_ADDR_CRANK_SHAFT = 1; // 2/12 ARRAY : CRANK SHAFT (CRANK_SHAFT.STL);
int ARRAY_ADDR_MASTER_ROD = 2; // 3/12 ARRAY : MASTER ROD (MASTER_ROD.STL);
int ARRAY_ADDR_PISTON_1 = 3; // 4/12 ARRAY : PISTON 1 (PISTON1.STL);
int ARRAY_ADDR_PISTON_2 = 4;// 5/12 ARRAY : PISTON 2 (PISTON1.STL);
int ARRAY_ADDR_PISTON_3 = 5;// 6/12 ARRAY : PISTON 3 (PISTON1.STL);
int ARRAY_ADDR_PISTON_4 = 6;// 7/12 ARRAY : PISTON 4 (PISTON1.STL);
int ARRAY_ADDR_PISTON_5 = 7;// 8/12 ARRAY : PISTON 5 (PISTON1.STL);
int ARRAY_ADDR_SLAVE_ROD_1 = 8; // 9/12 ARRAY : SLAVE ROD 1 (SLAVE_ROD1.STL);
int ARRAY_ADDR_SLAVE_ROD_2 = 9; // 10/12 ARRAY : SLAVE ROD 2 (SLAVE_ROD2.STL);
int ARRAY_ADDR_SLAVE_ROD_3 = 10; // 11/12 ARRAY : SLAVE ROD 3 (SLAVE_ROD3.STL);
int ARRAY_ADDR_SLAVE_ROD_4 = 11; // 12/12 ARRAY : SLAVE ROD 4 (SLAVE_ROD4.STL);

/********************************************************************/
/*         MODEL DATA STORAGE AND PARAMETER VARIABLE LIST           */
/********************************************************************/
glm::vec4 light_ORIGINAL = glm::vec4(0.0f, 0.0f, 350.0f, 1.0f);
glm::vec4 light = glm::vec4(0.0f, 0.0f, 350.0f, 1.0f);
MODEL_P MODEL_BASE; //BASE.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_CRANK_SHAFT; //CRANK_SHAFT.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_MASTER_ROD; //MASTER_ROD.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_PISTON1; //PISTON1.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_PISTON2; //PISTON1.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_PISTON3; //PISTON1.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_PISTON4; //PISTON1.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_PISTON5; //PISTON1.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_SLAVE_ROD_1; //SLAVE_ROD1.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_SLAVE_ROD_2; //SLAVE_ROD2.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_SLAVE_ROD_3; //SLAVE_ROD3.STL MODELING PROPERTY SAVING STRUCTURE
MODEL_P MODEL_SLAVE_ROD_4; //SLAVE_ROD4.STL MODELING PROPERTY SAVING STRUCTURE


GLfloat MODEL_BASE_COLOR_BASE[] = {0.5f, 0.5f, 0.5f, 1.0f}; //BASE.STL MODELING PROPERTY COLOR PARAMETER
GLfloat MODEL_CRANK_SHAFT_COLOR_BASE[] = {0.0f, 0.0f, 1.0f, 1.0f}; //CRANK_SHAFT.STL MODELING PROPERTY COLOR PARAMETER
GLfloat MODEL_MASTER_ROD_COLOR_BASE[] = {0.0f, 1.0f, 0.0f, 0.0f}; //MASTER_ROD.STL MODELING PROPERTY COLOR PARAMETER
GLfloat MODEL_PISTON1_COLOR_BASE[] = {1.0f, 0.0f, 0.0f, 1.0f}; //PISTON1.STL MODELING PROPERTY COLOR PARAMETER
GLfloat MODEL_SLAVE_ROD_COLOR_BASE[] = {1.0f, 1.0f, 0.0f, 1.0f}; //SLAVE_RODS MODELING PROPERTY COLOR PARAMETER

/********************************************************************/
/*                   MODEL ANIMATION VARIABLE LIST                  */
/********************************************************************/
GLint ANIMATION_SWITCH = 0;
GLfloat ANIMATION_DISPLAY_PERIOD = 16.666f;
GLfloat RATE_PER_MINUTE = 0.0f;
GLint ANIMATION_MODEL_RESET = 0;

GLfloat MODEL_ORIGIN_TO_PISTON_MAX_LENGTH = 92.5f;
GLfloat MODEL_MASTER_ROD_X_LOCATION = 0.0f;
GLfloat MODEL_MASTER_ROD_Y_LOCATION = 17.5f;
GLfloat MODEL_MASTER_ROD_Z_ROTATE_LOCATION = 0.0f;
GLfloat MODEL_SLAVE_ROD_LENGTH = 62.5f;

GLfloat RPM_TO_DEGREE_PER_MILISECONDS = 0.0f;
GLfloat MODEL_CRANK_SHAFT_LOCATION = 0.0f;
GLfloat MODEL_CRANK_SHAFT_TO_PISTON1 = 0.0f;

GLfloat MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN = 72.0f;
GLfloat MODEL_SLAVE_ROD_1_X_LOCATION = 0.0f + 12.5*(sin(radians(-MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN)));
GLfloat MODEL_SLAVE_ROD_1_Y_LOCATION = 17.5f + 12.5*(cos(radians(-MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN)));
GLfloat MODEL_SLAVE_ROD_1_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_Y_LOCATION);
GLfloat MODEL_SLAVE_ROD_1_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_Y_LOCATION);
GLfloat MODEL_SLAVE_ROD_1_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_1_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
GLfloat MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_1_Z_ROTATE_ANGLE;

GLfloat MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN = 144.0f;
GLfloat MODEL_SLAVE_ROD_2_X_LOCATION = 0.0f + 12.5*(sin(radians(-MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN)));
GLfloat MODEL_SLAVE_ROD_2_Y_LOCATION = 17.5f + 12.5*(cos(radians(-MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN)));
GLfloat MODEL_SLAVE_ROD_2_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_Y_LOCATION);
GLfloat MODEL_SLAVE_ROD_2_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_Y_LOCATION);
GLfloat MODEL_SLAVE_ROD_2_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_2_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
GLfloat MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_2_Z_ROTATE_ANGLE;

GLfloat MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN = 216.0f;
GLfloat MODEL_SLAVE_ROD_3_X_LOCATION = 0.0f + 12.5*(sin(radians(-MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN)));
GLfloat MODEL_SLAVE_ROD_3_Y_LOCATION = 17.5f + 12.5*(cos(radians(-MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN)));
GLfloat MODEL_SLAVE_ROD_3_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_Y_LOCATION);
GLfloat MODEL_SLAVE_ROD_3_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_Y_LOCATION);
GLfloat MODEL_SLAVE_ROD_3_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_3_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
GLfloat MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_3_Z_ROTATE_ANGLE;

GLfloat MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN = 288.0f;
GLfloat MODEL_SLAVE_ROD_4_X_LOCATION = 0.0f + 12.5*(sin(radians(-MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN)));
GLfloat MODEL_SLAVE_ROD_4_Y_LOCATION = 17.5f + 12.5*(cos(radians(-MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN)));
GLfloat MODEL_SLAVE_ROD_4_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_Y_LOCATION);
GLfloat MODEL_SLAVE_ROD_4_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_Y_LOCATION);
GLfloat MODEL_SLAVE_ROD_4_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_4_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
GLfloat MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_4_Z_ROTATE_ANGLE;

GLfloat MODEL_PISTON1_LOCATION = 0.0f;
GLfloat MODEL_PISTON2_Z_ROTATE_LOCATION = 72.0f;
GLfloat MODEL_PISTON2_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_1_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));
GLfloat MODEL_PISTON3_Z_ROTATE_LOCATION = 144.0f;
GLfloat MODEL_PISTON3_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_2_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));
GLfloat MODEL_PISTON4_Z_ROTATE_LOCATION = 216.0f;
GLfloat MODEL_PISTON4_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_3_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));
GLfloat MODEL_PISTON5_Z_ROTATE_LOCATION = 288.0f;
GLfloat MODEL_PISTON5_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_4_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));

/********************************************************************/
/*                   VIEW SETTING VARIABLE LIST                     */
/********************************************************************/
GLfloat VIEW_ROTATION_X = 0.0f;
GLfloat VIEW_ROTATION_Y = 0.0f;
GLfloat VIEW_ROTATION_Z = 0.0f;
GLfloat VIEW_MOVEMENT_X = 0.0f;
GLfloat VIEW_MOVEMENT_Y = 0.0f;
GLfloat VIEW_MOVEMENT_Z = 0.0f;

/********************************************************************/
/*                 KEY INPUT SETTING VARIABLE LIST                  */
/********************************************************************/
GLfloat KEY_ROTATE_MODEL_III_X = 0.0f;
GLfloat KEY_ROTATE_MODEL_III_Y = 0.0f;
GLfloat KEY_ROTATE_MODEL_III_Z = 0.0f;
GLfloat KEY_CHANGE_BACKGROUND_COLOR_RED = 0.0f;
GLfloat KEY_CHANGE_BACKGROUND_COLOR_GREEN = 0.0f;
GLfloat KEY_CHANGE_BACKGROUND_COLOR_BLUE = 0.0f;
GLfloat KEY_CHANGE_BACKGROUND_COLOR_ALPHA = 0.0f;

/********************************************************************/
/*               MOUSE INPUT SETTING VARIABLE LIST                  */
/********************************************************************/
GLint MOUSE_ACTIVATION = 0;
GLint LEFT_MOUSE_ACTIVATE = 0;
GLint MIDDLE_MOUSE_ACTIVATE = 0;
GLint GLUT_WHEEL_UP = 3;
GLint GLUT_WHEEL_DOWN = 4;
GLint MOUSE_POS_X_OLD = 0, MOUSE_POS_X = 0;
GLint MOUSE_POS_Y_OLD = 0, MOUSE_POS_Y = 0;
GLint MOUSE_POSTION_DETECTION = 0;

/*********************************************************************************************/
/*                          USER OPENGL INTERNAL FUNCTION LIST                               */
/*********************************************************************************************/
/********************************************************************/
/*                    KEYBOARD INPUT FUNCTION                       */
/********************************************************************/
void DoKeyboard(unsigned char key, int x, int y)	{
	switch (key) {
		case 033 : glutLeaveMainLoop(); break; // ESC KEY FUNCTION IS PROGRAM EXIT.
	}
}

void SpecialKeyboard(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_UP :
		    RATE_PER_MINUTE += 10.0f;
		    printf("      ANIMATION >>> RATE PER MINUTE : %5.3f\n",RATE_PER_MINUTE);
        break;
        case GLUT_KEY_DOWN :
		    RATE_PER_MINUTE -= 10.0f;
		    printf("      ANIMATION >>> RATE PER MINUTE : %5.3f\n",RATE_PER_MINUTE);
        break;
        //case GLUT_KEY_LEFT : KEY_ROTATE_MODEL_III_Z += 2.5f; break;
        //case GLUT_KEY_RIGHT : KEY_ROTATE_MODEL_III_Z -= 2.5f; break;
        case GLUT_KEY_F1 : ANIMATION_SWITCH = 1; printf("   ACTION >>> ANIMATION [ON]\n"); break;
        case GLUT_KEY_F2 : ANIMATION_SWITCH = 0; printf("   ACTION >>> ANIMATION [OFF]\n"); break;
        case GLUT_KEY_F3 :
            printf("      ANIMATION >>> VIEW MODEL STATUS\n");
            printf("     #############################################\n");
            printf("     #            MODEL STATUS VIEWER            #\n");
            printf("     #############################################\n");
            printf("       MODEL ENGINE RPM :           [%4.3f RPM]   \n",RATE_PER_MINUTE);
            printf("       CRANK SHAFT ROTATED ANGLE :  [%4.3f]   \n",MODEL_CRANK_SHAFT_LOCATION);
            printf("       PISTON 1 LOCATION :          [%4.3f]   \n",MODEL_PISTON1_LOCATION);
            printf("                            [TOP POINT ORIGIN]    \n");
            printf("       MASTER ROD LOCATION :                      \n");
            printf("         [X Axis : %4.3f]  [Y Axis : %4.3f]   \n",MODEL_MASTER_ROD_X_LOCATION,MODEL_MASTER_ROD_Y_LOCATION);
            printf("       MASTER ROD ROTATED ANGLE :   [%4.3f DEG]   \n",MODEL_MASTER_ROD_Z_ROTATE_LOCATION);
            printf("     #############################################\n");
        break;

        case GLUT_KEY_F4 : if ( ANIMATION_SWITCH == 0 ) ANIMATION_MODEL_RESET = 1; break;
        case GLUT_KEY_F8 :
            printf("   ACTION >>> VIEW POSITION RESET...!!!\n");
            VIEW_MOVEMENT_Z = 0;
            VIEW_MOVEMENT_X = 0; VIEW_MOVEMENT_Y = 0;
            VIEW_ROTATION_X = 0; VIEW_ROTATION_Y = 0; break;
        case GLUT_KEY_END :
            printf("   ACTION >>> VIEW POSITION [ISOMATRIC]\n");
            VIEW_ROTATION_X = 45.0f; VIEW_ROTATION_Y = -45.0f;
            break;
    }

}

/********************************************************************/
/*                      MOUSE INPUT FUNCTION                        */
/********************************************************************/
void MouseActivatonConfirm(int state) {
    if( state == GLUT_LEFT) {
        MOUSE_ACTIVATION = 0;
    }
    else {
        MOUSE_ACTIVATION = 1;
    }
}
void MouseButtonActivationConfirm(int button, int state, int x, int y) {
    if ( MOUSE_ACTIVATION == 1 ) {
        if ( state == GLUT_DOWN ) {
            if ( button == GLUT_LEFT_BUTTON ) {
                LEFT_MOUSE_ACTIVATE = 1;
            }
            else if( button == GLUT_MIDDLE_BUTTON ) {
                MIDDLE_MOUSE_ACTIVATE = 1;
            }
        }
        else {
            if ( button == GLUT_WHEEL_UP ) VIEW_MOVEMENT_Z += 5.0f;
            else if ( button == GLUT_WHEEL_DOWN ) VIEW_MOVEMENT_Z -= 5.0f;
            else {
                LEFT_MOUSE_ACTIVATE = 0;
                MIDDLE_MOUSE_ACTIVATE = 0;
            }
        }
    }
}
void MouseMotionConfirm(int x, int y) {
    if ( MOUSE_ACTIVATION == 1 ) {
        if (MOUSE_POSTION_DETECTION == 0) {
            MOUSE_POS_X_OLD = x;
            MOUSE_POS_Y_OLD = y;
            MOUSE_POSTION_DETECTION = 1;
        }
        else if (MOUSE_POSTION_DETECTION == 1) {
            MOUSE_POS_X = x;
            MOUSE_POS_Y = y;
            if ( LEFT_MOUSE_ACTIVATE == 1) {
                if ( (MOUSE_POS_X - MOUSE_POS_X_OLD) > 0) {
                    VIEW_MOVEMENT_X += 2.5f;
                }
                else if ((MOUSE_POS_X - MOUSE_POS_X_OLD) < 0) {
                    VIEW_MOVEMENT_X -= 2.5f;
                }
                if ( (MOUSE_POS_Y - MOUSE_POS_Y_OLD) < 0) {
                    VIEW_MOVEMENT_Y += 2.5f;
                }
                else if ((MOUSE_POS_Y - MOUSE_POS_Y_OLD) > 0) {
                    VIEW_MOVEMENT_Y -= 2.5f;
                }
            }
            if ( MIDDLE_MOUSE_ACTIVATE == 1) {
                if ( (MOUSE_POS_X - MOUSE_POS_X_OLD) > 0) {
                    VIEW_ROTATION_Y += 2.5f;
                }
                else if ((MOUSE_POS_X - MOUSE_POS_X_OLD) < 0) {
                    VIEW_ROTATION_Y -= 2.5f;
                }
                if ( (MOUSE_POS_Y - MOUSE_POS_Y_OLD) > 0) {
                    VIEW_ROTATION_X += 2.5f;
                }
                else if ((MOUSE_POS_Y - MOUSE_POS_Y_OLD) < 0) {
                    VIEW_ROTATION_X -= 2.5f;
                }
            }
            MOUSE_POSTION_DETECTION = 0;
        }
    }
}
/*********************************************************************************************/
/*                           MAIN DISPLAY RENDERING FUNCTION                                 */
/*********************************************************************************************/
void AnimationTimer(int value) {
    if ( ANIMATION_SWITCH == 1) {
        RPM_TO_DEGREE_PER_MILISECONDS = (6*RATE_PER_MINUTE*ANIMATION_DISPLAY_PERIOD)/1000;
        MODEL_CRANK_SHAFT_LOCATION += RPM_TO_DEGREE_PER_MILISECONDS;
        if ( MODEL_CRANK_SHAFT_LOCATION > 359) MODEL_CRANK_SHAFT_LOCATION = 0;

        MODEL_MASTER_ROD_X_LOCATION = 17.5*(sin(radians(-MODEL_CRANK_SHAFT_LOCATION)));
        MODEL_MASTER_ROD_Y_LOCATION = 17.5*(cos(radians(-MODEL_CRANK_SHAFT_LOCATION)));
        MODEL_MASTER_ROD_Z_ROTATE_LOCATION = degrees(asin(MODEL_MASTER_ROD_X_LOCATION/75));

        MODEL_SLAVE_ROD_1_X_LOCATION = 17.5*(sin(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(sin(radians(-MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
        MODEL_SLAVE_ROD_1_Y_LOCATION = 17.5*(cos(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(cos(radians(-MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
        MODEL_SLAVE_ROD_1_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_Y_LOCATION);
        MODEL_SLAVE_ROD_1_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_Y_LOCATION);
        MODEL_SLAVE_ROD_1_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_1_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
        MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_1_Z_ROTATE_ANGLE;

        MODEL_SLAVE_ROD_2_X_LOCATION = 17.5*(sin(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(sin(radians(-MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
        MODEL_SLAVE_ROD_2_Y_LOCATION = 17.5*(cos(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(cos(radians(-MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
        MODEL_SLAVE_ROD_2_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_Y_LOCATION);
        MODEL_SLAVE_ROD_2_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_Y_LOCATION);
        MODEL_SLAVE_ROD_2_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_2_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
        MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_2_Z_ROTATE_ANGLE;

        MODEL_SLAVE_ROD_3_X_LOCATION = 17.5*(sin(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(sin(radians(-MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
        MODEL_SLAVE_ROD_3_Y_LOCATION = 17.5*(cos(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(cos(radians(-MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
        MODEL_SLAVE_ROD_3_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_Y_LOCATION);
        MODEL_SLAVE_ROD_3_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_Y_LOCATION);
        MODEL_SLAVE_ROD_3_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_3_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
        MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_3_Z_ROTATE_ANGLE;

        MODEL_SLAVE_ROD_4_X_LOCATION = 17.5*(sin(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(sin(radians(-MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
        MODEL_SLAVE_ROD_4_Y_LOCATION = 17.5*(cos(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(cos(radians(-MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
        MODEL_SLAVE_ROD_4_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_Y_LOCATION);
        MODEL_SLAVE_ROD_4_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_Y_LOCATION);
        MODEL_SLAVE_ROD_4_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_4_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
        MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_4_Z_ROTATE_ANGLE;

        MODEL_PISTON1_LOCATION = -(17.5-MODEL_MASTER_ROD_Y_LOCATION) - (75-(75*cos(radians(MODEL_MASTER_ROD_Z_ROTATE_LOCATION))));
        MODEL_PISTON2_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_1_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));
        MODEL_PISTON3_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_2_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));
        MODEL_PISTON4_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_3_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));
        MODEL_PISTON5_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_4_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));

    }
    else if ( ANIMATION_SWITCH == 0) {
        if ( ANIMATION_MODEL_RESET == 1 ) {
            printf("      ANIMATION >>> ALL ANIMATION MODEL LOCATION RESET!!!\n");
            MODEL_CRANK_SHAFT_LOCATION = 0;
            MODEL_MASTER_ROD_X_LOCATION = 17.5*(sin(radians(-MODEL_CRANK_SHAFT_LOCATION)));
            MODEL_MASTER_ROD_Y_LOCATION = 17.5*(cos(radians(-MODEL_CRANK_SHAFT_LOCATION)));
            MODEL_MASTER_ROD_Z_ROTATE_LOCATION = degrees(asin(MODEL_MASTER_ROD_X_LOCATION/75));

            MODEL_SLAVE_ROD_1_X_LOCATION = 17.5*(sin(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(sin(radians(-MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
            MODEL_SLAVE_ROD_1_Y_LOCATION = 17.5*(cos(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(cos(radians(-MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
            MODEL_SLAVE_ROD_1_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_Y_LOCATION);
            MODEL_SLAVE_ROD_1_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_1_Y_LOCATION);
            MODEL_SLAVE_ROD_1_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_1_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
            MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_1_Z_ROTATE_ANGLE;

            MODEL_SLAVE_ROD_2_X_LOCATION = 17.5*(sin(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(sin(radians(-MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
            MODEL_SLAVE_ROD_2_Y_LOCATION = 17.5*(cos(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(cos(radians(-MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
            MODEL_SLAVE_ROD_2_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_Y_LOCATION);
            MODEL_SLAVE_ROD_2_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_2_Y_LOCATION);
            MODEL_SLAVE_ROD_2_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_2_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
            MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_2_Z_ROTATE_ANGLE;

            MODEL_SLAVE_ROD_3_X_LOCATION = 17.5*(sin(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(sin(radians(-MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
            MODEL_SLAVE_ROD_3_Y_LOCATION = 17.5*(cos(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(cos(radians(-MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
            MODEL_SLAVE_ROD_3_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_Y_LOCATION);
            MODEL_SLAVE_ROD_3_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_3_Y_LOCATION);
            MODEL_SLAVE_ROD_3_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_3_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
            MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_3_Z_ROTATE_ANGLE;

            MODEL_SLAVE_ROD_4_X_LOCATION = 17.5*(sin(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(sin(radians(-MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
            MODEL_SLAVE_ROD_4_Y_LOCATION = 17.5*(cos(radians(-MODEL_CRANK_SHAFT_LOCATION))) + 12.5*(cos(radians(-MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN - MODEL_MASTER_ROD_Z_ROTATE_LOCATION)));
            MODEL_SLAVE_ROD_4_X_LOCATION_PRIME = (cos(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_X_LOCATION) + (sin(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_Y_LOCATION);
            MODEL_SLAVE_ROD_4_Y_LOCATION_PRIME = (-sin(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_X_LOCATION) + (cos(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN))*MODEL_SLAVE_ROD_4_Y_LOCATION);
            MODEL_SLAVE_ROD_4_Z_ROTATE_ANGLE = degrees(asin(MODEL_SLAVE_ROD_4_X_LOCATION_PRIME/MODEL_SLAVE_ROD_LENGTH));
            MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION = MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION_ORIGIN + MODEL_SLAVE_ROD_4_Z_ROTATE_ANGLE;

            MODEL_PISTON1_LOCATION = -(17.5-MODEL_MASTER_ROD_Y_LOCATION) - (75-(75*cos(radians(MODEL_MASTER_ROD_Z_ROTATE_LOCATION))));
            MODEL_PISTON2_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_1_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_1_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));
            MODEL_PISTON3_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_2_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_2_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));
            MODEL_PISTON4_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_3_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_3_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));
            MODEL_PISTON5_LOCATION = -(92.5f-(MODEL_SLAVE_ROD_4_Y_LOCATION_PRIME + (cos(radians(MODEL_SLAVE_ROD_4_Z_ROTATE_ANGLE)) * MODEL_SLAVE_ROD_LENGTH)));

            ANIMATION_MODEL_RESET = 0;
        }

    }

        glutPostRedisplay();
        glutTimerFunc(ANIMATION_DISPLAY_PERIOD, AnimationTimer, 1);
}

/********************************************************************/
/*                       VIWEPORT FUNCTION                          */
/********************************************************************/
void changeViewport(int w, int h) {
	glViewport(0,0,w,h);
}
/*********************************************************************************************/
/*                           MAIN DISPLAY RENDERING FUNCTION                                 */
/*********************************************************************************************/
void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5f + KEY_CHANGE_BACKGROUND_COLOR_RED
               , 0.5f + KEY_CHANGE_BACKGROUND_COLOR_GREEN
               , 0.5f + KEY_CHANGE_BACKGROUND_COLOR_BLUE
               , 0.5f + KEY_CHANGE_BACKGROUND_COLOR_ALPHA);
/********************************************************************/
/*              MODEL ANIMATION VARIABLE VARIATION                  */
/********************************************************************/

/********************************************************************/
/*                VIEW AND PROJECTION MATRIX AREA                   */
/********************************************************************/
	MATRIX_PROJECTION = perspective(radians(45.0f), 4.0f/3.0f, 1.0f, 5000.0f);
	MATRIX_VIEW_TEMP = glm::lookAt(glm::vec3(0, 0, 350), glm::vec3(0,0,0), glm::vec3(0,1,0));
	MATRIX_VIEW_rotX = glm::rotate(glm::mat4x4(1.0f), radians(VIEW_ROTATION_X), glm::vec3(1.0f, 0.0f, 0.0f));
	MATRIX_VIEW_rotY = glm::rotate(glm::mat4x4(1.0f), radians(VIEW_ROTATION_Y), glm::vec3(0.0f, 1.0f, 0.0f));
	MATRIX_VIEW_rotZ = glm::rotate(glm::mat4x4(1.0f), radians(VIEW_ROTATION_Z), glm::vec3(0.0f, 0.0f, 1.0f));
	MATRIX_VIEW_ROTATION = MATRIX_VIEW_rotX * MATRIX_VIEW_rotY * MATRIX_VIEW_rotZ;
	MATRIX_TRANSLATION = glm::translate(glm::mat4(1.0f), glm::vec3(VIEW_MOVEMENT_X, VIEW_MOVEMENT_Y, VIEW_MOVEMENT_Z));
    MATRIX_VIEW = MATRIX_VIEW_TEMP * MATRIX_VIEW_ROTATION * MATRIX_TRANSLATION;

/********************************************************************/
/*                  LIGHT TRANSFROMANTION AREA                     */
/*******************************************************************/
    light = MATRIX_VIEW_ROTATION * MATRIX_TRANSLATION * light_ORIGINAL;
/********************************************************************/
/*               BASE.STL MODEL TRANSFORM MATRIX AREA               */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_ENGINE_BASE]);
    glUseProgram(shaderProgramID);
    MATRIX_MODEL_BASE = MATRIX_MODEL_BASE_ORIGIN;
    MATRIX_MVP_BASE = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_BASE;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_BASE));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_BASE));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
	glDrawElements(GL_TRIANGLES, MODEL_BASE.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);

/********************************************************************/
/*           CRANK_SHAFT.STL MODEL TRANSFORM MATRIX AREA            */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_CRANK_SHAFT]);
    glUseProgram(shaderProgramID);
    MATRIX_rotZ_CRANK_SHAFT = glm::rotate(glm::mat4x4(1.0f), radians(MODEL_CRANK_SHAFT_LOCATION), glm::vec3(0.0f, 0.0f, 1.0f));
    MATRIX_MODEL_CRANK_SHAFT = MATRIX_MODEL_CRANK_SHAFT_ORIGIN * MATRIX_rotZ_CRANK_SHAFT;
    MATRIX_RotALL_CRANK_SHAFT = MATRIX_MODEL_CRANK_SHAFT_ORIGIN;
    MATRIX_MVP_CRANK_SHAFT = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_CRANK_SHAFT;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_CRANK_SHAFT));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_CRANK_SHAFT));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_CRANK_SHAFT.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);

/********************************************************************/
/*          MASTER_ROD.STL MODEL TRANSFORM MATRIX AREA              */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_MASTER_ROD]);
    glUseProgram(shaderProgramID);
    MATRIX_rotZ_MASTER_ROD = glm::rotate(glm::mat4x4(1.0f), radians(MODEL_MASTER_ROD_Z_ROTATE_LOCATION), glm::vec3(0.0f, 0.0f, 1.0f));
    MATRIX_TRANSLATION_MASTER_ROD = glm::translate(glm::mat4x4(1.0f), glm::vec3(MODEL_MASTER_ROD_X_LOCATION, MODEL_MASTER_ROD_Y_LOCATION, 0.0f));
    MATRIX_MODEL_MASTER_ROD = MATRIX_MODEL_MASTER_ROD_ORIGIN * MATRIX_TRANSLATION_MASTER_ROD *  MATRIX_rotZ_MASTER_ROD;
    MATRIX_RotALL_MASTER_ROD = MATRIX_MODEL_MASTER_ROD_ORIGIN;
    MATRIX_MVP_MASTER_ROD = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_MASTER_ROD;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_MASTER_ROD));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_MASTER_ROD));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_MASTER_ROD.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);

/********************************************************************/
/*          PISTON1.STL MODEL TRANSFORM MATRIX AREA              */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_PISTON_1]);
    glUseProgram(shaderProgramID);
    MATRIX_MODEL_PISTON1_ORIGIN = glm::mat4(1.0f);
    MATRIX_TRANSLATION_PISTON1 = glm::translate(glm::mat4x4(1.0f), glm::vec3(0.0f, MODEL_PISTON1_LOCATION, 0.0f));
    MATRIX_MODEL_PISTON1 = MATRIX_MODEL_PISTON1_ORIGIN * MATRIX_TRANSLATION_PISTON1;
    MATRIX_RotALL_PISTON1 = MATRIX_MODEL_PISTON1_ORIGIN;
    MATRIX_MVP_PISTON1 = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_PISTON1;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_PISTON1));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_PISTON1));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_PISTON1.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);

/********************************************************************/
/*        PISTON2(PISTON1.STL) MODEL TRANSFORM MATRIX AREA          */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_PISTON_2]);
    glUseProgram(shaderProgramID);
    MATRIX_MODEL_PISTON2_ORIGIN = glm::mat4(1.0f);
    MATRIX_rotZ_PISTON2 = glm::rotate(glm::mat4(1.0f), radians(MODEL_PISTON2_Z_ROTATE_LOCATION), glm::vec3(0.0f, 0.0f, 1.0f));
    MATRIX_TRANSLATION_PISTON2 = glm::translate(glm::mat4x4(1.0f), glm::vec3(0.0f, MODEL_PISTON2_LOCATION, 0.0f));
    MATRIX_MODEL_PISTON2 = MATRIX_MODEL_PISTON2_ORIGIN * MATRIX_rotZ_PISTON2 * MATRIX_TRANSLATION_PISTON2;
    MATRIX_RotALL_PISTON2 = MATRIX_MODEL_PISTON2_ORIGIN;
    MATRIX_MVP_PISTON2 = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_PISTON2;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_PISTON2));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_PISTON2));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_PISTON2.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);


/********************************************************************/
/*        PISTON3(PISTON1.STL) MODEL TRANSFORM MATRIX AREA          */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_PISTON_3]);
    glUseProgram(shaderProgramID);
    MATRIX_MODEL_PISTON3_ORIGIN = glm::mat4(1.0f);
    MATRIX_rotZ_PISTON3 = glm::rotate(glm::mat4(1.0f), radians(MODEL_PISTON3_Z_ROTATE_LOCATION), glm::vec3(0.0f, 0.0f, 1.0f));
    MATRIX_TRANSLATION_PISTON3 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, MODEL_PISTON3_LOCATION, 0.0f));
    MATRIX_MODEL_PISTON3 = MATRIX_MODEL_PISTON3_ORIGIN * MATRIX_rotZ_PISTON3 * MATRIX_TRANSLATION_PISTON3;
    MATRIX_RotALL_PISTON3 = MATRIX_MODEL_PISTON3_ORIGIN;
    MATRIX_MVP_PISTON3 = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_PISTON3;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_PISTON3));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_PISTON3));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_PISTON3.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);

/********************************************************************/
/*        PISTON4(PISTON1.STL) MODEL TRANSFORM MATRIX AREA          */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_PISTON_4]);
    glUseProgram(shaderProgramID);
    MATRIX_MODEL_PISTON4_ORIGIN = glm::mat4(1.0f);
    MATRIX_rotZ_PISTON4 = glm::rotate(glm::mat4(1.0f), radians(MODEL_PISTON4_Z_ROTATE_LOCATION), glm::vec3(0.0f, 0.0f, 1.0f));
    MATRIX_TRANSLATION_PISTON4 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, MODEL_PISTON4_LOCATION, 0.0f));
    MATRIX_MODEL_PISTON4 = MATRIX_MODEL_PISTON4_ORIGIN * MATRIX_rotZ_PISTON4 * MATRIX_TRANSLATION_PISTON4;
    MATRIX_RotALL_PISTON4 = MATRIX_MODEL_PISTON4_ORIGIN;
    MATRIX_MVP_PISTON4 = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_PISTON4;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_PISTON4));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_PISTON4));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_PISTON4.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);

/********************************************************************/
/*        PISTON5(PISTON1.STL) MODEL TRANSFORM MATRIX AREA          */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_PISTON_5]);
    glUseProgram(shaderProgramID);
    MATRIX_MODEL_PISTON5_ORIGIN = glm::mat4(1.0f);
    MATRIX_rotZ_PISTON5 = glm::rotate(glm::mat4(1.0f), radians(MODEL_PISTON5_Z_ROTATE_LOCATION), glm::vec3(0.0f, 0.0f, 1.0f));
    MATRIX_TRANSLATION_PISTON5 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, MODEL_PISTON5_LOCATION, 0.0f));
    MATRIX_MODEL_PISTON5 = MATRIX_MODEL_PISTON5_ORIGIN * MATRIX_rotZ_PISTON5 * MATRIX_TRANSLATION_PISTON5;
    MATRIX_RotALL_PISTON5 = MATRIX_MODEL_PISTON5_ORIGIN;
    MATRIX_MVP_PISTON5 = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_PISTON5;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_PISTON5));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_PISTON5));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_PISTON5.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);

/********************************************************************/
/*     SLAVE_ROD1(SLAVE_ROD1.STL) MODEL TRANSFORM MATRIX AREA       */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_SLAVE_ROD_1]);
    glUseProgram(shaderProgramID);
    MATRIX_rotZ_SLAVE_ROD_1 = glm::rotate(glm::mat4x4(1.0f), radians(MODEL_SLAVE_ROD_1_Z_ROTATE_LOCATION), glm::vec3(0.0f, 0.0f, 1.0f));
    MATRIX_TRANSLATION_SLAVE_ROD_1 = glm::translate(glm::mat4x4(1.0f), glm::vec3(MODEL_SLAVE_ROD_1_X_LOCATION, MODEL_SLAVE_ROD_1_Y_LOCATION, 0.0f));
    MATRIX_MODEL_SLAVE_ROD_1 = MATRIX_MODEL_SLAVE_ROD_1_ORIGIN * MATRIX_TRANSLATION_SLAVE_ROD_1 *  MATRIX_rotZ_SLAVE_ROD_1;
    MATRIX_RotALL_SLAVE_ROD_1 = MATRIX_MODEL_SLAVE_ROD_1_ORIGIN;
    MATRIX_MVP_SLAVE_ROD_1 = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_SLAVE_ROD_1;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_SLAVE_ROD_1));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_SLAVE_ROD_1));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_SLAVE_ROD_1.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);

/********************************************************************/
/*     SLAVE_ROD2(SLAVE_ROD1.STL) MODEL TRANSFORM MATRIX AREA       */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_SLAVE_ROD_2]);
    glUseProgram(shaderProgramID);
    MATRIX_rotZ_SLAVE_ROD_2 = glm::rotate(glm::mat4x4(1.0f), radians(MODEL_SLAVE_ROD_2_Z_ROTATE_LOCATION), glm::vec3(0.0f, 0.0f, 1.0f));
    MATRIX_TRANSLATION_SLAVE_ROD_2 = glm::translate(glm::mat4x4(1.0f), glm::vec3(MODEL_SLAVE_ROD_2_X_LOCATION, MODEL_SLAVE_ROD_2_Y_LOCATION, 0.0f));
    MATRIX_MODEL_SLAVE_ROD_2 = MATRIX_MODEL_SLAVE_ROD_2_ORIGIN * MATRIX_TRANSLATION_SLAVE_ROD_2 *  MATRIX_rotZ_SLAVE_ROD_2;
    MATRIX_RotALL_SLAVE_ROD_2 = MATRIX_MODEL_SLAVE_ROD_2_ORIGIN;
    MATRIX_MVP_SLAVE_ROD_2 = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_SLAVE_ROD_2;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_SLAVE_ROD_2));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_SLAVE_ROD_2));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_SLAVE_ROD_2.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);

/********************************************************************/
/*     SLAVE_ROD3(SLAVE_ROD1.STL) MODEL TRANSFORM MATRIX AREA       */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_SLAVE_ROD_3]);
    glUseProgram(shaderProgramID);
    MATRIX_rotZ_SLAVE_ROD_3 = glm::rotate(glm::mat4x4(1.0f), radians(MODEL_SLAVE_ROD_3_Z_ROTATE_LOCATION), glm::vec3(0.0f, 0.0f, 1.0f));
    MATRIX_TRANSLATION_SLAVE_ROD_3 = glm::translate(glm::mat4x4(1.0f), glm::vec3(MODEL_SLAVE_ROD_3_X_LOCATION, MODEL_SLAVE_ROD_3_Y_LOCATION, 0.0f));
    MATRIX_MODEL_SLAVE_ROD_3 = MATRIX_MODEL_SLAVE_ROD_3_ORIGIN * MATRIX_TRANSLATION_SLAVE_ROD_3 *  MATRIX_rotZ_SLAVE_ROD_3;
    MATRIX_RotALL_SLAVE_ROD_3 = MATRIX_MODEL_SLAVE_ROD_3_ORIGIN;
    MATRIX_MVP_SLAVE_ROD_3 = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_SLAVE_ROD_3;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_SLAVE_ROD_3));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_SLAVE_ROD_3));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_SLAVE_ROD_3.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);

/********************************************************************/
/*     SLAVE_ROD4(SLAVE_ROD1.STL) MODEL TRANSFORM MATRIX AREA       */
/********************************************************************/
    glBindVertexArray(VertexArrayID[ARRAY_ADDR_SLAVE_ROD_4]);
    glUseProgram(shaderProgramID);
    MATRIX_rotZ_SLAVE_ROD_4 = glm::rotate(glm::mat4x4(1.0f), radians(MODEL_SLAVE_ROD_4_Z_ROTATE_LOCATION), glm::vec3(0.0f, 0.0f, 1.0f));
    MATRIX_TRANSLATION_SLAVE_ROD_4 = glm::translate(glm::mat4x4(1.0f), glm::vec3(MODEL_SLAVE_ROD_4_X_LOCATION, MODEL_SLAVE_ROD_4_Y_LOCATION, 0.0f));
    MATRIX_MODEL_SLAVE_ROD_4 = MATRIX_MODEL_SLAVE_ROD_4_ORIGIN * MATRIX_TRANSLATION_SLAVE_ROD_4 *  MATRIX_rotZ_SLAVE_ROD_4;
    MATRIX_RotALL_SLAVE_ROD_4 = MATRIX_MODEL_SLAVE_ROD_4_ORIGIN;
    MATRIX_MVP_SLAVE_ROD_4 = MATRIX_PROJECTION * MATRIX_VIEW * MATRIX_MODEL_SLAVE_ROD_4;

    glUniformMatrix4fv(MVPID, 1, GL_FALSE, glm::value_ptr(MATRIX_MVP_SLAVE_ROD_4));
	glUniformMatrix4fv(allRotsMatID, 1, GL_FALSE, glm::value_ptr(MATRIX_RotALL_SLAVE_ROD_4));
	glUniform4fv(lightID, 1, glm::value_ptr(light));
    glDrawElements(GL_TRIANGLES, MODEL_SLAVE_ROD_4.VERTEX_COUNT_FOR_DRAW, GL_UNSIGNED_INT, NULL);



	glutSwapBuffers();
}


/*********************************************************************************************/
/*                                 MAIN FUNCTION START                                       */
/*********************************************************************************************/
int main(int argc, char** argv) {
/********************************************************************/
/*                       LOCAL VARIABLE LIST                        */
/********************************************************************/
    unsigned char* VSS;
    unsigned char* FSS;
    unsigned int flength1 = 0;
    unsigned int flength2 = 0;
    unsigned int x_flength = 0;
/********************************************************************/
/*                    *.STL MODELING LOAD PHASE                     */
/********************************************************************/
    system("cls"); //CLEAR CONSOLE DISPLAY(windows.h)
    printf("******************************************************************\n");
	printf("*               Amylose openGL Example Program                   *\n");
    printf("*               FULL BUILD DATE : 2016-12-08 THU                 *\n");
    printf("*               HOMEWORK NUMBER : HW #03                         *\n");
    printf("*               VERSION : FIRST NUMBERING v0.3 ALPHA             *\n");
	printf("******************************************************************\n");
    printf("STATUS >>> INITIALIZE MODELING.....\n");

    printf("STATUS >>> 1ST MODELING FILE LOADING.....\n");
    MODEL_BASE = model_loader(1, "MODEL/BASE.STL", MODEL_BASE_COLOR_BASE);
    printf("STATUS >>> 2ND MODELING FILE LOADING.....\n");
    MODEL_CRANK_SHAFT = model_loader(1, "MODEL/CRANK_SHAFT.STL", MODEL_CRANK_SHAFT_COLOR_BASE);
    printf("STATUS >>> 3RD MODELING FILE LOADING.....\n");
    MODEL_MASTER_ROD = model_loader(1, "MODEL/MASTER_ROD.STL", MODEL_MASTER_ROD_COLOR_BASE);
    printf("STATUS >>> 4TH MODELING FILE LOADING.....\n");
    MODEL_PISTON1 = model_loader(1, "MODEL/PISTON1.STL", MODEL_PISTON1_COLOR_BASE);
    printf("STATUS >>> 5TH MODELING FILE LOADING.....\n");
    MODEL_PISTON2 = model_loader(1, "MODEL/PISTON1.STL", MODEL_PISTON1_COLOR_BASE);
    printf("STATUS >>> 6TH MODELING FILE LOADING.....\n");
    MODEL_PISTON3 = model_loader(1, "MODEL/PISTON1.STL", MODEL_PISTON1_COLOR_BASE);
    printf("STATUS >>> 7TH MODELING FILE LOADING.....\n");
    MODEL_PISTON4 = model_loader(1, "MODEL/PISTON1.STL", MODEL_PISTON1_COLOR_BASE);
    printf("STATUS >>> 8TH MODELING FILE LOADING.....\n");
    MODEL_PISTON5 = model_loader(1, "MODEL/PISTON1.STL", MODEL_PISTON1_COLOR_BASE);
    printf("STATUS >>> 9TH MODELING FILE LOADING.....\n");
    MODEL_SLAVE_ROD_1 = model_loader(1, "MODEL/SLAVE_ROD1.STL", MODEL_SLAVE_ROD_COLOR_BASE);
    printf("STATUS >>> 10TH MODELING FILE LOADING.....\n");
    MODEL_SLAVE_ROD_2 = model_loader(1, "MODEL/SLAVE_ROD1.STL", MODEL_SLAVE_ROD_COLOR_BASE);
    printf("STATUS >>> 11TH MODELING FILE LOADING.....\n");
    MODEL_SLAVE_ROD_3 = model_loader(1, "MODEL/SLAVE_ROD1.STL", MODEL_SLAVE_ROD_COLOR_BASE);
    printf("STATUS >>> 12TH MODELING FILE LOADING.....\n");
    MODEL_SLAVE_ROD_4 = model_loader(1, "MODEL/SLAVE_ROD1.STL", MODEL_SLAVE_ROD_COLOR_BASE);

    printf("STATUS >>> 1ST MODEL (BASE.STL) VERTEX [%6d]EA\n",MODEL_BASE.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 2ND MODEL (CRANK_SHAFT.STL) VERTEX [%6d]EA\n",MODEL_CRANK_SHAFT.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 3RD MODEL (MASTER_ROD.STL) VERTEX [%6d]EA\n",MODEL_MASTER_ROD.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 4TH MODEL (PISTON1 BY PISTON1.STL) VERTEX [%6d]EA\n",MODEL_PISTON1.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 5TH MODEL (PISTON2 BY PISTON1.STL) VERTEX [%6d]EA\n",MODEL_PISTON2.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 6TH MODEL (PISTON3 BY PISTON1.STL) VERTEX [%6d]EA\n",MODEL_PISTON3.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 7TH MODEL (PISTON4 BY PISTON1.STL) VERTEX [%6d]EA\n",MODEL_PISTON4.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 8TH MODEL (PISTON5 BY PISTON1.STL) VERTEX [%6d]EA\n",MODEL_PISTON5.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 9TH MODEL (SLAVE_ROD_1 BY SLAVE_ROD1.STL) VERTEX [%6d]EA\n",MODEL_SLAVE_ROD_1.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 10TH MODEL (SLAVE_ROD_2 BY SLAVE_ROD2.STL) VERTEX [%6d]EA\n",MODEL_SLAVE_ROD_2.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 11TH MODEL (SLAVE_ROD_3 BY SLAVE_ROD3.STL) VERTEX [%6d]EA\n",MODEL_SLAVE_ROD_3.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> 12TH MODEL (SLAVE_ROD_4 BY SLAVE_ROD4.STL) VERTEX [%6d]EA\n",MODEL_SLAVE_ROD_4.VERTEX_COUNT_FOR_DRAW);
    printf("STATUS >>> ALL MODELING FILE LOADING SUCCESS.....\n");

/********************************************************************/
/*                     OPENGL INITIALIZE PHASE                      */
/********************************************************************/
    printf("STATUS >>> \n\n\n");
    printf("STATUS >>> INITIALIZING openGL, GLUT, GLEW.....");
	glutInit(&argc, argv); //glut 함수 초기화 main함수의 가공되지 않은 data를 읽어들임.
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH); //glut 함수 초기화, Display모드 지정, GLUT_RGBA ->RGB모드를 사용
//															GLUT_INDEX -> 인덱스 색상모드
	glutInitWindowSize(800, 600); //glut 함수 초기화, 창의 크기를 지정.
	glutCreateWindow("openGL PROJECT by Amylose & LIN"); //glut창을 생성, 창의 이름을 정의
	glutReshapeFunc(changeViewport);
	if ( glewInit() != GLEW_OK ) {
		printf("\nSTATUS >>> ERROR : FAILED TO INITIALIZED GLEW");
		return 0;
	}
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
    printf("DONE.....\n");

/***************************************************************************/
/*           OPENGL GLSL SHADER SOURCE CODE LOAD & COMPILE PHASE           */
/***************************************************************************/
    printf("STATUS >>> INITIALIZING GLSL, SLCOMPILER, LINKER.....\n");
    flength1 = FileLengthCalc("SHADER/vertexShader.vsh");
    flength2 = FileLengthCalc("SHADER/fragmentShader.fsh");
    if ( (flength1 == NULL) || (flength2 == NULL) ) {
        printf("STATUS >>> FILE LENGTH CONFIRM FAIL\n");
        return 0;
    }
    else printf("STATUS >>> SHADER FILE LENGTH CALC SUCCESS.....\n");
    x_flength = xport_value(flength1, flength2);
    VSS = filereader("SHADER//vertexShader.vsh",x_flength);
    FSS = filereader("SHADER//fragmentShader.fsh",x_flength);
    if ((VSS == NULL) || (FSS == NULL)) {
        printf("STATUS >>> PROGRAM NOT READED\n");
        return 0;
    }
	else printf("STATUS >>> SHADER PROGRAM SOURCE LOAD SUCCESS.....\n");

	GLuint vertShaderID = makeVertexShader(VSS); //vertexShader컴파일 및 ID획득
	GLuint fragShaderID = makeFragmentShader(FSS); //fragmentShader컴파일 및 ID획득
	shaderProgramID = makeShaderProgram(vertShaderID, fragShaderID); //쉐이더들을 파이프라이닝 및 linking후 ID획득.

	if ( (vertShaderID != -1) || (fragShaderID != -1) || (shaderProgramID != -1) )
        printf("STATUS >>> SHADER PROGRAM BUILD SUCCESS.....\n");
    else {
        printf("STATUS >>> SHADER PROGRAM BUILD FAILED.....\n");
        printf("          vertex Shader ID is %d\n", vertShaderID); //vertexShaderID확인
        printf("          fragment Shader ID is %d\n", fragShaderID); //fragmentShaderID확인
        printf("          Program Shader ID is %d\n", shaderProgramID); //파이프라이닝 된 프로그램의 ID확인
        printf("STATUS >>> CONFIRM THE ADDRESS FOR PROBLEM SHADER CODE.....\n");
        return 0;
    }

/***************************************************************************/
/*           OPENGL GLSL SHADER SOURCE CODE LOAD & COMPILE PHASE           */
/***************************************************************************/
    PositionID = glGetAttribLocation(shaderProgramID, "s_vPosition");
	colorID = glGetAttribLocation(shaderProgramID, "s_vColor");
	normalID = glGetAttribLocation(shaderProgramID, "s_vNormal");
	lightID = glGetUniformLocation(shaderProgramID, "vLight");
	MVPID = glGetUniformLocation(shaderProgramID, "MVP");
	allRotsMatID = glGetUniformLocation(shaderProgramID, "mRotations");

/*********************************************************************************************/
/*               MODELING DATA IN CPU TO GPU FOR STREAM PROCESSING AREA START                */
/*********************************************************************************************/
/***************************************************************************/
/*             1ST MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//1ST MODELING = ENGINE_BASE
    printf("STATUS >>> UPLOADING TO GPU.....ENGINE BASE MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_ENGINE_BASE]); // 1ST MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_ENGINE_BASE]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_ENGINE_BASE]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_ENGINE_BASE]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_BASE.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_BASE.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_ENGINE_BASE]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_ENGINE_BASE]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_BASE.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_BASE.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_ENGINE_BASE]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_ENGINE_BASE]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_BASE.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_BASE.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_ENGINE_BASE]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_ENGINE_BASE]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_BASE.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_BASE.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*             2ND MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//2ND MODELING = CRANK_SHAFT
    printf("STATUS >>> UPLOADING TO GPU.....CRANK SHAFT MODELING DATA.....");
    glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_CRANK_SHAFT]); // 2ND MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_CRANK_SHAFT]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_CRANK_SHAFT]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_CRANK_SHAFT]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_CRANK_SHAFT.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_CRANK_SHAFT.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_CRANK_SHAFT]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_CRANK_SHAFT]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_CRANK_SHAFT.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_CRANK_SHAFT.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_CRANK_SHAFT]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_CRANK_SHAFT]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_CRANK_SHAFT.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_CRANK_SHAFT.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_CRANK_SHAFT]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_CRANK_SHAFT]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_CRANK_SHAFT.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_CRANK_SHAFT.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*             3RD MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//3RD MODELING = MASTER_ROD
    printf("STATUS >>> UPLOADING TO GPU.....MASTER ROD MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_MASTER_ROD]); // 3RD MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_MASTER_ROD]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_MASTER_ROD]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_MASTER_ROD]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_MASTER_ROD.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_MASTER_ROD.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_MASTER_ROD]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_MASTER_ROD]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_MASTER_ROD.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_MASTER_ROD.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_MASTER_ROD]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_MASTER_ROD]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_MASTER_ROD.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_MASTER_ROD.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_MASTER_ROD]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_MASTER_ROD]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_MASTER_ROD.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_MASTER_ROD.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*             4TH MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//4TH MODELING = PISTON 1
    printf("STATUS >>> UPLOADING TO GPU.....PISTON 1 MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_PISTON_1]); // 4TH MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_PISTON_1]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_PISTON_1]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_PISTON_1]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON1.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_PISTON1.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_PISTON_1]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_PISTON_1]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON1.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_PISTON1.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_PISTON_1]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_PISTON_1]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON1.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_PISTON1.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_PISTON_1]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_PISTON_1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_PISTON1.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_PISTON1.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*             5TH MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//5TH MODELING = PISTON 2
    printf("STATUS >>> UPLOADING TO GPU.....PISTON 2 MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_PISTON_2]); // 5TH MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_PISTON_2]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_PISTON_2]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_PISTON_2]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON2.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_PISTON2.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_PISTON_2]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_PISTON_2]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON2.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_PISTON2.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_PISTON_2]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_PISTON_2]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON2.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_PISTON2.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_PISTON_2]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_PISTON_2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_PISTON2.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_PISTON2.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*             6TH MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//6TH MODELING = PISTON 3
    printf("STATUS >>> UPLOADING TO GPU.....PISTON 3 MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_PISTON_3]); // 6TH MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_PISTON_3]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_PISTON_3]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_PISTON_3]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON3.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_PISTON3.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_PISTON_3]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_PISTON_3]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON3.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_PISTON3.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_PISTON_3]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_PISTON_3]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON3.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_PISTON3.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_PISTON_3]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_PISTON_3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_PISTON3.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_PISTON3.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*             7TH MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//7TH MODELING = PISTON 4
    printf("STATUS >>> UPLOADING TO GPU.....PISTON 4 MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_PISTON_4]); // 7TH MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_PISTON_4]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_PISTON_4]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_PISTON_4]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON4.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_PISTON4.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_PISTON_4]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_PISTON_4]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON4.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_PISTON4.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_PISTON_4]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_PISTON_4]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON4.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_PISTON4.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_PISTON_4]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_PISTON_4]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_PISTON4.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_PISTON4.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*             8TH MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//8TH MODELING = PISTON 5
    printf("STATUS >>> UPLOADING TO GPU.....PISTON 5 MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_PISTON_5]); // 8TH MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_PISTON_5]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_PISTON_5]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_PISTON_5]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON5.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_PISTON5.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_PISTON_5]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_PISTON_5]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON5.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_PISTON5.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_PISTON_5]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_PISTON_5]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_PISTON5.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_PISTON5.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_PISTON_5]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_PISTON_5]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_PISTON5.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_PISTON5.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*             9TH MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//9TH MODELING = SLAVE_ROD 1
    printf("STATUS >>> UPLOADING TO GPU.....SLAVE ROD 1 MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_SLAVE_ROD_1]); // 9TH MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_SLAVE_ROD_1]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_SLAVE_ROD_1]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_SLAVE_ROD_1]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_1.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_SLAVE_ROD_1.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_SLAVE_ROD_1]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_SLAVE_ROD_1]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_1.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_SLAVE_ROD_1.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_SLAVE_ROD_1]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_SLAVE_ROD_1]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_1.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_SLAVE_ROD_1.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_SLAVE_ROD_1]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_SLAVE_ROD_1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_SLAVE_ROD_1.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_SLAVE_ROD_1.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*            10TH MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//10TH MODELING = SLAVE_ROD 2
    printf("STATUS >>> UPLOADING TO GPU.....SLAVE ROD 2 MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_SLAVE_ROD_2]); // 10TH MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_SLAVE_ROD_2]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_SLAVE_ROD_2]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_SLAVE_ROD_2]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_2.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_SLAVE_ROD_2.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_SLAVE_ROD_2]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_SLAVE_ROD_2]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_2.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_SLAVE_ROD_2.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_SLAVE_ROD_2]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_SLAVE_ROD_2]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_2.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_SLAVE_ROD_2.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_SLAVE_ROD_2]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_SLAVE_ROD_2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_SLAVE_ROD_2.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_SLAVE_ROD_2.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*            11TH MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//11TH MODELING = SLAVE_ROD 3
    printf("STATUS >>> UPLOADING TO GPU.....SLAVE ROD 3 MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_SLAVE_ROD_3]); // 11TH MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_SLAVE_ROD_3]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_SLAVE_ROD_3]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_SLAVE_ROD_3]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_3.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_SLAVE_ROD_3.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_SLAVE_ROD_3]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_SLAVE_ROD_3]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_3.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_SLAVE_ROD_3.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_SLAVE_ROD_3]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_SLAVE_ROD_3]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_3.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_SLAVE_ROD_3.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_SLAVE_ROD_3]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_SLAVE_ROD_3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_SLAVE_ROD_3.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_SLAVE_ROD_3.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/***************************************************************************/
/*            12TH MODELING DATA TO GPU TRANSLATE CODE START               */
/***************************************************************************/
//12TH MODELING = SLAVE_ROD 4
    printf("STATUS >>> UPLOADING TO GPU.....SLAVE ROD 4 MODELING DATA.....");
	glGenVertexArrays(1, &VertexArrayID[ARRAY_ADDR_SLAVE_ROD_4]); // 12TH MODELING VERTEX ARRAY
	glBindVertexArray(VertexArrayID[ARRAY_ADDR_SLAVE_ROD_4]);

	glGenBuffers(1, &vertexBuffer[ARRAY_ADDR_SLAVE_ROD_4]);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer[ARRAY_ADDR_SLAVE_ROD_4]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_4.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_SLAVE_ROD_4.VERTEX_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(PositionID);
	glVertexAttribPointer(PositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &colorBuffer[ARRAY_ADDR_SLAVE_ROD_4]);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer[ARRAY_ADDR_SLAVE_ROD_4]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_4.VERTEX_COUNT_FOR_DRAW*4*sizeof(GLfloat), MODEL_SLAVE_ROD_4.COLOR_VECTOR, GL_STATIC_DRAW);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &normalBuffer[ARRAY_ADDR_SLAVE_ROD_4]);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[ARRAY_ADDR_SLAVE_ROD_4]);
	glBufferData(GL_ARRAY_BUFFER, MODEL_SLAVE_ROD_4.VERTEX_COUNT_FOR_DRAW*3*sizeof(GLfloat), MODEL_SLAVE_ROD_4.NORMAL_VECTOR, GL_STATIC_DRAW);
    glEnableVertexAttribArray(normalID);
	glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &indexBuffer[ARRAY_ADDR_SLAVE_ROD_4]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[ARRAY_ADDR_SLAVE_ROD_4]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, MODEL_SLAVE_ROD_4.VERTEX_COUNT_FOR_DRAW*sizeof(GLuint), MODEL_SLAVE_ROD_4.INDEX, GL_STATIC_DRAW);
    printf("DONE.....\n");

/*******************************************************************************************/
/*               MODELING DATA IN CPU TO GPU FOR STREAM PROCESSING AREA END                */
/*******************************************************************************************/
/***************************************************************************/
/*                  DISPLAYING AND LOOP FUNCTION PHASE                     */
/***************************************************************************/
	printf("STATUS >>> VIEW MODEL DATA\n");
    glutDisplayFunc(render);
    glutSpecialFunc(SpecialKeyboard);
    glutKeyboardFunc(DoKeyboard);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
    glutTimerFunc(ANIMATION_DISPLAY_PERIOD, AnimationTimer, 1);
    glutEntryFunc(MouseActivatonConfirm);
    glutMouseFunc(MouseButtonActivationConfirm);
    glutMotionFunc(MouseMotionConfirm);

    glutMainLoop();


/***************************************************************************/
/*               RELEASE MEMORY SPACE FOR PROGRAM CLOSING                  */
/***************************************************************************/
	glDeleteBuffers(1, &vertexBuffer[ARRAY_ADDR_ENGINE_BASE]); glDeleteBuffers(1, &colorBuffer[ARRAY_ADDR_ENGINE_BASE]);
    glDeleteBuffers(1, &normalBuffer[ARRAY_ADDR_ENGINE_BASE]);glDeleteBuffers(1, &indexBuffer[ARRAY_ADDR_ENGINE_BASE]);
    glDeleteVertexArrays(1, &VertexArrayID[ARRAY_ADDR_ENGINE_BASE]);

	glDeleteBuffers(1, &vertexBuffer[ARRAY_ADDR_CRANK_SHAFT]); glDeleteBuffers(1, &colorBuffer[ARRAY_ADDR_CRANK_SHAFT]);
    glDeleteBuffers(1, &normalBuffer[ARRAY_ADDR_CRANK_SHAFT]);glDeleteBuffers(1, &indexBuffer[ARRAY_ADDR_CRANK_SHAFT]);
    glDeleteVertexArrays(1, &VertexArrayID[ARRAY_ADDR_CRANK_SHAFT]);

	glDeleteBuffers(1, &vertexBuffer[ARRAY_ADDR_MASTER_ROD]); glDeleteBuffers(1, &colorBuffer[ARRAY_ADDR_MASTER_ROD]);
    glDeleteBuffers(1, &normalBuffer[ARRAY_ADDR_MASTER_ROD]);glDeleteBuffers(1, &indexBuffer[ARRAY_ADDR_MASTER_ROD]);
    glDeleteVertexArrays(1, &VertexArrayID[ARRAY_ADDR_MASTER_ROD]);

	glDeleteBuffers(1, &vertexBuffer[ARRAY_ADDR_PISTON_1]); glDeleteBuffers(1, &colorBuffer[ARRAY_ADDR_PISTON_1]);
    glDeleteBuffers(1, &normalBuffer[ARRAY_ADDR_PISTON_1]);glDeleteBuffers(1, &indexBuffer[ARRAY_ADDR_PISTON_1]);
    glDeleteVertexArrays(1, &VertexArrayID[ARRAY_ADDR_PISTON_1]);

	glDeleteBuffers(1, &vertexBuffer[ARRAY_ADDR_PISTON_2]); glDeleteBuffers(1, &colorBuffer[ARRAY_ADDR_PISTON_2]);
    glDeleteBuffers(1, &normalBuffer[ARRAY_ADDR_PISTON_2]);glDeleteBuffers(1, &indexBuffer[ARRAY_ADDR_PISTON_2]);
    glDeleteVertexArrays(1, &VertexArrayID[ARRAY_ADDR_PISTON_2]);

	glDeleteBuffers(1, &vertexBuffer[ARRAY_ADDR_PISTON_3]); glDeleteBuffers(1, &colorBuffer[ARRAY_ADDR_PISTON_3]);
    glDeleteBuffers(1, &normalBuffer[ARRAY_ADDR_PISTON_3]);glDeleteBuffers(1, &indexBuffer[ARRAY_ADDR_PISTON_3]);
    glDeleteVertexArrays(1, &VertexArrayID[ARRAY_ADDR_PISTON_3]);

	glDeleteBuffers(1, &vertexBuffer[ARRAY_ADDR_PISTON_4]); glDeleteBuffers(1, &colorBuffer[ARRAY_ADDR_PISTON_4]);
    glDeleteBuffers(1, &normalBuffer[ARRAY_ADDR_PISTON_4]);glDeleteBuffers(1, &indexBuffer[ARRAY_ADDR_PISTON_4]);
    glDeleteVertexArrays(1, &VertexArrayID[ARRAY_ADDR_PISTON_4]);

	glDeleteBuffers(1, &vertexBuffer[ARRAY_ADDR_PISTON_5]); glDeleteBuffers(1, &colorBuffer[ARRAY_ADDR_PISTON_5]);
    glDeleteBuffers(1, &normalBuffer[ARRAY_ADDR_PISTON_5]);glDeleteBuffers(1, &indexBuffer[ARRAY_ADDR_PISTON_5]);
    glDeleteVertexArrays(1, &VertexArrayID[ARRAY_ADDR_PISTON_5]);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDeleteProgram(shaderProgramID);

	printf("STATUS >>> Program is CLOSED\n");
	return 0;
}

/***************************************************************************/
/*                         MAIN SOURCE CODE END                            */
/***************************************************************************/
