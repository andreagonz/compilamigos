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
VisitorCreaTabla * vct = new VisitorCreaTabla();
string archivo;
ofstream codefile;
bool archivos = false;
    
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
    if(archivos) {
        ofstream arbol;
        arbol.open (archivo + ".asa");
        arbol << str($$);
        arbol.close();
    }
    $$->accept(vct);
    if(!vct->tuvo_error()) {
        if(archivos) {
            ofstream tsimb;
            tsimb.open (archivo + ".tds");
            tsimb << tstr(vct->get_tabla()->get_raiz());
            tsimb.close();
        }
        VisitorVerificaTipos * vvt = new VisitorVerificaTipos();
        $$->accept(vvt);        
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
        //cout << n->str() << endl;
        nodos->pop();
        delete n;
    }
    delete nodos;
}

//Metodo que marca los nodos de seq y pone cuanto nodos de secuencia tiene en su arbol contandolo a ellos
int transTreeSeqs(Nodo *nodo){	
	int seqs = 0;
        std::string seqstr = "(seq)";
	if(seqstr.compare(nodo->str()) == 0){
		seqs += 1;
	}
        
	int numhijos = nodo->num_hijos();
	for(int i = 0; i < numhijos; i++){
		seqs += transTreeSeqs(nodo->get(i));
	}

	nodo->set_num_seqs(seqs);
	return seqs;
}

//Metodo que nos dice si una cadena es un entero
inline bool isNumber(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}


//Metodo que nos dice si una cadena es un float
bool isFloat(const std::string & s)
{
   char * p ;
   strtod(s.c_str(), &p) ;

   return (*p == 0) ;
}

std::string registroStr(int reg){
	if ( reg == 0){
		return "rax";
	}
	if ( reg == 1){
		return "rcx";
	}
	//No se regresa RDX que es el que le tocaria al r2
	//por que es el que se usa para divir y se pone en 0
	if ( reg == 2){
		return "r15";
	}
	if ( reg == 3){
		return "rbx";
	}
	if ( reg == 4){
		return "rsp";
	}
	if ( reg == 5){
		return "rbp";
	}
	if ( reg == 6){
		return "rsi";
	}
	if ( reg == 7){
		return "rdi";
	}
	if ( reg == 8){
		return "r8";
	}
	if ( reg == 9){
		return "r9";
	}
	if ( reg == 10){
		return "r10";
	}
	if ( reg == 11){
		return "r11";
	}
	if ( reg == 12){
		return "r12";
	}
	if ( reg == 13){
		return "r13";
	}
	if ( reg == 14){
		return "r14";
	}
	if ( reg == 15){
		return "r15";
	}
}

