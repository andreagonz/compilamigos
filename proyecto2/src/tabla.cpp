#include "tabla.h"
#include<iostream>

using namespace std;

Tipo Simbolo::get_tipo() {
    return tipo;
}

Tabla * Tabla::get_padre() {
    return padre;
}

void Tabla::guarda_simbolo(string s, Simbolo * simb) {
    simbolos[s] = simb;
}

Simbolo * Tabla::get_simbolo(string s) {
    if(simbolos.find(s) != simbolos.end())
        return simbolos[s];
    return NULL;
}

void TablaSimbolos::insert(string s, Simbolo * simb) {
    if(actual != NULL)
        actual->guarda_simbolo(s, simb);
}

void TablaSimbolos::open_scope() {
    if(actual != NULL) {
        Tabla * t = new Tabla(actual);
        actual = t;
    }
}

void TablaSimbolos::close_scope() {
    if(actual != NULL)
        actual = actual->get_padre();
}

bool TablaSimbolos::declared_locally(string s) {
    return actual->get_simbolo(s) != NULL;
}

Simbolo * TablaSimbolos::look_up(string s) {
    if(declared_locally(s))
        return actual->get_simbolo(s);
    Tabla * t = actual;
    while(t->get_padre() != NULL) {
        if(t->get_padre()->get_simbolo(s) != NULL)
            return t->get_padre()->get_simbolo(s);
	t = t->get_padre();
    }
    return NULL;
}
