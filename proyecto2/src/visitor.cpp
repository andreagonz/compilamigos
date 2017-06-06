#include "visitor.h"
#include "nodo.h"
#include<iostream>

using namespace std;

/*
  Visitor que crea la tabla de símbolos
*/

////**CHECAR QUE LAS LLAMADAS A FUNCIONES TENGAN EL NÚMERO DE ARGUMENTOS CORRECTO**////
//FALTA CHECAR QUE LOS ARGUMENTOS DE LLAMADAS DE FUNCIONESS TENGAN EL TIPO CORRECTO
//MEJORAR MENSAJES DE ERROR 

void VisitorCreaTabla::error(string s) {
    cout << s <<endl;
    exito = false;
}

bool VisitorCreaTabla::tuvo_error() {
    return !exito;
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
    if(n->num_hijos() > 1)
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
            string s = "Variable '" + x + "' declarada más de una vez en el mismo alcance.";
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
            string s = "Variable '" + x + "' no declarada previamente a su uso.";
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
        if(tipo == NONE) {
            string s = "Variable '" + x + "' no declarada previamente a su uso.";
            error(s);
        } else {
            Simbolo * simb2 = new Simbolo(x, tipo);
            n->set_simbolo(simb2);
            tabla->insert(x, simb2);
        }
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
        Nodo * n2 = n->get(n->num_hijos() - 1)->get(0);
        Simbolo * nsimb;
        if(n2->get_valor() == "int" ||
           n2->get_valor() == "bool" ||
           n2->get_valor() == "float") {
            NodoTipo * nt = (NodoTipo*)n2;
            nsimb = new Simbolo(x, nt->get_tipo());
        } else
            nsimb = new Simbolo(x, NONE);
        tabla->insert(x, nsimb);
        tabla->open_scope();
        NodoId * nid = (NodoId*)n->get(0);
        nid->set_simbolo(nsimb);
        n->get(1)->accept(this);
        if(n->num_hijos() > 2)
            n->get(2)->accept(this);
        tabla->close_scope();
    }
}

