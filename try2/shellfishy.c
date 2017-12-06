#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <dirent.h>
#include "parse_stuff.h"
#include "shellfishy.h"

void copy_ary(char **args, char * return_me[]){
  int i=0;
  while(args[i]){
    return_me[i]=args[i];
    i++;
  }
}
// copies the array

int count_tokens(char *line, char delimeter){
  int answer = 1;
  while (*line) {
    line++;
    if (*line == delimeter)
      answer++;
  }
  return answer;
}

char * trim(char *line){
  while(*line==' ')
    line++;
  char * answer=line;
  while(*line)
    line++;
  line--;
  while(*line==' ' || *line=='\n')
    line--;
  line++;
  *line=0;
  return answer;
}

char ** parse_line(char * line, char *delimeter){
  int size = count_tokens(line, delimeter[0]);
  char** answer = (char**) malloc((size+1) * sizeof(char));
  char* pointer = line;
  int index = 0;
  while(index < size){
    answer[index] = strsep(&pointer,delimeter);
    index++;
  }
  answer[index] = 0; 
  return answer;
}
int shud_cd(char *args[]){
  int did_it__not_work;
  if(strcmp(args[0], "cd")==0){
    did_it__not_work = chdir(args[1]);
    if(did_it_not_work){
      printf("Something went wrong. Could not change directories.\n");
      return 1;
    }
  }
    return 0;
}
//returns 1 if cd did not work, 0 if cd did work
int shud_pipe(char *args[]){
  int index=0;
  while(args[index]){
    if(strcmp(args[index], "|")==0){
      pid_t first_kid= fork();
      if(first_kid==0{
	  int fd = open("temp", O_WRONLY | O_CREAT, 0666);
	  if(fd ==-1){
	    printf("Pipe filed.\n");
	    return 0;
	  }
	  int fd2 = dup2(fd,1);
	  if(fd2 ==-1){
	    printf("Pipe failed.n");
	    return 0;
	  }
	  ags[index] = 0;
	  execvp(args[0], args);
	}
	int child_status;
	wait(&child_status);
	int fd = open("temp", O_WRONLY | O_CREAT, 0666);
	if(fd ==-1){
	    printf("Pipe filed.\n");
	    return 0;
	}
	dup2(fd, 0);
	return index;
	}
      index++;
    }}
  return 0;
}

        
int shud_exit(char *args[]){
  if(strcmp(args[0], "exit")==0){
    return 1;
  }
  else{
    return 0;
  }
}
// returns 1 if exit, returns 0 if not

int redirecting_left(char *args[], int index){
  int fd = open(args[index+1], O_RWDR | O_CREAT, 0666);
  if(fd==-1){
    printf("Redirection failed.\n");
    return 0;
  }
  dup2(fd,1);
  return index;
}
// if > pipe found it replaces the stdout with the desired file to write to and replaces stdout in the file table with that file

int redirecting_right(char *args[], int index){
  int fd = open(args[index+1], O_RWDR | O_CREAT, 0666);
  if(fd == -1){
    printf("Redirection failed.\n");
    return 0;
  }
  dup2(fd,0);
  if(strcmp(args[index+2], ">")==0){
    int fd= open(args[index+3], O_RWDR | O_CREAT, 0666);
    if(fd == -1){
      printf("Redirection failed.\n");
      return 0;
    }
    dup2(fd,1);
  }
  return index;
}
//if < pipe found it replaces stdin in file table w desired file and looks for replacement for stdout. 	
  
int shud_redirect(char *args[]){
  int index = 0;
  int_to_return;
  while(args[index]){
    if(strcmp(args[index],"<")==0){
      to_return = redirecting_right(args,index);
      return to_return;
    }
    if(strcmp(args[index], ">")==0){
     redirecting_left(args,index);
     return to_return;
    }
    index++;
  }
  return 0;
}
//returns first occurence of redirection or 0 if no redirection

void promopt(){
  char *cwd = getcwd(curr_directory,PATH_MAX + 1);
  if(!cwd){
    printf("Cannot find cwd.\n");
  }
  printf("\n Cwd: %s \n", cdwd);
}
void breakup(int i, int num){
  if(i!=num-1 && i>0){
    printf("\n");
  }
}
int main();
pid_t child_pid_num;
int child_status;
char curr_directory[PATH_MAX +1];
char command[MAX_SIZE];
char pre_command[MAX_SIZE];
int num_commands;
char ** temporary;
while(1){
  prompt();
  fgets(pre_command,MAX_SIZE,stdin);
  strcpy(command,trim(pre_command));
  
  num_commands= count_tokens(command, ';');
  char * m_args[num_commands];
  temporary = parse_line(command, ";");
  copy_ary(temporary,m_args);
  int index =0;
  
  while (index < num_commands){
    breakup(index,num_commands);
  }
  char sub_command[MAX_SIZE];
  strpy(sub_command,trim(m_args[index]));
  
  int num_tokens = count_tokens(sub_commnad,' ');
  char *args[count_tokens+1];
  temporary = parse_line(sub_command, ' ');
  copy_ary(temporary,args);
  args[count_tokens]= 0;

  int is_exit = shud_exit(args);
  if(is_exit){
    return 0;
  }

  int is_cd = shud_cd(args);
  if(!is_cd){
    child_pid_num = fork();
    if(child_pid_num==0){
      int is_pipe = shud_pipe(args);
      if(is_pipe){
	is_pipe ++;
	int index = 0;
	char * new_args[num_tokens -2];
	while(args[is_pipe]){
	  new_args[index]=args[index+is_pipe];
	  is_pipe++;
	  index++;
	}
	execvp(new_args[0],new_args);
      }
      int is_redirect = shud_redirect(args);
      if(is_redirect){
	args[is_redirect] = 0;
      }
      execvp(args[0], args);
    }
    else{
      wait(%child_status);
    }
  }
  index++;
 }
}
    
      
      
