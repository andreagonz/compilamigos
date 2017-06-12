#include "tabla.h"
#include<iostream>

using namespace std;


string tstr(Tipo t) {
    if(t == TINT)
        return"int";
    if(t == TFLOAT)
        return"float";
    if(t == TBOOL)
        return"bool";
    return "T";
}

Tipo Simbolo::get_tipo() {
    return tipo;
}

bool Simbolo::es_fun() {
    return fun;
}

void Simbolo::add_arg(Tipo t) {
    args.push_back(t);
}

int Simbolo::num_args() {
    return args.size();
}

Tipo Simbolo::get_arg(int i) {
    return args[i];
}

string Simbolo::str() {
    string s = tstr(tipo) + ": " + nombre;
    return s;
}

Tabla * Tabla::get_padre() {
    return padre;
}

int Tabla::num_hijos() {
    return hijos.size();
}

void Tabla::guarda_simbolo(string s, Simbolo * simb) {
    simbolos[s] = simb;
}

Simbolo * Tabla::get_simbolo(string s) {
    if(simbolos.find(s) != simbolos.end())
        return simbolos[s];
    return NULL;
}

Tabla * Tabla::get(int i) {
    if(i < hijos.size())
        return hijos[i];
    return NULL;
}

string Tabla::str() {
    string s = "{";
    int i = 0;
    for (auto it : simbolos) {
        s += it.second->str();
        if(i < simbolos.size() - 1)
            s += ", ";
        i++;
    }
    s += "}";
    return s;
}

void Tabla::add_hijo(Tabla * t) {
    hijos.push_back(t);
}

void TablaSimbolos::insert(string s, Simbolo * simb) {
    if(actual != NULL)
        actual->guarda_simbolo(s, simb);
}

void TablaSimbolos::open_scope() {
    if(actual != NULL) {
        Tabla * t = new Tabla(actual);
        actual->add_hijo(t);
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

Tabla * TablaSimbolos::get_raiz() {
    return raiz;
}

/* Regresa la representación en cadena del árbol desde el nodo n */
string tstr(Tabla * n) {
    int p = tprofundidad(n) + 1;
    bool rama[p];
    for (int i = 0; i < p; i++)
        rama[i] = false;    
    string s = taCadena(n, 0, rama);
    return s.substr(0, s.length()-1);
}

string taCadena(Tabla * t, int nivel, bool rama[]) {
    string s = t->str() + "\n";
    rama[nivel] = true;
    for(int i = 0; i < t->num_hijos(); i++) {
        s += tespacios(nivel, rama);
        rama[nivel] = true;
        if(i < t->num_hijos() - 1)
            s += "├─›";
        else {
            s += "└─›";
            rama[nivel] = false;
        }
        s += taCadena(t->get(i), nivel + 1, rama);
    }
    return s;
}

string tespacios(int n, bool rama[]) {
    string s = "";
    for (int i = 0; i < n; i++)
        if (rama[i])
            s += "│  ";
        else
            s += "   ";
    return s;
}

/* Calcula la profundidad del árbol desde el nodo v */
int tprofundidad(Tabla * t){
    int max = -1;
    for(int i = 0; i < t->num_hijos(); i++) {
        int p = tprofundidad(t->get(i));
        if(p > max)
            max = p;
    }    
    return max + 1;
}
