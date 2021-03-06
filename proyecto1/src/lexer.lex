%{
#include "nodo.h"
#include <string>
#include <iostream>
#include "parser.tab.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
int linea = 1;
int col = 1;

%}

int	[0-9]+
float   [0-9]+\.[0-9]+
id	[a-zA-Z][a-zA-Z0-9_]*

%%

{int}	{
        yylval.sval = yytext;
        col++;    
        return INT;
}

{float}	{
        yylval.sval = yytext;
        col++;    
        return FLOAT;
}

"and" {
        col = col + 3;
        return AND;
}

"or" { 
        col = col + 2;
        return OR;
}

"not" { 
        col = col + 3;
        return NOT;
}

"bool" {
        col = col + 4;
        return BOOLEANO;
}

"int" {
        col = col + 3;
        return ENTERO;
}

"float" {
        col = col + 5;
        return FLOTANTE;
}

	
"true" {
        col = col + 4;
        return TRUE;
}

"false" {
        col = col + 5;
        return FALSE;
}

"default" {
        col = col + 7;
        return DEFAULT;
}

"fun"	{
        col = col + 3;
      return FUN;
}


"cond"	{
        col = col + 4;
      return COND;
}

"while"	{
        col = col + 5;
      return WHILE;
}

"return"	{
        col = col + 6;
      return RETURN;
}

"void"	{
        col = col + 4;
      return VOID;
}

"," {
        col = col + 1;
      return COMMA;
}

"+"	{
        col = col + 1;
      return PLUS;
}

"-"	{
        col = col + 1;
        return MINUS;
}

"*"	{
        col = col + 1;
        return MULT;
}

"/"	{
        col = col + 1;
      return DIV;
}

"("	{
        col = col + 1;
      return LPAR;
}

")"	{
        col = col + 1;
      return RPAR;
}

";"	{
        col = col + 1;
      return SEMIC;
}

"="	{
        col = col + 1;
      return ASIG;
}

"~fun"	{
        col = col + 4;
      return ENDFUN;
}

"~cond"	{
        col = col + 5;
      return ENDCOND;
}

"~while"	{
        col = col + 6;
      return ENDWHILE;
}


":"	{
        col = col + 1;
      return DOTDOT;
}


{id}	{
        yylval.sval = strdup(yytext);
	col++;     
        return ID;
}

"==" {
        col = col + 2;
      return EQ;
}

"!=" {
        col = col + 2;
    return NEQ;
}

"<" {
        col = col + 1;
      return LESS;
}

">" {
        col = col + 1;
      return GREAT;
}

"<=" {
        col = col + 2;
        return LESSEQ;
}

">=" {
        col = col + 2;
        return GREATEQ;
}


"|" {
        col = col + 1;
        return PIPE;
}


[ \t\r]	{

        col = col + 1;
}

[\n]	{
	    linea++;
	    col = 1;
}

.	{
	    cout << "Carácter no reconocido en línea " << linea << ", columna " << col << ": " <<  yytext[0] << "\n";
	    exit(1);
}

%%

