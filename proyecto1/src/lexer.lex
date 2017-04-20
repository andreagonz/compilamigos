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

queue<Nodo*> * nodos = new queue<Nodo*>;
%}
						
num	[0-9]+|[0-9]+\.[0-9]+
id	[a-zA-Z][a-zA-Z0-9_]*
tipo	bool|int|float
		       			
%%
{id}	{
	    col++;            
	}
{num}	{
	    col++;            
	}

{var}	{
	    col++;            
	}

"+"	{
	    col++;            
	}

"-"	{
	    col++;            
	}

"*"	{
	    col++;            
	}

"/"	{
	    col++;            
	}

"("	{
	    col++;            
	}

")"	{
	    col++;            
	}

";"	{
	    col++;            
	}

"="	{
	    col++;            
	}

"~fun"	{
	    col++;            
}

"~cond"	{
	    col++;            
}

"~while"	{
	    col++;            
}

"fun"	{
	    col++;            
}

"cond"	{
	    col++;            
}

"while"	{
	    col++;            
}

":"	{
	    col++;            
}

"|"	{
	    col++;            
}

"true"	{
	    col++;            
}

"false"	{
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
