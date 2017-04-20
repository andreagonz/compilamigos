#ifndef NODO_H
#define NODO_H

#include<string>

class Nodo {
protected:
    Nodo *izq;
    Nodo *der;
    std::string valor;
public:
Nodo(std::string v): der(0), izq(0), valor(v) {}
    Nodo * get_izq(void);
    Nodo * get_der(void);
    std::string get_valor(void);
    void set_izq(Nodo * n);
    void set_der(Nodo * n);
    std::string str(void);
};

class NodoSum: public Nodo {
public:
NodoSum(std::string v): Nodo(v) {}
};

class NodoMenos: public Nodo {
public:
NodoMenos(std::string v): Nodo(v) {}
};

class NodoNeg: public Nodo {
public:
NodoNeg(std::string v): Nodo(v) {}
};

class NodoDiv: public Nodo {
public:
NodoDiv(std::string v): Nodo(v) {}
};

class NodoMult: public Nodo {
public:
NodoMult(std::string v): Nodo(v) {}
};

class NodoNum: public Nodo {
public:
NodoNum(std::string v): Nodo(v) {}
};

class NodoVar: public Nodo {
public:
NodoVar(std::string v): Nodo(v) {}
};

class NodoAsig: public Nodo {
public:
NodoAsig(std::string v): Nodo(v) {}
};

class NodoSeq: public Nodo {
public:
NodoSeq(std::string v): Nodo(v) {}
};

std::string str(Nodo * n);

std::string aCadena(Nodo * vertice, int nivel, bool rama[]);

std::string espacios(int n, bool rama[]);

int profundidad(Nodo * v);

#endif
