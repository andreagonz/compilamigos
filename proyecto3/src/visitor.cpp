#include "visitor.h"
#include "nodo.h"
#include<iostream>

using namespace std;

/*
  Visitor que crea la tabla de símbolos
*/


//Se le agrego el metodo get_table para poder obtener y preguntale por las variable el tipo de variables al genera el codigo

void VisitorCreaTabla::error(string s) {
    cout << s <<endl;
    exito = false;
}

TablaSimbolos * VisitorCreaTabla::get_tabla(void) {
    return tabla;
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
        if(actual != nullptr)
            actual->add_arg(tipo);
        n->get(0)->accept(this);
        tipo = NONE;
    }
}

void VisitorCreaTabla::visitaNodoSeq(NodoSeq * n) {
    for(int i = 0; i < n->num_hijos(); i++)
        n->get(i)->accept(this);
}

/*
Visitor que verifica los tipos
*/


void VisitorVerificaTipos::error(string s) {
    cout << "Error de semántica: " << s << endl;
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
        string s = "Suma de " + str(t1) + " con " + str(t2) + " no válida";
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
            string s = "Resta de " + str(t1) + " con " + str(t2) + " no válida";
            error(s);
        }
    } else {
        if(t1 == TFLOAT || t1 == TINT)
            tipo = t1;
        else {
            string s = "Operación 'menos' de " + str(t1) +  " no válida.";
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
        string s = "Multiplicación de " + str(t1) + " con " + str(t2) + " no válida";
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
        string s = "División de " + str(t1) + " con " + str(t2) + " no válida";
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
        string s = "Negación de " + str(t1) + " no válida.";
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
        string s = "Igualdad de " + str(t1) + " con " + str(t2) + " no válida";
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
        string s = "Desigualdad de " + str(t1) + " con " + str(t2) + " no válida";
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
        string s = "'Menor que' de " + str(t1) + " con " + str(t2) + " no válido";
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
        string s = "'Mayor que' de " + str(t1) + " con " + str(t2) + " no válido";
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
        string s = "'Menor o igual que' de " + str(t1) + " con " + str(t2) + " no válido";
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
        string s = "'Mayor o igual que' de " + str(t1) + " con " + str(t2) + " no válido";
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
        string s = "And de " + str(t1) + " con " + str(t2) + " no válido";
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
        string s = "Or de " + str(t1) + " con " + str(t2) + " no válido";
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
        string s = "Negación de " + str(t1) + " no válida.";
        error(s);
    }
}
 
void VisitorVerificaTipos::visitaNodoId(NodoId * n) {
    if(args.size() > 0 && n->get_simbolo()->es_fun()) {
        string s = "Tratando de usar función '" + n->get_valor() + "' como argumento a una función";
        error(s);
    } else if(n->get_simbolo()->es_fun()) {
        string s = "Se está tratando de usar función '" + n->get_valor() + "' como variable.";
        error(s);
    }
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

void VisitorVerificaTipos::visitaNodoSeq(NodoSeq * n) {
    for(int i = 0; i < n->num_hijos(); i++)
        n->get(i)->accept(this);
}

