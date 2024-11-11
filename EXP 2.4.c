%{
    #include <stdio.h>
    int v = 0;
    int c = 0;
%}

%%

[aeiouAEIOU] {          // Match vowels and count them
    v++;
}

[a-zA-Z&&[^aeiouAEIOU]] { // Match consonants (alphabetic letters excluding vowels)
    c++;
}

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the string of vowels and consonants:\n");
    yylex();
    printf("Number of vowels are: %d\n", v);
    printf("Number of consonants are: %d\n", c);
    return 0;
}
