#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define EXIT_SUCCESS 1
#define EXIT_FAILURE -1
#define BUFSIZE 256

#define TOK_DEL


char* read_line() {
    int current_bufsize = BUFSIZE;
    char* buffer = (char*) malloc(current_bufsize);
    int pos = 0;
    char c;

    while (1) {
        if (pos >= current_bufsize) {//allocate more to the buffer
            current_bufsize += BUFSIZE;
            buffer = realloc(buffer, current_bufsize);
        }
        if (!buffer) {
            fprintf(stderr, "hrish: couldn't allocate line buffer\n");
            exit(EXIT_FAILURE);
        }
        

        c = getchar();
        if (c == ((char) EOF) || c == '\n') {
            buffer[pos] == '\0';
            return buffer;
        }
        buffer[pos] = c;
        pos += 1;
    }
};

char** get_args(char* line) {
    int curr_bufsize = BUFSIZE;
    char** tokens;
    
    // while (char* token = )
    
    return tokens;
}

int execute(char** args) {
    return 0;
}

int sh_loop() {
    int status;
    while (status) {
        char* line = read_line();
        char** args = get_args(line);
        status = execute(args);
        free(line);
        free(args);
    }

    return status;
}


int main(int argc, char** argv) {
    //config

    //loop
    sh_loop();

    //shutdown
    return EXIT_SUCCESS;
}

