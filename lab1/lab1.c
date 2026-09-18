#define _POSIX_C_SOURCE 200809L
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

    //Items for outer loop
    char *buff = NULL;
    size_t size = 0;
    ssize_t user_input;

    while(1){ //outer loop
    printf("Please enter some text:");

    user_input = getline(&buff, &size, stdin);
    if(user_input == -1){
        perror("getline failed");
        exit(EXIT_FAILURE);
    }
    printf("Tokens: \n");

    char *saveptr;
    char *user_token = strtok_r(buff, " ", &saveptr); //first call

    while(user_token != NULL){ //go throigh remaining with delimeter
    printf(" %s\n", user_token);

    user_token = strtok_r(NULL, " ", &saveptr);
    }
    }

free(buff);
    

    return 0;
}
