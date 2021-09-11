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
void feature4(FILE *fin, int **parr, int *length, char **op){
    char* buf = (char *)calloc(_MAX_LONG,sizeof(char));
    char* tmp = (char *)calloc(4,sizeof(char));
    *parr = (int *)calloc(_MAX_LONG,sizeof(int));
    char* bsh = (char *)calloc(_MAX_LONG,sizeof(char));
    *op = (char *)calloc(4,sizeof(char));
    int i =0;
    fgets(buf,_MAX_LONG,fin);
    tmp = strtok(buf," ");
    while(tmp != NULL){
        (*parr)[i] = strtol(tmp,&bsh,10);
        tmp = strtok(NULL," ");
        i++;
    }
    strncpy(*op,bsh,3);
    *length = i;
    free(buf);
    free(tmp);
}
void feature5(FILE *fout, int *parr, int length, char *op){
    if(strcmp(op,"avg")==0){
        int sum =0;
        for(short i=0;i <length-1;i++){
            sum = sum +parr[i];
        }
        fprintf(fout,"%d\n",sum/(length-1));
    }else if(strcmp(op,"min")==0){
        int min = 5000;
        for(short i=0;i <length-1;i++){
            if(parr[i] < min){
                min = parr[i];
            }
        }
        fprintf(fout,"%d\n",min);
    }else if(strcmp(op,"max")==0){
        int max = -5000;
        for(short i=0;i <length-1;i++){
            if(parr[i] < max){
                max = parr[i];
            }
        }
        fprintf(fout,"%d\n",max);
    }
}
void feature6(FILE *fin, struct Obj_t *pobj){
    char* buf = (char *)calloc(_MAX_LONG,sizeof(char));
    char* name = (char *)calloc(_MAX_LONG,sizeof(char));
    int id=0;
    pobj->nombre = (char *)calloc(_MAX_LONG,sizeof(char));
    char* bsh;
    fgets(buf,_MAX_LONG,fin);
    name = strtok(buf,",");
    id = strtol(strtok(NULL,","),&bsh,10);
    strcpy(pobj->nombre,name);
    pobj->cedula = id;
    free(buf);
}
void feature7(FILE *fout, struct Obj_t *pobj){
    fprintf(fout,"%d, %s",pobj->cedula, pobj->nombre);
    free(pobj->nombre);
}
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length){
    char* buf = (char *)calloc(_MAX_LONG,sizeof(char));
    int N=0, j=0;
    char *bsh, *tmp;
    fgets(buf,_MAX_LONG,fin);
    N = strtol(buf,&bsh,10);
    struct _courseInfo_t *parr = (struct _courseInfo_t *)calloc(N,sizeof(struct _courseInfo_t));
    printf("Ingresa la Info del Curso\nNombre,Credito,Nota\n");
    for(int i=0;i<N;i++){
        j=0;
        printf("Curso %d: ",i+1);
        fgets(buf,_MAX_LONG,stdin);
        tmp = strtok(buf,",");
        while(tmp != NULL){
            if(j==0){
                strcpy(parr[i].name,tmp);
            }else if(j==1){
                parr[i].credits = strtol(tmp,&bsh,10);
            }else if(j==2){
                parr[i].grade = strtof(tmp,&bsh);
            }
            j++;
            tmp = strtok(NULL,",");
        }
    }
    *pobj = parr;
    *length = N;
    free(buf);
    fclose(fin);
}
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length){}