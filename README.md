# project1
# Systems Project: Shell

### Features
* takes in one line shell commands from user and runs it
* can run multiple commands on one line if separated by a ";"
* can exit and cd into different directories

### Attempted
*We tried implement pipe but kept on getting segmentation fault errors and it was 3am so we decided to give up trying to make it work. 
*We tried to implement redirect but but it didn't work for functions. Rather, it copied from stdin and placed it into the file.

### Bugs
*Redirecting opens the stdin for the file and the only way to exit is to force quit in the terminal. Would not suggest redirecting…

### Files & Function Headers:
main.c includes functions.h which receives commands from user and runs them.
char ** parse_args( char * line, char * delimiter ): cuts of line by delimiter and puts that component into arg string array and returns an array of strings where each slot is an arg.
int cd( char *args[]): takes a string and changes the directory based on the string
void prompt(): returns the current directory 
void bufferz(char *buff): takes in a string and creates a buffer. 
void run(): forks, child will execvp the commands, parent waits for the child. 

### A note
 Hi it’s Inbar here, I felt very sick last week and I was unsure of why. After not being able to sleep all night Thursday due to throat pain, I went to the doctor Friday and it turns out I have strep throat. I’m pretty disappointed that we didn’t get to implement pipe and redirect because I feel that if I weren’t sick for most of last week I would have been able to spend less time sleeping and more time working on the project. Once my medication started kicking in I was able to be much more productive, but that only happened Saturday afternoon. I know that you gave us a very long extension (the weekend) to work on the project, and that grades are due, so we decided to submit the unfinished product, but Dasha and I both agreed to continue working on this tomorrow because it bothered us that it wasn’t working. 
