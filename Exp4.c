#include <stdio.h>
#include <string.h>

char result[20][20], copy[3], states[20][20];

void display(int n) {
    printf("\nEpsilon closure of %s = { ", copy);
    for (int k = 0; k < n; k++) {
        printf(" %s", result[k]);
    }
    printf(" }\n");
}

int main() {
    FILE *fp;
    fp = fopen("input.dat", "r");
    if (fp == NULL) {
        printf("Error opening input.dat\n");
        return 1; // Error opening file
    }

    char state[3];
    int i, n, k;
    char state1[20], input[3], state2[20]; // Increased array sizes
    printf("\nEnter the no of states : ");
    scanf("%d", &n);
    printf("\nEnter the states : ");
    for (k = 0; k < n; k++) {
        scanf("%s", states[k]);
    }

    for (k = 0; k < n; k++) {
        i = 0;
        strcpy(state, states[k]);
        strcpy(copy, state);
        strcpy(result[i++], state);

        while (fscanf(fp, "%s%s%s", state1, input, state2) == 3) { // Check if fscanf succeeds
            if (strcmp(state, state1) == 0) {
                if (strcmp(input, "e") == 0) {
                    strcpy(result[i++], state2);
                    strcpy(state, state2);
                }
            }
        }

        display(i);
        rewind(fp); // Rewind the file for the next iteration
    }

    fclose(fp); // Close the file
    return 0;
}


/*
input.dat

q0 0 q0
q0 1 q1
q0 e q1
q1 e q2
*/


/*
gcc Exp4.c 
./a.out

Enter the no of states: 3

Enter the states :q0 q1 q2

Epsilon closure of q0 = {  q0 q1 q2 }

Epsilon closure of q1 = {  q1 q2 }

Epsilon closure of q2 = {  q2 }
*/
