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
void feature2(FILE *fin, FILE *fout){
    char* buf = (char *)calloc(_MAX_LONG,sizeof(char));
    char* tmp = (char *)calloc(1,sizeof(char));
    fgets(buf,_MAX_LONG,fin);
    buf = strtok (buf,"\n");
    int lng = strlen(buf);
    for(int iz=0; iz < (lng/2);iz++){
        *tmp = buf[iz];
        buf[iz] = buf[lng - iz -1];
        buf[lng - iz -1] = *tmp;
    }
    fprintf(fout,"%s\n",buf);
    free(buf);
    free(tmp);
}
void feature3(FILE *fin, FILE *fout){
    char* buf = (char *)calloc(_MAX_LONG,sizeof(char));
    char* tmp = (char* )calloc(4,sizeof(char));
    char* bsh;
    short* number = (short *)calloc(_MAX_LONG,sizeof(short));
    short i=0;
    int sum=0;
    fgets(buf,_MAX_LONG,fin);
    tmp =strtok(buf," ");
    while(tmp != NULL){
        number[i] = strtol(tmp,&bsh,10);
        sum = sum + number[i];
        tmp = strtok(NULL," ");
        i++;
    }
    fprintf(fout,"%d\n",sum);
    free(number);
    free(tmp);
    free(buf);
    free(bsh);

}
void feature4(FILE *fin, int **parr, int *length, char **op){}
void feature5(FILE *fout, int *parr, int length, char *op){}
void feature6(FILE *fin, struct Obj_t *pobj){}
void feature7(FILE *fout, struct Obj_t *pobj){}
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length){}
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length){}