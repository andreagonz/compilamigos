%{
#include <cstdio>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

extern int linea;
extern int col;
 
void yyerror(const char *s);
%}

/* bison declarations */

%union {
  int ival;
  float fval; 
  char* sval; // $$ can either be an int or a string
}

%token TRUE FALSE DEFAULT ENTERO FLOTANTE BOOLEANO
%token EQ NEQ LESS GREAT LESSEQ GREATEQ NOT AND OR
%token LPAR RPAR SEMIC ASIG FUN ENDFUN COND ENDCOND WHILE ENDWHILE DOTDOT COMMA PIPE
%left  PLUS MINUS
%left  MULT DIV

%token <ival> INT 
%token <fval> FLOAT 
%token <sval> ID

%%

/*gramática*/

S :  Fprog
;
Fprog :  Fprog FprogPrim | FprogPrim 
;
FprogPrim :  AsigPrim SEMIC | Fundef 
;
Prog :  Prog ProgPrim | ProgPrim 
;
ProgPrim :  Conditional | Whileloop | Inst SEMIC | Function SEMIC 
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
Fparams :  Fparams COMMA Param | Param  
;
Param :  Expr
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
Bcomp :  Bcomp LESS ExprPrim | Bcomp GREAT ExprPrim | Bcomp LESSEQ ExprPrim | Bcomp GREATEQ ExprPrim | ExprPrim 
; 
ExprPrim :  ExprPrim PLUS Term | ExprPrim MINUS Term | Term 
;
Term :  Term MULT Factor | Term DIV Factor | Factor 
;    
Factor :  ID | Num | LPAR Expr RPAR | MINUS Factor | NOT Factor | Bool
;
Bool :  TRUE | FALSE 
;
Asig :   Easig | AsigPrim 
;
AsigPrim :  Tipo Easig 
;
Easig :  ID ASIG Expr | ID ASIG Function
;
Num: FLOAT | INT
;
Tipo: ENTERO | FLOTANTE | BOOLEANO
;
%%

/* epilogo */

int main(int argc, char* argv[]) {
	if(argc < 2) {
		cout << "Uso: ./kyc-ip <archivo>" << endl;
		return -1;
 	}
	FILE *myfile = fopen(argv[1], "r");
	if (!myfile) {
		cout << "Error al abrir archivo!" << endl;
		return -1;
	}
	yyin = myfile;

	do {
		yyparse();
	} while (!feof(yyin));
}

void yyerror(const char *s) {
	cout << "Error! en línea " << linea << ", columna " << col << "  Mensaje: " << s << endl;
	exit(-1);
}
