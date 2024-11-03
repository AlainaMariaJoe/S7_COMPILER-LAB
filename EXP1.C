#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for",
        "goto", "if", "int", "long", "register", "return", "short",
        "signed", "sizeof", "static", "struct", "switch", "typedef",
        "union", "unsigned", "void", "volatile", "while"
    };
    for (int i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;

    fp = fopen("inp.txt", "r");
    if (fp == NULL) {
        printf("Error while opening the file\n");
        exit(0);
    }

    while ((ch = fgetc(fp)) != EOF) {
        for (i = 0; i < 6; ++i) {
            if (ch == operators[i]) {
                printf("%c is an operator\n", ch);
            }
        }

        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if ((ch == ' ' || ch == '\n' || ch == ';' || ch == '\t') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer)) {
                printf("%s is a keyword\n", buffer);
            } else {
                for (int k = 0; k < strlen(buffer); k++) {
                    printf("%c is an identifier\n", buffer[k]);
                }
            }
        }
    }

    fclose(fp);
    return 0;
} 

// Input
/* inp.txt
x= b+c
*/

// Output
/*
= is an operator
+ is an operator
x is an identifier
b is an identifier
c is an identifier
*/
