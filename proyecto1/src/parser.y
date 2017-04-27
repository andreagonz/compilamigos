%{

/*cosas de c++. prologo*/
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int yylex(void);
int yyerror(char *err);


%}

/* bison declarations */

%union {
  int ival;
  float fval; 
  char *sym; // $$ can either be an int or a string
};

%token <ival> INT 
%token <fval> FLOAT 
%token <sym> BOOL 
%token <sym> ID
%token <sym> EQ 
%token <sym> NEQ
%token <sym> LESS
%token <sym> GREAT
%token <sym> LESSEQ
%token <sym> GREATEQ
%token <sym> NOT
%token <sym> AND
%token <sym> OR
%token <sym> LPAR
%token <sym> RPAR
%token <sym> ASIG
%token <sym> FUN
%token <sym> Tipo
%token <sym> ENDFUN
%token <sym> COND
%token <sym> ENDCOND
%token <sym> WHILE
%token <sym> ENDWHILE
%token <sym> DEFAULT
%token <sym> DOTDOT
%token <sym> PIPE
%token <sym> TRUE
%token <sym> FALSE
%token <sym> COMMA
%left <sym> '+' 
%left <sym> '-'
%left <sym> '*' 
%left <sym> '/'
%token <sym> SEMIC


%%

/*gramática*/

/*Cambie todas las ' por la letra a*/
S :  Fprog
;
Fprog :  Fprog Fproga | Fproga 
;
Fproga :  Asiga SEMIC | Fundef 
;
Prog :  Prog Proga | Proga 
;
Proga :  Conditional | Whileloop | Inst SEMIC | Function SEMIC 
;
Inst :  Expr | Asig
;
Fundef :  FUN ID LPAR Fdparams RPAR Tipo DOTDOT Prog ENDFUN
;
Whileloop :  WHILE Expr DOTDOT Prog ENDWHILE 
;    
Function :  ID LPAR Fparams RPAR
;
Fdparams :  Fdparams COMMA Tipo ID | Tipo ID 
;
Fparams :  Fparams  Param | Param  
;
Param :  Function | ID | Num 
;
Conditional :  COND Expr DOTDOT Sig ENDCOND
;
Sig :  Prog PIPE Expr DOTDOT Sig | Prog PIPE DEFAULT DOTDOT Prog | Prog 
;
Expr :  Bexp
;
Bexp :  Bexp OR Bterm | Bterm 
; 
Bterm :  Bterm AND Beq | Beq 
; 
Beq :  Beq EQ Bcomp | Beq NEQ Bcomp | Bcomp 
;
Bcomp :  Bcomp LESS Expra | Bcomp GREAT Expra | Bcomp LESSEQ Expra | Bcomp GREATEQ Expra | Expra 
; 
Expra :  Expra '+' Term | Expra '-' Term | Term 
;
Term :  Term '*' Factor | Term '/' Factor | Factor 
;    
Factor :  ID | Num | LPAR Expr RPAR | '-' Factor | NOT Factor | Bool 
;
Bool :  TRUE | FALSE 
;
Asig :   Easig | Asiga 
;
Asiga :  Tipo Easig 
;
Easig :  ID ASIG Expr | ID ASIG Function
;
Num: FLOAT | INT
;
%%

/* epilogo */

int main() {
    yyparse();
}
