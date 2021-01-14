/****************************************************************************/
/*                   Amylose Opengl Program #3                              */
/*                   DATE : 2016-11-13                                      */
/*              SOURCE TYPE : EXTERNAL_FILE_LOADER.H (HEADER)               */
/*              CONTAINED EXTERNAL_FILE_LOADER FUNCTION LIST                */
/*              DETAILED SOURCE DATA IS IN EXTERNAL_FILE_LOADER.CPP         */
/****************************************************************************/
/*********************************************************************************************/
/*                        STRUCTURE TO STORAGE OF MODEL PROPERTY                             */
/*********************************************************************************************/
typedef struct MODEL_PROPERTY {
    GLfloat* NORMAL_VECTOR;
    GLfloat* VERTEX_VECTOR;
    GLfloat* COLOR_VECTOR;
    GLuint* INDEX;
    GLuint VERTEX_COUNT_FOR_DRAW;
}MODEL_P;

/*********************************************************************************************/
/*                         USER EXTERNAL UTILITY FUNCTION LIST                               */
/*********************************************************************************************/
unsigned int FileLengthCalc(const char* fname); //SHADER SOURCE FILE LENGTH CALCULATION FUNCTION
unsigned char* filereader(char* filename, unsigned int flength); //SHADER SOURCE FILE READER FUNCTION
unsigned int xport_value(unsigned int a, unsigned int b); //CONFIGURE FILE LENGTH FUNCTION
MODEL_P model_loader(int PROGRAM_MODE, char* MODEL_FILENAME, GLfloat COLOR_BASE[]); //STL MODELING FILE READER VER 0.20 ALPHA
                                                                                   //UG NX & SOLIDWORKS EXPORT STL DATA


/***************************************************************************/
/*                      UTILITY.H SOURCE CODE END                          */
/***************************************************************************/