//Metodo que genera el codigo en x86-64 (AUXILIAR)
void genCodeOpera(Nodo *nodo, int reg, std::string tipo){

	int vars = nodo->num_vars();
	int numhijos = nodo->num_hijos();
	std::string nodo_value = nodo->get_valor();

	if( nodo_value.compare("+") == 0 || nodo_value.compare("-") == 0 || nodo_value.compare("*") == 0 || nodo_value.compare("/") == 0 ){
		Nodo *h0 = nodo->get(0);
		Nodo *h1 = nodo->get(1);			
		if (h0->num_vars() == 0 || h1->num_vars() == 0){
				if(h0->num_vars() == 0){
					genCodeOpera(h1, reg, tipo);
					if(tipo.compare("int") == 0){
						if( nodo_value.compare("+") == 0){
							//codefile << "addq $"+h0->get_valor()+" %"+registroStr(reg) +"\t#addq S, D D ← D "+nodo_value+" S"<< endl;	
							codefile << "\tadd \t"+registroStr(reg)+", "+h0->get_valor()<< endl;	
						}
						if( nodo_value.compare("-") == 0){
							//codefile << "subq $"+h0->get_valor()+" %"+registroStr(reg) +"\t#subq S, D D ← D "+nodo_value+" S"<< endl;	
							codefile << "\tsub \t"+registroStr(reg)+", "+h0->get_valor()<< endl;	
						}
						if( nodo_value.compare("*") == 0){
							//codefile << "imulq $"+h0->get_valor()+" %"+registroStr(reg) +"\t#imulq S, D D ← D "+nodo_value+" S"<< endl;
							codefile << "\timul \t"+registroStr(reg)+", "+h0->get_valor()<< endl;		
						}
						if( nodo_value.compare("/") == 0){
							std::string dividend = registroStr(reg);
							std::string divisor = h0->get_valor();
							codefile <<"\tmov\trax,"+dividend<< endl;
							codefile <<"\tmov\trdx, 0"<<endl;
							codefile <<"\tdiv\t"+divisor<< endl;
							codefile <<"\tmov\t"+dividend+",rax"<< endl;
							//codefile << "divq $"+h0->get_valor()+" %"+registroStr(reg) +"\t#divq S, D D ← D "+nodo_value+" S"<< endl;	
						}
						//cout << "INT"+nodo_value+"CONS "+registroStr(reg)+" "+h0->get_valor() << endl;
					}else{
						if(isFloat(h0->get_valor())){
							codefile << ";Truco horrible para operar con una constante float"<< endl;
							codefile << ";cargandolo primero aun registro normal y memoria y de la memoria"<< endl;
							codefile << ";al registro xmm15"<< endl;
							codefile << "\tmov\tr15, __float64__("+h0->get_valor()+")"<< endl;
							codefile <<"\tmov\t[floattemp], r15" << endl;
							codefile <<"\tmovsd\txmm15, [floattemp]" << endl;
							if( nodo_value.compare("+") == 0){
								//codefile << "addss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#addss S, D D ← D "+nodo_value+" S"<< endl;
								codefile << "\taddsd \txmm"+std::to_string(reg)+", xmm15"<< endl;	
							}
							if( nodo_value.compare("-") == 0){
								//codefile << "subss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#subss S, D D ← D "+nodo_value+" S"<< endl;	
								codefile << "\tsubsd \txmm"+std::to_string(reg)+", xmm15"<< endl;	
							}
							if( nodo_value.compare("*") == 0){
								//codefile << "mulss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#mulss S, D D ← D "+nodo_value+" S"<< endl;
								codefile << "\tmulsd \txmm"+std::to_string(reg)+", xmm15"<< endl;		
							}
							if( nodo_value.compare("/") == 0){
								//codefile << "divss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#divss S, D D ← D "+nodo_value+" S"<< endl;	
								codefile << "\tdivsd \txmm"+std::to_string(reg)+", xmm15"<< endl;		
							}
						}else{
							if( nodo_value.compare("+") == 0){
								//codefile << "addss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#addss S, D D ← D "+nodo_value+" S"<< endl;
								codefile << "\taddsd \txmm"+std::to_string(reg)+", "+h0->get_valor()<< endl;	
							}
							if( nodo_value.compare("-") == 0){
								//codefile << "subss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#subss S, D D ← D "+nodo_value+" S"<< endl;	
								codefile << "\tsubsd \txmm"+std::to_string(reg)+", "+h0->get_valor()<< endl;	
							}
							if( nodo_value.compare("*") == 0){
								//codefile << "mulss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#mulss S, D D ← D "+nodo_value+" S"<< endl;
								codefile << "\tmulsd \txmm"+std::to_string(reg)+", "+h0->get_valor()<< endl;		
							}
							if( nodo_value.compare("/") == 0){
								//codefile << "divss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#divss S, D D ← D "+nodo_value+" S"<< endl;	
								codefile << "\tdivsd \txmm"+std::to_string(reg)+", "+h0->get_valor()<< endl;		
							}
						}
						//cout << "FLOAT"+nodo_value+"CONS "+registroStr(reg)+" "+h0->get_valor() << endl;
					}
				}else{
					genCodeOpera(h0, reg, tipo);
					if(tipo.compare("int") == 0){
						if( nodo_value.compare("+") == 0){
							//codefile << "addq $"+h1->get_valor()+" %"+registroStr(reg) +"\t#addq S, D D ← D "+nodo_value+" S"<< endl;	
							codefile << "\tadd \t"+registroStr(reg)+", "+h1->get_valor()<< endl;
						}
						if( nodo_value.compare("-") == 0){
							//codefile << "subq $"+h1->get_valor()+" %"+registroStr(reg) +"\t#subq S, D D ← D "+nodo_value+" S"<< endl;	
							codefile << "\tsub \t"+registroStr(reg)+", "+h1->get_valor()<< endl;	
						}
						if( nodo_value.compare("*") == 0){
							//codefile << "imulq $"+h1->get_valor()+" %"+registroSxmm"+std::to_string(reg)tr(reg) +"\t#imulq S, D D ← D "+nodo_value+" S"<< endl;
							codefile << "\timul \t"+registroStr(reg)+", "+h1->get_valor()<< endl;			
						}
						if( nodo_value.compare("/") == 0){
							std::string dividend = h1->get_valor();
							std::string divisor = registroStr(reg);
							codefile <<"\tmov\trax,"+dividend<< endl;
							codefile <<"\tmov\trdx, 0"<<endl;
							codefile <<"\tdiv\t"+divisor<< endl;
							codefile <<"\tmov\t"+divisor+",rax"<< endl;
							//codefile << "divq $"+h1->get_valor()+" %"+registroStr(reg) +"\t#divq S, D D ← D "+nodo_value+" S"<< endl;	

						}
						//cout << "INT"+nodo_value+"CONS "+registroStr(reg)+" "+h1->get_valor() << endl;
					}else{
						if(isFloat(h1->get_valor())){
							codefile << ";Truco horrible para operar con una constante float"<< endl;
							codefile << ";cargandolo primero aun registro normal y memoria y de la memoria"<< endl;
							codefile << ";al registro xmm15"<< endl;
							codefile << "\tmov\tr15, __float64__("+h1->get_valor()+")"<< endl;
							codefile <<"\tmov\t[floattemp], r15" << endl;
							codefile <<"\tmovsd\txmm15, [floattemp]" << endl;
							if( nodo_value.compare("+") == 0){
								//codefile << "addss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#addss S, D D ← D "+nodo_value+" S"<< endl;
								codefile << "\taddsd \txmm"+std::to_string(reg)+", xmm15"<< endl;	
							}
							if( nodo_value.compare("-") == 0){
								//codefile << "subss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#subss S, D D ← D "+nodo_value+" S"<< endl;	
								codefile << "\tsubsd \txmm"+std::to_string(reg)+", xmm15"<< endl;	
							}
							if( nodo_value.compare("*") == 0){
								//codefile << "mulss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#mulss S, D D ← D "+nodo_value+" S"<< endl;
								codefile << "\tmulsd \txmm"+std::to_string(reg)+", xmm15"<< endl;		
							}
							if( nodo_value.compare("/") == 0){
								//codefile << "divss $"+h0->get_valor()+" %xmm"+std::to_string(reg) +"\t#divss S, D D ← D "+nodo_value+" S"<< endl;	
								codefile << "\tdivsd \txmm"+std::to_string(reg)+", xmm15"<< endl;		
							}
						}else{
							if( nodo_value.compare("+") == 0){
								//codefile << "addss $"+h1->get_valor()+" %xmm"+std::to_string(reg) +"\t#addss S, D D ← D "+nodo_value+" S"<< endl;	
								codefile << "\taddsd \txmm"+std::to_string(reg)+", "+h1->get_valor()<< endl;	
							}
							if( nodo_value.compare("-") == 0){
								//codefile << "subss $"+h1->get_valor()+" %xmm"+std::to_string(reg) +"\t#subss S, D D ← D "+nodo_value+" S"<< endl;
								codefile << "\taddsd \txmm"+std::to_string(reg)+", "+h1->get_valor()<< endl;		
							}
							if( nodo_value.compare("*") == 0){
								//codefile << "mulss $"+h1->get_valor()+" %xmm"+std::to_string(reg) +"\t#mulss S, D D ← D "+nodo_value+" S"<< endl;
								codefile << "\tmulsd \txmm"+std::to_string(reg)+", "+h1->get_valor()<< endl;		
							}
							if( nodo_value.compare("/") == 0){
								//codefile << "divss $"+h1->get_valor()+" %xmm"+std::to_string(reg) +"\t#divss S, D D ← D "+nodo_value+" S"<< endl;	
								codefile << "\tdivsd \txmm"+std::to_string(reg)+", "+h1->get_valor()<< endl;	
							}
						}
						//cout << "FLOAT"+nodo_value+"CONS "+registroStr(reg)+" "+h1->get_valor() << endl;
					}

				}
		}else{
			genCodeOpera(nodo->get(0), reg, tipo);
			genCodeOpera(nodo->get(1), reg-1, tipo);

			if(tipo.compare("int") == 0){
				if( nodo_value.compare("+") == 0){
					//codefile << "addq %"+std::to_string(reg-1)+" %"+registroStr(reg) +"\t#addq S, D D ← D "+nodo_value+" S"<< endl;	
					codefile << "\tadd \t"+registroStr(reg)+", "+std::to_string(reg-1)<< endl;
				}
				if( nodo_value.compare("-") == 0){
					//codefile << "subq %"+std::to_string(reg-1)+" %"+registroStr(reg) +"\t#subq S, D D ← D "+nodo_value+" S"<< endl;	
					codefile << "\tsub \t"+registroStr(reg)+", "+std::to_string(reg-1)<< endl;
				}
				if( nodo_value.compare("*") == 0){
					//codefile << "imulq %"+std::to_string(reg-1)+" %"+registroStr(reg) +"\t#imulq S, D D ← D "+nodo_value+" S"<< endl;	
					codefile << "\timul \t"+registroStr(reg)+", "+std::to_string(reg-1)<< endl;
				}
				if( nodo_value.compare("/") == 0){
					std::string dividend = registroStr(reg);
					std::string divisor = registroStr(reg-1);
					codefile <<"\tmov\trax,"+dividend<< endl;
					codefile <<"\tmov\trdx, 0"<<endl;
					codefile <<"\tdiv\t"+divisor << endl;
					codefile <<"\tmov\t"+dividend+",rax"<< endl;
					//codefile << "divq %"+std::to_string(reg-1)+" %"+registroStr(reg) +"\t#divq S, D D ← D "+nodo_value+" S"<< endl;	
				}
				//cout << "INT"+nodo_value+" "+registroStr(reg)+" "+std::to_string(reg-1) << endl;	
			}else{
				if( nodo_value.compare("+") == 0){
					//codefile << "addss %xmm"+std::to_string(reg-1)+" %xmm"+std::to_string(reg) +"\t#addss S, D D ← D "+nodo_value+" S"<< endl;	
					codefile << "\taddsd \txmm"+std::to_string(reg)+", xmm"+std::to_string(reg-1)<< endl;				
				}
				if( nodo_value.compare("-") == 0){
					//codefile << "subss %xmm"+std::to_string(reg-1)+" %xmm"+std::to_string(reg) +"\t#subss S, D D ← D "+nodo_value+" S"<< endl;
					codefile << "\tsubsd \txmm"+std::to_string(reg)+", xmm"+std::to_string(reg-1)<< endl;					
				}
				if( nodo_value.compare("*") == 0){
					//codefile << "mulss %xmm"+std::to_string(reg-1)+" %xmm"+std::to_string(reg) +"\t#mulss S, D D ← D "+nodo_value+" S"<< endl;	
					codefile << "\tmulsd \txmm"+std::to_string(reg)+", xmm"+std::to_string(reg-1)<< endl;				
				}
				if( nodo_value.compare("/") == 0){
					//codefile << "divss %xmm"+std::to_string(reg-1)+" %xmm"+std::to_string(reg) +"\t#divss S, D D ← D "+nodo_value+" S"<< endl;
					codefile << "\tdivsd \txmm"+std::to_string(reg)+", xmm"+std::to_string(reg-1)<< endl;					
				}
				//cout << "FLOAT"+nodo_value+" "+registroStr(reg)+" "+std::to_string(reg-1) << endl;	
			}		
		}
		return;
	}

	if( nodo_value.compare("and") == 0 || nodo_value.compare("or") == 0){
		Nodo *h0 = nodo->get(0);
		Nodo *h1 = nodo->get(1);
		if (h0->num_vars() == 0 || h1->num_vars() == 0){
				if(h0->num_vars() == 0){
					std::string consvalue = "0";
					if (h0->get_valor().compare("true") == 0){
						consvalue = "1";
					}else{
						consvalue = "0";
					}
					genCodeOpera(h1, reg, tipo);
					//codefile <<nodo_value+"q $"+consvalue+" %"+registroStr(reg)  +"\t#"+nodo_value+"q S, D D ← D "+nodo_value+" S"<< endl;
					codefile << "\t"+nodo_value+"\t"+registroStr(reg)+", "+consvalue<< endl;					
					//cout <<"BOOL"+nodo_value+"CONS "+registroStr(reg)+" "+h0->get_valor() << endl;
				}else{ 
					std::string consvalue = "0";
					if (h1->get_valor().compare("true") == 0){
						consvalue = "1";
					}else{
						consvalue = "0";
					}
					genCodeOpera(h0, reg, tipo);
					//codefile <<nodo_value+"q $"+consvalue+" %"+registroStr(reg)  +"\t#"+nodo_value+"q S, D D ← D "+nodo_value+" S"<< endl;
					codefile << "\t"+nodo_value+"\t"+registroStr(reg)+", "+consvalue<< endl;					
					//cout <<"BOOL"+nodo_value+"CONS "+registroStr(reg)+" "+h1->get_valor() << endl;
				}			

		}else{
			genCodeOpera(nodo->get(0), reg, tipo);
			genCodeOpera(nodo->get(1), reg-1, tipo);
			//cout << "BOOL"+nodo_value+" "+registroStr(reg)+" "+std::to_string(reg-1) << endl;
			//codefile << nodo_value+"q %"+std::to_string(reg-1)+" %"+registroStr(reg) +"\t#"+nodo_value+"q S, D D ← D "+nodo_value+" S"<< endl;					
			codefile << "\t"+nodo_value+"\t"+registroStr(reg)+", "+std::to_string(reg-1)<< endl;					
		}
		return;
	}

	if(nodo_value.compare("not") == 0){
		//notq D D ← ˜D
		genCodeOpera(nodo->get(0), reg, tipo);
			//codefile << "notq %"+registroStr(reg) +"\t#notq D D ← ^D"<< endl;
			codefile << "\tnot \t"+registroStr(reg)<< endl;
		//cout << "BOOL"+nodo_value+" "+registroStr(reg) << endl;
		return;

	}

	//movq S, D ####D ← S
	if(tipo.compare("int") == 0){
		if (isNumber(nodo_value)){
			codefile << "\tmov \t"+registroStr(reg)+","+nodo_value<< endl;
		}else{
			codefile << "\tmov \t"+registroStr(reg)+", ["+nodo_value+"]"<< endl;
		}
		//codefile << "movq "+nodo_value+" %"+registroStr(reg)+"\t#movq S, D D ← S   LOAD"<< endl;
		//cout << "INT LOAD "+registroStr(reg)+" "+nodo_value << endl;
	}
	if(tipo.compare("bool") == 0){
		std::string consvalue = "0";
		if (nodo_value.compare("true") == 0 || nodo_value.compare("false") == 0){
			if (nodo_value.compare("true") == 0){
				consvalue = "1";
				codefile << "\tmov \t"+registroStr(reg)+", "+consvalue<< endl;
			}else{
				consvalue = "0";
				codefile << "\tmov \t"+registroStr(reg)+", "+consvalue<< endl;
			}
		}else{
		
			codefile << "\tmov \t"+registroStr(reg)+", ["+nodo_value+"]"<< endl;
		}
		//codefile << "movq "+consvalue+" %"+registroStr(reg)+"\t#movq S, D D ← S   LOAD"<< endl;
		//cout << "BOOL LOAD "+registroStr(reg)+" "+nodo_value << endl;
	}
	if(tipo.compare("float") == 0){
		if (isFloat(nodo_value)){
			codefile << ";Truco horrible para cargar una constante float a un registro xmm"<< endl;
			codefile << ";cargandolo primero aun registro normal y memoria y de la memoria"<< endl;
			codefile << ";al registro xmm"<< endl;
			codefile << "\tmov\tr15, __float64__("+nodo_value+")"<< endl;
			codefile <<"\tmov\t[floattemp], r15" << endl;
			codefile << "\tmovsd \txmm"+std::to_string(reg)+",[floattemp]"<< endl;
			//codefile << "\tmovsd \t"+registroStr(reg)+","+nodo_value<< endl;
		}else{
			codefile << "\tmovsd \txmm"+std::to_string(reg)+", ["+nodo_value+"]"<< endl;
		}
		//codefile << "movss "+nodo_value+" %xmm"+std::to_string(reg)+"\t#movss S, D D ← S   LOAD"<< endl;
		//cout << "FLOAT LOAD "+registroStr(reg)+" "+nodo_value << endl;
	}	
}


