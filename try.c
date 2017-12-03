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
  char commands[256]= "ls -la /Users";
  int i  = 0;
  printf("\n Calling the function parse_args to execute commands:\n");
  char ** args = parse_args(commands);
  printf("\ncommand %s\n", args[0]);
  char **com_args = &args[1];
  while ( com_args[i] ){
    printf("%d-th argument %s\n",i, com_args[i]);
    ++i;
  }
  execvp(args[0], args);
  free(args);
  return 0;
  
}
