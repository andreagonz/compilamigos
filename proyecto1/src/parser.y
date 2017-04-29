%{
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include "nodo.h"
    
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

extern int linea;
extern int col;
 
void yyerror(const char *s);
queue<Nodo*> * nodos = new queue<Nodo*>();
    
%}

/* bison declarations */

%union {
  int ival;
  float fval; 
  char* sval;
  Nodo *nval;
}

%token <sval> TRUE FALSE DEFAULT ENTERO FLOTANTE BOOLEANO
%token <sval> LPAR RPAR SEMIC ASIG FUN ENDFUN COND ENDCOND WHILE ENDWHILE DOTDOT COMMA PIPE RETURN VOID
%token <sval> EQ NEQ LESS GREAT LESSEQ GREATEQ AND OR NOT
%token <sval> PLUS MINUS MULT DIV
%left EQ NEQ LESS GREAT LESSEQ GREATEQ AND OR
%left  PLUS MINUS
%left  MULT DIV
%right NOT

%token <sval> INT 
%token <sval> FLOAT 
%token <sval> ID

%type <nval> Num Factor Bool Fprog Prog FprogPrim AsigPrim Term ExprPrim Easig Expr Function Id
  

%%

/*gramática*/

S :  Fprog 
;
Fprog :  Fprog FprogPrim | FprogPrim 
;

FprogPrim :
AsigPrim SEMIC {
  Nodo *n = new NodoSeq($2);
  n->add($1);
  nodos->push(n);
  $$ = n; 
}
|
Fundef 
;
Prog :  Prog ProgPrim | ProgPrim 
;
ProgPrim :  Conditional | Whileloop | Inst SEMIC | Function SEMIC 
;
Inst :  Expr | Asig
;
Fundef :  FUN Id LPAR Fdparams RPAR FundefPrim | FUN Id LPAR RPAR FundefPrim
;
FundefPrim:  Tipo DOTDOT Prog Return SEMIC ENDFUN | VOID DOTDOT Prog ENDFUN
;
Return: RETURN Expr | RETURN Function
;
Whileloop :  WHILE Expr DOTDOT Prog ENDWHILE 
;    
Function :  Id LPAR Fparams RPAR | Id LPAR RPAR
;
Fdparams :  Fdparams COMMA Tipo Id | Tipo Id 
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
ExprPrim :
ExprPrim PLUS Term {
  Nodo * n = new NodoSum($2);
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| ExprPrim MINUS Term {
  Nodo * n = new NodoMenos($2);
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Term { $$ = $1; } 
;
Term :
Term MULT Factor{
  Nodo * n = new NodoMult($2);
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Term DIV Factor {
  Nodo * n = new NodoDiv($2);
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
|
Factor {
  $$ = $1;
} 
;    
Factor :
Id{
  $$ = $1;
}
|
Num{
  $$ = $1;
}
|
LPAR Expr RPAR {
  
}
|
MINUS Factor {
  Nodo * n = new NodoMenos($1);
  n->add($2);
  nodos->push(n);
  $$ = n;
}
|
NOT Factor {
  Nodo * n = new NodoNot($1);
  n->add($2);
  nodos->push(n);
  $$ = n;
}
|
Bool {
  $$ = $1;
}
;

Bool :
TRUE {
  Nodo * n = new NodoBool($1);
  nodos->push(n);
  cout << "true fine" << endl;
  $$ = n;
}
|
FALSE {
  Nodo * n = new NodoBool($1);
  nodos->push(n);
  cout << "bool fine" << endl;
  $$ = n;
} 
;
Asig :   Easig | AsigPrim 
;
AsigPrim :  Tipo Easig 
;
Easig :
Id ASIG Expr {
  Nodo * n = new NodoAsig($2);
  nodos->push(n);
  n->add($1);
  n->add($3);
  cout << "asig func fine" << endl;
  $$ = n;
}
| Id ASIG Function {
  Nodo * n = new NodoAsig($2);
  nodos->push(n);
  n->add($1);
  n->add($3);
  cout << "asig fine" << endl;
  $$ = n;
}
;

Id:
ID {
  Nodo * n = new NodoId($1);
  nodos->push(n);
  cout << "id fine" << endl;
  $$ = n;
}
Num:
FLOAT {
  Nodo * n = new NodoFloat($1);
  nodos->push(n);
  cout << " float fine" << endl;
  $$ = n;
} |
INT {
  Nodo * n = new NodoInt($1);
  nodos->push(n);
  cout << "int fine" << endl;
  $$ = n;
}
;
Tipo: ENTERO | FLOTANTE | BOOLEANO
;
%%

/* epilogo */
    
void clear() {
    while(!nodos->empty()) {
        Nodo *n = nodos->front();
        nodos->pop();
        delete n;
    }
    delete nodos;
}

int main(int argc, char* argv[]) {
	if(argc < 2) {
		cout << "Uso: ./kyc-ip <archivo>" << endl;
                clear();
		return -1;
 	}
	FILE *myfile = fopen(argv[1], "r");
	if (!myfile) {
		cout << "Error al abrir archivo!" << endl;
                clear();
		return -1;
	}
	yyin = myfile;

	do {
		yyparse();
	} while (!feof(yyin));
        clear();
}

void yyerror(const char *s) {
	cout << "Error! en línea " << linea << ", columna " << col << "  Mensaje: " << s << endl;
        clear();
	exit(-1);
}