//Metodo que genera el codigo en x86-64 (PRINCIPAL)
void genCode(Nodo *nodo, TablaSimbolos *ts){	

  	int num_seqs = nodo->num_seqs();
	if (num_seqs == 1){

                Nodo *linea = nodo->get(0);
		std::string nodo_value = linea->get_valor();

		if( nodo_value.compare("bool") == 0 || nodo_value.compare("int") == 0 || nodo_value.compare("float") == 0 || nodo_value.compare("=") == 0){

			if(nodo_value.compare("=") == 0){
				Nodo *var = linea->get(0);
				Nodo *exp = linea->get(1);


                                Simbolo *sim1 = ts->look_up(var->get_valor());
				int tiposim = sim1->get_tipo();
				std::string tipo;
				//cout << "Varible:"+var->get_valor() << endl;
				//cout << "Tipo:"+tipo << endl;
				//cout << str(exp) << endl;
			
				//movq S, D ####D ← S
				if(tiposim == 0){
					tipo = "int";
					genCodeOpera(exp, exp->num_vars(), tipo);
					codefile << "\tmov \t["+var->get_valor()+"], "+registroStr(exp->num_vars())<< endl;
  					//codefile << "movq %"+registroStr(exp->num_vars())+" "+var->get_valor()+"\t#movq S, D D ← S   SAVE"<< endl;
					//cout << "INT SAVE "+registroStr(exp->num_vars())+" "+var->get_valor() << endl;
					//genCodeX8664(tipo, "SAVE", ""+registroStr(exp->num_vars()), var->get_valor());
				}
				if(tiposim == 2){
					tipo = "bool";
					genCodeOpera(exp, exp->num_vars(), tipo);
					codefile << "\tmov \t["+var->get_valor()+"], "+registroStr(exp->num_vars())<< endl;
  					//codefile << "movq %"+registroStr(exp->num_vars())+" "+var->get_valor()+"\t#movq S, D D ← S   SAVE"<< endl;
					//cout << "BOOL SAVE "+registroStr(exp->num_vars())+" "+var->get_valor() << endl;
					//genCodeX8664(tipo, "SAVE", ""+registroStr(exp->num_vars()), var->get_valor());
				}
				if(tiposim == 1){
					tipo = "float";
					genCodeOpera(exp, exp->num_vars(), tipo);
					codefile << "\tmovsd \t["+var->get_valor()+"], xmm"+std::to_string(exp->num_vars())<< endl;
  					//codefile << "movss %xmm"+std::to_string(exp->num_vars())+" "+var->get_valor()+"\t#movss S, D D ← S   SAVE"<< endl;
					//cout << "FLOAT SAVE "+std::to_string(exp->num_vars())+" "+var->get_valor() << endl;
					//genCodeX8664(tipo, "SAVE", ""+std::to_string(exp->num_vars()), var->get_valor());
				}

			}else{
				std::string tipo = linea->get_valor();
				Nodo *linea2 = linea->get(0);
				Nodo *var = linea2->get(0);
				Nodo *exp = linea2->get(1);
				//cout << "Tipo:"+tipo << endl;
				//cout << "Varible:"+var->get_valor() << endl;
				//cout << str(exp) << endl;


				//movq S, D D ← S
				//genCodeX8664(tipo, "SAVE", ""+registroStr(exp->num_vars()), var->get_valor());
				if(tipo.compare("int") == 0){
					genCodeOpera(exp, exp->num_vars(), tipo);
					codefile << "\tmov \t["+var->get_valor()+"], "+registroStr(exp->num_vars())<< endl;
  					//codefile << "movq %"+registroStr(exp->num_vars())+" "+var->get_valor()+"\t#movq S, D D ← S   SAVE"<< endl;
					//cout << "INT SAVE "+registroStr(exp->num_vars())+" "+var->get_valor() << endl;
				}
				if(tipo.compare("bool") == 0){
					codefile << "\tmov \t["+var->get_valor()+"], "+registroStr(exp->num_vars())<< endl;
					genCodeOpera(exp, exp->num_vars(), tipo);
  					//codefile << "movq %"+registroStr(exp->num_vars())+" "+var->get_valor()+"\t#movq S, D D ← S   SAVE"<< endl;
					//cout << "BOOL SAVE "+registroStr(exp->num_vars())+" "+var->get_valor() << endl;
				}
				if(tipo.compare("float") == 0){
					genCodeOpera(exp, exp->num_vars(), tipo);
					codefile << "\tmovsd \t["+var->get_valor()+"], xmm"+std::to_string(exp->num_vars())<< endl;
  					//codefile << "movss %xmm"+std::to_string(exp->num_vars())+" "+var->get_valor()+"\t#movss S, D D ← S   SAVE"<< endl;
					//cout << "FLOAT SAVE "+std::to_string(exp->num_vars())+" "+var->get_valor() << endl;
				}


			}

		}else{
			//cout << str(linea) << endl;
			//IGNORAMOS CALCULOS QUE NO TENGA ASIGNACION POR QUE SE SON CALCULOS QUE NO SE
			//USAN NUNCA
			//genCodeOpera(linea, linea->num_vars());
		}

	}else{
		int numhijos = nodo->num_hijos();
		for(int i = 0; i < numhijos; i++){
			genCode(nodo->get(i), ts);
		}
	}

}


