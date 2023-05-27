#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct _cabezalListaPosInt {
	int largo;
	int cantElementos;
	int* datos;
};


/* FUNCIONES AUXILIARES */

void actualizarLargo(ListaPosInt& l) {
	int* nuevoVector = new int[l->largo*2];

	for (int pos = 0; pos < l->largo; pos++) {
		nuevoVector[pos] = l->datos[pos];
	}

	l->datos = nuevoVector;
	l->largo *= 2;
}

/* FIN FUNCIONES AUXILIARES */


ListaPosInt crearListaPosInt() {
	ListaPosInt cabezal = new _cabezalListaPosInt;
	cabezal->cantElementos = 0;
	cabezal->largo = 2;
	cabezal->datos = new int[cabezal->largo]();
	return cabezal;
}

void agregar(ListaPosInt& l, int e, unsigned int pos) {
	if (l->cantElementos == l->largo) {
		actualizarLargo(l);
	}
	if (pos < l->cantElementos) {
		for (int cambio = l->cantElementos; cambio >= pos; cambio--) {
			l->datos[cambio + 1] = l->datos[cambio];
		}
		l->datos[pos] = e;
	}
	else {
		l->datos[l->cantElementos] = e;
	}

	l->cantElementos++;
}

void borrar(ListaPosInt& l, unsigned int pos) {
	if (pos <= l->cantElementos - 1 && l->cantElementos != 0) {
		for (int cambio = pos; cambio < l->cantElementos; cambio++) {
			l->datos[cambio] = l->datos[cambio + 1];
		}
		l->cantElementos--;
	}
}

int elemento(ListaPosInt l, unsigned int pos) {	// O(1)
	return l->datos[pos];
}

bool esVacia(ListaPosInt l) {
	return l->cantElementos == 0;
}

unsigned int cantidadElementos(ListaPosInt l) { // O(1)
	return l->cantElementos;
}

ListaPosInt clon(ListaPosInt l) {
	ListaPosInt retorno = crearListaPosInt();
	for (int pos = 0; pos < l->cantElementos; pos++) {
		agregar(retorno, l->datos[pos], pos);
	}

	return retorno;
}

void destruir(ListaPosInt& l) {
	delete[] l->datos;
	l->datos = NULL;

	delete l;
	l = NULL;
}


#endif