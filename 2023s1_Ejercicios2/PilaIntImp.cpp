#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct _cabezalPilaInt {
	NodoListaInt* ppio;
	unsigned int largo;
};

/* AUXILIARES */

void push(NodoListaInt*& l, int dato) {
	if (l == NULL) {
		l = new NodoListaInt(dato);
	}
	else {
		NodoListaInt* nuevoNodo = new NodoListaInt(dato);
		nuevoNodo->sig = l;
		l = nuevoNodo;
	}
}

void pop(NodoListaInt*& p) {
	if (p == NULL) return;
	
	NodoListaInt* aBorrar = p;
	p = p->sig;
	delete aBorrar;
	aBorrar->dato = NULL;
}

NodoListaInt* clon(NodoListaInt* p) {
	if (p == NULL) return NULL;
	NodoListaInt* nuevoNodo = new NodoListaInt;
	nuevoNodo->dato = p->dato;
	nuevoNodo->sig = clon(p->sig);
	return nuevoNodo;
}

/* FIN AUXILIARES */


PilaInt crearPilaInt(){
	PilaInt cabezal = new _cabezalPilaInt;
	cabezal->ppio = NULL;
	cabezal->largo = 0;
	return cabezal;
}

void push(PilaInt& p, int e) {
	push(p->ppio, e);
	p->largo++;
}

int top(PilaInt p) {
	assert(!esVacia(p));
	return p->ppio->dato;
}

void pop(PilaInt& p) {
	assert(!esVacia(p));
	pop(p->ppio);
}

unsigned int cantidadElementos(PilaInt p) {
	return p->largo;
}

bool esVacia(PilaInt p) {
	return p->largo == 0;
}

PilaInt clon(PilaInt p) {
	PilaInt cabezal = new _cabezalPilaInt;
	cabezal->ppio = clon(p->ppio);
	cabezal->largo = p->largo;
	return cabezal;
	return NULL;
}

void destruir(PilaInt& p) {
	// NO IMPLEMENTADO
}


#endif