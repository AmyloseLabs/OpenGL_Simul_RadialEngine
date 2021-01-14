/****************************************************************************/
/*                   Amylose Opengl Program #3                              */
/*                   DATE : 2016-11-13                                      */
/*      SOURCE TYPE : EXTERNAL_FILE_LOADER.CPP(USING EXTERNAL_FILE_LOADER.h)*/
/*      CONTAINED USER EXTERNAL_FILE_LOADER FUNCTION LIST                   */
/****************************************************************************/
/*********************************************************************************************/
/*                                  REFERENCE HEADER LIST                                    */
/*********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <GL/freeglut.h>
#include <string.h>

/*********************************************************************************************/
/*                                     USER HEADER LIST                                      */
/*********************************************************************************************/
#include "EXTERNAL_FILE_LOADER.hpp"

/*********************************************************************************************/
/*                         USER EXTERNAL UTILITY FUNCTION LIST                               */
/*********************************************************************************************/
/********************************************************************/
/*          SHADER SOURCE FILE LENGTH CALCULATION FUNCTION          */
/********************************************************************/
unsigned int FileLengthCalc(const char* fname) {
     unsigned int flength ;
     FILE *lfile = NULL;
     if ( (lfile = fopen(fname,"r") ) == NULL ) return NULL;
     fseek(lfile, 0, SEEK_END);
     flength = ftell(lfile);
     fseek(lfile, 0, SEEK_SET);
     if ( lfile != NULL ) {
          fclose(lfile);
          lfile = NULL;
     }
     return flength;
}

/********************************************************************/
/*                SHADER SOURCE FILE READER FUNCTION                */
/********************************************************************/
unsigned char* filereader(char* filename, unsigned int flength) {
     FILE *rfile  = NULL;
     if ( (rfile = fopen(filename, "r") ) == NULL ) return NULL;
     else {
          unsigned char* data = NULL;
          data = (unsigned char*)calloc((flength+2),sizeof(unsigned char));
          fread(data, flength, 1, rfile);
          data[flength+1] = '\0';
          if ( rfile != NULL ) {
               fclose(rfile);
               rfile = NULL;
          }
          return data;
     }
}

/********************************************************************/
/*                  CONFIGURE FILE LENGTH FUNCTION                  */
/********************************************************************/
unsigned int xport_value(unsigned int a, unsigned int b) {
     unsigned int xport = 0;
     if ( a > b) xport = a;
     else xport =b;
     return xport;
}

