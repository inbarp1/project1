#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ) {
  char ** return_dis = (char**)calloc(6, sizeof(char *));
  int count = 0;
  while (line) {
    char * curr = strsep(&line, " ");
    return_dis[count]= curr;
    count++;
  }
  return_dis[count]= NULL;
  return return_dis;
}

int main() {
  char commands[256]= "ls -a -l";
  printf("\n Calling the function parse_args to execute commands:\n");
  char ** args = parse_args(commands);
  execvp(args[0], args);
  free(args);
  return 0;
  
}
