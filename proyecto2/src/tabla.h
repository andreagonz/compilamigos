#ifndef TABLA_H
#define TABLA_H

#include<unordered_map>
#include<string>

typedef enum Tipo {
    TINT,
    TFLOAT,
    TBOOL,
    NONE
} Tipo;

class Simbolo {
  std::string nombre;
  Tipo tipo;
public:
Simbolo(std::string s, Tipo t) : nombre(s), tipo(t) {} 
  std::string get_nombre(void);
  Tipo get_tipo(void);
};

class Tabla {
    Tabla * padre;
    std::unordered_map<std::string, Simbolo*> simbolos;
public:
Tabla(): padre(NULL){};
Tabla(Tabla * p): padre(p){};
    Tabla * get_padre(void);
    void guarda_simbolo(std::string, Simbolo*);
    Simbolo * get_simbolo(std::string);
};

class TablaSimbolos {
  Tabla * actual;
 public:
TablaSimbolos(Tabla * a) : actual(a) {}
  Simbolo * look_up(std::string);
  void insert(std::string, Simbolo*);
  void open_scope(void);
  void close_scope(void);
  bool declared_locally(std::string);
};

#endif
