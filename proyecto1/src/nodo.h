#ifndef NODO_H
#define NODO_H
#include <vector>
#include <string>

class Nodo {
 protected:
  std::vector<Nodo> hijos(2); //al menos tendra dos hijos
  std::string valor;
 public:
 Nodo(std::string v): valor(v) {}
  Nodo * get(int i);
  std::string get_valor(void);
  void set(int i, Nodo *n);
  std::string str(void);
};

/**
 * Nodos valor
 */

class NodoInt: public Nodo {
 public:
 NodoInt(std::string v): Nodo(v) {}
};

class NodoFloat: public Nodo {
 public:
 NodoFloat(std::string v): Nodo(v) {}
};

class NodoBool: public Nodo{
 public:
 NodoBool(std::string v): Nodo(v) {}
};

/** TERMINA SECCION DE VALORES */

/**
 * Nodos de operaciones 
 */
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

class NodoEq: public Nodo {
 public:
 NodoEq(std::string v): Nodo(v) {}
};

class NodoNeq: public Nodo {
 public:
 NodoNeq(std::string v): Nodo(v) {}
};

class NodoLess: public Nodo {
 public:
 NodoLess(std::string v): Nodo(v) {}
};

class NodoGreat: public Nodo {
 public:
 NodoGreat(std::string v): Nodo(v) {}
};

class NodoLessEq: public Nodo {
 public:
 NodoLessEq(std::string v): Nodo(v) {}
};

class NodoGreatEq: public Nodo {
 public:
 NodoGreatEq(std::string v): Nodo(v) {}
};

class NodoAnd: public Nodo {
 public:
 NodoAnd(std::string v): Nodo(v) {}
};

class NodoOr: public Nodo {
 public:
 NodoOr(std::string v): Nodo(v) {}
};

class NodoAsig: public Nodo {
 public:
 NodoAsig(std::string v): Nodo(v) {}
};

class NodoNot: public Nodo {
 public:
 NodoNot(std::string v): Nodo(v) {}
};

/** TERMINA SECCION DE SIMBOLOS DE OPERACIONES */


class NodoId: public Nodo {
 public:
 NodoId(std::string v): Nodo(v) {}
};


/**
 * Seccion de bloques
 */

class NodoFunDef: public Nodo {
 public:
 NodoFunDef(std::string v): Nodo(v) {}
};

class NodoFun: public Nodo {
 public:
 NodoFun(std::string v): Nodo(v) {}
};

class NodoWhile: public Nodo {
 public:
 NodoWhile(std::string v): Nodo(v) {}
};

class NodoCond: public Nodo {
 public:
 NodoCond(std::string v): Nodo(v) {}
};

/** TERMINA SECCION DE BLOQUES */

/**
 * Caracteres regidores
 */
class NodoComa: public Nodo {
 public:
 NodoComa(std::string v): Nodo(v) {}
};

class NodoSeq: public Nodo {
 public:
 NodoSeq(std::string v): Nodo(v) {}
};

/** TERMINA SECCION DE REGIDORES */

/*
std::string str(Nodo * n);

std::string aCadena(Nodo * vertice, int nivel, bool rama[]);

std::string espacios(int n, bool rama[]);

int profundidad(Nodo * v);
*/
#endif