/********************************************************************/
/*            STL MODELING FILE READER VER 0.10 ALPHA               */
/*            ONLY CONFIRMED SOLIDWORKS EXPORT STL DATA             */
/********************************************************************/
MODEL_P model_loader(int PROGRAM_MODE, char* MODEL_FILENAME, GLfloat COLOR_BASE[]) {
    printf("     **********************************************************\n");
    printf("     *                 STL MODELING FILE LOADER               *\n");
    printf("     *                 VERSION : 0.20 ALPHA                   *\n");
    printf("     **********************************************************\n");
	char TEMP_BUFFER[1024];
	char DEBUG_TEMP_BUFFER[1024];
	char DEBUG_CONFIG1[10];
	char DEBUG_CONFIG2[10];
	char CONFIG_OUTER[] = {"outer"};
	char CONFIG_LOOP[] = {"loop"};
	char CONFIG_ENDLOOP[] = {"endloop"};
	char CONFIG_ENDFACET[] = {"endfacet"};
	char CONFIG_ENDSOLID[] = {"endsolid"};
	unsigned int TEMP_BUFFER_LENGTH;
	long int FILE_POINTER_LOCATION = 0;
	long int FACET_COUNT = 0;
	long int FILE_LINE = 0;
	long int DEBUG_FILE_LINE = 0;
	int i_shift = 0;
	int j_shift = 0;
	FILE *MODEL_FILE;
	GLfloat *TEMP_NORMAL;
	GLfloat *TEMP_VERTEX;
	GLuint VERTEX_NUMBER_FOR_DRAW = 0;
	MODEL_P MODEL;
    printf("     STATUS >>> FILE : [%12s] OPEN.....",MODEL_FILENAME);
	if( (MODEL_FILE = fopen(MODEL_FILENAME,"r")) == NULL ) {
		printf("\n     STATUS >>> [ERROR] FILE : [%12s] OPEN FAILED.....\n",MODEL_FILENAME);
		printf("     STATUS >>> PROGRAM COLOSED.....\n");
		exit(0);
	}
    else printf("     SUCCESS DONE.....\n");
	while( feof(MODEL_FILE) == 0 ) {
        FILE_LINE++;
		fgets(TEMP_BUFFER, 1024, MODEL_FILE);
		TEMP_BUFFER_LENGTH = strlen(TEMP_BUFFER);
	}

    for ( ;; ) {
        FILE_POINTER_LOCATION = ftell(MODEL_FILE);
        if( FILE_POINTER_LOCATION != 0 ) {
            fseek(MODEL_FILE, 0, 0);
            break;
        }
    }
    FILE_LINE = FILE_LINE - 1;
	printf("     STATUS >>> FILE : [%12s] LINE COUNTING.....\n",MODEL_FILENAME);
	printf("     STATUS >>> LINE : [%d] COUNTED.....\n",FILE_LINE);
	FACET_COUNT = (FILE_LINE - 2) / 7;
	printf("     STATUS >>> FACET : [%d] COUNTED.....\n", FACET_COUNT);
	DEBUG_FILE_LINE++;
	if( fscanf(MODEL_FILE, "solid %s\n", TEMP_BUFFER) != 1) {
        printf("     STATUS >>> [ERROR] FILE : [%12s] FAIL TO READ MODELING DATA.....\n",MODEL_FILENAME);
        fgets(DEBUG_TEMP_BUFFER, 1024, MODEL_FILE);
        printf("          ERROR LINE >>>[%5d][%5d facet left] %s",DEBUG_FILE_LINE ,FACET_COUNT ,DEBUG_TEMP_BUFFER);
        printf("     STATUS >>> PROGRAM COLOSED.....\n");
        exit(0);
	}

	TEMP_NORMAL = (GLfloat*)calloc((FACET_COUNT*9),sizeof(GLfloat));
	TEMP_VERTEX = (GLfloat*)calloc((FACET_COUNT*9),sizeof(GLfloat));

	for(long int TEMP_i = 0 ; TEMP_i < FACET_COUNT ;++TEMP_i) {
        if( strnicmp(DEBUG_CONFIG1,CONFIG_ENDSOLID,8) == 0 ){
                break;
        }
        DEBUG_CONFIG1[10] = '\0';
        if( PROGRAM_MODE == 0 ) {
            DEBUG_FILE_LINE++;
            if(fscanf(MODEL_FILE, "   facet normal %f %f %f\n", &TEMP_NORMAL[i_shift], &TEMP_NORMAL[i_shift+1], &TEMP_NORMAL[i_shift+2]) != 3) {
                printf("     STATUS >>> [ERROR] FAILED TO READ FACET NORMAL.....\n");
                fgets(DEBUG_TEMP_BUFFER, 1024, MODEL_FILE);
                printf("          ERROR LINE >>>[%5d][%5d facet left] %s",DEBUG_FILE_LINE ,TEMP_i ,DEBUG_TEMP_BUFFER);
                printf("     STATUS >>> PROGRAM COLOSED.....\n");
                exit(0);
            }
        }
        else if ( PROGRAM_MODE == 1 ) {
            DEBUG_FILE_LINE++;
            if(fscanf(MODEL_FILE, "  facet normal %f %f %f\n", &TEMP_NORMAL[i_shift], &TEMP_NORMAL[i_shift+1], &TEMP_NORMAL[i_shift+2]) != 3) {
                printf("     STATUS >>> [ERROR] FAILED TO READ FACET NORMAL.....\n");
                fgets(DEBUG_TEMP_BUFFER, 1024, MODEL_FILE);
                printf("          ERROR LINE >>>[%5d][%5d facet left] %s",DEBUG_FILE_LINE ,TEMP_i ,DEBUG_TEMP_BUFFER);
                printf("     STATUS >>> PROGRAM COLOSED.....\n");
                exit(0);
            }
        }
		TEMP_NORMAL[i_shift+3] = TEMP_NORMAL[i_shift]; TEMP_NORMAL[i_shift+6] = TEMP_NORMAL[i_shift];
		TEMP_NORMAL[i_shift+4] = TEMP_NORMAL[i_shift+1]; TEMP_NORMAL[i_shift+7] = TEMP_NORMAL[i_shift+1];
		TEMP_NORMAL[i_shift+5] = TEMP_NORMAL[i_shift+2]; TEMP_NORMAL[i_shift+8] = TEMP_NORMAL[i_shift+2];
		i_shift = i_shift + 9;

		if ( PROGRAM_MODE == 0 ) {
		    DEBUG_FILE_LINE++;
            fscanf(MODEL_FILE, "      %s %s",DEBUG_CONFIG1, DEBUG_CONFIG2);
                if ( (strnicmp(DEBUG_CONFIG1,CONFIG_OUTER,5) != 0) || (strnicmp(DEBUG_CONFIG2,CONFIG_LOOP,4) != 0) ) {
                    printf("     STATUS >>> [ERROR] FAIL TO READ [outer loop]\n");
                    printf("          ERROR LINE >>>[%5d][%5d facet left] %s %s\n",DEBUG_FILE_LINE ,TEMP_i ,DEBUG_CONFIG1, DEBUG_CONFIG2);
                    printf("     STATUS >>> PROGRAM COLOSED.....\n");
                    exit(0);
            }
            DEBUG_CONFIG1[10] = '\0';
            DEBUG_CONFIG2[10] = '\0';
            for(int TEMP_j = 0 ; TEMP_j < 3 ; ++TEMP_j) {
                DEBUG_FILE_LINE++;
                if(fscanf(MODEL_FILE, "         vertex %f %f %f\n", &TEMP_VERTEX[j_shift], &TEMP_VERTEX[j_shift+1], &TEMP_VERTEX[j_shift+2]) != 3) {
                    printf("     STATUS >>> FAILED TO READ [vertex]\n");
                    fgets(DEBUG_TEMP_BUFFER, 1024, MODEL_FILE);
                    printf("          ERROR LINE >>>[%5d][%5d facet left] %s",DEBUG_FILE_LINE ,TEMP_i ,DEBUG_TEMP_BUFFER);
                    printf("     STATUS >>> PROGRAM COLOSED.....\n");
                    exit(0);
                }
                j_shift = j_shift + 3;
            }

            DEBUG_FILE_LINE++;
            fscanf(MODEL_FILE, "      %s",DEBUG_CONFIG1);
            if ( strnicmp(DEBUG_CONFIG1, CONFIG_ENDLOOP, 7) != 0 ) {
                printf("     STATUS >>> FAILED TO READ [endloop]\n");
                printf("          ERROR LINE >>>[%5d][%5d facet left] %s\n",DEBUG_FILE_LINE ,TEMP_i ,DEBUG_CONFIG1);
                printf("     STATUS >>> PROGRAM COLOSED.....\n");
                exit(0);
            }
            DEBUG_CONFIG1[10] = '\0';

            DEBUG_FILE_LINE++;
            fscanf(MODEL_FILE, "   %s",DEBUG_CONFIG1);
            if( strnicmp(DEBUG_CONFIG1, CONFIG_ENDFACET, 8) !=0 ) {
                printf("     STATUS >>> FAILED TO READ [endfacet]\n");
                printf("          ERROR LINE >>>[%5d][%5d facet left] %s\n",DEBUG_FILE_LINE ,TEMP_i ,DEBUG_CONFIG1);
                printf("     STATUS >>> PROGRAM COLOSED.....\n");
                exit(0);
            }
            DEBUG_CONFIG1[10] = '\0';
            fscanf(MODEL_FILE,"%s",DEBUG_CONFIG1);
		}

		else if ( PROGRAM_MODE == 1 ) {
            DEBUG_FILE_LINE++;
            fscanf(MODEL_FILE, "    %s %s",DEBUG_CONFIG1, DEBUG_CONFIG2);
                if ( (strnicmp(DEBUG_CONFIG1,CONFIG_OUTER,5) != 0) || (strnicmp(DEBUG_CONFIG2,CONFIG_LOOP,4) != 0) ) {
                    printf("     STATUS >>> [ERROR] FAIL TO READ [outer loop]\n");
                    printf("          ERROR LINE >>>[%5d][%5d facet left] %s %s\n",DEBUG_FILE_LINE ,TEMP_i ,DEBUG_CONFIG1, DEBUG_CONFIG2);
                    printf("     STATUS >>> PROGRAM COLOSED.....\n");
                    exit(0);
            }
            DEBUG_CONFIG1[10] = '\0';
            DEBUG_CONFIG2[10] = '\0';
            for(int TEMP_j = 0 ; TEMP_j < 3 ; ++TEMP_j) {
                DEBUG_FILE_LINE++;
                if(fscanf(MODEL_FILE, "      vertex   %f %f %f\n", &TEMP_VERTEX[j_shift], &TEMP_VERTEX[j_shift+1], &TEMP_VERTEX[j_shift+2]) != 3) {
                    printf("     STATUS >>> FAILED TO READ [vertex]\n");
                    fgets(DEBUG_TEMP_BUFFER, 1024, MODEL_FILE);
                    printf("          ERROR LINE >>>[%5d][%5d facet left] %s",DEBUG_FILE_LINE ,TEMP_i ,DEBUG_TEMP_BUFFER);
                    printf("     STATUS >>> PROGRAM COLOSED.....\n");
                    exit(0);
                }
                j_shift = j_shift + 3;
            }

            DEBUG_FILE_LINE++;
            fscanf(MODEL_FILE, "    %s",DEBUG_CONFIG1);
            if ( strnicmp(DEBUG_CONFIG1, CONFIG_ENDLOOP, 7) != 0 ) {
                printf("     STATUS >>> FAILED TO READ [endloop]\n");
                printf("          ERROR LINE >>>[%5d][%5d facet left] %s\n",DEBUG_FILE_LINE ,TEMP_i ,DEBUG_CONFIG1);
                printf("     STATUS >>> PROGRAM COLOSED.....\n");
                exit(0);
            }
            DEBUG_CONFIG1[10] = '\0';

            DEBUG_FILE_LINE++;
            fscanf(MODEL_FILE, "  %s",DEBUG_CONFIG1);
            if( strnicmp(DEBUG_CONFIG1, CONFIG_ENDFACET, 8) !=0 ) {
                printf("     STATUS >>> FAILED TO READ [endfacet]\n");
                printf("          ERROR LINE >>>[%5d][%5d facet left] %s\n",DEBUG_FILE_LINE ,TEMP_i ,DEBUG_CONFIG1);
                printf("     STATUS >>> PROGRAM COLOSED.....\n");
                exit(0);
            }
            DEBUG_CONFIG1[10] = '\0';
		}

	}
	MODEL.NORMAL_VECTOR = (GLfloat*)calloc((FACET_COUNT*9), sizeof(GLfloat));
	MODEL.VERTEX_VECTOR = (GLfloat*)calloc((FACET_COUNT*9), sizeof(GLfloat));
	MODEL.COLOR_VECTOR = (GLfloat*)calloc((FACET_COUNT*12), sizeof(GLfloat));
	MODEL.INDEX = (GLuint*)calloc((FACET_COUNT*3), sizeof(GLuint));
	for(int TEMP_i=0; TEMP_i<(FACET_COUNT*3); ++TEMP_i) {
        MODEL.INDEX[TEMP_i] = TEMP_i;
	}
	i_shift = 0;
	for(int TEMP_i = 0; TEMP_i<(3*FACET_COUNT); ++TEMP_i) {
        MODEL.COLOR_VECTOR[i_shift] = COLOR_BASE[0]; MODEL.COLOR_VECTOR[i_shift+1] = COLOR_BASE[1]; MODEL.COLOR_VECTOR[i_shift+2] = COLOR_BASE[2];
        MODEL.COLOR_VECTOR[i_shift+3] = COLOR_BASE[3];
        i_shift = i_shift + 4;
	}

	for(int TEMP_i = 0; TEMP_i<(FACET_COUNT*9);++TEMP_i) {
        MODEL.NORMAL_VECTOR[TEMP_i] = TEMP_NORMAL[TEMP_i];
        MODEL.VERTEX_VECTOR[TEMP_i] = TEMP_VERTEX[TEMP_i];
	}
	free(TEMP_NORMAL); free(TEMP_VERTEX);
    fclose(MODEL_FILE);
    VERTEX_NUMBER_FOR_DRAW = FACET_COUNT*3;
    MODEL.VERTEX_COUNT_FOR_DRAW = VERTEX_NUMBER_FOR_DRAW;
    printf("     STATUS >>> FILE : [%12s] LOAD SUCCESS.....\n",MODEL_FILENAME);
    return MODEL;
}
/***************************************************************************/
/*                 EXTERNAL_FILE_LOADER.CPP SOURCE CODE END                */
/***************************************************************************/
