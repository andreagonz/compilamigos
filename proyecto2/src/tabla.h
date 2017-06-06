#ifndef TABLA_H
#define TABLA_H

#include<unordered_map>
#include<string>
#include<vector>

typedef enum Tipo {
    TINT,
    TFLOAT,
    TBOOL,
    NONE
} Tipo;

class Simbolo {
  std::string nombre;
  Tipo tipo;
  bool fun;
  std::vector<Tipo> args;
public:
Simbolo(std::string s, Tipo t) : nombre(s), tipo(t), fun(false) {}
Simbolo(std::string s, Tipo t, bool f) : nombre(s), tipo(t), fun(f) {}
  std::string get_nombre(void);
  Tipo get_tipo(void);
  bool es_fun(void);
  void add_arg(Tipo t);
  int num_args();
  Tipo get_arg(int i);
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
