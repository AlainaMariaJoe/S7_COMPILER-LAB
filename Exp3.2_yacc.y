%{
	#include <stdio.h>
	int valid=1;
%}

%token digit letter

%%
start : letter s
s : letter s
| digit s
|
;
%%

int yyerror() {
	printf("Its not a identifier!\n");
	valid=0;
	return 0;
}
int main() {
	printf("Enter the expression : ");
	yyparse();
	if(valid)	{
		printf("It is a identifier!\n");
	}
}