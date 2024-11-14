%{
	#include<stdio.h>
	#include<ctype.h>
%}

%%
abc {
	printf("ABC");
}

. {
	putchar(yytext[0]);
}
%%

int main() {
	printf("Enter the String: ");
	yylex();
	return 0;
}

int yywrap() {
	return(1);
}


/*
lex Exp2.3_lex.l
gcc lex.yy.c
./a.out
*/

/*
Enter the String: Demoabcdemo
DEMOABCdemo
*/