//Metodo que evalua las contasntes dentro del arbol para simplificarlos (AUXILIAR)
std::string evalConstantsNodo(Nodo *nodo){

	int numhijos = nodo->num_hijos();
	std::string nodo_value = nodo->get_valor();

	if(numhijos == 0){
		return nodo->get_valor();
	}
	if(numhijos == 1){
		std::string new_val;
		std::string valh0 =  evalConstantsNodo(nodo->get(0));
		if ( nodo_value.compare("not") == 0){
			if (valh0.compare("true") == 0){
				new_val = "false";
			}else{
				new_val = "true";
			}
			return new_val;
		}else{
			cout << "evalNodo: NOOO DEBE PASAR" << endl;
			cout << nodo_value << endl;
		}
	}
	if(numhijos == 2){
		std::string new_val;
		std::string valh0 =  evalConstantsNodo(nodo->get(0));
		std::string valh1 =  evalConstantsNodo(nodo->get(1));

		if( nodo_value.compare("and") == 0 || nodo_value.compare("or") == 0 ){
			if( nodo_value.compare("and") == 0){
				if (valh0.compare("true") == 0 && valh1.compare("true") == 0){
					new_val = "true";
				}else{
					new_val = "false";
				}
			}
			if( nodo_value.compare("or") == 0){
				if (valh0.compare("true") == 0 || valh1.compare("true") == 0){
					new_val = "true";
				}else{
					new_val = "false";
				}
			}
			return new_val;
		}

		if( nodo_value.compare("+") == 0 || nodo_value.compare("-") == 0 || nodo_value.compare("*") == 0 || nodo_value.compare("/") == 0 ){
			if(isNumber(valh0)){
				int new_num = 0;
				int numh0 = std::stoi(valh0);
				int numh1 = std::stoi(valh1);
				if(nodo_value.compare("+") == 0){
					new_num = numh0 + numh1;
				}
				if(nodo_value.compare("-") == 0){
					new_num = numh0 - numh1;
				}
				if(nodo_value.compare("*") == 0){
					new_num = numh0 * numh1;
				}
				if(nodo_value.compare("/") == 0){
					new_num = numh0 / numh1;
				}
				return std::to_string(new_num);
			}else{
				float new_num = 0.0;
				float numh0 = std::atof(valh0.c_str());
				float numh1 = std::atof(valh1.c_str());
				if(nodo_value.compare("+") == 0){
					new_num = numh0 + numh1;
				}
				if(nodo_value.compare("-") == 0){
					new_num = numh0 - numh1;
				}
				if(nodo_value.compare("*") == 0){
					new_num = numh0 * numh1;
				}
				if(nodo_value.compare("/") == 0){
					new_num = numh0 / numh1;
				}
				return std::to_string(new_num);
			}
	
		}	
	}

}


