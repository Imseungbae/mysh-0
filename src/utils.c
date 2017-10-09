#include <stdlib.h>
#include <string.h>
#include "utils.h"




void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
 int count=0;
 char* result;
 char str[20];
 *argc =0;
 char* tok=" \n\t";


 strcpy(str,command);
 *argv=(char**)malloc(sizeof(char*)*20);
 (*argv)[count]=(char*)malloc(sizeof(char)*20);
 
 result=strtok(str,tok);
 if(result==NULL){
 strcpy((*argv)[count]," ");
 *argc=1;
 return;
 }

 while(result!=NULL){
 strcpy((*argv)[count],result);
 count++;
 (*argv)[count]=(char*)malloc(sizeof(char)*20);
 result=strtok(NULL,tok);
 *(argc)++;
 }
}













