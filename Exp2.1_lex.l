%{
  #include<stdio.h>
%}

%%
if|else|while|int|switch|for|char {
  printf("%s is a keyword\n", yytext);
}
  
[a-zA-Z_][a-zA-Z0-9_]* {
  printf("%s is an  identifier\n", yytext);
}

"="|"+"|"-"|"*"|"/"|"<"|">" {
  printf("%s is an operator\n", yytext);
  o++;
  n++;
}

[0-9]+ {
  printf("%s is a number\n", yytext);num++;n++;
}
(.) {}

"\t"|"\n" {exit(0);}
%%

int main() {
  printf("Enter the input text: ");
  yylex();
  return 0;
}

int yywrap() {}


/*
lex EXP02_1.l
gcc lex.yy.c
./a.out 
Enter the input text: x=y+z
x is an  identifier
= is an operator
y is an  identifier
+ is an operator
z is an  identifier
*/
