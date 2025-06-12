#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <builtins.h>

#define EXIT_SUCCESS 1
#define EXIT_FAILURE -1
#define BUFSIZE 256

#define TOK_DELIMITERS " \n\a\r\t"


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
    char** tokens = malloc(sizeof(char*) * curr_bufsize);
    int num_tokens = 0;

    char* token = strtok(line, TOK_DELIMITERS);
    while (token) {

        if (!tokens) {
            fprintf(stderr, "hrish: couldn't allocate token buffer\n");
            exit(EXIT_FAILURE);
        }

        tokens[num_tokens] = token;
        num_tokens += 1;
        if (num_tokens >= curr_bufsize) {
            curr_bufsize += BUFSIZE;
            tokens = realloc(tokens, sizeof(char*) * curr_bufsize);
        }
        token = strtok(line, NULL);
    }
    
    return tokens;
}

int hrish_fork(char** args) {
    pid_t pid = fork();
    if (pid == 0) { //child
        int res = execvp(args[0], args);
        if (res == -1) {
            fprintf(stderr, "hrish: failed to exec process %s", args[0]);
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) { //parent
        int status;
        while (!WIFEXITED(status) && !WIFSIGNALED(status)) {
            waitpid(pid, &status, WUNTRACED);
        }
    } else { //fork error
        fprintf(stderr, "hrish: failed to fork");
        exit(EXIT_FAILURE);

    }

    return EXIT_SUCCESS;
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

