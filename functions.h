#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

void run();

//headers


char ** parse_args( char * line, char * delimeter ){
  char ** args = (char**)calloc(sizeof(char*), 20);
  char *s1 = line;
  int i = 0;
  while(s1){
    args[i] = s1;
    strsep( &s1, delimeter);
    i++;
  }
  return args;
}
    }
    args3[i] = args[i];
      
}
void run(){
  char buffer[1024];
  char *p = buffer;
  bufferz(buffer);
  char ** args = (char**)calloc(10,sizeof(char *));
  args = parse_args(buffer, ";");
  int i = 0;
  while(args[i]){
    int wow;
    char ** args2 = (char**)calloc(10, sizeof(char *));
    args2 = parse_args(args[i], " ");
    //printf("%s\n",args2[0]);
    // exit command quits the shell
    char ** args3 (char**)calloc(10,sizeof(char *));
    args3=redirect(args2);
    if(strcmp(args2[0], "exit")== 0){
      free(args1);
      free(args2);
      free(args3);
      exit(0);
    }
    //cd command 
    if(strcmp(args3[0],"cd") == 0){
      cd(args3);
      prompt();
      //exit(0);
      }
    else{
      int parent = getpid();
      int child1 = fork();
      //execvp(args2[0], args2);
      if(parent == getpid()){
	int childpid = wait(&wow);
	//if(args2[0] == "cd"){
	// cd(args2[1]);
	//}
      }
      else{
	execvp(args3[0], args3);
	exit(wow);
      }
    }
    i++;
      }
}