//Metodo que evalua las contasntes dentro del arbol para simplificarlos  (PRINCIPAL)
void evalConstants(Nodo *nodo){
	std::string nodo_value = nodo->get_valor();
  	int num_vars = nodo->num_vars();
	

	if (num_vars == 0 && nodo_value.compare("seq") != 0){
		std::string val = evalConstantsNodo(nodo);
		while( nodo->num_hijos() > 0){
			Nodo *newnodo = nodo->pop_back();
		}
		nodo->set_valor(val);
	}else{
		int numhijos = nodo->num_hijos();
		for(int i = 0; i < numhijos; i++){
			evalConstants(nodo->get(i));
		}
	}

}


//Metodo que implementa el agoritmo Sehti-Ullman simple
int simpleSethUll(Nodo *nodo){

	//cout << "entro a: "+nodo->str() +"tiene "+ std::to_string(nodo->num_hijos()) +" hijos "<< endl;
	int vars = 0;
        std::string seqstr = "(seq)";
	int numhijos = nodo->num_hijos();
	if(seqstr.compare(nodo->str()) == 0){
		for(int i = 0; i < numhijos; i++){
			int vars_temp;
			vars_temp = simpleSethUll(nodo->get(i));

                        if (vars_temp > vars){
				vars = vars_temp;
			}

		}
	}else{
		if (numhijos == 2){

			//cout << nodo->get_valor()+": DOS hijos" << endl;
			int vars_temp1 = simpleSethUll(nodo->get(0));
			int vars_temp2 = simpleSethUll(nodo->get(1));
			if (vars_temp1 > vars_temp2){
				vars = vars_temp1;
			}else{
				if (vars_temp1 < vars_temp2){
					vars = vars_temp2;
				}else{
					if (vars_temp1 != 0	){
						vars = vars_temp1 + 1;
					}
				}
			}

		}else{
			if (numhijos == 1){
				//cout << nodo->get_valor()+": UN hijos" << endl;
				vars = simpleSethUll(nodo->get(0));
			}else{
				if (numhijos == 0){
					//cout << nodo->get_valor()+": NINGUN hijo" << endl;
					std::string nodo_value = nodo->get_valor();
					if ( isNumber(nodo_value) || isFloat(nodo_value) || nodo_value.compare("true") == 0  || nodo_value.compare("false") == 0  ){
						//cout << nodo_value+": Es INT FLOAT True o False" << endl;
						vars = 0;
					}else{
						//cout << nodo_value+": NO ES INT Numero FLOAT True o False" << endl;
						vars = 1;
					}
				}else{
					cout << "simpleSethUll: NOOoO DEBE PASRA" << endl;					
				}
			}
		}
	}
	//cout << nodo->str() +" "+ std::to_string(vars) << endl;
	nodo->set_num_vars(vars);
	return vars;	
}


