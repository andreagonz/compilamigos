#include "nodo.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

Nodo * Nodo::get(int i) {
  return hijos[i];
}

void Nodo::set(int i, Nodo * n) {
  hijos[i] = n;
}

void Nodo::add(Nodo * n) {
  hijos.push_back(n);
}

string Nodo::str() {
    return "(" + valor + ")";
}

string Nodo::get_valor() {
    return valor;
}

int Nodo::num_hijos() {
    return hijos.size();
}

Nodo * Nodo::pop_back() {
  Nodo * t = hijos.back();
  hijos.pop_back();
  return  t;
}

void transfer(Nodo *n, Nodo *m, int i) {
  if(m->num_hijos() == 0)
    return;
  if(m->num_hijos() == 1) {
    n->get(i)->add(m->pop_back());
    if(m->num_hijos() > 0)
      n->add(m->pop_back());
    return;
  }
  n->get(i)->add(m->pop_back());
  n->add(m->pop_back());
  transfer(n,m->get(0), i+1);
}

/* Regresa la representación en cadena del árbol desde el nodo n */
string str(Nodo * n) {
    int p = profundidad(n) + 1;
    bool rama[p];
    for (int i = 0; i < p; i++)
        rama[i] = false;    
    string s = aCadena(n, 0, rama);
    return s.substr(0, s.length()-1);
}

string aCadena(Nodo * vertice, int nivel, bool rama[]) {
    string s = vertice->str() + "\n";
    rama[nivel] = true;
    for(int i = 0; i < vertice->num_hijos(); i++) {
        s += espacios(nivel, rama);
        rama[nivel] = true;
        if(i < vertice->num_hijos() - 1)
            s += "├─›";
        else {
            s += "└─›";
            rama[nivel] = false;
        }
        s += aCadena(vertice->get(i), nivel + 1, rama);
    }
    return s;
}

string espacios(int n, bool rama[]) {
    string s = "";
    for (int i = 0; i < n; i++)
        if (rama[i])
            s += "│  ";
        else
            s += "   ";
    return s;
}

/* Calcula la profundidad del árbol desde el nodo v */
int profundidad(Nodo * v){
    int max = -1;
    for(int i = 0; i < v->num_hijos(); i++) {
        int p = profundidad(v->get(i));
        if(p > max)
            max = p;
    }    
    return max + 1;
}
