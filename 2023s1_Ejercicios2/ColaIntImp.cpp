#include "ColaInt.h"

#ifdef COLA_INT_IMP

struct _cabezalColaInt {
	int largo;
	int ppio;
	int final;
	int* datos;
};


/* FUNCIONES AUXILIARES */

void actualizarLargo(ColaInt c) {
	int* nuevoVector = new int[c->largo*2];

	for (int pos = 0; pos < c->largo; pos++) {
		nuevoVector[pos] = c->datos[pos];
	}

	c->datos = nuevoVector;
	c->largo *= 2;
}

/* FIN FUNCIONES AUXILIARES */


ColaInt crearColaInt() {
	ColaInt cabezal = new _cabezalColaInt;
	cabezal->ppio = 0;
	cabezal->final = 0;
	cabezal->largo = 10;
	cabezal->datos = new int[cabezal->largo]();
	return cabezal;
}

void encolar(ColaInt& c, int e) { // O(1)
	if (c->final == c->largo) {
		actualizarLargo(c);
	}

	c->datos[c->final] = e;
	c->final++;
}

int principio(ColaInt c) { // O(1)
	return c->datos[c->ppio];
}

void desencolar(ColaInt& c) { // O(1)
	c->ppio++;
}

bool esVacia(ColaInt c) {
	if (c == NULL)return true;
	if (c->final - c->ppio == 0) return true;
	else return false;
}

unsigned int cantidadElementos(ColaInt c) { // O(1)
	return c->final - c->ppio;
}

ColaInt clon(ColaInt c) {
	ColaInt clonada = crearColaInt();

	for (int pos = c->ppio; pos < c->final; pos++) {
		encolar(clonada, c->datos[pos]);
	}

	return clonada;
}

void destruir(ColaInt& c) {
	delete[] c->datos;
	c->datos = NULL;

	delete c;
	c = NULL;
}

#endif