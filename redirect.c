#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>

//removes whitespace from string
char * rm_whitespace(char * str){
  char * final = str + strlen(str) - 1;
  while(isspace(*str) && *str){ //while more to string and theres space
    str++;
  }
  while(isspace(*str) && final > str){
     *final--  = '\0';
  }
  return str;
}

char ** parse_args( char * line, char * delimeter ){
  char ** args = (char**)calloc(sizeof(char), 20);
  //char *s1 = line;
  int i = 0;
  while(line){
    args[i] = line;
    strsep( &line, delimeter);
    //args[i] = rm_whitespace(args[i]);
    //printf("args[%d]: %s\n", i, args[i]);
    i++;
  }
  return args;
  }

void redirect(char * command, char direction){
  int read_file;
  int written_file;
  int fid;
  char ** args;
  if(direction == '>'){
    args = parse_args(command,">");
    printf("hi\n");
    written_file = open(args[1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
    fid = dup(STDOUT_FILENO);
    dup2(written_file, fid);
    //fid = fcntl(STDOUT_FILENO, F_DUPFD, 0);
    // read_file = fcntl(written_file, F_DUPFD, fid);
    //read_file = dup2(written_file, fid);
    close(written_file);
  }
  else{
    //printf("no");
    written_file = open(args[1], O_RDONLY, 0644);
    fid = dup(STDOUT_FILENO);
    read_file = fcntl(written_file, fid);
    close(written_file);
  }
}


int main(){
  // char ** args = (char**)calloc(10,sizeof(char *));
  //redirect("hi.txt > meow.txt", '>');
  return 0;
}
