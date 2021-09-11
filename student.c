#define _MAX_LONG 200
#include <stdlib.h>
#include "student.h"
#include <string.h>

void feature1(FILE *fin, FILE *fout){
    char* buf = (char *)calloc(_MAX_LONG,sizeof(char));
    fgets(buf,_MAX_LONG,fin);
    fprintf(fout,"%s",buf);
    free(buf);
}
void feature2(FILE *fin, FILE *fout){}
void feature3(FILE *fin, FILE *fout){}
void feature4(FILE *fin, int **parr, int *length, char **op){}
void feature5(FILE *fout, int *parr, int length, char *op){}
void feature6(FILE *fin, struct Obj_t *pobj){}
void feature7(FILE *fout, struct Obj_t *pobj){}
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length){}
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length){}