#include "utils.h"
#include "stdlib.h"
#include "string.h"
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
 int cur=0;
 int count=0;
 char str[20];
 char* temp;
 char* commandsave;
 argc=&count; 
 strcpy(str,command);
 strcpy(commandsave,str);

 temp=strtok(str," ");
 while(temp!=NULL){
 count++;
 temp=strtok(NULL," ");
 }
 strcpy(str,commandsave); 
 temp=NULL;

 argv=(char***)malloc(sizeof(char*)*count);
 
 for(int i=0; i<count; i++){
 argv[i]=(char**)malloc(sizeof(char*));
 } 
 for(int i=0; i<count; i++){
 argv[i][0]=(char*)malloc(sizeof(char*)*10);
 }
 
 temp=strtok(str," ");
 while(temp!=NULL){
 strcpy(argv[cur][0],temp);
 cur++;
 temp=strtok(NULL," ");
 }
}
