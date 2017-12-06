#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctype.h>

char ** parse_args( char * line, char * delimiter );
int cd( char *args[]);
void prompt();
void bufferz(char *buff);
void run();

//headers
char * rm_whitespace(char * str){
  // char ** args = (char**)calloc(10,sizeof(char*));
  char * final = str + strlen(str) - 1;
  while(isspace(*str) && *str){ //while more to string and theres space
    str++;
  }
  while(isspace(*str) && final > str){
     *final--  = '\0';
  }
  return str;
}

int redirect(char * command, char direction){
  int read_file;
  int fid;
  int status;
  if(direction == '>'){
    read_file = dup(STDOUT_FILENO);
    char **args = parse_args(command,">");
    printf("%s\n", rm_whitespace(args[1]));
    int written_file = open(rm_whitespace(args[1]), O_WRONLY | O_CREAT, 0644);
    fid = dup2(written_file, STDOUT_FILENO);
    printf("hi3\n");
    int child = fork();
    if(child){
      wait(&status);
    }
    else{
      execvp(args[0], args);
      exit(0);
    }
    dup2(read_file, written_file);
  }
  else{
    read_file = dup(STDIN_FILENO);
    char **args = parse_args(command,"<");
    int written_file = open(rm_whitespace(args[1]), O_TRUNC | O_CREAT | O_WRONLY, 0644);
    fid = dup2(written_file, STDIN_FILENO);
    int child = fork();
    if(child){
      wait(&status);
    }
    else{
      execvp(args[0], args);
      exit(0);
    }
    dup2(read_file, written_file);
  }
  return fid;
}


char ** parse_args( char * line, char * delimeter ){
  char ** args = (char**)calloc(sizeof(char*), 20);
  char *s1 = line;
  int i = 0;
  while(s1){
    args[i] =  strsep( &s1, delimeter);
    args[i] = rm_whitespace(args[i]);
    i++;
  }
  return args;
}
//cd function
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
 
void run(){
  char buffer[1024];
  char *p = buffer;
  bufferz(buffer);
  char ** args = (char**)calloc(10,sizeof(char *));
  args = parse_args(buffer, ";");
  int i = 0;
  while(args[i]){
    int pipez[2];
    pipe(pipez);
    if(strchr(args[i], '>') != 0){
      printf("hi2\n");
      int later = redirect(args[i], '>');
      //write(pipez[1], &later, sizeof(int));
      //close(pipez[1]);
      prompt();
    }
    int wow;
    char ** args2 = (char**)calloc(10, sizeof(char *));
    args2 = parse_args(args[i], " ");
    printf("%s\n", args[i]);
    //printf("%s\n",args2[0]);
    // exit command quits the shell
    
    if(strcmp(args[i], "exit")== 0){
      exit(0);
    }
    //cd command 
    if(strcmp(args2[0],"cd") == 0){
      cd(args2);
      prompt();
      //exit(0);
      }
    /*   if(args2[1] && (strchr(args[i], ">") != 0)){
      printf("hi");
      printf("%s", store);
      redirect(args[i], '>');
      prompt();
      }*/
    else{
      int parent = getpid();
      int child1 = fork();
      // char ** args2 = (char**)calloc(10, sizeof(char *));
      // args2 = parse_args(args[i], " ");
      //execvp(args2[0], args2);
      if(parent == getpid()){
	int childpid = wait(&wow);
	//if(args2[0] == "cd"){
	// cd(args2[1]);
	//}
      }
      else{
	execvp(args2[0], args2);
	exit(wow);
      }
    }
    i++;
    }
}
