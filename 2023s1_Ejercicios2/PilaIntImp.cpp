#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct _cabezalPilaInt {
	NodoListaInt* ppio;
	unsigned int largo;
};

/* FUNCIONES AUXILIARES */

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

NodoListaInt* auxClon(NodoListaInt* p) {
	if (p == NULL) return NULL;
	NodoListaInt* nuevoNodo = new NodoListaInt(p->dato);
	nuevoNodo->sig = auxClon(p->sig);
	return nuevoNodo;
}

void destruir(NodoListaInt*& nodo) {
	if (nodo == NULL) return;
	destruir(nodo->sig);
	nodo = NULL;
	delete nodo;
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
	if (esVacia(p)) return NULL;
	return p->ppio->dato;
}

void pop(PilaInt& p) {
	if (esVacia(p)) return;

	NodoListaInt* aBorrar = p->ppio;
	p->ppio = p->ppio->sig;
	p->largo--;
	aBorrar = NULL;
	delete aBorrar;
}

unsigned int cantidadElementos(PilaInt p) {
	return p->largo;
}

bool esVacia(PilaInt p) {
	return p->largo == 0;
}

PilaInt clon(PilaInt p) {
	PilaInt cabezal = new _cabezalPilaInt;
	cabezal->ppio = auxClon(p->ppio);
	cabezal->largo = p->largo;
	return cabezal;
	return NULL;
}

void destruir(PilaInt& p) {
	p->largo = 0;
	destruir(p->ppio);
	p->ppio = NULL;
	delete p;
}


#endif