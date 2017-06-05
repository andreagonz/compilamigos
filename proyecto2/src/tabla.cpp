#include "tabla.h"

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
    return nullptr;
}

void TablaSimbolos::insert(string s, Simbolo * simb) {
    if(actual != nullptr)
        actual->guarda_simbolo(s, simb);
}

void TablaSimbolos::open_scope() {
    if(actual != nullptr) {
        Tabla * t = new Tabla(actual);
        actual = t;
    }
}

void TablaSimbolos::close_scope() {
    if(actual != nullptr)
        actual = actual->get_padre();
}

bool TablaSimbolos::declared_locally(string s) {
    return actual->get_simbolo(s) != nullptr;
}

Simbolo * TablaSimbolos::look_up(string s) {
    if(declared_locally(s))
        return actual->get_simbolo(s);
    while(actual->get_padre() != nullptr) {
        if(actual->get_padre()->get_simbolo(s) != nullptr)
            return actual->get_padre()->get_simbolo(s);
    }
    return nullptr;
}
