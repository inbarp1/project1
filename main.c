#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

char ** parse_args( char * line ){
  char ** args = (char**)calloc(6,sizeof(char*));
  char *s1 = line;
  int i = 0;
  while(s1){
    args[i] = strsep( &s1, " ");
    i++;
  }
  return args;
}

//prints the prompt
void prompt(){
  char commandz[1024];
  getcwd(commandz, 1024);
  printf("current dir: %s\n", commandz);
}

//copies input into given buffer
void bufferz( char * buff ){
  char * buffer = calloc(1024,sizeof(char));
  fgets(buffer, 1024, stdin);
  int i = 0;
  while(buffer[i] != 0){
    if(buffer[i] == '/n'){
      buffer[i] = 0;
    }
    else{
      i++;
    }
  }
strncpy(buff, buffer, 1024);
free(buffer);
//printf("%s", buff);
}

void run(){
  char buffer[1024];
  char *p = buffer;
  bufferz(buffer);
  char ** args = (char**)calloc(10,sizeof(char *));
  args = parse_args(buffer);
  int i = 0;
  while(args[i]){
    int parent = getpid();
    int child1 = fork();
    int wow;
    char ** args2 = (char**)calloc(10, sizeof(char *));
    args2 = parse_args(args[i]);
    execvp(args2[0], args2);

     if(parent == getpid()){
      int childpid = wait(&wow);
    }
    else{
      execvp(args2[0], args2);
      exit(wow);
    }
    i++;
  }
}
char ** command_reader(FILE * filepointer){
  char line[256];
  fgets(line, sizeof(line), filepointer);
  printf(“s: %s \n”, s);
  char ** ret = parse_args(line);
  return ret;
}
		       
int main(){
  prompt();
  /*while(1){
    run();
    }*/
  char ** args = command_reader(stdin);
  execvp(args[0], args);
  return 0;
}
