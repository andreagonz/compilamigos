%{
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "nodo.h"
#include "tabla.h"
#include "visitor.h"
    
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

extern int linea;
extern int col;
 
void yyerror(const char *s);
queue<Nodo*> * nodos = new queue<Nodo*>();
string archivo;
%}

/* bison declarations */

%union {
  int ival;
  float fval; 
  char* sval;
  Nodo *nval;
}

/* Declaración de tokens */
%token <sval> TRUE FALSE ENTERO FLOTANTE BOOLEANO
%token <sval> LPAR RPAR SEMIC ASIG
%token <sval> EQ NEQ LESS GREAT LESSEQ GREATEQ AND OR NOT
%token <sval> PLUS MINUS MULT DIV
%left EQ NEQ LESS GREAT LESSEQ GREATEQ AND OR
%left  PLUS MINUS
%left  MULT DIV
%right NOT

%token <sval> INT 
%token <sval> FLOAT 
%token <sval> ID

%type <nval> Num Factor Bool Prog AsigPrim Term ExprPrim Easig Expr Id Bcomp
%type <nval> Beq Bterm Bexp Tipo Inst Asig
%type <nval> ProgPrim S

%%

/* Gramática */
S :  Prog {
  $$ = $1;
  ofstream arbol;
  arbol.open (archivo + ".asa");
  arbol << str($$);
  arbol.close();
  VisitorCreaTabla * vct = new VisitorCreaTabla();
  $$->accept(vct);
  if(!vct->tuvo_error()) {
        VisitorVerificaTipos * vvt = new VisitorVerificaTipos();
        $$->accept(vvt);
        if(!vvt->tuvo_error()) {
            cout << "Todo bien" << endl;
        }
  }
 } 
;

Prog :  Prog ProgPrim {
  Nodo *n = new NodoSeq("seq");
  n->add($1);
  nodos->push(n);
  n->add($2);
  $$ = n;
}
| ProgPrim { $$ = $1; }
;

ProgPrim :
Inst SEMIC {
      Nodo *n = new NodoSeq("seq");
      n->add($1);
      nodos->push(n);
      $$ = n; }
;

Inst :
Expr { $$ = $1; }
| Asig { $$ = $1; }
;

Expr :  Bexp {
  $$ = $1; 
}
;

Bexp :
Bexp OR Bterm {
  Nodo * n = new NodoOr("or");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Bterm { $$ = $1; }
;
 
Bterm :
Bterm AND Beq {
  Nodo * n = new NodoAnd("and");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Beq { $$ = $1;  } 
;
 
Beq :  Beq EQ Bcomp {
  Nodo * n = new NodoEq("==");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Beq NEQ Bcomp {
  Nodo * n = new NodoNeq("!=");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Bcomp { $$ = $1; }
;

Bcomp :
Bcomp LESS ExprPrim {
  Nodo * n = new NodoLess("<");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Bcomp GREAT ExprPrim {
  Nodo * n = new NodoGreat(">");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Bcomp LESSEQ ExprPrim {
  Nodo * n = new NodoLessEq("<=");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Bcomp GREATEQ ExprPrim {
  Nodo * n = new NodoGreatEq(">=");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| ExprPrim { $$ = $1; } 
;
 
ExprPrim :
ExprPrim PLUS Term {
  Nodo * n = new NodoSum("+");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| ExprPrim MINUS Term {
  Nodo * n = new NodoMenos("-");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Term { $$ = $1; } 
;

Term :
Term MULT Factor{
  Nodo * n = new NodoMult("*");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
| Term DIV Factor {
  Nodo * n = new NodoDiv("/");
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
Id {
  $$ = $1;
}
|
Num {
  $$ = $1;
}
|
LPAR Expr RPAR {
    $$ = $2;
}
|
MINUS Factor {
  Nodo * n = new NodoNeg("-");
  n->add($2);
  nodos->push(n);
  $$ = n;
}
|
NOT Factor {
  Nodo * n = new NodoNot("not");
  n->add($2);
  nodos->push(n);
  $$ = n;
}
|
Bool { $$ = $1; }
;

Bool :
TRUE {
  Nodo * n = new NodoBool("true");
  nodos->push(n);
  $$ = n;
}
|
FALSE {
  Nodo * n = new NodoBool("false");
  nodos->push(n);
  $$ = n;
} 
;

Asig :
Easig { $$ = $1; }
| AsigPrim { $$ = $1; } 
;

AsigPrim :
Tipo Easig {
  $1->add($2);
  $$ = $1;
} 
;

Easig :
Id ASIG Expr {
  Nodo * n = new NodoAsig("=");
  nodos->push(n);
  n->add($1);
  n->add($3);
  $$ = n;
}
;

Id:
ID {
  Nodo * n = new NodoId($1);
  nodos->push(n);
  $$ = n;
}

Num:
FLOAT {
  Nodo * n = new NodoFloat($1);
  nodos->push(n);
  $$ = n;
}
| INT {
  Nodo * n = new NodoInt($1);
  nodos->push(n);
  $$ = n;
}
;

Tipo:
ENTERO {
    Nodo * n = new NodoTipo("int", TINT);
    nodos->push(n);
    $$ = n;
}
| FLOTANTE {
  Nodo * n = new NodoTipo("float", TFLOAT);
  nodos->push(n);
  $$ = n;
  }
| BOOLEANO {
  Nodo * n = new NodoTipo("bool", TBOOL);
  nodos->push(n);
  $$ = n;
  }
;
%%

/* Epilogo */

/* Función para liberar espacio de los nodos */
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
        string s = argv[1];
        archivo = s.substr(s.find_last_of("\\/") + 1, s.size());
        archivo = archivo.substr(0, archivo.find_last_of("."));
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
