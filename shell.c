#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(){
  char execute_me[256];
  while( //more lines){
    fgets(execute_me, sizeof(execute_me), stdin);
    it(execute_me == "cd"){
      //execute
    }
    if(execute_me == "exit"){
      //execute
    }
    pid_t f=fork();
    if(!f){
      //execute
      
    
