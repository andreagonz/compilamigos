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
        if(i < vertice->num_hijos() - 1)
            s += "├─›";
        else
            s += "└─»";
        s += aCadena(vertice->get(i), nivel + 1, rama);
        rama[nivel] = false;
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

int profundidad(Nodo * v){
    int max = -1;
    for(int i = 0; i < v->num_hijos(); i++) {
        int p = profundidad(v->get(i));
        if(p > max)
            max = p;
    }    
    return max + 1;
}

string crea_circ(Nodo * n, double x, double y){
    return string("\n    <circle cx='") + to_string(x) + "' cy='" + to_string(y) + "' r='7' "
        + "style='fill:white;stroke:black;stroke-width:1' />"
        + "\n    <text fill='black' font-family='Arial' "
        + "font-size='5px' x='" + to_string(x) + "' y='" + to_string(y + 1) + "' text-anchor='middle' "
        + "font-weight='bold'>" + n->get_valor() + "</text>";
}

string crea_lin(double x1, double y1, double x2, double y2) {
    return string("\n    <line x1='") + to_string(x1) + "' y1='" + to_string(y1) + "' x2='" + to_string(x2) + "' y2='" + to_string(y2) + "' "
        + "style='stroke:black;stroke-width:1.3' />";
}

string vacio(){
    return string("<?xml version='1.0' encoding='UTF-8' ?>")
        + "\n<svg width='65' height='11'>" 
        + "\n  <g>"
        + "\n    <text fill='black' font-family='Arial' font-size='12px' "
        + "x='0' y='11' font-weight='bold'>&#193;rbol vac&#237;o</text>"
        + "\n  </g>"
        + "\n</svg>";
}

string circulos(Nodo * n, double x, double y, double h, string s) {
    if(n->num_hijos() == 0)
        return s;
    if(n->num_hijos() == 1) 
        s += circulos(n->get(0), x, y + 80, h / n->num_hijos(),
                      crea_circ(n->get(0), x, y + 80));
    else if(n->num_hijos() % 2 == 0) {
        cout << "x: " << x << endl;
        cout << "h: " << h << endl;        
        int init = x - (h / n->num_hijos()) * (n->num_hijos() / 2);
        cout << "init: " << init << endl;
        for(int i = 0; i < n->num_hijos(); i++) {
            s += circulos(n->get(i), init, y + 80, h / n->num_hijos(),
                          crea_circ(n->get(i), init, y + 80));
            init += h / n->num_hijos();
            if(i == (n->num_hijos() / 2) - 1)
                init += h / n->num_hijos();
        }
    }
    else {
        cout << "x: " << x << endl;
        cout << "h: " << h << endl;        
        int init = x - (h / n->num_hijos()) * (n->num_hijos() / 2);
        cout << "init: " << init << endl;
        for(int i = 0; i < n->num_hijos(); i++) {
            s += circulos(n->get(i), init, y + 80, h / n->num_hijos(),
                          crea_circ(n->get(i), init, y + 80));
            init += h / n->num_hijos();
        }
    }
    return s;
}

string lineas(Nodo * n, double x, double y, double h, string s) {
    if(n->num_hijos() == 0)
        return s;
    if(n->num_hijos() == 1)
        s += lineas(n->get(0), x, y + 80, h / n->num_hijos(),
		    crea_lin(x, y, x, y + 80));
    else if(n->num_hijos() % 2 == 0) {
        cout << "x: " << x << endl;
        cout << "h: " << h << endl;        
        int init = x - (h / n->num_hijos()) * (n->num_hijos() / 2);
        cout << "init: " << init << endl;
        for(int i = 0; i < n->num_hijos(); i++) {
            s += lineas(n->get(i), init, y + 80, h / n->num_hijos(),
                        crea_lin(x, y, init, y + 80));
            init += h / n->num_hijos();
            if(i == (n->num_hijos() / 2) - 1)
                init += h / n->num_hijos();
        }
    }
    else {
        cout << "x: " << x << endl;
        cout << "h: " << h << endl;        
        int init = x - (h / n->num_hijos()) * (n->num_hijos() / 2);
        cout << "init: " << init << endl;
        for(int i = 0; i < n->num_hijos(); i++) {
            s += lineas(n->get(i), init, y + 80, h / n->num_hijos(),
                        crea_lin(x, y, init, y + 80));
            init += h / n->num_hijos();
        }
    }
    return s;
}

string str_svg(Nodo * n) {
    if(!n)
        return vacio();
    int p = profundidad(n);
    double h = (p * 80) + 15.495;
    double w = (pow(2, p) - 1) * 20;
    string s = string("<?xml version='1.0' encoding='UTF-8' ?>")
        + "\n<svg width='" + to_string(w * 2) + "' height='" + to_string(h) + "'>"
        + "\n  <g>";
    s += lineas(n, w, 7.6, w / n->num_hijos(), "");
    s += circulos(n, w, 7.6, w / n->num_hijos(), crea_circ(n, w, 7.6));
    s += "\n  </g>\n</svg>";
    return s;
}
