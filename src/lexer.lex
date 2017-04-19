%option C++ noyywrap

%{
#include <fstream>
#include <queue>
#include <string>
#include "Nodo"
#include "Token"
    
using namespace std;
int linea = 1;
int col = 1;
queue<Token*> * tokens = new queue<Token*>;
queue<Nodo*> * nodos = new queue<Nodo*>;
%}
						
num	[0-9]+|[0-9]+\.[0-9]+
id	[a-zA-Z][a-zA-Z0-9_]*
tipo	bool|int|float
		       			
%%
{id}	{
	    Token * t = new Token(PVAR, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}
{num}	{
	    Token * t = new Token(NUM, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}

{var}	{
	    Token * t = new Token(VAR, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}

"+"	{

	    Token * t = new Token(MAS, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}

"-"	{
	    Token * t = new Token(MENOS, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}

"*"	{
	    Token * t = new Token(MULT, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}

"/"	{
	    Token * t = new Token(DIV, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}

"("	{
	    Token * t = new Token(IZQ, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}

")"	{
	    Token * t = new Token(DER, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}

";"	{
	    Token * t = new Token(SEQ, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}

"="	{
	    Token * t = new Token(ASIG, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
	}

"~fun" {
	    Token * t = new Token(END_FUN, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
}

"~cond"{
	    Token * t = new Token(END_COND, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
}

"~while"{
	    Token * t = new Token(END_WHILE, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
}

"fun"{
	    Token * t = new Token(FUN, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
}

"cond"{
	    Token * t = new Token(COND, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
}

"while"{
	    Token * t = new Token(WHILE, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
}

":"{
	    Token * t = new Token(DOSP, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
}

"|"{
	    Token * t = new Token(PIPE, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
}

"true"{
	    Token * t = new Token(TRUE, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
}

"false"{
	    Token * t = new Token(FALSE, YYText(), linea, col);
	    tokens->push(t);
	    col++;            
}

[ \t\r]	{
	    col++;
	}

[\n]	{
	    linea++;
	    col = 1;
	}
.	{
	    cout << "Carácter no reconocido en línea " << linea << ", columna " << col << ": " <<  yytext[0] << "\n";
            clear(tokens, nodos);
	    exit(1);
	}
%%

int main( int argc, char **argv ) {
    ifstream in(argv[1]);
    if(argc < 2) {
        cout << "Uso: ./kyc-ip <archivo.txt>" << endl;
        return 1;
    }
        
    if(!in.is_open()) {
        cout << "Archivo inválido" << endl;
        return 1;
    }
    
    FlexLexer* lexer = new yyFlexLexer(in, cout);
    lexer->yylex();
    in.close();
 
    return 0;
}
