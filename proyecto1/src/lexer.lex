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
	//cout << "Encontre un entero:" << yytext << endl;
        yylval.sval = yytext;
        col++;    
        return INT;
}

{float}	{
	//cout << "Encontre un flotante:" << yytext << endl;
        yylval.sval = yytext;
        col++;    
        return FLOAT;
}

"and" {
        //cout << "Encontre un and:" << yytext << endl;
        col = col + 3;
        return AND;
}

"or" { 
        //cout << "Encontre un or:" << yytext << endl;
        col = col + 2;
        return OR;
}

"not" { 
        //cout << "Encontre un not:" << yytext << endl;
        col = col + 3;
        return NOT;
}

"bool" {
        //cout << "Encontre un bool:" << yytext << endl;
        col = col + 4;
        return BOOLEANO;
}

"int" {
        //cout << "Encontre un int:" << yytext << endl;
        col = col + 3;
        return ENTERO;
}

"float" {
        //cout << "Encontre un float:" << yytext << endl;
        col = col + 5;
        return FLOTANTE;
}

	
"true" {
        //cout << "Encontre un true:" << yytext << endl;
        col = col + 4;
        return TRUE;
}

"false" {
        //cout << "Encontre un false:" << yytext << endl;
        col = col + 5;
        return FALSE;
}

"default" {
        //cout << "Encontre un default:" << yytext << endl;
        col = col + 7;
        return DEFAULT;
}

"fun"	{
        //cout << "Encontre un fun:" << yytext << endl;
        col = col + 3;
      return FUN;
}


"cond"	{
        //cout << "Encontre un cond:" << yytext << endl;
        col = col + 4;
      return COND;
}

"while"	{
        //cout << "Encontre un while:" << yytext << endl;
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
        //cout << "Encontre un ,:" << yytext << endl;
        col = col + 1;
      return COMMA;
}

"+"	{
        //cout << "Encontre un +:" << yytext << endl;
        col = col + 1;
      return PLUS;
}

"-"	{
        //cout << "Encontre un -:" << yytext << endl;
        col = col + 1;
        return MINUS;
}

"*"	{
        //cout << "Encontre un *:" << yytext << endl;
        col = col + 1;
        return MULT;
}

"/"	{
        //cout << "Encontre un /:" << yytext << endl;
        col = col + 1;
      return DIV;
}

"("	{
        //cout << "Encontre un ( :" << yytext << endl;
        col = col + 1;
      return LPAR;
}

")"	{
        //cout << "Encontre un ):" << yytext << endl;
        col = col + 1;
      return RPAR;
}

";"	{
        //cout << "Encontre un ; :" << yytext << endl;
        col = col + 1;
      return SEMIC;
}

"="	{
        //cout << "Encontre un = :" << yytext << endl;
        col = col + 1;
      return ASIG;
}

"~fun"	{
        //cout << "Encontre un ~fun:" << yytext << endl;
        col = col + 4;
      return ENDFUN;
}

"~cond"	{
        //cout << "Encontre un ~cond:" << yytext << endl;
        col = col + 5;
      return ENDCOND;
}

"~while"	{
        //cout << "Encontre un ~while:" << yytext << endl;
        col = col + 6;
      return ENDWHILE;
}


":"	{
        //cout << "Encontre un : :" << yytext << endl;
        col = col + 1;
      return DOTDOT;
}


{id}	{
        //cout << "Encontre un ID :" << yytext << endl;
        yylval.sval = strdup(yytext);
	col++;     
        return ID;
}

"==" {
        //cout << "Encontre un == :" << yytext << endl;
        col = col + 2;
      return EQ;
}

"!=" {
        //cout << "Encontre un != :" << yytext << endl;
        col = col + 2;
    return NEQ;
}

"<" {
        //cout << "Encontre un < :" << yytext << endl;
        col = col + 1;
      return LESS;
}

">" {
        //cout << "Encontre un >:" << yytext << endl;
        col = col + 1;
      return GREAT;
}

"<=" {
        //cout << "Encontre un <= :" << yytext << endl;
        col = col + 2;
        return LESSEQ;
}

">=" {
        //cout << "Encontre un >= :" << yytext << endl;
        col = col + 2;
        return GREATEQ;
}


"|" {
        //cout << "Encontre un | :" << yytext << endl;
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

