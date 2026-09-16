#include <stdlib.h>
#include <stdio.h>

int main(){

    char *buff = NULL;
    size_t size = 0;
    ssize_t num_char = 0;

    while(){
    printf("Please enter some text:");
    ssize_t user_input = getline(&buff, &size, stdin);
    if(num_char == -1){
        perror("getline failed");
        exit(EXIT_FAILURE);
        free(buff);
    }
    for (j = 1, &buff = argv[1]; ; j++, &buff = NULL) {
        token = strtok_r(&buff, argv[2], &saveptr1);
        if (token == NULL)
            break;
        printf("%d: %s\n", j, token);
        ...
    }
    }


    return 0;
}