//Metodo para generar el .data apartir del arbol
void genData(Nodo *nodo){	
	
  	int num_seqs = nodo->num_seqs();
	if (num_seqs == 1){
                Nodo *linea = nodo->get(0);
		std::string nodo_value = linea->get_valor();

		if( nodo_value.compare("bool") == 0 || nodo_value.compare("int") == 0 || nodo_value.compare("float") == 0){
			Nodo *var = linea->get(0);
			Nodo *exp = linea->get(1);
			if( nodo_value.compare("bool") == 0 || nodo_value.compare("int") == 0){
				codefile << var->get(0)->get_valor()+": \t dd\t 0"  << endl;		
			}else{
				codefile << var->get(0)->get_valor()+": \t dq\t 0.0"  << endl;		
			}
		}
	}else{
		int numhijos = nodo->num_hijos();
		for(int i = 0; i < numhijos; i++){
			genData(nodo->get(i));
		}
	}
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

        if(argc > 2) {
            string arg = argv[2];
            if(arg == "-a")
                archivos = true;
        }        

	do {
		yyparse();
	} while (!feof(yyin));
        

	//Obtenemos la tabla de simbolos y los nodos 
	TablaSimbolos *ts = vct->get_tabla();
        Nodo *root = nodos->back();

	//Abrimos el archivo para escribir el codigo generado
        codefile.open (archivo+".asm");

	//Generamos la marca de seqs los nodos que solo tiene una sequencia son los que "tiene" lineas de codigo
	transTreeSeqs(root);
	//Implementacion simple del algoritmo Sehti-Ullman
	simpleSethUll(root);
	//Este metodo simplifica el arbol es decir las operaciones que operan entre puras contasntes se simplifican en un solo nodo
	evalConstants(root);
	//Genera el codigo .data
	codefile << "\tsection .data" << endl;
	codefile << "message: db      \"TODO BIEN\", 9" << endl;
	codefile << "floattemp:\tdq\t 0.0 " << endl;

	genData(root);
	//Genera el codigo .text
	codefile << "\tsection .text" << endl;
	codefile << "\tglobal _start" << endl;
	codefile << "_start:" << endl;
	genCode(root, ts);

	//CODIGO para que imprma todo bien si todo sale bien
	codefile << "mov rax, 1" << endl;
	codefile << "mov rdi, 1" << endl;
	codefile << "mov rsi, message" << endl;
	codefile << "mov rdx, 13" << endl;
	codefile << "syscall" << endl;
	codefile << "mov eax, 60" << endl;
	codefile << "xor rdi, rdi" << endl;
	codefile << "syscall" << endl;

	//Cerramos el archivo
	codefile.close();

        clear();
}




void yyerror(const char *s) {
	cout << "Error! en línea " << linea << ", columna " << col << "  Mensaje: " << s << endl;
        clear();
	exit(-1);
}
