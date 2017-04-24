%{

/*cosas de c++. prologo*/
int yylex(void);
int yyerror(char *err);

%}

/* bison declarations */

%union {
  int val; 
  char* sym; // $$ can either be an int or a string
};

%token <val> INT FLOAT 
%token <sym> BOOL ID
%token <sym> EQ NEQ LESS GREAT LESSEQ GREATEQ NEG AND OR
%token <sym> LPAR RPAR SEMIC ASIG FUN ENDFUN COND ENDCOND WHILE ENDWHILE DOTDOT PIPE
%left <sym> '+' '-'
%left <sym> '*' '/'

%%

/*gramática*/

S :  Fprog
;
Fprog :  Fprog Fprog' | Fprog' 
;
Fprog' :  Asig'SEMIC | Fundef 
;
Prog :  Prog Prog' | Prog' 
;
Prog' :  COND | WHILE | InstSEMIC | FUNSEMIC 
;
Inst :  Expr | Asig
;
Fundef :  FUN ID LPAR Fdparams RPAR Tipo DOTDOT Prog ENDFUN
;
WHILE :  WHILE Expr DOTDOT Prog ENDWHILE 
;    
FUN :  ID LPAR Fparams RPAR
;
Fdparams :  FdparamsCOMMA Tipo ID | Tipo ID 
;
Fparams :  FparamsCOMMA Param | Param  
;Param :  FUN | ID | Num 
;
COND :  COND Expr DOTDOT Sig ENDCOND
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
Bcomp :  Bcomp LESS Expr' | Bcomp GREAT Expr' | Bcomp LESSEQ Expr' | Bcomp GREATEQ Expr' | Expr' 
; 
Expr' :  Expr' '+' Term | Expr' '-' Term | Term 
;
Term :  Term '*' Factor | Term '/' Factor | Factor 
;    
Factor :  ID | Num | LPAR Expr RPAR | '-' Factor | NOTFactor | Bool 
;
Bool :  TRUE | FALSE 
;
Asig :   Easig | Asig' 
;
Asig' :  Tipo Easig 
;
Easig :  ID ASIG Expr | ID ASIG FUN
;
Num: float | int
;
%%

/* epilogo */

int main(){
    yyparse();
}
