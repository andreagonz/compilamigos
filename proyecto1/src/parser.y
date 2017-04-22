%{
/*cosas de c++*/

int yylex(void);
int yyerror(char *err);

%}

%token INT FLOAT BOOL ID 
%token EQ NEQ LESS GREAT LESSEQ GREATEQ NEG AND OR
%token LPAR RPAR SEMIC ASIG FUN ENDFUN COND ENDCOND WHILE ENDWHILE DOTDOT PIPE
%left '+' '-'
%left '*' '/'
%left NEG

%%

/*gramática*/

S : INT; /*tiene que haber al menos una producción de la gramática para que compile*/


%%

int main(){
    yyparse();
}
