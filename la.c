#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {
    "int", "float", "char", "double", "void", "for", "while", "if", "else", "do", "break", "continue", "return"
};

#define NUM_KEYWORDS 13

const char *operators[] = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||"
};

#define NUM_OPERATORS 14

const char *special_symbols[] = {
    ",", ";", "(", ")", "{", "}", "[", "]", "\"", "\'"
};

#define NUM_SPECIAL_SYMBOLS 10

int is_keyword(const char *str) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_operator(const char *str) {
    for (int i = 0; i < NUM_OPERATORS; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_special_symbol(const char *str) {
    for (int i = 0; i < NUM_SPECIAL_SYMBOLS; i++) {
        if (strcmp(str, special_symbols[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char input[1000];
    int count = 0;
    fp = fopen("C:\\Users\\USER\\Downloads\\spcc-prac\\2-LA-input.txt","r");
    if (fp == NULL) {
    printf("File not found!\n");
    return 1;
    }

    printf("Input:\n");
    while (fgets(input, 1000, fp)) {
        printf("%s", input);
        if (input[0] == '\n') {
            count++;
        } else {
            count = 0;
        }
        char *token = strtok(input, " \n");
        while (token != NULL) {
            if (is_keyword(token)) {
                printf("%s is keyword\n", token);
            } else if (isalpha(token[0]) || token[0] == '$') {
                printf("%s is identifier\n", token);
            } else if (isdigit(token[0])) {
                printf("%s is constant\n", token);
            } else if (token[0] == '\"' || token[0] == '\'') {
                printf("%s is literal\n", token);
            } else if (is_operator(token)) {
                printf("%s is operator\n", token);
            } else if (is_special_symbol(token)) {
                printf("%s is special symbol\n", token);
            }
            token = strtok(NULL, " \n");
        }
        if (count < 2) {
            printf("\n");
        }
    }

    fclose(fp);

    return 0;
}
