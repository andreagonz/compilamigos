#ifndef VISITOR_H
#define VISITOR_H

#include<unordered_map>
#include<string>
#include<vector>
#include "tabla.h"

//Se le agrego el metodo get_table para poder obtener y preguntale por las variable el tipo de variables al genera el codigo

class NodoInt;
class NodoFloat;
class NodoBool;
class NodoSum;
class NodoMenos;
class NodoMult;
class NodoDiv;
class NodoNeg;
class NodoEq;
class NodoNeq;
class NodoLess;
class NodoGreat;
class NodoLessEq;
class NodoGreatEq;
class NodoAnd;
class NodoOr;
class NodoAsig;
class NodoNot;
class NodoId;
class NodoTipo;
class NodoSeq;

class Visitor {
public:
    virtual void visitaNodoInt(NodoInt * n) = 0; 
    virtual void visitaNodoFloat(NodoFloat * n) = 0; 
    virtual void visitaNodoBool(NodoBool * n) = 0;
    virtual void visitaNodoSum(NodoSum * n) = 0; 
    virtual void visitaNodoMenos(NodoMenos * n) = 0; 
    virtual void visitaNodoMult(NodoMult * n) = 0;
    virtual void visitaNodoDiv(NodoDiv * n) = 0; 
    virtual void visitaNodoNeg(NodoNeg * n) = 0; 
    virtual void visitaNodoEq(NodoEq * n) = 0;
    virtual void visitaNodoNeq(NodoNeq * n) = 0; 
    virtual void visitaNodoLess(NodoLess * n) = 0;
    virtual void visitaNodoGreat(NodoGreat * n) = 0; 
    virtual void visitaNodoLessEq(NodoLessEq * n) = 0;
    virtual void visitaNodoGreatEq(NodoGreatEq * n) = 0;
    virtual void visitaNodoAnd(NodoAnd * n) = 0; 
    virtual void visitaNodoOr(NodoOr * n) = 0;
    virtual void visitaNodoAsig(NodoAsig * n) = 0;
    virtual void visitaNodoNot(NodoNot * n) = 0; 
    virtual void visitaNodoId(NodoId * n) = 0;
    virtual void visitaNodoTipo(NodoTipo * n) = 0;
    virtual void visitaNodoSeq(NodoSeq * n) = 0; 
};

class VisitorCreaTabla: public Visitor {
    TablaSimbolos * tabla;
    Tipo tipo;
    bool exito;
    Simbolo * actual;
public:
VisitorCreaTabla() : exito(true) {
        Tabla * t = new Tabla();
        tabla = new TablaSimbolos(t);    
    }
    
    TablaSimbolos * get_tabla(void);
    void error(std::string s);
    bool tuvo_error();
    void visitaNodoInt(NodoInt * n); 
    void visitaNodoFloat(NodoFloat * n); 
    void visitaNodoBool(NodoBool * n);
    void visitaNodoSum(NodoSum * n); 
    void visitaNodoMenos(NodoMenos * n); 
    void visitaNodoMult(NodoMult * n);
    void visitaNodoDiv(NodoDiv * n); 
    void visitaNodoNeg(NodoNeg * n); 
    void visitaNodoEq(NodoEq * n);
    void visitaNodoNeq(NodoNeq * n); 
    void visitaNodoLess(NodoLess * n);
    void visitaNodoGreat(NodoGreat * n); 
    void visitaNodoLessEq(NodoLessEq * n);
    void visitaNodoGreatEq(NodoGreatEq * n);
    void visitaNodoAnd(NodoAnd * n); 
    void visitaNodoOr(NodoOr * n);
    void visitaNodoAsig(NodoAsig * n);
    void visitaNodoNot(NodoNot * n); 
    void visitaNodoId(NodoId * n);
    void visitaNodoTipo(NodoTipo * n);
    void visitaNodoSeq(NodoSeq * n); 
};

class VisitorVerificaTipos: public Visitor {
    Tipo tipo;
    bool exito;
    std::vector<Tipo> args;
public:
    VisitorVerificaTipos() {}
    void error(std::string s);
    bool tuvo_error();
    void visitaNodoInt(NodoInt * n);
    void visitaNodoFloat(NodoFloat * n); 
    void visitaNodoBool(NodoBool * n);
    void visitaNodoSum(NodoSum * n); 
    void visitaNodoMenos(NodoMenos * n); 
    void visitaNodoMult(NodoMult * n);
    void visitaNodoDiv(NodoDiv * n); 
    void visitaNodoNeg(NodoNeg * n); 
    void visitaNodoEq(NodoEq * n);
    void visitaNodoNeq(NodoNeq * n); 
    void visitaNodoLess(NodoLess * n);
    void visitaNodoGreat(NodoGreat * n); 
    void visitaNodoLessEq(NodoLessEq * n);
    void visitaNodoGreatEq(NodoGreatEq * n);
    void visitaNodoAnd(NodoAnd * n); 
    void visitaNodoOr(NodoOr * n);
    void visitaNodoAsig(NodoAsig * n);
    void visitaNodoNot(NodoNot * n); 
    void visitaNodoId(NodoId * n);
    void visitaNodoTipo(NodoTipo * n);
    void visitaNodoSeq(NodoSeq * n); 
};

std::string str(Tipo t);

#endif
