#include "visitor.h"
#include "nodo.h"
#include<iostream>

using namespace std;

/*
  Visitor que crea la tabla de símbolos
*/

void VisitorCreaTabla::error(string s) {
    cout << s <<endl;
    exito = false;
}

void VisitorCreaTabla::visitaNodoInt(NodoInt * n) {
}
 
void VisitorCreaTabla::visitaNodoFloat(NodoFloat * n) {
}
 
void VisitorCreaTabla::visitaNodoBool(NodoBool * n) {
}

void VisitorCreaTabla::visitaNodoSum(NodoSum * n) {    
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}
 
void VisitorCreaTabla::visitaNodoMenos(NodoMenos * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}
 
void VisitorCreaTabla::visitaNodoMult(NodoMult * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}

void VisitorCreaTabla::visitaNodoDiv(NodoDiv * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}
 
void VisitorCreaTabla::visitaNodoNeg(NodoNeg * n) {
    n->get(0)->accept(this);
}
 
void VisitorCreaTabla::visitaNodoEq(NodoEq * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}

void VisitorCreaTabla::visitaNodoNeq(NodoNeq * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}
 
void VisitorCreaTabla::visitaNodoLess(NodoLess * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}

void VisitorCreaTabla::visitaNodoGreat(NodoGreat * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}
 
void VisitorCreaTabla::visitaNodoLessEq(NodoLessEq * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}

void VisitorCreaTabla::visitaNodoGreatEq(NodoGreatEq * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}

void VisitorCreaTabla::visitaNodoAnd(NodoAnd * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}
 
void VisitorCreaTabla::visitaNodoOr(NodoOr * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
}

void VisitorCreaTabla::visitaNodoAsig(NodoAsig * n) {
    string x = n->get(0)->get_valor();
    if(tipo != NONE) {
        if(tabla->declared_locally(x)) {
            string s = "Variable " + x + " declarada más de una vez en el mismo alcance.";
            error(s);
        } else {
            Simbolo * simb = new Simbolo(x, tipo);
            tabla->insert(x, simb);
            NodoId * nid = (NodoId*)n->get(0);
            nid->set_simbolo(simb);
        }
    } else {
        Simbolo * simb = tabla->look_up(x);
        if(simb == nullptr) {
            string s = "Variable " + x + " no declarada previamente a su uso.";
            error(s);
        } else {
            NodoId * nid = (NodoId*)n->get(0);
            nid->set_simbolo(simb);
        }
    }
    n->get(1)->accept(this);
}

void VisitorCreaTabla::visitaNodoNot(NodoNot * n) {
    n->get(0)->accept(this);
}

void VisitorCreaTabla::visitaNodoId(NodoId * n) {
    string x = n->get_valor();
    Simbolo * simb = tabla->look_up(x);
    if(simb == nullptr) {
        string s = "Variable " + x + " no declarada previamente a su uso.";
        error(s);
    } else {
        n->set_simbolo(simb);
    }
}

void VisitorCreaTabla::visitaNodoTipo(NodoTipo * n) {
    if(n->num_hijos() > 0) {
        tipo = n->get_tipo();
        n->get(0)->accept(this);
        tipo = NONE;
    }
}

void VisitorCreaTabla::visitaNodoFunDef(NodoFunDef * n) {
    string x = n->get(0)->get_valor();
    Simbolo * simb = tabla->look_up(x);
    if(simb != nullptr) {
        string s = "Nombre para función '" + x + "' previamente utilizado.";
        error(s);
    } else {
        NodoTipo * nt = (NodoTipo*)n->get(2)->get(0);
        Simbolo * nsimb = new Simbolo(x, nt->get_tipo());
        tabla->insert(x, nsimb);
        NodoId * nid = (NodoId*)n->get(0);
        nid->set_simbolo(nsimb);
        tabla->open_scope();
        n->get(1)->accept(this);
        n->get(2)->accept(this);
        tabla->close_scope();
    }
}

///REVISAR SI ES VAR O FUN
void VisitorCreaTabla::visitaNodoFun(NodoFun * n) {
    string x = n->get(0)->get_valor();
    Simbolo * simb = tabla->look_up(x);
    if(simb == nullptr) {
        string s = "Función '" + x + "' no ha sido declarada previamente.";
        error(s);
    } else {
        NodoId * nid = (NodoId*)n->get(0);
        nid->set_simbolo(simb);
        n->get(1)->accept(this);
    }
}
 
void VisitorCreaTabla::visitaNodoWhile(NodoWhile * n) {
    n->get(0)->accept(this);
    tabla->open_scope();
    n->get(1)->accept(this);
    tabla->close_scope();
}
 