void VisitorCreaTabla::visitaNodoFun(NodoFun * n) {
    string x = n->get(0)->get_valor();
    Simbolo * simb = tabla->look_up(x);
    if(simb == nullptr) {
        string s = "Función '" + x + "' no ha sido definida previamente.";
        error(s);
    } else {
        NodoId * nid = (NodoId*)n->get(0);
        nid->set_simbolo(simb);
        if(n->num_hijos() > 1)
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

void VisitorCreaTabla::visitaNodoComa(NodoComa * n) {
    for(int i = 0; i < n->num_hijos(); i++) {
        if(n->get(i)->get_valor() == "int" ||
            n->get(i)->get_valor() == "bool" ||
           n->get(i)->get_valor() == "float") {
            NodoTipo * nt = (NodoTipo*)n->get(i);
            string x = nt->get(0)->get_valor();
            Simbolo * nsimb = new Simbolo(x, nt->get_tipo());
            tabla->insert(x, nsimb);
            NodoId * nid = (NodoId*)nt->get(0);
            nid->set_simbolo(nsimb);
        } else n->get(i)->accept(this);
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


void VisitorVerificaTipos::error(string s) {
    cout << "Error de tipos: " << s << endl;
    exito = false;
}

bool VisitorVerificaTipos::tuvo_error() {
    return !exito;
}

void VisitorVerificaTipos::visitaNodoInt(NodoInt * n) {
    tipo = TINT;
}
 
void VisitorVerificaTipos::visitaNodoFloat(NodoFloat * n) {
    tipo = TFLOAT;
}
 
void VisitorVerificaTipos::visitaNodoBool(NodoBool * n) {
    tipo = TBOOL;
}

void VisitorVerificaTipos::visitaNodoSum(NodoSum * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if(t1 == TFLOAT && t2 == TFLOAT)
        tipo = TFLOAT;
    else if(t1 == TINT && t2 == TINT)
        tipo = TINT;    
    else {
        string s = "Suma de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válida";
        error(s);
    }
}
 
void VisitorVerificaTipos::visitaNodoMenos(NodoMenos * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    if(n->num_hijos() > 1) {
        n->get(1)->accept(this);
        Tipo t2 = tipo;
        if(t1 == TFLOAT && t2 == TFLOAT)
            tipo = TFLOAT;
        else if(t1 == TINT && t2 == TINT)
            tipo = TINT;    
        else {
            string s = "Resta de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válida";
            error(s);
        }
    } else {
        if(t1 == TFLOAT || t1 == TINT)
            tipo = t1;
        else {
            string s = "Negación de " + n->get(0)->get_valor() +  " no válida.";
            error(s);
        }
    }
}
 
void VisitorVerificaTipos::visitaNodoMult(NodoMult * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if(t1 == TFLOAT && t2 == TFLOAT)
        tipo = TFLOAT;
    else if(t1 == TINT && t2 == TINT)
        tipo = TINT;    
    else {
        string s = "Multiplicación de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válida";
        error(s);
    }
}

void VisitorVerificaTipos::visitaNodoDiv(NodoDiv * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if(t1 == TFLOAT && t2 == TFLOAT)
        tipo = TFLOAT;
    else if(t1 == TINT && t2 == TINT)
        tipo = TINT;    
    else {
        string s = "División de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válida";
        error(s);
    }
}
 
void VisitorVerificaTipos::visitaNodoNeg(NodoNeg * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    if(t1 == TFLOAT)
        tipo = TFLOAT;
    else if(t1 == TINT)
        tipo = TINT;    
    else {
        string s = "Negación de " + n->get(0)->get_valor() + " no válida.";
        error(s);
    }
}
 
void VisitorVerificaTipos::visitaNodoEq(NodoEq * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if((t1 == TFLOAT && t2 == TFLOAT) ||
       (t1 == TINT && t2 == TINT) ||
       (t1 == TBOOL && t2 == TBOOL))
        tipo = TBOOL;
    else {
        string s = "Igualdad de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válida.";
        error(s);
    }
}

void VisitorVerificaTipos::visitaNodoNeq(NodoNeq * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if((t1 == TFLOAT && t2 == TFLOAT) ||
       (t1 == TINT && t2 == TINT) ||
       (t1 == TBOOL && t2 == TBOOL))
        tipo = TBOOL;
    else {
        string s = "Desigualdad de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válida.";
        error(s);
    }
}
 
void VisitorVerificaTipos::visitaNodoLess(NodoLess * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if((t1 == TFLOAT && t2 == TFLOAT) ||
       (t1 == TINT && t2 == TINT))
        tipo = TBOOL;
    else {
        string s = "Menor que de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válido.";
        error(s);
    }
}

void VisitorVerificaTipos::visitaNodoGreat(NodoGreat * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if((t1 == TFLOAT && t2 == TFLOAT) ||
       (t1 == TINT && t2 == TINT))
        tipo = TBOOL;
    else {
        string s = "'Mayor que' de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válido.";
        error(s);
    }
}
 
void VisitorVerificaTipos::visitaNodoLessEq(NodoLessEq * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if((t1 == TFLOAT && t2 == TFLOAT) ||
       (t1 == TINT && t2 == TINT))
        tipo = TBOOL;
    else {
        string s = "'Menor o igual que' de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válido.";
        error(s);
    }
}

void VisitorVerificaTipos::visitaNodoGreatEq(NodoGreatEq * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if((t1 == TFLOAT && t2 == TFLOAT) ||
       (t1 == TINT && t2 == TINT))
        tipo = TBOOL;
    else {
        string s = "'Mayor o igual que' de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válido.";
        error(s);
    }
}

void VisitorVerificaTipos::visitaNodoAnd(NodoAnd * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if(t1 == TBOOL && t2 == TBOOL)
        tipo = TBOOL;
    else {
        string s = "And de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válido.";
        error(s);
    }
}
 
void VisitorVerificaTipos::visitaNodoOr(NodoOr * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    Tipo t2 = tipo;
    if(t1 == TBOOL && t2 == TBOOL)
        tipo = TBOOL;
    else {
        string s = "Or de " + n->get(0)->get_valor() + " con " + n->get(1)->get_valor() + " no válido.";
        error(s);
    }
}

void VisitorVerificaTipos::visitaNodoAsig(NodoAsig * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(1)->accept(this);
    if(t1 != tipo) {
        string s = "Se está tratando de asignar tipo " + str(tipo) + " a variable '" + n->get(0)->get_valor() + "' de tipo " + str(t1);
        error(s);
    }
}

void VisitorVerificaTipos::visitaNodoNot(NodoNot * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    if(t1 == TBOOL)
        tipo = TBOOL;
    else {
        string s = "Negación de " + n->get(0)->get_valor() + " no válida.";
        error(s);
    }
}
 
void VisitorVerificaTipos::visitaNodoId(NodoId * n) {
    tipo = n->get_tipo();
}

void VisitorVerificaTipos::visitaNodoTipo(NodoTipo * n) {
    if(n->num_hijos() > 0)
        n->get(0)->accept(this);
}

string str(Tipo t) {
    if(t == TINT)
        return"int";
    if(t == TFLOAT)
        return"float";
    if(t == TBOOL)
        return"bool";
    if(t == NONE)
        return "void";
    return "T";
}

void VisitorVerificaTipos::visitaNodoFunDef(NodoFunDef * n) {
    n->get(0)->accept(this);
    Tipo t1 = tipo;
    n->get(n->num_hijos() - 1)->accept(this);
    if(t1 != tipo) {
        string s = "Función '" + n->get(0)->get_valor() + "' regresa tipo " + str(tipo) + ", tipo " + str(t1) + " esperado.";
        error(s);
    } 
}

void VisitorVerificaTipos::visitaNodoFun(NodoFun * n) {
    NodoTipo * nt = (NodoTipo*)n->get(0);
    tipo = nt->get_tipo();
}
 
void VisitorVerificaTipos::visitaNodoWhile(NodoWhile * n) {
    n->get(0)->accept(this);
    if(tipo != TBOOL)
        error("Condición de while no tiene tipo bool.");
    else
        n->get(1)->accept(this);    
}
 
void VisitorVerificaTipos::visitaNodoCond(NodoCond * n) {
    n->get(0)->accept(this);
    if(tipo != TBOOL)
        error("Condición de cond no tiene tipo bool");
    else {
        n->get(1)->accept(this);
    }
}

void VisitorVerificaTipos::visitaNodoCuerpo(NodoCuerpo * n) {
    if(n->num_hijos() > 2) {
        n->get(1)->accept(this);
        n->get(2)->accept(this);
    } else {
        n->get(1)->accept(this);
        tipo = NONE;
    }
}

void VisitorVerificaTipos::visitaNodoComa(NodoComa * n) {
}

void VisitorVerificaTipos::visitaNodoSeq(NodoSeq * n) {
    for(int i = 0; i < n->num_hijos(); i++)
        n->get(i)->accept(this);
}
 
void VisitorVerificaTipos::visitaNodoReturn(NodoReturn * n) {
    n->get(0)->accept(this);
}

void VisitorVerificaTipos::visitaNodoPipe(NodoPipe * n) {
    n->get(0)->accept(this);
    n->get(1)->accept(this);
    if(tipo != TBOOL)
        error("Condición de cond no tiene tipo bool");
    else
        n->get(2)->accept(this);
}
 
void VisitorVerificaTipos::visitaNodoDefault(NodoDefault * n) {
    tipo = TBOOL;
}

