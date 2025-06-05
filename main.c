#define EXIT_SUCCESS 1


char* read_line() {
    return "";
};

char** get_args(char* line) {
    char** res;
    return res;
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

