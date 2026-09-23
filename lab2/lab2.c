#define _POSIX_C_SOURCE_200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while (1) { // infinite loop
    printf("Enter programs to run. \n>");
    read = getline(&line, &len, stdin);

    if (read == -1) { // error handling for getline
      printf("getline failed");
      break;
    }

    pid_t pid = fork();

    if (pid < 0) { // error handling for fork process

      perror("fork failed");
      break;

    } else if (pid == 0) {

      execlp(line, line, NULL);
      printf("Exec failure"); // fail case for execlp
      break;
    } else {
      int status = 0;
      int result = waitpid(pid, &status, 0);

      if (result == -1) { // error handling for waitpid
        perror("waitpid failed");
      }
    }
  }
  free(line); // free the malloc

  return 0;
}