void VisitorCreaTabla::visitaNodoCond(NodoCond * n) {
    n->get(0)->accept(this);
    if(n->get(1)->get_valor() != "pipe") {
        tabla->open_scope();
        n->get(1)->accept(this);
        tabla->close_scope();
    } else n->get(1)->accept(this);
}

void VisitorCreaTabla::visitaNodoCuerpo(NodoCuerpo * n) {
    for(int i = 1; i < n->num_hijos(); i++)
        n->get(i)->accept(this);
}

// AREGLAR ESTO, SI HAY MAS DE DOS ELEMENTOS CON COMA HAY PROBLEMAS
void VisitorCreaTabla::visitaNodoComa(NodoComa * n) {
    for(int i = 0; i < n->num_hijos(); i++) {
        NodoTipo * nt = (NodoTipo*)n->get(i);
        string x = nt->get(0)->get_valor();
        Simbolo * nsimb = new Simbolo(x, nt->get_tipo());
        tabla->insert(x, nsimb);
        NodoId * nid = (NodoId*)nt->get(0);
        nid->set_simbolo(nsimb);
    }
}

void VisitorCreaTabla::visitaNodoSeq(NodoSeq * n) {
    for(int i = 0; i < n->num_hijos(); i++)
        n->get(i)->accept(this);
}
 
void VisitorCreaTabla::visitaNodoReturn(NodoReturn * n) {
    n->get(0)->accept(this);
}

void VisitorCreaTabla::visitaNodoPipe(NodoPipe * n) {
    tabla->open_scope();
    n->get(0)->accept(this);
    tabla->close_scope();
    n->get(1)->accept(this);
    if(n->get(2)->get_valor() != "pipe") {
        tabla->open_scope();
        n->get(2)->accept(this);
        tabla->close_scope();
    } else n->get(2)->accept(this);
}
 
void VisitorCreaTabla::visitaNodoDefault(NodoDefault * n) {
}

/*
Visitor que verifica los tipos
*/

void VisitorVerificaTipos::visitaNodoInt(NodoInt * n) {
}
 
void VisitorVerificaTipos::visitaNodoFloat(NodoFloat * n) {
}
 
void VisitorVerificaTipos::visitaNodoBool(NodoBool * n) {
}

void VisitorVerificaTipos::visitaNodoSum(NodoSum * n) {
}
 
void VisitorVerificaTipos::visitaNodoMenos(NodoMenos * n) {
}
 
void VisitorVerificaTipos::visitaNodoMult(NodoMult * n) {
}

void VisitorVerificaTipos::visitaNodoDiv(NodoDiv * n) {
}
 
void VisitorVerificaTipos::visitaNodoNeg(NodoNeg * n) {
}
 
void VisitorVerificaTipos::visitaNodoEq(NodoEq * n) {
}

void VisitorVerificaTipos::visitaNodoNeq(NodoNeq * n) {
}
 
void VisitorVerificaTipos::visitaNodoLess(NodoLess * n) {
}

void VisitorVerificaTipos::visitaNodoGreat(NodoGreat * n) {
}
 
void VisitorVerificaTipos::visitaNodoLessEq(NodoLessEq * n) {
}

void VisitorVerificaTipos::visitaNodoGreatEq(NodoGreatEq * n) {
}

void VisitorVerificaTipos::visitaNodoAnd(NodoAnd * n) {
}
 
void VisitorVerificaTipos::visitaNodoOr(NodoOr * n) {
}

void VisitorVerificaTipos::visitaNodoAsig(NodoAsig * n) {
}

void VisitorVerificaTipos::visitaNodoNot(NodoNot * n) {
}
 
void VisitorVerificaTipos::visitaNodoId(NodoId * n) {
}

void VisitorVerificaTipos::visitaNodoTipo(NodoTipo * n) {
}

void VisitorVerificaTipos::visitaNodoFunDef(NodoFunDef * n) {
}

void VisitorVerificaTipos::visitaNodoFun(NodoFun * n) {
}
 
void VisitorVerificaTipos::visitaNodoWhile(NodoWhile * n) {
}
 
void VisitorVerificaTipos::visitaNodoCond(NodoCond * n) {
}

void VisitorVerificaTipos::visitaNodoCuerpo(NodoCuerpo * n) {
}

void VisitorVerificaTipos::visitaNodoComa(NodoComa * n) {
}

void VisitorVerificaTipos::visitaNodoSeq(NodoSeq * n) {
}
 
void VisitorVerificaTipos::visitaNodoReturn(NodoReturn * n) {
}

void VisitorVerificaTipos::visitaNodoPipe(NodoPipe * n) {
}
 
void VisitorVerificaTipos::visitaNodoDefault(NodoDefault * n) {
}

