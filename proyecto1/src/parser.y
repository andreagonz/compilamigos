%{
/*cosas de c++*/

int yylex(void);
int yyerror(char *err);

%}

%union {
  int val; 
  char sym;
};

%token <val> INT FLOAT 
%token <sym> BOOL ID 
%token <sym> EQ NEQ LESS GREAT LESSEQ GREATEQ NEG AND OR
%token <sym> LPAR RPAR SEMIC ASIG FUN ENDFUN COND ENDCOND WHILE ENDWHILE DOTDOT PIPE
%left <sym> '+' '-'
%left <sym> '*' '/'

%%

/*gramática*/

S : INT; /*tiene que haber al menos una producción de la gramática para que compile*/


%%

int main(){
    yyparse();
}
