#ifndef VISITOR_H
#define VISITOR_H

#include<unordered_map>
#include<string>
#include "tabla.h"

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
class NodoFunDef;
class NodoFun;
class NodoWhile;
class NodoCond;
class NodoCuerpo;
class NodoComa;
class NodoSeq;
class NodoReturn;
class NodoPipe;
class NodoDefault;

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
    virtual void visitaNodoFunDef(NodoFunDef * n) = 0;
    virtual void visitaNodoFun(NodoFun * n) = 0; 
    virtual void visitaNodoWhile(NodoWhile * n) = 0; 
    virtual void visitaNodoCond(NodoCond * n) = 0;
    virtual void visitaNodoCuerpo(NodoCuerpo * n) = 0;
    virtual void visitaNodoComa(NodoComa * n) = 0;
    virtual void visitaNodoSeq(NodoSeq * n) = 0; 
    virtual void visitaNodoReturn(NodoReturn * n) = 0;
    virtual void visitaNodoPipe(NodoPipe * n) = 0; 
    virtual void visitaNodoDefault(NodoDefault * n) = 0;
};

class VisitorCreaTabla: public Visitor {
    TablaSimbolos * tabla;
    Tipo tipo;
    bool exito;
public:
VisitorCreaTabla() : exito(true) {
        Tabla * t = new Tabla();
        tabla = new TablaSimbolos(t);    
    }
    void error(std::string s);
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
    void visitaNodoFunDef(NodoFunDef * n);
    void visitaNodoFun(NodoFun * n); 
    void visitaNodoWhile(NodoWhile * n); 
    void visitaNodoCond(NodoCond * n);
    void visitaNodoCuerpo(NodoCuerpo * n);
    void visitaNodoComa(NodoComa * n);
    void visitaNodoSeq(NodoSeq * n); 
    void visitaNodoReturn(NodoReturn * n);
    void visitaNodoPipe(NodoPipe * n); 
    void visitaNodoDefault(NodoDefault * n);
};

class VisitorVerificaTipos: public Visitor {
public:
    VisitorVerificaTipos() {}
    void error(std::string s);
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
    void visitaNodoFunDef(NodoFunDef * n);
    void visitaNodoFun(NodoFun * n); 
    void visitaNodoWhile(NodoWhile * n); 
    void visitaNodoCond(NodoCond * n);
    void visitaNodoCuerpo(NodoCuerpo * n);
    void visitaNodoComa(NodoComa * n);
    void visitaNodoSeq(NodoSeq * n); 
    void visitaNodoReturn(NodoReturn * n);
    void visitaNodoPipe(NodoPipe * n); 
    void visitaNodoDefault(NodoDefault * n);
};

#endif
