#include <stdio.h>

void interpret(char program[]) {

    char var = 'q';
    int val = 42;

    printf("%c:%d\n",var,val);
}

int main(int argc, char* argv[]) {

    interpret(argv[1]);

    return 0;
}
