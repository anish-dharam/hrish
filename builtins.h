
int cd(char** args);
int help(char** args);
int exit(char** args);

char* builtin_funcs[] = {
    &cd,
    &help,
    &exit
};

int lsh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}