#ifndef NODO_H
#define NODO_H

#include <vector>
#include <string>
#include "tabla.h"

class Visitor;

class Nodo {
protected:
    std::vector<Nodo*> hijos;
    std::string valor;
public:
Nodo(std::string v): valor(v) {}
    Nodo * get(int i);
    std::string get_valor(void);
    void set(int i, Nodo *n);
    void add(Nodo *n);
    std::string str(void);
    int num_hijos();
    Nodo * pop_back();
    virtual void accept(Visitor * v) = 0;
};

/**
 * Nodos valor
 */

class NodoInt: public Nodo {
public:
NodoInt(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoFloat: public Nodo {
public:
NodoFloat(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoBool: public Nodo{
public:
NodoBool(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

/** TERMINA SECCION DE VALORES */

/**
 * Nodos de operaciones 
 */
class NodoSum: public Nodo {
public:
NodoSum(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoMenos: public Nodo {
public:
NodoMenos(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoNeg: public Nodo {
public:
NodoNeg(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoDiv: public Nodo {
public:
NodoDiv(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoMult: public Nodo {
public:
NodoMult(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoEq: public Nodo {
public:
NodoEq(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoNeq: public Nodo {
public:
NodoNeq(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoLess: public Nodo {
public:
NodoLess(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoGreat: public Nodo {
public:
NodoGreat(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoLessEq: public Nodo {
public:
NodoLessEq(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoGreatEq: public Nodo {
public:
NodoGreatEq(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoAnd: public Nodo {
public:
NodoAnd(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoOr: public Nodo {
public:
NodoOr(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoAsig: public Nodo {
public:
NodoAsig(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoNot: public Nodo {
public:
NodoNot(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

/** TERMINA SECCION DE SIMBOLOS DE OPERACIONES */


/**
 * Seccion variables
 */

class NodoId: public Nodo {
    Simbolo * simbolo;
public:
NodoId(std::string v): Nodo(v) {}
    void accept(Visitor * v);
    void set_simbolo(Simbolo * t);
    Tipo get_tipo(void);
};

class NodoTipo: public Nodo {
    Tipo tipo;
public:
NodoTipo(std::string v, Tipo t): Nodo(v), tipo(t) {}
    Tipo get_tipo();
    void accept(Visitor * v);
};

/** TERMINA SECCION DE SIMBOLOS DE OPERACIONES */


/**
 * Seccion de bloques
 */

class NodoFunDef: public Nodo {
public:
NodoFunDef(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoFun: public Nodo {
public:
NodoFun(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoWhile: public Nodo {
public:
NodoWhile(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoCond: public Nodo {
public:
NodoCond(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoCuerpo: public Nodo {
public:
NodoCuerpo(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoPipe: public Nodo {
public:
NodoPipe(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoDefault: public Nodo {
public:
NodoDefault(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

/** TERMINA SECCION DE BLOQUES */

/**
 *  regidores
 */
class NodoComa: public Nodo {
public:
NodoComa(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoSeq: public Nodo {
public:
NodoSeq(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};

class NodoReturn: public Nodo {
public:
NodoReturn(std::string v): Nodo(v) {}
    void accept(Visitor * v);
};


/** TERMINA SECCION DE REGIDORES */

std::string str(Nodo * n);

std::string aCadena(Nodo * vertice, int nivel, bool rama[]);

std::string espacios(int n, bool rama[]);

int profundidad(Nodo * v);

void transfer(Nodo *n, Nodo *m, int i);

#endif
