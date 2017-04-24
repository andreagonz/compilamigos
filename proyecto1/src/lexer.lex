%option C++ noyywrap

%{
#include <fstream>
#include <string>
#include "nodo.h"

    
using namespace std;
int linea = 1;
int col = 1;

%}

int	[0-9]+
float   [0-9]+\.[0-9]+
id	[a-zA-Z][a-zA-Z0-9_]*
tipo	["bool""int""float"]

%%
{tipo}	{
          col++;            
}

{int}	{
        col++;    
        return INT;
}

{float}	{
        col++;    
        return INT;
}

"," {
      col++;
      return COMMA;
}

"+"	{
      col++;    
      return '+';
}

"-"	{
        col++;     
        return '-';
}

"*"	{
        col++;      
        return '*';
}

"/"	{
	    col++;  
      return '/';
}

"("	{
	    col++;    
      return LPAR;
}

")"	{
	    col++;
      return RPAR;
}

";"	{
	    col++; 
      return SEMIC;
}

"="	{
	    col++; 
      return ASIG;
}

"~fun"	{
	    col++;    
      return ENDFUN;
}

"~cond"	{
	    col++;  
      return ENDCOND;
}

"~while"	{
	    col++;     
      return ENDWHILE;
}


"fun"	{
	    col++;    
      return FUN;
}


"cond"	{
	    col++;      
      return COND;
}

"while"	{
	    col++;     
      return WHILE;
}

":"	{
	    col++; 
      return DOTDOT;
}

"|"	{
	    col++; 
      return PIPE;
}

{id}	{
	    col++;     
      return ID;
}

"==" {
      col++;
      return EQ;
}

"!=" {
    col++;
    return NEQ;
}

"<" {
      col++;
      return LESS;
}

">" {
      col++;
      return GREAT;
}

"<=" {
        col++;
        return LESSEQ;
}

">=" {
        col++;
        return GREATEQ;
}

"&&" {
        col++;
        return AND;
}

"||" { 
        col++;
        return OR;
}

"!" {
        col++;
        return NOT;
}

"true" {
        col++;
        return TRUE;
}

"false" {
        col++;
        return FALSE;
}

"default" {
        col++;
        return DEFAULT;
}

[ \t\r]	{
	    col++;
}

[\n]	{
	    linea++;
	    col = 1;
}

<<EOF>> {
          return 0;
}

.	{
	    cout << "Carácter no reconocido en línea " << linea << ", columna " << col << ": " <<  yytext[0] << "\n";
            /* clear(tokens, nodos); */
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
