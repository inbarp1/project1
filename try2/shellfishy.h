#ifndef shell 
#define shell

void copy_ary();

int shud_exit();

int shud_cd();

int shud_pipe();

int count_tokens(char *line, char delimeter);

char *trim();

char ** parse_line();

int redirecting_left();

int redirecting_right();

int shud_redirect();

void prompt();

void breakup();


#endif
