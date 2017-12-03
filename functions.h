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
//cd function that doesnt workkkk
/*int cd( char ** args){
  if (args[1] == NULL) {
		chdir(getenv("HOME"));
		printf("Directory changed to home directory. \n");
		return 1;
	}   
  // if nothing entered w cd, change to home
   else{ 
		if (chdir(args[1]) !=0) {
			printf(" %s: no such directory\n", args[1]);
            return -1;
	    //directory not found 
		}
		else{
		  printf("Directory changed to specified directory. \n");
		  //directory changed 
		}    
	}
	return 0;
}
*/
int cd (char ** args) {
  if (!chdir(args[1])) {
    return 1;
  }
  return 0;
}


//prints the prompt 
void prompt(){
  char commandz[1024];
  getcwd(commandz, 1024);
  printf("current dir: %s\n", commandz);
}

//copies input into given buffer
void bufferz( char * buff ){
  char * buffer = (char *)calloc(1024,sizeof(char));
  fgets(buffer, 1024, stdin);
  // printf("buffer is: %s\n", buff);
  int i = 0;
  while(buffer[i] != '\0'){
    //if(strcmp(buffer[i], "/n") == 0){
    if(buffer[i]== '\n'){
      buffer[i] = 0;
    }
    else{
      i++;
    }
  }
strncpy(buff, buffer, 1024);
free(buffer);
}

char ** redirect(char ** args){
  char ** args3 = (char**)calloc(sizeof(char*), 20);
  int i = 0;
  while(args){
    if(strcmp(args[i], "<")==0){
    }
    if(strcmp(args[i],">")==0){
      
    }
    args3[i] = args[i]
      
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

