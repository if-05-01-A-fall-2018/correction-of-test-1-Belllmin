#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Removed
// char *arguments[256];
// char *pointer;

int main(int argc, char const *argv[]) {
	
  char* input = {"ls", "df", "ps", "pwd"};  // <--- Changed - char input[256];
  for(int i = 0; i < 4; i++) {	            // <--- Added to old code
  
  /* R E M O V E D
  
  char *save;
  gets(input);
  char *div = "&&";
  pointer = strtok_r(input, div, &save);

  while(pointer != 0){ // Split
    char *div2 = " ";
    char *save2;
    char *pointer2 = strtok_r(pointer, div2, &save2);
    int cnt = 0;

    while(pointer2 != 0){
      arguments[cnt] = pointer2;
      cnt++;
      pointer2 = strtok_r(0, div2, &save2);
    }
    arguments[cnt] = 0;   */

    int pid = fork();
    if(pid == 0){
      char *arguments[2] = {input[i], 0}; // <----  Added to old code
      execvp(arguments[0], arguments);
      printf("Error - Fail! \n");
    }else{
      int status;
      waitpid(-1, &status, 0);
    }
    //pointer = strtok_r(0, div, &save);  <----- Removed
  }
  printf("Done\n");
  return 0;
}
