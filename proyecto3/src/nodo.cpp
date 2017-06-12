#include "nodo.h"
#include "tabla.h"
#include "visitor.h"
#include <string>
#include <iostream>
#include <math.h>


//Se le agregaron metodos y propiedades para implemtnar el algoritmo de Sehti-Ullman y para contabailisar las seqs 
//vars y seqs
using namespace std;

Nodo * Nodo::get(int i) {
  return hijos[i];
}

void Nodo::set_valor(std::string val){
	valor = val;
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

void Nodo::set_num_seqs(int n) {
  seqs = n;
}

int Nodo::num_seqs() {
    return seqs;
}

void Nodo::set_num_vars(int n) {
  vars = n;
}

int Nodo::num_vars() {
    return vars;
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

void NodoId::set_simbolo(Simbolo * s) {
    simbolo = s;
}

Tipo NodoId::get_tipo() {
    return simbolo->get_tipo();
}

Tipo NodoTipo::get_tipo() {
    return tipo;
}

Simbolo * NodoId::get_simbolo() {
    return simbolo;
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
    //string s = vertice->str() +" Vars: "+std::to_string(vertice->num_vars()) +"\n";
    //string s = vertice->str() +" Seqs: "+std::to_string(vertice->num_seqs()) +"\n";
    //string s = vertice->str() +" Vars: "+std::to_string(vertice->num_vars())+" Seqs: "+std::to_string(vertice->num_seqs()) +"\n";
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

void NodoInt::accept(Visitor * v) {
    v->visitaNodoInt(this);
}
   
void NodoFloat::accept(Visitor * v) {
    v->visitaNodoFloat(this);
}
 
void NodoBool::accept(Visitor * v) {
    v->visitaNodoBool(this);
}
  
void NodoSum::accept(Visitor * v) {
    v->visitaNodoSum(this);
}
   
void NodoMenos::accept(Visitor * v) {
    v->visitaNodoMenos(this);
}
 
void NodoMult::accept(Visitor * v) {
    v->visitaNodoMult(this);
}
  
void NodoDiv::accept(Visitor * v) {
    v->visitaNodoDiv(this);
}
   
void NodoNeg::accept(Visitor * v) {
    v->visitaNodoNeg(this);
}
   
void NodoEq::accept(Visitor * v) {
    v->visitaNodoEq(this);
}
    
void NodoNeq::accept(Visitor * v) {
    v->visitaNodoNeq(this);
}
   
void NodoLess::accept(Visitor * v) {
    v->visitaNodoLess(this);
}
  
void NodoGreat::accept(Visitor * v) {
    v->visitaNodoGreat(this);
}
 
void NodoLessEq::accept(Visitor * v) {
    v->visitaNodoLessEq(this);
}

void NodoGreatEq::accept(Visitor * v) {
    v->visitaNodoGreatEq(this);
}

void NodoAnd::accept(Visitor * v) {
    v->visitaNodoAnd(this);
}
   
void NodoOr::accept(Visitor * v) {
    v->visitaNodoOr(this);
}
    
void NodoAsig::accept(Visitor * v) {
    v->visitaNodoAsig(this);
}
  
void NodoNot::accept(Visitor * v) {
    v->visitaNodoNot(this);
}
   
void NodoId::accept(Visitor * v) {
    v->visitaNodoId(this);
}
    
void NodoTipo::accept(Visitor * v) {
    v->visitaNodoTipo(this);
}
void NodoSeq::accept(Visitor * v) {
    v->visitaNodoSeq(this);
}
