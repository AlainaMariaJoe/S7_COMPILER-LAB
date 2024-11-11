#include <stdio.h>
#include <string.h>

char op[2], arg1[5], arg2[5], result[5];

void main() {
    FILE *fp1, *fp2;
    char f[100];
    
    printf("Enter input file name: ");
    scanf("%[^\n]s", f);
    getchar();  // Consume newline character left by scanf

    fp1 = fopen(f, "r");
    fp2 = fopen("output.txt", "w");

    if (fp1 == NULL) {
        printf("Error opening input file\n");
        return;
    }

    if (fp2 == NULL) {
        printf("Error opening output file\n");
        fclose(fp1);  // Ensure input file is closed on error
        return;
    }

    // Process each line
    while (fscanf(fp1, "%s %s %s %s", op, arg1, arg2, result) == 4) {
        if (strcmp(op, "+") == 0) {
            fprintf(fp2, "\nMOV R0,%s", arg1);
            fprintf(fp2, "\nADD R0,%s", arg2);
            fprintf(fp2, "\nMOV %s,R0", result);
        }
        else if (strcmp(op, "*") == 0) {
            fprintf(fp2, "\nMOV R0,%s", arg1);
            fprintf(fp2, "\nMUL R0,%s", arg2);
            fprintf(fp2, "\nMOV %s,R0", result);
        }
        else if (strcmp(op, "-") == 0) {
            fprintf(fp2, "\nMOV R0,%s", arg1);
            fprintf(fp2, "\nSUB R0,%s", arg2);
            fprintf(fp2, "\nMOV %s,R0", result);
        }
        else if (strcmp(op, "/") == 0) {
            fprintf(fp2, "\nMOV R0,%s", arg1);
            fprintf(fp2, "\nDIV R0,%s", arg2);
            fprintf(fp2, "\nMOV %s,R0", result);
        }
        else if (strcmp(op, "=") == 0) {
            fprintf(fp2, "\nMOV R0,%s", arg1);
            fprintf(fp2, "\nMOV %s,R0", result);
        }
        else {
            fprintf(fp2, "\n// Unsupported operation: %s", op);
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("Assembly code has been written to output.txt\n");
}


/*
input.txt
+ a b t1
* c d t2
- t1 t2 t
= t ? x

gcc EXP 9.c
./a.out
Enter input file name: input.txt

cat output.txt

MOV R0,a
ADD R0,b
MOV t1,R0
MOV R0,c
MUL R0,d
MOV t2,R0
MOV R0,t1
SUB R0,t2
MOV t,R0
MOV R0,t
MOV x,R0
MOV R0,t
MOV x,R0
*/
